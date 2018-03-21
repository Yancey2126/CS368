///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.cpp
//
// Author:         Yang Chen
// CS email:       <your CS email>
//
// Description:    Implementations for Student Class
///////////////////////////////////////////////////////////////////////////////

#include "Student.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int Student::numStudents = 0;
/**
   * @brief A parameterised constructor for a Student.
   *
   * @param name Student's name.
   * @param yearOfBirth Student's year of birth.
   * @param assignmentsScore Student's assignment scores.
   * @param projectScore Student's project score.
   */
  Student::Student(std::string name,
          int yearOfBirth,
          const std::vector<double> &assignmentsScore,
          double projectScore) {
                  Student::name = name;
                  Student::yearOfBirth = yearOfBirth;
                  Student::assignmentsScore =assignmentsScore;
                  Student::projectScore = projectScore;
                  ++Student::numStudents;
                  Student::id = numStudents;
          }

  /**
   * @brief Print all assginment scores of the student
   */
  void Student::printAssignmentScores() {
        std::cout << "Assignments = [" << assignmentsScore[0];
        for (auto it = assignmentsScore.begin() + 1;
            it != assignmentsScore.end(); ++it ) {
                  std::cout << ", " << *it;
            }
        std::cout << "]" << std::endl;
  }

  /**
   * @brief Calculate average assignment score of the student
   *
   * @return The average assignment score of the student
   *
  double Student::calculateAvg() {
        return accumulate(assignmentsScore.begin(), assignmentsScore.end(),
            0.0) / assignmentsScore.size();
  }
  */

  /**
   * @brief Getter for student's id.
   *
   * @return The id of the student.
   */
  int Student::getId() {
        return id;
  }

  /**
   * @brief Getter for student's name.
   *
   * @return The name of the student.
   */
  std::string Student::getName() {
        return name;
  }

  /**
   * @brief Getter for student's YOB.
   *
   * @return The YOB of the student.
   */
  int Student::getYearOfBirth() {
        return yearOfBirth;
 }

  /**
   * @brief Get the age of a student.
   *
   * @return The student's age.
   */
  int Student::getAge() {
        return current_year - yearOfBirth;
 }

  /**
   * @brief Getter for student's assignment scores.
   *
   * @return A const reference to the vector of student's assignment scores.
   */
  const std::vector<double> &Student::getAssignmentsScore() {
        return assignmentsScore;
 }

  /**
   * @brief Getter for student's project score.
   *
   * @return The project score of the student.
   */
  double Student::getProjectScore() {
        return projectScore;
 }

  /**
   * @brief Get the total number of students.
   *
   * @return The total number of students.
   */
  int Student::getNumStudents() {
        return Student::numStudents;
 }

  /**
   * @brief Prints the details of the student.
   *
   * @example This method prints the following details of a student.
   * Id = 10
   * Name = Rex Fernando
   * Age =  19
   * Assignments = [57, 90, 81, 96, 80, 95, 78]
   * Project = 98
   * Total = 90.2143
   * Grade = CR
   */
  void Student::printDetails() {
        std::cout << "STUDENT DETAILS: " << std::endl;
        std::cout << "Id = " << getId() << std::endl;
        std::cout << "Name = " << getName() << std::endl;
        std::cout << "Age = " << getAge() << std::endl;
        printAssignmentScores();
        std::cout << "Project = " << getProjectScore() << std::endl;
        std::cout << "Total = " << getTotal() << std::endl;
        std::cout << "Grade = " << getGrade() << std::endl;
 }

 // No Implementations for getTotal() and getGrade()
