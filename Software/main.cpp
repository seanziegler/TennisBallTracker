#include "main.h"
#include "track.h"

using namespace cv;

int main(){

	bool webcam = false;

	// Capture video from default video device
	cv::VideoCapture cap(0);

	// Check if video capture opened successful
	if (cap.isOpened()) {
		std::cout << "Webcam feed aquired.";
		webcam = true;
	}
	else {
		std::cout << "No webcam feed found.";
	}

	while (webcam){
		Tracker tracker;

		tracker.activateTracker(cap);

		int key = cv::waitKey(2);
		if (key == 27) {
			break;
			std::cout << "Program terminated by user." << std::endl;
		};
	};
}
