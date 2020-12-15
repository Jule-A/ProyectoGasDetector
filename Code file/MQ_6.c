#include "config_intosc.h"          /* Header File for Configuration bits */
#include "LCD_8bit_file.h"
#include "MQ_6_file.h"
#include "ADC_file.h"          /* Header File for ADC Functions */
#include <math.h>
/*
 * Sensor Related Functions
 */
float SensorCalibration() {
    int count; // This function assumes that sensor is in clean air.
    float val = 0;
    for (count = 0; count < 50; count++) { //take multiple samples and calculate the average value   
        val += calculate_resistance(ADC_Read(0));
        __delay_ms(100);
    }
    val = val / 50;
    val = val / RO_VALUE_CLEAN_AIR; //divided by RO_CLEAN_AIR_FACTOR yields the Ro 
    //according to the chart in the datasheet 
    return val;
}

float read_mq() {
    int count;
    float rs = 0;
    for (count = 0; count < 5; count++) { // take multiple readings and average it.
        rs += calculate_resistance(ADC_Read(0)); // rs changes according to gas concentration.
        __delay_ms(50);
    }
    rs = rs / 5;
    return rs;
}

float calculate_resistance(int adc_channel) { // sensor and load resistor forms a voltage divider. so using analog value and load value 
    return ( ((float) RL_VALUE * (1023 - adc_channel) / adc_channel)); // we will find sensor resistor.
}

int gas_plot_log_scale(float rs_ro_ratio, float *curve) {
    return pow(10, (((log(rs_ro_ratio) - curve[1]) / curve[2]) + curve[0]));
}
