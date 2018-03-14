///////////////////////////////////////////////////////////////////////
// File Name:      a1.cpp
//
// Author:         <your_name>
// CS email:       <your_cs_login>@cs.wisc.edu
//
// Course:         CS 368 (C++)
// Section:        2
// Instructor:     Kuemmel
//
// Description:
//
// Sources:
//
// URL(s) of sources:
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

int main(int argc, char** argv)
{
    float testme[] = { 1.07500, 1.89500, 2.70500, 3.47500};
    //float testme[] = { 0.00500, 0.01500, 2.00500, 3.47500};
    std::cout << std::setprecision(2) << std::fixed;

    for(int i = 0; i < 4; ++i)
    {
        std::cout << testme[i] << std::endl;
    }

    return 0;
}
