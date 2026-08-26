#include "physics.h"

// TODO: g from period T and pendulum length L, small-angle approximation
// T = 2*pi*sqrt(L/g)  =>  g = 4*pi^2*L / T^2
//
// Two irrational constants (pi, sqrt) in one formula, in a project that
// otherwise refuses float/double everywhere else -- this is the honest
// edge of the "everything stays Rational32" rule. Decide, in a comment
// here, whether this final step is the one place a double conversion is
// allowed (this is the last stage -- nothing downstream consumes g's
// output for further calculation), or whether you'd rather carry a
// fixed-point rational approximation of pi/sqrt through this too. Either
// is defensible; the audit's rule was "no float in the pipeline", and
// this is arguably the pipeline's exit, not its middle.
