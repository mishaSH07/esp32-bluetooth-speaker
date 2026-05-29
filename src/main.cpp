// Bluetooth A2DP audio sink for ESP32 — receives audio over Bluetooth
// and outputs it through the built-in DAC via I2S.
#include <BluetoothA2DPSink.h>
#include <Arduino.h>

extern "C" {
#include "esp_log.h"   // debugging and info messages
}

BluetoothA2DPSink a2dp_sink;   // A2DP sink object (receives audio over Bluetooth)

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

TaskHandle_t hled;                                  // handle for the LED task
static void vLEDTask(void* pvParameters);           // forward declaration

// Create the LED blink task, pinned to core 0
void initial() {
    ESP_LOGI("INIT", "Create Task");
    xTaskCreatePinnedToCore(
        vLEDTask, "LEDTask",   // task function and name
        1024,                  // stack size
        NULL, 2,               // priority (0 = lowest)
        &hled,                 // task handle
        0                      // core to run on
    );
}

void setup() {
    Serial.begin(115200);
    ESP_LOGI("SETUP", "initializing...");
    initial();                 // start LED blinking task

    static const i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
        .sample_rate = 44100,                          // standard audio sample rate
        .bits_per_sample = (i2s_bits_per_sample_t)16,  // 16-bit audio
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,  // stereo
        .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = false
    };
    a2dp_sink.set_i2s_config(i2s_config);
    a2dp_sink.start("Misha Luke Ricky");   // Bluetooth device name
}

void loop() {
    ESP_LOGI("MAIN", "running on core: %d", xPortGetCoreID());
    while (1) {
        if (a2dp_sink.is_connected()) {
            ESP_LOGI("BLUETOOTH", "connected");
        } else {
            ESP_LOGI("BLUETOOTH", "not connected");
        }
        vTaskDelay(100);   // non-blocking 100ms delay
    }
}

// LED blink task
static void vLEDTask(void* pvParameters) {
    (void)pvParameters;
    ESP_LOGI("LED_TASK", "running led task on core: %d", xPortGetCoreID());
    pinMode(LED_BUILTIN, OUTPUT);
    for (;;) {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(200);
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(200);
    }
}
