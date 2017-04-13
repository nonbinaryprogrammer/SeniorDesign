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
	int MAX_ANGLE = 365;
	int x = MAX_ANGLE/accuracyFactor;
	int a, b, c, d;
	float af, bf, cf, df;
	bool endOfFile = 0;

	int CSpace[37][37][37][37];

	//init C-Space with 1's
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					CSpace[a][b][c][d] = 1;
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
		cout << ";" << endl;
		
		//convert to ints
		a = floor(af);
		b = floor(bf);
		c = floor(cf);
		d = floor(df);

		//check floored values against original FOR TESTING
		//cout << a << "/" << af << " - " << b << "/" << bf << " - " << c << "/" << cf << " - " << d << "/" << df << endl;

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

	//store array in file
	outfile.open("cspace.out");
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					outfile << CSpace[a][b][c][d];
				}
			}
		}
	}
	

}