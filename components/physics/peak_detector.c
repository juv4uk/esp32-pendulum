#include "physics.h"

// TODO: find each local amplitude extreme (peak) in the unwrapped,
// filtered angle stream. Audit finding: "пошук піків (зараз можливі
// пропуски)" -- the original could silently skip a peak, which quietly
// corrupts every downstream Q calculation without crashing anything.
// Per the audit's own suggestion: prove this one works by feeding it a
// synthetic, hand-generated noisy sine wave (not live sensor data) and
// checking it finds exactly the peaks you put there -- a pipeline stage
// that's only ever been tested against a live pendulum is a stage
// that's never actually been tested.
