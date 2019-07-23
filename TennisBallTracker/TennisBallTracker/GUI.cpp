#include "main.h"

using namespace cv;

class GUI {

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
		
	/*cv::namedWindow("HSV Value Selection");

	const String HSVwindowName = "HSV Value Selection";


	createTrackbar("Low H", HSVwindowName, 0, 180, lowHChange);
	createTrackbar("Low S", HSVwindowName, 0, 255, lowSChange);
	createTrackbar("Low V", HSVwindowName, 0, 255, lowVChange);
	createTrackbar("High H", HSVwindowName, &highH, 180, highHChange);
	createTrackbar("High S", HSVwindowName, &highS, 255, highSChange);
	createTrackbar("High V", HSVwindowName, &highV, 255, highVChange);
*/



};