
#include "spi.h"

#include <xc.h>

#define _XTAL_FREQ 20000000  // necessary for __delay_us

void SPI_init() {
    PORTB = 0;
    TRISB  = 0;
}

uint8_t SPI_write_read(uint8_t byte) {
    uint8_t answer = 0;

    for (uint8_t x = 8; x > 0; x--) {
        spi_dat_out = (__bit)((byte >> (x - 1)) & 0b00000001);
        //__delay_us(5);
        spi_clk = 1;
        //__delay_us(10);
        answer |= (char)spi_dat_in;
        spi_clk = 0;
        //__delay_us(10);
        if (x > 1)
            answer = (uint8_t)(answer << 1);
    }

    return answer;
}