//HW07_121044038_Recep_Sivri
//
//  naturalNumbers.h
//  Created on 15/12/2015
//  Description:
//    naturalNumbers File for HW07_121044038_Recep_Sivri which naturalNumbers header file.
#ifndef NATURALNUMBERS_H_INCLUDED
#define NATURALNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"IntegerNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class naturalNumbers:public IntegerNumbers
    {
        public:
            naturalNumbers(int number=0);//constructors.
            void setNaturalNumbers(int number);//setter.
            int getNaturalNumbers()const{return getIntegers();}//getter.
            friend ostream& operator<<(ostream& outputStream,const naturalNumbers& value);//<< operator.
            naturalNumbers operator+(const naturalNumbers& value)const;//+ operator.
            naturalNumbers operator-(const naturalNumbers& value)const;//- operator.
            bool operator<(const naturalNumbers& value)const;//< operator.
    };
}
#endif // NATURALNUMBERS_H_INCLUDED
