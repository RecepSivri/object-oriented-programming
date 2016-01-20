//HW07_121044038_Recep_Sivri
//
//  ImaginaryNumbers.h
//  Created on 15/12/2015
//  Description:
//    ImaginaryNumbers File for HW07_121044038_Recep_Sivri which ImaginaryNumbers header file.
#ifndef IMAGINARYNUMBERS_H_INCLUDED
#define IMAGINARYNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"ComplexNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class ImaginaryNumbers:public ComplexNumbers
    {
        public:
            ImaginaryNumbers(double number=0.0):ComplexNumbers(0.0,number){};//constructors.
            void setImaginary(double number);//setter.
            double getImaginaryNumber()const{return getImaginary();}//getter.
            ImaginaryNumbers operator+(const ImaginaryNumbers& value)const;//+ operator.
            ImaginaryNumbers operator-(const ImaginaryNumbers& value)const;//- operator.
            friend ostream& operator<<(ostream& outputStream,const ImaginaryNumbers& value);//<< operator.
            bool operator<(const ImaginaryNumbers& value)const;//< operator.

    };
}

#endif // IMAGINARYNUMBERS_H_INCLUDED
