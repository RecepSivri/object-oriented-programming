//HW07_121044038_Recep_Sivri
//
//  RationalNumbers.h
//  Created on 15/12/2015
//  Description:
//    RationalNumbers File for HW07_121044038_Recep_Sivri which RationalNumbers header file.
#ifndef RATIONALNUMBERS_H_INCLUDED
#define RATIONALNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"RealNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class RationalNumbers:public RealNumbers
    {
        public:

            RationalNumbers(int num=0,int denum=1):RealNumbers(),nominator(num),denominator(denum)//constructors.
            {setComplexNumbers(nominator/static_cast<double>(denominator),0);}
            double getRational()const{return getReal();}//getter.
            int getNominator()const{return nominator;}//getter.
            int getDenominator()const{return denominator;}//getter.
            void setRationalNumbers(int num1,int num2);//setter.
            friend ostream& operator<<(ostream& outputStream,const RationalNumbers& value);//<< operator.
            RationalNumbers operator+(const RationalNumbers& value)const;//+ operator.
            RationalNumbers operator-(const RationalNumbers& value)const;//- operator.
            bool operator<(const RationalNumbers& value)const;//< operator.
        private:
            int nominator;//nominator part.
            int denominator;//denominator part.
    };
}


#endif // RATIONALNUMBERS_H_INCLUDED
