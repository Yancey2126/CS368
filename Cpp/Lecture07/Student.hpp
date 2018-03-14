//
// Created by Adalbert Gerald Soosai Raj on 10/19/16.
//

#ifndef LECTURE6_STUDENT_HPP
#define LECTURE6_STUDENT_HPP

#include <string>

class Student {
private:
    std::string name;
    int yob;
    // static...one variable shared with all objects of this class
    static int numStudents; 

public:
    Student();
    Student(std::string name, int yob);
    std::string getName();
    void setName(std::string name);
    int getYob();
    void setYob(int year);
    
    // static function....belongs to the class
    // made static because it will access a static data member
    static int getNumStudents();
    
    // virtual function....will be overriden in derived classes
    // makes the Student class abstract
    virtual void printStudent();

    // pure virtual function...has no implementation in Student
    // the =0 at the end signifies that it is 'pure virtual'
    virtual std::string getType() = 0;
};

#endif //LECTURE6_STUDENT_HPP
