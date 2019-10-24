#pragma once

//OpenCV
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>

class Tracker {
public:
	Mat trackBall(cv::VideoCapture cap);

	void activateTracker(cv::Mat threshFrame, cv::VideoCapture cap);
};