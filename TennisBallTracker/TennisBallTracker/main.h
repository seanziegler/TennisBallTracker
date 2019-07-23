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

};