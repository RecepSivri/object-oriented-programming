//HW07_121044038_Recep_Sivri
//
//  RationalNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    RationalNumbers File for HW07_121044038_Recep_Sivri which RationalNumbers implementation file.
#include"RationalNumbers.h"
namespace recepSivriHW7
{
    ostream& operator<<(ostream& outputStream,const RationalNumbers& value)// << operator.
    {
        outputStream<<value.nominator<<"/"<<value.denominator;
        return outputStream;
    }
    RationalNumbers RationalNumbers::operator+(const RationalNumbers& value)const// + operator.
    {
        int num,denomin,temp,a,b,c;
        denomin=value.denominator*denominator;
        num=value.denominator*nominator+value.nominator*denominator;
        a=num;
        b=denomin;
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        while(a%b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        num=num/b;
        denomin=denomin/b;
        return RationalNumbers(num,denomin);
    }
    RationalNumbers RationalNumbers::operator-(const RationalNumbers& value)const// - operator.
    {
        int num,denomin,temp,a,b,c;
        denomin=value.denominator*denominator;
        num=value.denominator*nominator-value.nominator*denominator;
        a=num;
        b=denomin;
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        while(a%b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        if(b<0)
            b=b*-1;
        num=num/b;
        denomin=denomin/b;
        return RationalNumbers(num,denomin);
    }
    void RationalNumbers::setRationalNumbers(int num1,int num2)//setter.
    {
        if(num2==0)
            num2=1;

        nominator=num1;
        denominator=num2;
        setComplexNumbers(nominator/static_cast<double>(denominator),0);
    }
    bool RationalNumbers::operator<(const RationalNumbers& value)const// < operator.
    {
        return getRational()<value.getRational();
    }
}

