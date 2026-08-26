#include "physics.h"

// TODO: two responsibilities the audit flagged separately --
// 1. zero-crossing detection (find each pass through equilibrium,
//    "визначення переходу через нуль" in the audit's list)
// 2. period = time between two zero-crossings in the same direction
//    ("обчислення періоду")
// Both stay in Rational32/Rational64 (timestamps are already integer
// microseconds from the driver, so this should never need float).
