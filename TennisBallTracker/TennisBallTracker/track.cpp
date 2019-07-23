#include "main.h"

using namespace cv;

class Tracker {
	
public:

	void trackBall(VideoCapture cap){

		cv::Mat frame;
		
		//Resize large images to reduce processing load
		cap >> frame;
		
		//Convert RGB to HSV colormap
		//and apply Gaussain blur
		cv::Mat hsvFrame;
		cv::cvtColor(frame, hsvFrame, CV_RGB2HSV);
		cv::blur(hsvFrame, hsvFrame, cv::Size(1, 1));

		//Threshold 
		cv::Scalar lowerBound = cv::Scalar(55, 100, 50);
		cv::Scalar upperBound = cv::Scalar(90, 255, 255);
		cv::Mat threshFrame;
		cv::inRange(hsvFrame, lowerBound, upperBound, threshFrame);

		//Erosion filter to reduce noise
		cv::Mat element;
		cv::erode(threshFrame, threshFrame, element);

		//Calculate X,Y centroid
		cv::Moments m = moments(threshFrame, false);
		cv::Point com(m.m10 / m.m00, m.m01 / m.m00);

		//Draw crosshair
		cv::Scalar color = cv::Scalar(0, 0, 255);
		cv::drawMarker(frame, com, color, cv::MARKER_CROSS, 50, 5);

		cv::imshow("Tennis Ball", frame);
		cv::imshow("Thresholded Tennis Ball", threshFrame);


			
	};


};