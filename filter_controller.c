// ----------------------------------------------------------
// -------------coefficient for first stage------------------
// ----------------------------------------------------------
	// section #1
	float a_coef_1_1[3] = {0.525828543039357776, -1.99315287833078858, 0.997244104076249416};
	float b_coef_1_1[3] = {1, -1.99631885323521785, 1};
	// section #2
	float a_coef_1_2[3] = {0.98514378788174306, -1.9665278007775604, 0.971680540810641924};
	float b_coef_1_2[3] = {1, -1.99759749798163111, 1};
	// section #3
	float a_coef_1_3[3] = {1.7899432111289777, -0.885200010264396653, 0};
	float b_coef_1_3[3] = {1, -1, 0};
// ----------------------------------------------------------
// -------------coefficient for second stage-----------------
// ----------------------------------------------------------
	// section #1
	float a_coef_2_1[3] = {0.780545597983568928, -1.98454172327042144, 0.998468983060898374};
	float b_coef_2_1[3] = {1, -1.98640637335991888, 1};
	// section #2
	float a_coef_2_2[3] = {0.780545597983568928, -1.98653531191395594, 0.998576070222813805};
	float b_coef_2_2[3] = {1, -1.98764535316191138, 1};
	// section #3
	float a_coef_2_3[3] = {1.62751709363638364, -1.97321776696518358, 0.986087001680641895};
	float b_coef_2_3[3] = {1, -1.98704061332200621, 1};
// ----------------------------------------------------------
// -------------coefficient for third stage------------------
// ----------------------------------------------------------
	// section #1
	float a_coef_3_1[3] = {0.780545597983568817, -1.94490255673515455, 0.998496105813971191};
	float b_coef_3_1[3] = {1, -1.94703027431694564, 1};
	// section #2
	float a_coef_3_2[3] = {0.780545597983568817, -1.94870398482269636, 0.998548945297613622};
	float b_coef_3_2[3] = {1, -1.94949292626011861, 1};
	// section #3
	float a_coef_3_3[3] = {1.6275170936363812, -1.93472288180304686, 0.986087001680639008};
	float b_coef_3_3[3] = {1, -1.94827606259531683, 1};


// general list of time delay
	float Z[3][3][3] = {//delay line for first stage
						{{0.0,0.0,0.0}, // z_1_1 
						{0.0,0.0,0.0},  // z_1_2
						{0.0,0.0,0.0}}, // z_1_3

						// delay line for second stage
						{{0.0,0.0,0.0}, // z_2_1 
						{0.0,0.0,0.0},  // z_2_2
						{0.0,0.0,0.0}}, // z_2_3

						// delay line for third stage
						{{0.0,0.0,0.0}, // z_3_1
						{0.0,0.0,0.0},  // z_3_2
						{0.0,0.0,0.0}}};// z_3_3


float filter(int stage_n, int sec_n, int n_coef, float a_coef[3], float b_coef[3], float input_data){
	float Y = 0.0;
	int i;
	// shift values of delay line
	for (i = n_coef; i < 0; i--){
		Z[stage_n - 1][sec_n - 1][i] = Z[stage_n - 1][sec_n - 1][i - 1];
	}
	// add new values of data to array
	Z[stage_n - 1][sec_n - 1][0] = input_data * a_coef[0];

	for (i = 1; i < n_coef; i++){
		Z[stage_n - 1][sec_n - 1][0] = Z[stage_n - 1][sec_n - 1][0] + Z[stage_n - 1][sec_n - 1][i] * a_coef[i];
	}

	for (i = 0; i <= n_coef; i++){
		Y = Y + Z[stage_n - 1][sec_n - 1][i] * b_coef[i];
	}
	return Y;
}


float filter_controller(float input_data){

	float X = filter(1, 1, 2, a_coef_1_1, b_coef_1_1, input_data);
	X = filter(1, 2, 2, a_coef_1_2, b_coef_1_2, X);
	X = filter(1, 3, 1, a_coef_1_3, b_coef_1_3, X);

	X = filter(2, 1, 2, a_coef_2_1, b_coef_2_1, X);
	X = filter(2, 2, 2, a_coef_2_2, b_coef_2_2, X);
	X = filter(2, 3, 2, a_coef_2_3, b_coef_2_3, X);

	X = filter(3, 1, 2, a_coef_3_1, b_coef_3_1, X);
	X = filter(3, 2, 2, a_coef_3_2, b_coef_3_2, X);
	X = filter(3, 3, 2, a_coef_3_3, b_coef_3_3, X);

	return X;
}

