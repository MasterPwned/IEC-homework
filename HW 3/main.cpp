// Name: Grant Walter
// Date: Oct 3, 2018
// File Name: main.cpp
/* Description: Program will take data from a given input file and use those specifications to
                calculate the values of temperatures across a certain metal plate. The program
                will create a output file to go with it. This file contains information on
                time passed and temperature at the specified points.
*/

#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

//given equation
double calculateTemp(double y, double x, double alpha, double To, double Tm, double PI, double e, double H, double L, double t) {
    return To + (Tm * sin(PI*x/L) * sin(PI*y/H) * pow(e, (-2.0*PI*PI*alpha*t)/(L*L)));
}

int main() {
    ifstream inputDat("input.dat");
    ofstream outputDat("output.dat");

    if ( inputDat.fail() ) {
        cerr << "File could not be read." <<endl;
        return -1;
    }

    if ( outputDat.fail() ) {
        cerr << "File could not be writen." <<endl;
        return -1;
    }

    string read;
    double PI = acos(-1.0);
    double e = 2.7182818284590452353602875;
    double t = 0;
    double H; //height of plate
    double L; //length of plate
    double alpha; //alpha constant aka thermal diffusivity
    double To;
    double Tm;
    double dt; //change in time aka time increment
    double xSensor; //how many "sensors" along the x-axis
    double ySensor; //same as above but for the y-axis
    double k; //useless, evil value used to trick students

    //this takes the data from the input file and places it in the variables from above
    inputDat >> read >> H;
    inputDat >> read >> L;
    inputDat >> read >> alpha;
    inputDat >> read >> To;
    inputDat >> read >> Tm;
    inputDat >> read >> dt;
    inputDat >> read >> xSensor;
    inputDat >> read >> ySensor;
    inputDat >> read >> k;

    double maxTemp = Tm;
    double minTemp = To;

    //while loop stops when temperature difference between min and max is less than 0.1
    while (maxTemp - minTemp >= 0.1) {
        //heading for each jump in time in output file
        outputDat << "VARIABLES= 'X' 'Y' 'T'" << endl;
        outputDat << "ZONE I = " << xSensor << " J = " << ySensor << " SOLUTIONTIME = " << t << " F=POINT" <<endl;

        //resents the max and min temp after each loop since the plate will cool over time (max will decrease)
        maxTemp = calculateTemp(H/ySensor, L/xSensor , alpha, To, Tm, PI, e, H, L, t);
        minTemp = To;

        //for loops calculate the temperature data for each point on the specified x-y grid from the input file
        for (int x = 0; x < xSensor; x++) {
            for (int y = 0; y < ySensor; y++) {
                //calculates temp
                double temp = calculateTemp(y / (ySensor - 1), x / (xSensor - 1), alpha, To, Tm, PI, e, H, L, t);
                //actually prints the x, y, temp values in the output file
                outputDat << x / (xSensor - 1) << " " << y / (ySensor - 1) << " " << temp << endl;

                //changes max and min temp depending on changes in temp across the plate
                if (temp > maxTemp) {
                    maxTemp = temp;
                }
                if (temp < minTemp) {
                    minTemp = temp;
                }
            }
        }
        t += dt; //adds time increment
    }

    cout << "Time to cool: " << t - dt <<endl; //quickly prints time to cool for user

    //close all files
    inputDat.close();
    outputDat.close();

	return 0;
}