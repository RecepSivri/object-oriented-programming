//HW07_121044038_Recep_Sivri
//
//  ComplexNumbers.h
//  Created on 15/12/2015
//  Description:
//    ComplexNumbers File for HW07_121044038_Recep_Sivri which ComplexNumbers header file.
#ifndef COMPLEXNUMBERS_H_INCLUDED
#define COMPLEXNUMBERS_H_INCLUDED
#include<iostream>
#include <cmath>
using namespace std;
namespace recepSivriHW7
{
    class ComplexNumbers
    {
        public:
            ComplexNumbers():real(0),imaginary(0){}//default constructor.
            ComplexNumbers(double num1):real(num1),imaginary(0){}// one parameter constructors.
            ComplexNumbers(double num1,double num2):real(num1),imaginary(num2){}// two parameter constructors.
            void setComplexNumbers(double realNumber,double ComplexNUmber);//setter.
            double getImaginary()const{return imaginary;}//getter.
            double getReal()const{return real;}//getter.
            friend ostream& operator<<(ostream& outputStream,const ComplexNumbers& value);//<< operator.
            ComplexNumbers operator+(const ComplexNumbers& value)const;//+ operator.
            ComplexNumbers operator-(const ComplexNumbers& value)const;//-operator.
            bool operator<(const ComplexNumbers& value)const;//< operator.
        private:
          double real;// real part.
          double imaginary;// imagine part.
    };
}
#endif // COMPLEXNUMBERS_H_INCLUDED
