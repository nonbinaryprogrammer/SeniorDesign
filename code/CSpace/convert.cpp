#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <time.h>
#include <unistd.h>
#include <math.h>

using namespace std;

/************************************************************************************************
 * Program: Target point converter
 * Author: Helena Bales (Inverse Kinematics by Brett Moffatt)
 * Date: May 17th, 2017
 * Description: For the RockSat-X Hephaestus payload. Converts our target points from cartesian 
 * 	form into a representation within the configuration space. This is accomplished through 
 * 	Inverse Kinematics with theta0 isolated to four discrete values, allowing us to resolve 
 * 	the results of IK from a 4D area in the configuration space to four possible solutions,
 * 	of which at least one must be marked as 0 in the cspace.
 * Input: ./targets - A text document containing one target (in the form: x y z) per line, in 
 * 		cartesian form
 * Output: ./thetaTargets - A text document containing one target per line (in the form: 
 * 	theta0 theta1 theta2 theta3), where theta0-3 refers to the rotational angle from the 
 * 	defined normal
 ***********************************************************************************************/

/************************************
 * theta1 = roll = {0, 90, 180, 270}
 * theta2 = yaw = tan-1(yo/xo)
 * theta3 = pitch1
 * theta4 = pitch2
 ***********************************/

int main() {
	char* myFile;
	ifstream sourceFile;
	ofstream outfile;
	char line[24];
	char* tokens;

	int xo, yo, zo;	//real target point
	int theta0, theta1, theta2, theta3; //cspace target point
	double l1, l2; //arm segment lengths
	double k1, k2, gamma; //variables for calculating pitch
	double t, b, fraction1, pt1, pt2; //some more variables for calculations
	bool endOfFile = 0; //marker for eof

	//define arm lengths
	l1 = 3.99;
	l2 = 4.49;

	//open the file of targets
	myFile = "./targets";
	sourceFile.open(myFile);

	//open the file for theta targets
	myFile = "./thetaTargets";
	outfile.open(myFile);


	while(!endOfFile) {
		//read a line
		sourceFile.getline(line, 24);

		//break the line on spaces
		tokens = strtok(line, " ");

		//store the values as integers
		xo = stoi(tokens);
		tokens = strtok(NULL, " ");

		yo = stoi(tokens);
		tokens = strtok(NULL, " ");

		zo = stoi(tokens);
		tokens = strtok(NULL, " ");

		//check if it is eof
		if(sourceFile.eof() || sourceFile.peek() == 10) {
			endOfFile = 1;
			cout << "end of file reached" << endl;
		}

		//calculate variables
		t = (xo*xo) + (yo*yo) - (l1*l1) - (l2*l2);
		b = 2 * l1 * l2;
		fraction1 = t/b;
		pt1 = sqrt(1 - (fraction1 * fraction1));
		pt2 = fraction1;

		//calcualte theta2
		theta2 = atan2(zo, sqrt((yo*yo) + (xo*xo)));

		//calculate k1, k2, and gamma
		k1 = l1 + (l2 * cos(theta2));
		k2 = l2 * sin(theta2);
		gamma = atan2(k1, k2);

		//calculate theta0, theta1, theta3
		theta1 = atan(yo/xo);
		theta3 = atan2(yo, xo) - gamma;
		theta0 = 0; //TODO move this motor to change the plane

		//print the thetas to the file
		outfile << theta0 << " " << theta1 << " " << theta2 << " " << theta3 << " " << endl;

	}

	//close the file
	if(sourceFile.is_open()) {
		sourceFile.close();
	}

	//close the file
	if(outfile.is_open()) {
		outfile.close();
	}


	return 0;
}
