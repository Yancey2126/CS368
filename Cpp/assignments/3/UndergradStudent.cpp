///////////////////////////////////////////////////////////////////////////////
// File Name:      UndergradStudent.cpp
//
// Author:         Yang Chen
// CS email:       <your CS email>
//
// Description:    Implementations for UndergradStudent Class
///////////////////////////////////////////////////////////////////////////////

#include "UndergradStudent.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int UndergradStudent::numUndergradStudents = 0;

/**
 * @brief Constructor for an undergraduate student.
 *
 * @param name Undergraduate student's name
 * @param yearOfBirth Undergraduate student's YOB
 * @param assignmentsScore Undergraduate student's assignment scores.
 * @param projectScore Undergraduate student's project score.
 * @param residenceHall Undergraduate student's residence hall.
 * @param yearInCollege Undergraduate student's year in college.
 */
UndergradStudent::UndergradStudent(std::string name,
                 int yearOfBirth,
                 const std::vector<double> &assignmentsScore,
                 double projectScore,
                 std::string residenceHall,
                 std::string yearInCollege):Student(name, yearOfBirth, assignmentsScore, projectScore) {
                     this -> residenceHall = residenceHall;
                     this -> yearInCollege = yearInCollege;
                     ++numUndergradStudents;
                 }

/**
   * @brief Getter for a student's residence hall.
   *
   * @return The residence hall in which the student resides.
   */
  std::string UndergradStudent::getResidenceHall() {
      return residenceHall;
  }

  /**
   * @brief Getter for a student's year in college.
   *
   * @return The year in college of the student.
   */
  std::string UndergradStudent::getYearInCollege() {
      return yearInCollege;
  }

  /**
   * @brief Get the total number of undergraduate students.
   *
   * @return The number of undergraduate students.
   */
  int UndergradStudent::getNumStudents() {
      return numUndergradStudents;
  }

  void UndergradStudent::printDetails() {
      Student::printDetails();
      std::cout << "Type = Undergraduate Student" << std::endl;
      std::cout << "Residence Hall = " << getResidenceHall()<< std::endl;
      std::cout << "Year in College = " << getYearInCollege() << std::endl;
  }

  double UndergradStudent::getTotal() {
      std::vector<double> assignmentsScore = Student::getAssignmentsScore();
      double AvgScore = accumulate(assignmentsScore.begin(),
            assignmentsScore.end(), 0.0) / assignmentsScore.size();
      return 0.7 * AvgScore + 0.3 * Student::getProjectScore();
  }

  std::string UndergradStudent::getGrade() {
      std::string Grade;
      UndergradStudent::getTotal() < 70 ? Grade = "N" : Grade = "CR";
      return Grade;
  }
