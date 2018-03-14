//
// Created by Adalbert Gerald Soosai Raj on 10/19/16.
//

#include <iostream>
#include "Student.hpp"

int Student::numStudents = 0;

Student::Student() {
    name = "noname";
    yob = 0;
    ++Student::numStudents;
}

Student::Student(std::string name, int yob) {
    Student::name = name;
    Student::yob = yob;
    ++Student::numStudents;
}

std::string Student::getName() {
    return name;
}

int Student::getYob() {
    return yob;
}

void Student::setYob(int year) {
    yob = year;
}

void Student::setName(std::string name) {
    // this->name = name;
    Student::name = name;
}

void Student::printStudent() {
    std::cout << "name = " << getName() << std::endl;
    std::cout << "yob = " << getYob() << std::endl;
}


// there is NO implementation of Student::getType() in this class
// because it is purely virtual



int Student::getNumStudents() {
    return Student::numStudents;
}
