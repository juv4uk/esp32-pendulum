#include "physics.h"

// TODO: angular velocity from two consecutive UnwrappedSamples --
// (angle2 - angle1) / (t2 - t1), entirely in Rational32/Rational64, no
// float. Audit finding: "розрахунок швидкості" was one of the items
// flagged for review in the original. Watch for the same overflow class
// of bug rational.c's mul_div exists to solve -- a naive angle-delta *
// some large timestamp scale can overflow 32-bit before you divide.
