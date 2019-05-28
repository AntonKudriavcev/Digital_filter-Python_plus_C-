%module filter_controller

%{
#include "filter_controller.c"	
%}

%include filter_controller.c

extern float a_coef_1_1[3];
extern float a_coef_1_2[3];
extern float a_coef_1_3[3]; 

extern float a_coef_2_1[3];
extern float a_coef_2_2[3]; 
extern float a_coef_2_3[3];

extern float a_coef_3_1[3];
extern float a_coef_3_2[3]; 
extern float a_coef_3_3[3]; 

extern float b_coef_1_1[3];
extern float b_coef_1_2[3];
extern float b_coef_1_3[3]; 

extern float b_coef_2_1[3];
extern float b_coef_2_2[3]; 
extern float b_coef_2_3[3];

extern float b_coef_3_1[3];
extern float b_coef_3_2[3]; 
extern float b_coef_3_3[3]; 

extern float Z[3][3][3];

extern float filter(int stage_n, int sec_n, int n_coef, float a_coef[3], float b_coef[3], float input_data);
extern float filter_controller(float input_data);


