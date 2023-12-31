#include "APA102.h"

#include "spi.h"

uint8_t num_leds;

void send_start_frame(void) {
    SPI_write_read(0x00);
    SPI_write_read(0x00);
    SPI_write_read(0x00);
    SPI_write_read(0x00);
}

void send_end_frame(void) {
    SPI_write_read(0xFF);
    SPI_write_read(0xFF);
    SPI_write_read(0xFF);
    SPI_write_read(0xFF);
}

void send_color_frame(uint8_t power, uint8_t r, uint8_t g, uint8_t b) {
    SPI_write_read(0b11100000 | power);
    SPI_write_read(b);
    SPI_write_read(g);
    SPI_write_read(r);
}

void APA102_init(uint8_t config_num_leds) {
    num_leds = config_num_leds;

    send_end_frame();
}

void APA102_set_color(uint8_t power, uint8_t r, uint8_t g, uint8_t b) {
    send_start_frame();

    for (uint8_t i = 0; i < num_leds; ++i) {
        send_color_frame(power, r, g, b);
    }

    send_end_frame();
}