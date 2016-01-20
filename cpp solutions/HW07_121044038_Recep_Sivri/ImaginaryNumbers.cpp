//HW07_121044038_Recep_Sivri
//
//  ImaginaryNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    ImaginaryNumbers File for HW07_121044038_Recep_Sivri which ImaginaryNumbers implementation file .
#include"ImaginaryNumbers.h"
namespace recepSivriHW7
{

    bool ImaginaryNumbers::operator<(const ImaginaryNumbers& value)const// < operator.
    {
        return getImaginary()<value.getImaginary();
    }
    ostream& operator<<(ostream& outputStream,const ImaginaryNumbers& value)// << operator.
    {
        outputStream<<value.getImaginary()<<"*i";
        return outputStream;
    }
    ImaginaryNumbers ImaginaryNumbers::operator+(const ImaginaryNumbers& value)const// + operator.
    {
       return ImaginaryNumbers(getImaginary()+value.getImaginary());
    }
    void ImaginaryNumbers::setImaginary(double number)
    {
        setComplexNumbers(0,number);
    }
    ImaginaryNumbers ImaginaryNumbers::operator-(const ImaginaryNumbers& value)const// - operator.
    {
       return ImaginaryNumbers(getImaginary()-value.getImaginary());
    }
}

