#pragma once

//STD LIB
#include <iostream>
#include <windows.h>

//OpenCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>

class Tracker{
	public:
		void trackBall(cv::VideoCapture cap);

		void activateTracker(cv::Mat threshFrame, cv::VideoCapture cap);
};

class PID {
	public:
		 
		float Kp, Kd, Ki, controlSignal;

		PID();

		std::vector<float> calculateError(int com, cv::Point motorPosition, std::vector<float> error);

		float controlSignal(std::vector<float> error);

};