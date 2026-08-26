#pragma once

// FreeRTOS task entry points. Per the audit's own advice, keep these
// thin -- each one is just `while(1) { real_function(); vTaskDelay(...); }`
// -- so the actual logic (sensor_update, pendulum_process, ...) stays
// testable without FreeRTOS and portable if the RTOS ever changes.
//
// Real bug from the original version, per the audit: "є місця, де
// можливі гонки між задачами при копіюванні великих масивів" -- shared
// state between these tasks needs an actual synchronization plan
// (mutex around the shared struct, or a queue handing off ownership of
// each sample) BEFORE any task touches it, not added after something
// breaks. Also per the audit: split the original monolithic SharedData
// into separate SensorState / PendulumState / MeasurementState /
// StatisticsState / CalibrationState structs instead of one struct with
// "сотні полів" -- decide where those structs live (probably
// components/physics or a new components/state) before wiring these
// tasks together.

void task_sensor(void *pvParameters);
void task_processing(void *pvParameters);
void task_logger(void *pvParameters);
void task_uart(void *pvParameters);
