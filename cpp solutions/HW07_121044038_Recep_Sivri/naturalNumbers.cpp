//HW07_121044038_Recep_Sivri
//
//  naturalNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    naturalNumbers File for HW07_121044038_Recep_Sivri which naturalNumbers implementation file.
#include"naturalNumbers.h"
namespace recepSivriHW7
{

    naturalNumbers::naturalNumbers(int number)//constructor.
    {
        if(number<0)
            setIntegerNumber(0);
        else
            setIntegerNumber(number);
    }
    void naturalNumbers::setNaturalNumbers(int number)//setter.
    {
        if(number<0)
            number=0;
        setIntegerNumber(number);
    }
    ostream& operator<<(ostream& outputStream,const naturalNumbers& value)//<< operator.
    {
        outputStream<<value.getIntegers();
        return outputStream;
    }
    naturalNumbers naturalNumbers::operator+(const naturalNumbers& value)const// + operator.
    {
        return naturalNumbers(getNaturalNumbers()+value.getNaturalNumbers());
    }
    naturalNumbers naturalNumbers::operator-(const naturalNumbers& value)const// - operator.
    {
        return naturalNumbers(getNaturalNumbers()-value.getNaturalNumbers());
    }
    bool naturalNumbers::operator<(const naturalNumbers& value)const// < operator.
    {
        return getNaturalNumbers()<value.getNaturalNumbers();
    }
}

