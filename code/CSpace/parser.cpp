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
 * Program: C-Space Data Parser
 * Author: Helena Bales
 * Date: April 12th, 2017
 * Description: A C++ implementation of a parser for the Hephaestus Configuration Space data. The 
 * 	parser creates a 4-D array of boolean values with a 0 representing a valid configuration 
 * 	and a 1 representing an invalid configuration.
 * Input: ./test1/data1 - Hephaestus C-Space data as defined in project docs
 * Output: ./cspace.out - Output file containing boolean data from 37x37x37x37 array
 ***********************************************************************************************/

int main() {
	char* myFile;
	ifstream sourceFile;
	ofstream outfile;
	string line;

	int accuracyFactor = 10;
	int MAX_ANGLE = 360;
	int x = MAX_ANGLE/accuracyFactor;
	int a, b, c, d;
	float af, bf, cf, df;
	bool endOfFile = 0;
	int x1, x2, x3, x4;

	//define cspace size
	x1 = 1;
	x2 = 37;
	x3 = 37;
	x4 = 37;

	unsigned char CSpace[1][37][37][37];

	//init C-Space with 255's to mark as invalid
	for(a=0; a<x1; a++) {
		for(b=0; b<x2; b++) {
			for(c=0; c<x3; c++) {
				for(d=0; d<x4; d++) {
					CSpace[a][b][c][d] = 255;
				}
			}
		}
	}

	//open file
	myFile = "./test1/data1";
	sourceFile.open(myFile);
	
	//loop for length of file
	while(!endOfFile) {
		//read 5 lines from the file
		
		//line 1 == a
		getline(sourceFile, line);
		af = stof(line, NULL);
		//cout << "af = " << af << endl; //FOR TESTING

		//line 2 == b
		getline(sourceFile, line);
		bf = stof(line, NULL);
		//cout << "bf = " << bf << endl; //FOR TESTING

		//line 3 == c
		getline(sourceFile, line);
		cf = stof(line, NULL);
		//cout << "cf = " << cf << endl; //FOR TESTING

		//line 4 == d
		getline(sourceFile, line);
		df = stof(line, NULL);
		//cout << "df = " << df << endl; //FOR TESTING

		//line 5 == ; divider between coordinates
		getline(sourceFile, line);
		//cout << ";" << endl;

		//convert negative degrees to corresponding positive angle
		if(af < 0) {
			af = 360 + af;
		}

		if(bf < 0) {
			bf = 360 + bf;
		}

		if(cf < 0) {
			cf = 360 + cf;
		}

		if(df < 0) {
			df = 360 + df;
		}

		//convert to ints
		a = floor(af/10);
		b = floor(bf/10);
		c = floor(cf/10);
		d = floor(df/10);

		//check floored values against original FOR TESTING
		cout << a << "/" << af << " - " << b << "/" << bf << " - " << c << "/" << cf << " - " << d << "/" << df << endl;

		//mark array[a][b][c][d] = 0
		CSpace[a][b][c][d] = 0;

		//check if eof has been reached
		if(sourceFile.eof()) {
			cout << "Reached eof - check 3" << endl;
			endOfFile = 1;
		}

		//check if eof has been reached
		if(sourceFile.peek() == 10) {
			cout << "Reached eof - check 2" << endl;
			endOfFile = 1;
		}
	}

	//close source file
	if(sourceFile.is_open()) {
		sourceFile.close();
	}

	/*
	//print array
	for(a=0; a<1; a++) {
		for(b=0; b<37; b++) {
			for(c=0; c<37; c++) {
				for(d=0; d<37; d++) {
					cout << CSpace[a][b][c][d];
				}
				cout << endl;
			}
			cout << endl;
			cout << endl;
		}
	}
	*/

	//store array in file
	outfile.open("cspace");
	for(a=0; a<x1; a++) {
		for(b=0; b<x2; b++) {
			for(c=0; c<x3; c++) {
				for(d=0; d<x4; d++) {
					outfile << (int)CSpace[a][b][c][d];
				}
			}
		}
	}

	/*
	//store 0 locations in file for plotting
	outfile.open("cspacePlotData");
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					if(CSpace[a][b][c][d] == 0){
						outfile << b << " " << c << " " << d 
							<< endl;

					}
				}
			}
		}
		outfile << "\n";
	}
	*/
	
}
