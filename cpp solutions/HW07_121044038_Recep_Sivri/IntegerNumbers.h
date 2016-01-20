//HW07_121044038_Recep_Sivri
//
//  IntegerNumbers.h
//  Created on 15/12/2015
//  Description:
//    IntegerNumbers File for HW07_121044038_Recep_Sivri which IntegerNumbers header file.
#ifndef INTEGERNUMBERS_H_INCLUDED
#define INTEGERNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"RationalNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class IntegerNumbers:public RationalNumbers
    {
        public:
            IntegerNumbers(int number=0):RationalNumbers(number,1){}//constructors.
            int getIntegers()const{return getNominator();}//getter.
            void setIntegerNumber(int number);//setter.
            friend ostream& operator<<(ostream& outputStream,const IntegerNumbers& value);//<< operator.
            IntegerNumbers operator+(const IntegerNumbers& value)const;//+ operator.
            IntegerNumbers operator-(const IntegerNumbers& value)const;//- operator.
            bool operator<(const IntegerNumbers& value)const;//< operator.
    };
}

#endif // INTEGERNUMBERS_H_INCLUDED
