//
// Created by Adalbert Gerald Soosai Raj on 10/26/16.
//

#ifndef LECTURE6_UNDERGRADSTUDENT_HPP
#define LECTURE6_UNDERGRADSTUDENT_HPP


#include "Student.hpp"

class UndergradStudent : public Student {
private:
    std::string residenceHall;

public:
    UndergradStudent(std::string name, int yob, std::string rHall);

    // virtual functions....notice the word override at the end
    virtual void printStudent() override;
    virtual std::string getType() override;
};


#endif //LECTURE6_UNDERGRADSTUDENT_HPP
