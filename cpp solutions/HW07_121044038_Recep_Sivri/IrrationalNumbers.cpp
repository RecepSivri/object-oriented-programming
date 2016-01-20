//HW07_121044038_Recep_Sivri
//
//  IrrationalNumbers.cpp
//  Created on 15/12/2015
//  Description:
//    IrrationalNumbers File for HW07_121044038_Recep_Sivri which IrrationalNumbers implementation file.
#include"IrrationalNumbers.h"
namespace recepSivriHW7
{
    IrrationalNumbers::IrrationalNumbers(double num1,double num2)//constructor.
    {
        double res;
        int res2;
        res=pow(num1,(1/num2));
        res2=res;
        res=res-res2;
        if(res>0)
        {
            setRealNumbers(num1);
            reversePow=num2;
        }
        else
        {
            setRealNumbers(0);
            reversePow=0;
        }
    }
    void IrrationalNumbers::setIrrationalNumber(double number,double reversePower)//setter.
    {
        reversePow=reversePower;
        setRealNumbers(number);
    }
    ostream& operator<<(ostream& outputStream,const IrrationalNumbers& value)//<< operator.
    {
        outputStream<<value.getIrrational();
        return outputStream;
    }
    IrrationalNumbers IrrationalNumbers::operator+(const IrrationalNumbers& value)const//+ operator.
    {
        double result=getIrrational()+value.getIrrational();
        double base;
        if(value.reversePow<reversePow)
            base=value.reversePow;
        else
            base=reversePow;
        log(result)/log(base);
        return IrrationalNumbers(base,1/(log(result)/log(base)));
    }
    IrrationalNumbers IrrationalNumbers::operator-(const IrrationalNumbers& value)const// - operator.
    {
        double result=getIrrational()-value.getIrrational();
        double base;

        if(value.reversePow<reversePow)
            base=value.reversePow;
        else
            base=reversePow;
        log(result)/log(base);
        return IrrationalNumbers(base,1/(log(result)/log(base)));
    }
    bool IrrationalNumbers::operator<(const IrrationalNumbers& value)const// < operator.
    {
        return getIrrational()<value.getIrrational();
    }
}
