#include "esp_log.h"

static const char *TAG = "app_main";

// Entry point. Wires up sensor_task/processing_task/logger_task/uart_task
// once those exist in components/tasks -- for now just confirms the
// project builds and flashes.
void app_main(void)
{
    ESP_LOGI(TAG, "esp32-pendulum skeleton boot -- nothing wired up yet");
}
