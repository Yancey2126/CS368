//
// Created by Adalbert Gerald Soosai Raj on 10/26/16.
//

#include <iostream>
#include "UndergradStudent.hpp"


// has 3 parameters
// calls the constructor of Student 
UndergradStudent::UndergradStudent(std::string name,
                                   int yob,
                                   std::string rHall) : Student(name, yob) {
    residenceHall = rHall;
}

// polymorphic function...notice its implementation
// does NOT include 'virtual' or 'override'
// also notice that the first line calls printStudent in the base class
void UndergradStudent::printStudent() {
    Student::printStudent();
    std::cout << "residenceHall = " << residenceHall << std::endl;
    std::cout << "Type = " << getType() << std::endl;
}

// another polymorphic function
std::string UndergradStudent::getType() {
    return "Undergrad";
}

