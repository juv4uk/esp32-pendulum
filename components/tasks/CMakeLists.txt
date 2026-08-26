idf_component_register(
    SRCS "sensor_task.c" "processing_task.c" "logger_task.c" "uart_task.c"
    INCLUDE_DIRS "include"
    REQUIRES drivers physics
)
