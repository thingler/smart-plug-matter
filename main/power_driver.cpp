#include <esp_log.h>
#include <driver/gpio.h>
#include <power_driver.h>

static const char *TAG = "power_driver";
static gpio_num_t gpio_pin;

power_driver_handle_t power_driver_init(power_driver_config_t *config)
{
    gpio_pin = (gpio_num_t)config->gpio;

    ESP_LOGI(TAG, "Initializing GPIO driver");
    esp_err_t err = ESP_OK;

    ESP_LOGI(TAG, "Initializing GPIO pin > %d", gpio_pin);
    err = gpio_reset_pin(gpio_pin);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "GPIO reset pin failed");
        return NULL;
    }

    err = gpio_set_direction(gpio_pin, GPIO_MODE_OUTPUT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "GPIO set direction failed");
        return NULL;
    }
    gpio_set_level(gpio_pin, false);

    return (power_driver_handle_t)config->gpio;
}

esp_err_t driver_set_power(power_driver_handle_t handle, bool power)
{
    esp_err_t err = ESP_OK;
    gpio_set_level(gpio_pin, power);
    ESP_LOGI(TAG, "GPIO pin state -> %d", power);
    return err;
}
