///////////////////////////////////////////////////////////////////////
// File Name:      a1.cpp
//
// Author:         Yang Chen
// CS email:       ychen@cs.wisc.edu
//
// Course:         CS 368 (C++)
// Section:        2
// Instructor:     Kuemmel
//
// Description:	   read 2 input files consisting of an unknown number of
//				   student names and output the following:
//	1. A sorted list of students who are present
//	in both the files (i.e. intersection of the 2 sets of students)
//	2. A sorted list of students who are present
//	in at least one of the 2 files (i.e. union of the 2 sets of students).

//
// Sources:
//
// URL(s) of sources:
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @Read each line of a ifstream object and put them in an vector
 *
 * @param inFile The file to read data from.
 * @param nameList The vector to store the students' names, one per line.
 *
 */
void readfiles(ifstream &inFile, vector<string> &nameList) {
	string sName;
	while (getline(inFile, sName)) {
	// add a student to the list of students.
		nameList.push_back(sName);
   	}
}

/**
 * @Take two vectors of string and make the intersection of them
 *
 * @param v1 The first vector
 * @param v2 The second vector
 * @param v3 The intersection of v1 and v2
 *
 */
void intersect(vector<string> &v1, vector<string> &v2, vector<string> &v3) {
	// sort two input vectors
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
}

/**
 * @Take two vectors of string and make the union of them
 *
 * @param v1 The first vector
 * @param v2 The second vector
 * @param v3 The union of v1 and v2
 *
 */
void Makeunion(vector<string> &v1, vector<string> &v2, vector<string> &v3) {
	// sort two input vectors
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
}

/**
 * @Write the data of a vector into a output file
 *
 * @param outputName The name of the output file
 * @param nameList The vector which stores the students' names
 *
 */
void writeOutput(const string &outputName, vector<string> nameList) {
	// create an output file stream with the specified name
	ofstream outFile(outputName);
    	// check if the file can be accessed
	if (! outFile.is_open()) {
		cerr << "Unable to open the output file." << endl;
	} else {
		//write the names into the output file
		vector<string>::iterator it;
		for(it = nameList.begin(); it != nameList.end(); ++it) {
			outFile << *it << endl;
		}
	}
}


int main() {
	// Read 2 input files with student names
    	cout << "Enter the name of the first file: ";
    	string filename1;
    	getline(cin, filename1);
	ifstream inFile1(filename1.c_str());
  	while (! inFile1.is_open()) {
   		cerr << "Input file " << filename1 << " is NOT found. Please try again." << endl;
		cout << "Enter the name of the first file: ";
		getline(cin, filename1);
		inFile1.open(filename1.c_str());
	}
	vector<string> v1;
	readfiles(inFile1, v1);

	cout << "Enter the name of the second file: ";
	string filename2;
    	getline(cin, filename2);
	ifstream inFile2(filename2.c_str());
  	while (! inFile2.is_open()) {
   		cerr << "Input file " << filename2 << " is NOT found. Please try again." << endl;
	       	cout << "Enter the name of the second file: ";
	       	getline(cin, filename2);
	       	inFile2.open(filename2.c_str());
	}
    	vector<string> v2;
	readfiles(inFile2, v2);
	cout << endl;

   	// Compute and print the number of students in files
	cout << "Number of students in " << filename1 << " = " << v1.size() << endl;
	cout << "Number of students in " << filename2 << " = " << v2.size() << endl;

	vector<string> intersectList;
	intersect(v1, v2, intersectList);
	cout << "Number of students that are present in BOTH "
		<< filename1 << " AND " << filename2 << " = "
		<< intersectList.size() << endl;

	vector<string> unionList;
	Makeunion(v1, v2, unionList);
	cout << "Number of students that are present in EITHER "
		<< filename1 << " OR " << filename2 << " = "
		<< unionList.size() << endl;
	cout << endl;

	if (intersectList.size() != 0) {
		cout << "List of students that are present in BOTH "
			<< filename1 << " AND " << filename2 << ": " << endl;
		// print the names in the intersection vector, if it is not empty
		vector<string>::iterator it;
		for(it = intersectList.begin(); it != intersectList.end(); ++it) {
        		cout << *it << endl;
		}
		cout << endl;
	}

	// Write 2 output files named intersection.txt and union.txt
	writeOutput("intersection.txt", intersectList);
	if (intersectList.size() == 0) {
		cout << "The file intersection.txt is EMPTY since there are no students that are present in BOTH "
			<< filename1 << " AND " << filename2 << endl;
	} else {
		cout << "The names of the " << intersectList.size() << " students that are present in BOTH "
			<< filename1 << " AND " << filename2 << " are written to the file named intersection.txt" << endl;
	}

	writeOutput("union.txt", unionList);
	if (unionList.size() == 0) {
		cout << "The file union.txt is EMPTY since there are no students in the 2 files "
			<< filename1 << " AND " << filename2 << endl;
	} else {
		cout << "The names of the " << unionList.size() << " students that are present in BOTH "
			<< filename1 << " AND " << filename2 << " are written to the file named union.txt" << endl;
	}

	return 0;
}
