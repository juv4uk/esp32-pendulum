#include "physics.h"

// TODO: Q (quality factor) from successive peak amplitudes A1, A2.
//
// The ORIGINAL version computed this as Q = pi / ln(A1/A2), which pulls
// in math.h's log() and pi -- both double-precision, both audit finding
// #2 ("У computeQ_from_ratios() залишилася залежність від double").
// That's the one piece of this whole project NOT to just copy over.
//
// The plan discussed instead: either a rational approximation of the
// logarithmic decrement (a polynomial/rational fit good enough over the
// A1/A2 range this pendulum actually produces), or a regression across
// several successive peaks instead of just two -- both avoid log()
// entirely. Pick one, and be explicit in a comment here about which you
// chose and why -- this is the single most "interesting C problem" in
// the whole project, worth not rushing.
