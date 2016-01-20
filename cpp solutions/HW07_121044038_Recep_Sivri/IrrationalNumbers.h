//HW07_121044038_Recep_Sivri
//
//  IrrationalNumbers.h
//  Created on 15/12/2015
//  Description:
//    IrrationalNumbers File for HW07_121044038_Recep_Sivri which IrrationalNumbers header file.
#ifndef IRRATIONALNUMBERS_H_INCLUDED
#define IRRATIONALNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
#include"RealNumbers.h"
using namespace std;
namespace recepSivriHW7
{
    class IrrationalNumbers:public RealNumbers
    {
        public:
            IrrationalNumbers():RealNumbers(1),reversePow(1){}//default constructor.
            IrrationalNumbers(double num1=1,double num2=1);// two parameter constructors.
            double getIrrational()const{return pow(getReal(),(1/reversePow));}//getter.
            double getReversePow()const{return reversePow;}//getter.
            double getNumber()const{return getReal();}//getter.
            void setIrrationalNumber(double number,double reversePower);//setter.
            friend ostream& operator<<(ostream& outputStream,const IrrationalNumbers& value);//<< operator.
            IrrationalNumbers operator+(const IrrationalNumbers& value)const;//+ operator.
            IrrationalNumbers operator-(const IrrationalNumbers& value)const;//- operator.
            bool operator<(const IrrationalNumbers& value)const;//< operator.
        private:
            double reversePow;

    };
}
#endif // IRRATIONALNUMBERS_H_INCLUDED
