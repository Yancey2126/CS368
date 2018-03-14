//
// Created by Adalbert Gerald Soosai Raj on 10/26/16.
//

#ifndef LECTURE6_GRADSTUDENT_HPP
#define LECTURE6_GRADSTUDENT_HPP


#include <string>
#include "Student.hpp"

class GradStudent : public Student {
private:
    std::string researchArea;

public:
    GradStudent(std::string name, int yob, std::string rArea);
    virtual void printStudent() override;
    virtual std::string getType() override;
};


#endif //LECTURE6_GRADSTUDENT_HPP
