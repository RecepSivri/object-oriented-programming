//HW07_121044038_Recep_Sivri
//
//  RealNumbers.h
//  Created on 15/12/2015
//  Description:
//    RealNumbers File for HW07_121044038_Recep_Sivri which RealNumbers header file.
#ifndef REALNUMBERS_H_INCLUDED
#define REALNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"ComplexNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class RealNumbers:public ComplexNumbers
    {
        public:
            RealNumbers(double number=0.0):ComplexNumbers(number,0.0){};//constructors.
            void setRealNumbers(double number);//setter.
            friend ostream& operator<<(ostream& outputStream,const RealNumbers& value);//<< operator.
            RealNumbers operator+(const RealNumbers& value)const;//+ operator.
            RealNumbers operator-(const RealNumbers& value)const;//- operator.
            bool operator<(const RealNumbers& value)const;//< operator.
    };
}

#endif // REALNUMBERS_H_INCLUDED
