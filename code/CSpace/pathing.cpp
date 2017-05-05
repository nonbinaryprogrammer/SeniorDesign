#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <unistd.h>
#include <math.h>

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
	char* myFile;
	ifstream sourceFile;
	ofstream outfile;
	string line;

	int accuracyFactor = 10;
	int MAX_ANGLE = 360;
	int x = MAX_ANGLE/accuracyFactor;
	int a, b, c, d, pos;
	float af, bf, cf, df;
	bool endOfFile = 0, boolChar;

	int CSpace[37][37][37][37];

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
					boolChar = line.at(pos);
					CSpace[a][b][c][d] = boolChar;
					pos++;
				}
			}
		}
	}

	//close source file
	if(sourceFile.is_open()) {
		sourceFile.close();
	}

}
