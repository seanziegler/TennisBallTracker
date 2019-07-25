#include "main.h"


using namespace cv;
using namespace std;

PID::PID() {

	std::vector<float> error; 
	Kp, Kd, Ki, controlSignal = 0;
	controlSignal = 0;
	
}

std::vector<float> PID::calculateError(int com, Point motorPosition, std::vector <float> error ) {

	float current_error = com - motorPosition.x;

	error.push_back(current_error);
	error.erase(error.begin());
	
	return error
};

float PID::controlSignal(vector<float> error) {



};