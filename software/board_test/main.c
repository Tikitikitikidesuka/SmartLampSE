#pragma config CPD = OFF, BOREN = OFF, IESO = OFF, DEBUG = OFF, FOSC = HS
#pragma config FCMEN = OFF, MCLRE = ON, WDTE = OFF, CP = OFF, LVP = OFF
#pragma config PWRTE = ON, BOR4V = BOR21V, WRT = OFF

#pragma intrinsic(_delay)
#define _XTAL_FREQ 20000000 // necessary for __delay_us

#include <xc.h>
#include <stdio.h>

#include "pwm.h"

int max_pwm_duty_cycle_conf_value;

int main()
{
    INTCONbits.GIE = 1; // Enable interrupts
    
    init_pwm();
    set_pwm_duty_cycle(get_max_pwm_duty_cycle_conf_value());
    
    while(1);

    return (EXIT_SUCCESS);
}

// 1010011010

void __interrupt() interrupt_handler() {
    if (PIR1bits.TMR2IF) {
        pwm_tmr2_interrupt_handler();
    }
}
