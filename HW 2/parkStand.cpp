////////////////////////////////////////////////////////////////////////////////////////////////////////
// name: Grant Walter                                                                                 //
// date: Sep 19, 2018                                                                                 //
// file: parkStand.cpp                                                                                //
// description: Allows user to enter his desired spot for a stand on a 30x15 grid. The program        //
//				will then find a position for a second stand that makes the average total distance    //
//				between both stands, from all areas, the minimum amount. Values are printed at the    //
//				end of the program that show position and avgerage Minimum Distance.                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
using namespace std;

//Defines the position of the first stand
int getUserInput(string prompt, int min, int max) {
	int input = 0;
	do {
		cout << prompt;
		cin >> input;
	} while (input < min || input > max); //Continues to ask user for value in bounds
	return input;
}

//Distance formula to calulate distances
double calculateDistance(int x1, int y1, int x2, int y2 ) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 
}

//Saves the lowest (minimum) distance
double min(double first, double second) {
	if (first < second) {
		return first;
	} else {
		return second;
	}

}

//AvgClosestDistGivenTwoStandLocations type function
double avgDistance(int stand1X, int stand1Y, int stand2X, int stand2Y) {
	double totalDistance = 0;
	//Loops are for each possible square
	for (int checkX = 0; checkX < 30; checkX++) {
		for (int checkY = 0; checkY < 15; checkY++) {
			totalDistance += min(
				calculateDistance(checkX, checkY, stand2X, stand2Y), 
				calculateDistance(checkX, checkY, stand1X, stand1Y)
			);
		}
	}
	return totalDistance / (30*15); //Divides by total number of possible location for an average
}

int main() {
	//Positions for defined stand
	int stand1X = getUserInput(string("What is the X (0, 29): "), 0, 29);
	int stand1Y = getUserInput(string("What is the Y (0, 14): "), 0, 14);
	
	//Variables to save the second stand location for lowest average distance that is observed
	int stand2XLocation = 0;
	int stand2YLocation = 0;
	
	//Value for minimum distance
	double minimumAvgDist = 1000;
	
	//Loops are for each posible location for the second stand
	for (int stand2X = 0; stand2X < 30; stand2X++) { 
		for (int stand2Y = 0; stand2Y < 15; stand2Y++) {
			double dist = avgDistance(stand1X, stand1Y, stand2X, stand2Y);
			if (dist < minimumAvgDist) { //Saves "metadata" for a position if it is a min. avg. dis.
				minimumAvgDist = dist;
				stand2XLocation = stand2X;
				stand2YLocation = stand2Y;
			}
		}
	}
	
	//Outputs
	cout << "Put the PizzaHut here:" <<endl;
	cout << "x: " << stand2XLocation <<endl;
	cout << "y: " << stand2YLocation <<endl;
	cout << "Average distance to PizzaTime: " << minimumAvgDist <<endl;
	return 0;
}