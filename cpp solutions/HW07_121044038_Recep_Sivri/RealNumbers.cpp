//HW07_121044038_Recep_Sivri
//
//  RealNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    RealNumbers File for HW07_121044038_Recep_Sivri which RealNumbers implementation file.
#include"RealNumbers.h"
namespace recepSivriHW7
{
    ostream& operator<<(ostream& outputStream,const RealNumbers& value)// << operator.
    {
        outputStream<<value.getReal();
        return outputStream;
    }
    RealNumbers RealNumbers::operator+(const RealNumbers& value)const// + operator.
    {
        return RealNumbers(value.getReal()+getReal());
    }
    void RealNumbers::setRealNumbers(double number)// setter
    {
        setComplexNumbers(number,0);
    }
    RealNumbers RealNumbers::operator-(const RealNumbers& value)const// - operator.
    {
        return RealNumbers(getReal()-value.getReal());
    }
    bool RealNumbers::operator<(const RealNumbers& value)const// < operator.
    {
        return getReal()<value.getReal();
    }
}

