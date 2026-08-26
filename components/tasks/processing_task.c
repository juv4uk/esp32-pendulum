#include "tasks.h"

// TODO: while(1) { pull a sample off sensor_task's queue, run it through
// the physics.h pipeline (unwrap -> filter -> velocity -> ... -> g),
// hand the result off to logger_task/uart_task }. This is where the
// original's race condition lived (shared arrays copied between tasks
// with no lock) -- decide the ownership/handoff mechanism here first.
void task_processing(void *pvParameters)
{
}
