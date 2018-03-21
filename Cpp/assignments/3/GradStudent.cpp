///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.cpp
//
// Author:         Yang Chen
// CS email:       <your CS email>
//
// Description:    Implementations for GradStudent Class
///////////////////////////////////////////////////////////////////////////////

#include "GradStudent.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int GradStudent::numGradStudents = 0;

/**
 * @brief Constructor for a graduate student.
 *
 * @param name Graduate student's name.
 * @param yearOfBirth Graduate student's YOB.
 * @param assignmentsScore Graduate student's assignment scores.
 * @param projectScore Graduate student's project score.
 * @param researchArea Graduate student's research area.
 * @param advisor Graduate student's advisor.
 */
GradStudent::GradStudent(std::string name,
                 int yearOfBirth,
                 const std::vector<double> &assignmentsScore,
                 double projectScore,
                 std::string researchArea,
                 std::string advisor):Student(name, yearOfBirth, assignmentsScore, projectScore)  {
                this -> researchArea = researchArea;
                this -> advisor = advisor;
                ++numGradStudents;
            }

/**
   * @brief Getter for the student's research area.
   *
   * @return The research area of the student.
   */
  std::string GradStudent::getResearchArea() {
      return researchArea;
  }

  /**
   * @brief Getter for the student's advisor.
   *
   * @return The advisor of the student.
   */
  std::string GradStudent::getAdvisor() {
      return advisor;
  }

  /**
   * @brief Get the total number of graduate students.
   *
   * @return The number of graduate students.
   */
  int GradStudent::getNumStudents() {
      return numGradStudents;
  }

  void GradStudent::printDetails() {
      Student::printDetails();
      std::cout << "Type = Graduate Student" << std::endl;
      std::cout << "Research Area = " << getResearchArea() << std::endl;
      std::cout << "Advisor = " << getAdvisor() << std::endl;
  }

  double GradStudent::getTotal() {
      std::vector<double> assignmentsScore = Student::getAssignmentsScore();
      double AvgScore = accumulate(assignmentsScore.begin(),
            assignmentsScore.end(), 0.0) / assignmentsScore.size();
      return 0.5 * AvgScore + 0.5 * Student::getProjectScore();
  }

  std::string GradStudent::getGrade() {
      std::string Grade;
      GradStudent::getTotal() < 80 ? Grade = "N" : Grade = "CR";
      return Grade;
  }
