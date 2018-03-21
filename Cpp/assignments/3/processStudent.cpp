///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Yang Chen
// CS email:       <your CS email>
//
// Description:    Methods to perform some processing on student objects.
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {

                  // TODO: Implement this method.
                  string detailLine;
                  while (getline(inFile, detailLine)) {
                      std::vector<string> detail_list;
                      string token;
                      istringstream ss(detailLine);
                      while(getline(ss, token, ',')) {
                          detail_list.push_back(token);
                      }
                      // assign each value to the corresponding variables
                      string studentType = detail_list[0];
                      string name = detail_list[1];
                      int yob = std::stoi(detail_list[2]);
                      std::vector<double> assignmentsScore;
                      for (int i = 3; i < 10; ++i) {
                          assignmentsScore.push_back(std::stod(detail_list[i]));
                      }
                      double projectScore = std::stod(detail_list[10]);

                      // Check the type of the student
                      if (studentType == "U") {
                          UndergradStudent Undergrad(name, yob, assignmentsScore,
                                           projectScore, detail_list[11],
                                           detail_list[12]);
                          ugstudents.push_back(Undergrad);
                      } else {
                          GradStudent Grad(name, yob, assignmentsScore,
                                           projectScore, detail_list[11],
                                           detail_list[12]);
                          gstudents.push_back(Grad);
                      }
                  }

}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->get().printDetails();
        std::cout << std::endl;
    }


}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.

    // compute the # of students based on the type of students.

    // compute the mean of the total score.

    // sort and print the students based on their total.
    double totalScore = 0.0;

    std::cout << "Number of students = " << students.size() << std::endl;

    for (auto it = students.begin(); it != students.end(); ++it) {
        totalScore += it->get().getTotal();
    }
    std::cout << "The mean of the total score = " << totalScore / students.size() << std::endl;

    std:sort(students.begin(), students.end(),
        [](std::reference_wrapper<Student> a, std::reference_wrapper<Student> b){
            return a.get().getTotal() > b.get().getTotal();});

    std::cout << "The sorted list of students (id, name, total, grade) in descending order of total: ";
    std::cout << std::endl;

    for (auto it = students.begin(); it != students.end(); ++it) {
        std::cout << it->get().getId() << ", " << it->get().getName() << ", " <<
            it->get().getTotal() << ", " << it->get().getGrade() << std::endl;
    }
    std::cout << std::endl;
}
