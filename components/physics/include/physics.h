#pragma once
#include <stdint.h>
#include "rational.h"

// The measurement pipeline, exactly as designed in the ESP-IDF audit
// this project restarts from (2026-07-25):
//
//   AS5600 (raw 12-bit angle, wraps at 0/4095)
//     -> unwrap        (continuous angle, no more 0/4095 jump)
//     -> filter         (digital smoothing, still Rational32)
//     -> velocity        (d(angle)/dt, from consecutive samples + timestamps)
//     -> zero-crossing   (find each pass through equilibrium)
//     -> peak_detector   (find each amplitude extreme, for Q)
//     -> period_estimator (time between zero-crossings -> period)
//     -> quality_factor  (Q from successive peak amplitudes -- rationally,
//                          see the note in quality_factor.c, NOT via
//                          Q = pi / ln(A1/A2) and math.h's log())
//     -> gravity         (period + pendulum length -> g)
//
// One file per stage (unwrap.c, velocity.c, peak_detector.c,
// period_estimator.c, quality_factor.c, gravity.c) -- each stage is
// independently testable by feeding it synthetic input instead of a
// live sensor, per the audit's own suggestion (e.g. feed peak_detector
// a hand-built noisy synthetic wave and check it finds the right max).

typedef struct {
    int32_t unwrapped_angle; // continuous, no 0/4095 wrap
    uint64_t timestamp_us;
} UnwrappedSample;

// TODO (lesson 3+, after rational.c and as5600.c both work): implement
// one pipeline stage at a time, in the order above. Each stage's .c file
// has its own TODO with the specific correctness requirement the audit
// flagged for that stage.
