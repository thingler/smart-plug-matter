#pragma once
#include <esp_err.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int gpio;
} power_driver_config_t;

typedef void *power_driver_handle_t;

power_driver_handle_t power_driver_init(power_driver_config_t *config);
esp_err_t driver_set_power(power_driver_handle_t handle, bool power);

#ifdef __cplusplus
}
#endif
