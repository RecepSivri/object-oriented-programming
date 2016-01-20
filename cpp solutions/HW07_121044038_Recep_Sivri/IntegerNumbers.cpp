//HW07_121044038_Recep_Sivri
//
//  IntegerNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    IntegerNumbers File for HW07_121044038_Recep_Sivri which IntegerNumbers implementation file.
#include"IntegerNumbers.h"
namespace recepSivriHW7
{
    ostream& operator<<(ostream& outputStream,const IntegerNumbers& value)// << operator.
    {
        outputStream<<value.getIntegers();
        return outputStream;
    }
    IntegerNumbers IntegerNumbers::operator+(const IntegerNumbers& value)const// + operator.
    {
        return IntegerNumbers(getIntegers()+value.getIntegers());
    }
    IntegerNumbers IntegerNumbers::operator-(const IntegerNumbers& value)const// - operator.
    {
        return IntegerNumbers(getIntegers()-value.getIntegers());
    }
    void IntegerNumbers::setIntegerNumber(int number)//setter.
    {
        setRationalNumbers(number,1);
        setComplexNumbers(number,0);
    }
    bool IntegerNumbers::operator<(const IntegerNumbers& value)const// < operator.
    {
        return getIntegers()<value.getIntegers();
    }
}

