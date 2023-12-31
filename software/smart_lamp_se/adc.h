#ifndef ADC_H
#define ADC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    
#define ADC_VREF 5
#define ADC_RESOLUTION 1023

typedef enum ADCPin { ADC0 = 8, ADC1 = 10, ADC2 = 12 } ADCPin;

/**
 * ADC init function.
 * @brief Initializes the ADC module.
 * @warning Must be called before any other ADC function.
 */
void ADC_init(void);

/**
 * Read ADC pin 
 * @brief Reads the ADC pin analog signal.
 * @return Digital value of the analog signal in ADC pin.
 * @warning This function assumes that the acquisition time has already been waited for.
 */
uint16_t ADC_read(ADCPin pin);

#ifdef __cplusplus
}
#endif

#endif  // ADC_H
