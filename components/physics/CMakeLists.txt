idf_component_register(
    SRCS "unwrap.c" "velocity.c" "peak_detector.c" "period_estimator.c" "quality_factor.c" "gravity.c"
    INCLUDE_DIRS "include"
    REQUIRES math
)
