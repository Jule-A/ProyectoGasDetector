
#include "config_intosc.h"          /* Header File for Configuration bits */
#include "LCD_8bit_file.h"          /* Header File for LCD Functions */
#include "ADC_file.h"          /* Header File for ADC Functions */
#include "MQ_6_file.h"

#define vref 5.00               /*Reference Voltage is 5V*/

void main() {
    char data[10];
    int digital;
    OSCCON = 0x72; /*Set internal Oscillator frequency to 8 MHz*/
    LCD_Init(); /*Initialize 16x2 LCD*/
    ADC_Init(); /*Initialize 10-bit ADC*/
    mq_6_pin = 1; //Configure RD5 as input
    mq_6_propano = 0;
    LCD_Clear();
    LCD_String_xy(1, 1, "Calibrando");
    //Ro = SensorCalibration();
    LCD_Clear();
    LCD_String_xy(1, 1, "Listo!");
    __delay_ms(500);
    LCD_Clear();
    sprintf(data,"%.2f",Ro);
    LCD_String_xy(1, 1, data);
    LCD_String_xy(1, 6, "K Ohms");
    __delay_ms(1500);
    LCD_Clear();
    while (1) {
        if (mq_6_propano == 1) {
            LCD_String_xy(1, 1, "Gas Propano");
            LCD_String_xy(2, 1, "Detectado");
            __delay_ms(1500);
            LCD_Clear();
            LCD_String_xy(1, 1, "Gas ppm =");
            float rs = read_mq();
            float ratio = rs / Ro;
            sprintf(data,"%.d",gas_plot_log_scale(ratio, MQ6_curve));
            LCD_String_xy(2, 1, data);
            __delay_ms(1500);
            LCD_Clear();
        } else {
            LCD_String_xy(1, 1, "Gas No");
            LCD_String_xy(2, 1, "Detectado");
        }
    }
}
