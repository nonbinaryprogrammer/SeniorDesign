#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <list>
#include <queue>

using namespace std;

/************************************************************************************************
 * Program: Pathfinding within IR4 C-Space
 * Author: Helena Bales
 * Date: April 19th, 2017
 * Description: Finds a valid path using Dijstra's through the 4D binary array located in cspace. 
 * 	This is a draft of the implementation which will later be converted to run on the AVR 
 * 	board.
 * Input: ./cspace - Hephaestus C-Space data as defined in project docs
 * Output: ./cspace - Output file containing boolean data from 37x37x37x37 array
 ***********************************************************************************************/

int main() {
	//for file io
	char* myFile;
	ifstream sourceFile;
	ofstream outfile;
	string line;

	//for dijkstra's
	int accuracyFactor = 10;
	int MAX_ANGLE = 360;
	int x = MAX_ANGLE/accuracyFactor;
	int a, b, c, d, pos, temp[4];
	bool endOfFile = 0;
	int c0, c1, c2, c3, n0, n1, n2, n3;

	//for getting the targets
	char cline[24];
	char* tokens;
	int theta0, theta1, theta2, theta3;
	queue<int> targets0, targets1, targets2, targets3;

	unsigned char CSpace[37][37][37][37], tempchar;

	pos = 0;

	//open file
	myFile = "./cspace";
	sourceFile.open(myFile);
	
	//read the line from the file (it is one line long)
	getline(sourceFile, line);

	//loop through the array and line, copying the line to the array
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					tempchar = line.at(pos);
					CSpace[a][b][c][d] = tempchar;
					pos++;
				}
			}
		}
	}

	//close source file
	if(sourceFile.is_open()) {
		sourceFile.close();
	}

	//open the file of thetaTargets
	myFile = "./thetaTargets";
	sourceFile.open(myFile);

	//read in all the targets
	while(!endOfFile) {
		//get a line from the file
		sourceFile.getline(cline, 24);

		//tokenize on spaces
		tokens = strtok(cline, " ");

		//store the values as ints
		theta0 = stoi(tokens);
		tokens = strtok(NULL, " ");

		theta1 = stoi(tokens);
		tokens = strtok(NULL, " ");

		theta2 = stoi(tokens);
		tokens = strtok(NULL, " ");

		theta3 = stoi(tokens);
		tokens = strtok(NULL, " ");

		cout << "check" << endl;

		//push them onto the list of targets
		targets0.push(theta0);
		targets1.push(theta1);
		targets2.push(theta2);
		targets3.push(theta3);

		if(sourceFile.eof() || sourceFile.peek() == 10) {
			cout << "eof reached" << endl;
			endOfFile = 1;
		}
	}

	if(sourceFile.is_open()) {
		sourceFile.close();
		cout << "sourceFile closed" << endl;
	}

	//print targets for testing
	for(int i=0; i<targets0.size(); i++) {
		theta0 = targets0.front();
		theta1 = targets1.front();
		theta2 = targets2.front();
		theta3 = targets3.front();
		targets0.pop();
		targets1.pop();
		targets2.pop();
		targets3.pop();
		cout << theta0 << " " << theta1 << " " << theta2 << " " << theta3 << endl;
		targets0.push(theta0);
		targets1.push(theta1);
		targets2.push(theta2);
		targets3.push(theta3);
	}

	//dijkstra's algorithm through cspace from <0,0,0,0> through each of the targets 
	//in targets queue
	
	//set starting location
	c0 = 0;
	c1 = 0;
	c2 = 0;
	c3 = 0;

	//store the number of targets for later use
	a = targets0.size();

	//for each target do dijkstra's algorithm from c0-4 to n0-4 through CSpace[37][37][37][37]
	for(int i=0; i<a; i++) {
		//get the next target
		n0 = targets0.front();
		n1 = targets1.front();
		n2 = targets2.front();
		n3 = targets3.front();
		targets0.pop();
		targets1.pop();
		targets2.pop();
		targets3.pop();
	}
	
	//print the updated cspace to outfile
	//open outfile
	outfile.open("./path");

	//print the cspace
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					outfile << (int)CSpace[a][b][c][d] << " ";
				}
			}
		}
	}

	//close the file
	if(outfile.is_open()) {
		outfile.close();
	}

	return 0;
}
