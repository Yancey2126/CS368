//////////////////////////////////////
// main.cpp
// 
// Andy Kuemmel, CS 368, Spring 2018
// with ideas from Gerald
// 
//////////////////////////////////////

#include <iostream>
#include <vector>
#include <functional> // needed for reference wrappers
#include <sstream>
#include <fstream>

#include "Student.hpp"
#include "UndergradStudent.hpp"
#include "GradStudent.hpp"

// takes as input a Student reference, since Student is abstract
// it must be a refrence because cannot instantiate a Student
// the runtime environment checks the actual type
// of the reference and calls the correct version of printStudent()
void printDetails(Student &sRef) {
    sRef.printStudent();
}

// takes as input a vector of Student references
// because vectors store actual objects and Student is abstract
void printStudents(std::vector<std::reference_wrapper<Student>> studentRefs) {
    for (auto it = studentRefs.begin(); it != studentRefs.end(); ++it) {
        it->get().printStudent();
        std::cout << std::endl;
    }
}

// prototype for fillStudents
void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents);



int main() {

    std::vector<GradStudent> gstudents;
    std::vector<UndergradStudent> ugstudents;

    UndergradStudent ug1("Hailey", 1993, "Sellery");
    ug1.printStudent();
    ugstudents.push_back(ug1);
    std::cout << "typeid(ug1).name() : " << typeid(ug1).name() << std::endl;
    std::cout << std::endl;
    
 
    GradStudent g1("Vijay", 1986, "OS");
    g1.printStudent();
    gstudents.push_back(g1);
    std::cout << "typeid(g1).name() : " << typeid(g1).name() << std::endl;
    std::cout << std::endl;

    // you can check the type of an object with typeid(object)
    // you can check to see which type is
    if (typeid(g1) == typeid(GradStudent))
        std::cout << g1.getName() << " is a GradStudent." << std::endl;
    else if (typeid(g1) == typeid(UndergradStudent))
        std::cout << g1.getName() << " is type UndergradStudent" << std::endl;

    std::cout << std::endl;

    std::cout << "calling a polymorphic function with a reference:" << std::endl;
    printDetails(ug1);
    printDetails(g1);

    std::cout << "lets add more students from a file" << std::endl << std::endl;

    std::ifstream infile("delimiters.txt");
    if (!infile.is_open())
    {
        std::cerr << "Could not find file: delimiters.txt" << std::endl;
        return -1;  // leave main with error message
    }

    // call fillStudents
    fillStudents(infile, gstudents, ugstudents);

    // create a vector of references for undergraduate students.
    std::vector<std::reference_wrapper<Student>> ugstudentRefs;
    for (auto it = ugstudents.begin(); it != ugstudents.end(); ++it) {
        ugstudentRefs.push_back(*it);
    }

    // create a vector of references for graduate students.
    std::vector<std::reference_wrapper<Student>> gstudentRefs;
    for (auto it = gstudents.begin(); it != gstudents.end(); ++it) {
        gstudentRefs.push_back(*it);
    }

   // because each is a vector of <Student> references, 
   // we can call printStudents on each
    std::cout << "here are the undergrad students" << std::endl;
    printStudents(ugstudentRefs);
    std::cout << "here are the grad students" << std::endl;
    printStudents(gstudentRefs);


    // create a vector of references for ALL students
    std::vector<std::reference_wrapper<Student>> allStudentRefs;
    for (auto it = ugstudents.begin(); it != ugstudents.end(); ++it) {
        allStudentRefs.push_back(*it);
    }
    for (auto it = gstudents.begin(); it != gstudents.end(); ++it) {
        allStudentRefs.push_back(*it);
    }
    std::cout << "here are all " << Student::getNumStudents() << " students" << std::endl;
    printStudents(allStudentRefs);


    return 0;
}

void fillStudents(std::ifstream &infile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {
    std::string oneLineOfText;
    while (getline(infile, oneLineOfText))
    {
        std::cout << "reading in the line: " << oneLineOfText<< std::endl;
        std::stringstream ss(oneLineOfText);
        std::string UorG;
        std::string name;
        std::string yearAsString;
        std::string other;
        getline(ss, UorG, ',');
        getline(ss, name, ',');
        getline(ss, yearAsString,',');
        int year = std::stoi(yearAsString); // string to integer
        getline(ss, other);
        if (UorG == "U"){
            UndergradStudent u2(name,year,other);
            ugstudents.push_back(u2);
        }
        else{
            GradStudent g2(name, year, other);
            gstudents.push_back(g2);
        }
    }

}

