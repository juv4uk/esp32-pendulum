#include "physics.h"

// TODO: turn the AS5600's raw 0..4095 count (wraps every revolution)
// into a continuous angle. Audit finding this replaces: "неправильна
// обробка wrap AS5600" -- the wrap logic in the original version had a
// real bug here. Requirement: crossing the 0/4095 boundary in EITHER
// direction must add/subtract exactly one full revolution (4096 counts)
// to the running unwrapped total, not lose or double-count a step. Test
// this directly with a hand-built sequence of raw readings that crosses
// the boundary both ways before trusting it on real hardware.
