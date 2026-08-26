#pragma once
#include <stdint.h>
#include <stdbool.h>

// Exact rational arithmetic for the whole pendulum pipeline -- no float,
// no double, anywhere in the measurement/analysis code. Only place a
// double is allowed to exist at all is an optional final print/log
// conversion, never in a calculation that feeds back into the pipeline.
//
// Real bug from the original (July 2026) version, found by an external
// audit and the reason this type is being rewritten from scratch here:
// Rational32's multiply did `num1 * num2` / `den1 * den2` directly in
// 32-bit, which can silently overflow when either denominator is large.
// The fix is NOT "use bigger ints and hope" -- it's: do the intermediate
// multiply in 64-bit (int64_t), reduce by the gcd before multiplying
// wherever possible, and decide on purpose what happens if the result
// still doesn't fit back into 32-bit (saturate? assert? return a status?
// -- this is a real design decision, not a detail to skip).
typedef struct {
    int32_t num;
    int32_t den; // invariant: always > 0 -- sign lives in num
} Rational32;

typedef struct {
    int64_t num;
    int64_t den;
} Rational64;

// TODO (lesson 1): implement these. Each one has a specific correctness
// requirement noted below -- don't just make it compile, make it survive
// the requirement:
//
// - rational32_make(num, den): normalizes sign into num, reduces by gcd.
//   den == 0 is a caller bug -- decide how this function reports that.
// - rational32_mul(a, b): the actual overflow-prone operation described
//   above. Must not silently produce a wrong answer on inputs whose
//   product doesn't fit in 32 bits.
// - rational32_add(a, b), rational32_sub(a, b)
// - rational32_compare(a, b): returns -1/0/1 without converting to
//   float/double (cross-multiply in 64-bit instead).
// - rational32_average(values[], count): running average without
//   accumulating a fraction whose denominator explodes after N terms.
// - rational32_to_double(a): the ONLY function in this header allowed to
//   produce a double, and only for display -- nothing downstream may
//   consume its output.
//
// Deliberately not declaring sqrt/median yet -- add them when the
// physics pipeline (components/physics) actually needs them, so their
// signature is driven by a real caller instead of guessed in advance.
