#include "main.h"

using namespace cv;

	void Tracker::trackBall(VideoCapture cap){

		Mat frame;
		
		//Resize large images to reduce processing load
		cap >> frame;
		
		//Convert RGB to HSV colormap
		//and apply Gaussain blur
		Mat hsvFrame;
		cvtColor(frame, hsvFrame, CV_RGB2HSV);
		blur(hsvFrame, hsvFrame, cv::Size(1, 1));

		//Threshold 
		Scalar lowerBound = cv::Scalar(55, 100, 50);
		Scalar upperBound = cv::Scalar(90, 255, 255);
		Mat threshFrame;
		inRange(hsvFrame, lowerBound, upperBound, threshFrame);

		//Erosion filter to reduce noise
		Mat element;
		erode(threshFrame, threshFrame, element);

		//Calculate X,Y centroid
		Moments m = moments(threshFrame, false);
		Point com(m.m10 / m.m00, m.m01 / m.m00);

		//Draw crosshair
		Scalar color = cv::Scalar(0, 0, 255);
		drawMarker(frame, com, color, cv::MARKER_CROSS, 50, 5);

		imshow("Tennis Ball", frame);
		imshow("Thresholded Tennis Ball", threshFrame);
	
	};


