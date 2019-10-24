#pragma once

//STD LIB
#include <iostream>
#include <windows.h>
#include <vector>

#include "openCV.h"




class PID {
	public:
		 
		float Kp, Kd, Ki, controlSignal;

		PID();

		std::vector<float> calculateError(int com, cv::Point motorPosition, std::vector<float> error);

		float calculateControlSignal(std::vector<float> error);

};