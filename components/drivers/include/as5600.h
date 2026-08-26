#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c.h"

// Driver for the AS5600 magnetic angle sensor (I2C, 12-bit raw angle,
// 0..4095 counts per revolution) -- the pendulum's only sensor input.
//
// Two real requirements the original version got wrong, per the audit:
// 1. Raw angle wraps at 0/4095 -- a driver-level read must not itself
//    assume continuity; wrap-handling (unwrap) is physics.c's job, not
//    this driver's, but this driver must report the raw count honestly,
//    including right at the wrap boundary.
// 2. No float anywhere here either -- angle stays as a raw uint16_t
//    count (0..4095); conversion to any physical unit (radians, degrees)
//    happens later, in Rational32, in the physics layer.

typedef struct {
    i2c_port_t i2c_port;
    uint8_t i2c_addr; // AS5600 default: 0x36
} As5600Handle;

// TODO (lesson 2, after rational.c): implement these.
// - as5600_init(i2c_port, i2c_addr) -> As5600Handle
// - as5600_read_raw_angle(handle) -> raw 12-bit count (0..4095), plus a
//   way to report an I2C read failure (nothing here may silently return
//   a plausible-looking wrong value on a bus error).
// - as5600_read_median(handle, sample_count) -> raw count, taking
//   sample_count consecutive readings and returning the median (the
//   digital filter mentioned in the audit) -- decide what sample_count
//   is reasonable given the I2C bus speed and how often processing.c
//   will want a fresh angle.
