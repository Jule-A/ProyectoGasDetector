/* 
 * File:   MQ_6_file.h
 * Author: julia
 *
 * Created on 15 de diciembre de 2020, 01:23 AM
 */

#ifndef MQ_6_FILE_H
#define	MQ_6_FILE_H

#define mq_6_propano PORTDbits.RD5

#define mq_6_pin TRISDbits.TRISD5
#define RL_VALUE (10)     //define the load resistance on the board, in kilo ohms
#define RO_VALUE_CLEAN_AIR (9.83)  //(Sensor resistance in clean air)/RO,
//which is derived from the chart in datasheet
float MQ6_curve[3] = {2.3, 0.30, -0.41}; //two points from LPG curve are taken point1:(200,1.6) point2(10000,0.26)
//take log of each point (lg200, lg 1.6)=(2.3,0.20)  (lg10000,lg0.26)=(4,-0.58)
//find the slope using these points. take point1 as reference   
//data format:{ x, y, slope}; 
float Ro = 10; //Ro is initialized to 10 kilo ohms
#define _XTAL_FREQ 8000000 //20 Mhz
// System related definitions
void system_init(void);
void introduction_screen(void);
//int   GetPercentage(float rs_ro_ratio, float *pcurve);
int gas_plot_log_scale(float rs_ro_ratio, float *curve);
float read_mq();
float calculate_resistance(int raw_adc);
float SensorCalibration();

#endif	/* MQ_6_FILE_H */

