#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <windows.h>

int lowH, lowS, lowV = 90;
int highH = 180;
int highS = 255, highV = 255;

void lowHChange(int pos, void*) {
	int lowH = pos;
}

void lowSChange(int pos, void*) {
	int lowS = pos;
}

void lowVChange(int pos, void*) {
	int lowV = pos;
}

void highHChange(int pos, void*) {
	int highH = pos;
}

void highSChange(int pos, void*) {
	int highS = pos;
}

void highVChange(int pos, void*) {
	int highV = pos;
}


int main(){

	// Capture video from default video device
	cv::VideoCapture cap(0);

	// Check if video capture opened successfull 
	if (cap.isOpened()) {
		std::cout << "Webcam feed aquired.";
	}
	else {
		std::cout << "No webcam feed found.";
	}

	cv::Mat frame;
	cv::namedWindow("HSV Value Selection");
	
	const cv::String HSVwindowName = "HSV Value Selection";
	

	cv::createTrackbar("Low H", HSVwindowName, 0, 180, lowHChange);
	cv::createTrackbar("Low S", HSVwindowName, 0, 255, lowSChange);
	cv::createTrackbar("Low V", HSVwindowName, 0, 255, lowVChange);
	cv::createTrackbar("High H", HSVwindowName, &highH, 180, highHChange);
	cv::createTrackbar("High S", HSVwindowName, &highS, 255, highSChange);
	cv::createTrackbar("High V", HSVwindowName, &highV, 255, highVChange);

	while (true) {
		
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
		cv::inRange(hsvFrame, lowerBound, upperBound,  threshFrame);

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

		int key = cv::waitKey(2);
		if (key == 27) break;
	}
	std::cout << "Program terminated by user." << std::endl;
	
}
