//HW07_121044038_Recep_Sivri
//
//  ComplexNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    ComplexNumbers File for HW07_121044038_Recep_Sivri which ComplexNumbers implementation file .

#include"ComplexNumbers.h"
namespace recepSivriHW7
{
    ostream& operator<<(ostream& outputStream,const ComplexNumbers& value)//stream insertion operator.
    {
        outputStream<<value.real<<" + "<<value.imaginary<<"*i";
        return outputStream;
    }
    void ComplexNumbers::setComplexNumbers(double realNumber,double ImaginaryNUmber)//setter.
    {
        real=realNumber;
        imaginary=ImaginaryNUmber;
    }
    ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& value)const//+ operator.
    {
        double res1,res2;
        res1=value.real+real;
        res2=value.imaginary+imaginary;
        return ComplexNumbers(res1,res2);
    }
    ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& value)const//- operator.
    {
        double res1,res2;
        res1=real-value.real;
        res2=imaginary-value.imaginary;
        return ComplexNumbers(res1,res2);
    }
    bool ComplexNumbers::operator<(const ComplexNumbers& value)const//< operator.
    {
        if(real<value.real)
            return true;
        else
        if(real==value.real)
        {
            if(imaginary<value.imaginary)
                return true;
        }
        else
            return false;
    }
}

