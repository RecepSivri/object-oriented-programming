//HW07_121044038_Recep_Sivri
//
//  main.cpp
//  Created on 15/12/2015
//  Description:
//    main File for HW07_121044038_Recep_Sivri which contains tests.

#include"ComplexNumbers.h"
#include"ImaginaryNumbers.h"
#include"RealNumbers.h"
#include"RationalNumbers.h"
#include"IntegerNumbers.h"
#include"naturalNumbers.h"
#include"IrrationalNumbers.h"
using namespace std;
using namespace recepSivriHW7;
int main()
{
    //defining objects of classes.
    RealNumbers rNumber(123),rNumber2(1299),rNumber3(5678.123),rNumber4(67.912),rNumber5(981.123);
    ComplexNumbers cnum1(671.56,123.65),cnum2(987.123,43.12),cnum3(56.23,12),cnum4(56.23,13);
    RationalNumbers RatNum1(12,15),RatNum2(6,8),RatNum3(123,150),RatNum4(56,70),RatNum5(16,25);
    IntegerNumbers intNum1(-1256),intNum2(12456),intNum3(423),intNum4(897),intNum5(78);
    naturalNumbers natNum1(456),natNum2(2531),natNum3(53),natNum4(643),natNum5(12);
    ImaginaryNumbers imNum1(12.123),imNum2(45.12),imNum3(567.123),imNum4(897.623);
    IrrationalNumbers irrNum1(5,2),irrNum2(7,4),irrNum3(8,3),irrNum4(123,12),irrNum5(56,7);

        //Testing objects of clases.
       cout<<"----------Testing Complex Numbers-------------"<<endl;//for complex numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<cnum1<<endl;
       cout<<"2.    "<<cnum2<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<cnum1<<"  +  "<<cnum2<<" = ";
       cout<<cnum1+cnum2<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<cnum1<<"  -  "<<cnum2<<" = ";
       cout<<cnum1-cnum2<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<cnum1<<" < "<<cnum2<<" = ";
       if(cnum1<cnum2)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;
       cout<<"----testing complexNumbers with realNumbers:"<<endl;//for complex numbers with real numbers.
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum2<<endl;
       cout<<"realNumbers is:"<<endl;
       cout<<rNumber<<endl;
       cout<<cnum2<<" + "<<rNumber<<" = "<<cnum2+rNumber<<endl;
       cout<<cnum2<<" - "<<rNumber<<" = "<<cnum2-rNumber<<endl;
       cout<<cnum2<<" < "<<rNumber<<" = ";
       if(cnum2<rNumber)
           cout<<"True!"<<endl<<endl;
       else
           cout<<"False!"<<endl<<endl;

       cout<<"----testing complexNumbers with RationalNumbers:"<<endl;//for complex numbers with Rational Numbers.
       cout<<"RationalNumbers is:"<<endl;
       cout<<RatNum1<<endl;
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum3<<endl;
       cout<<cnum3<<" + "<<RatNum1<<" = "<<cnum3+RatNum1<<endl;
       cout<<cnum3<<" - "<<RatNum1<<" = "<<cnum3-RatNum1<<endl;
       cout<<cnum3<<" < "<<RatNum1<<" = ";
       if(cnum3<RatNum1)
           cout<<"True!"<<endl<<endl;
       else
           cout<<"False!"<<endl<<endl;

       cout<<"----testing complexNumbers with ImaginaryNumbers:"<<endl;//for complex numbers with Imaginary Numbers.
       cout<<"ImaginaryNumbers is:"<<endl;
       cout<<imNum1<<endl;
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum1<<endl;
       cout<<cnum1<<" + "<<imNum1<<" = "<<cnum1+imNum1<<endl;
       cout<<cnum1<<" - "<<imNum1<<" = "<<cnum1-imNum1<<endl;
       cout<<cnum1<<" < "<<imNum1<<" = ";
       if(cnum1<imNum1)
           cout<<"True!"<<endl<<endl;
       else
            cout<<"False!"<<endl<<endl;

       cout<<"----testing complexNumbers with IntegerNumbers:"<<endl;//for complex numbers with Integer Numbers.
       cout<<"IntegerNumbers is:"<<endl;
       cout<<intNum2<<endl;
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum4<<endl;
       cout<<cnum4<<" + "<<intNum2<<" = "<<cnum4+intNum2<<endl;
       cout<<cnum4<<" - "<<intNum2<<" = "<<cnum4-intNum2<<endl;
       cout<<cnum4<<" < "<<intNum2<<" = ";
       if(cnum4<intNum2)
           cout<<"True!"<<endl<<endl;
       else
           cout<<"False!"<<endl<<endl;

       cout<<"----testing complexNumbers with IrrationalNumbers:"<<endl;//for complex numbers with Irrational Numbers.
       cout<<"IrrationalNumbers is:"<<endl;
       cout<<irrNum2<<endl;
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum3<<endl;
       cout<<cnum3<<" + "<<irrNum2<<" = "<<cnum3+irrNum2<<endl;
       cout<<cnum3<<" - "<<irrNum2<<" = "<<cnum3-irrNum2<<endl;
       cout<<cnum3<<" < "<<irrNum2<<" = ";
       if(cnum3<irrNum2)
           cout<<"True!"<<endl<<endl;
       else
           cout<<"False!"<<endl<<endl;

       cout<<"----testing complexNumbers with naturalNumbers:"<<endl;//for complex numbers with natural Numbers.
       cout<<"naturalNumbers is:"<<endl;
       cout<<natNum2<<endl;
       cout<<"complexNumbers is:"<<endl;
       cout<<cnum1<<endl;
       cout<<cnum1<<" + "<<natNum2<<" = "<<cnum1+natNum2<<endl;
       cout<<cnum1<<" - "<<natNum2<<" = "<<cnum1-natNum2<<endl;
       cout<<cnum1<<" < "<<natNum2<<" = ";
       if(cnum1<natNum2)
           cout<<"True!"<<endl<<endl;
       else
           cout<<"False!"<<endl<<endl;

       cout<<"----------Testing ImaginaryNumbers Numbers-------------"<<endl;//for complex numbers with  Imaginary Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<imNum3<<endl;
       cout<<"2.    "<<imNum4<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<imNum3<<"  +  "<<imNum4<<" = ";
       cout<<imNum3+imNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<imNum3<<"  -  "<<imNum4<<" = ";
       cout<<imNum3-imNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<imNum3<<" < "<<imNum4<<" = ";
       if(imNum3<imNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RealNumbers Numbers-------------"<<endl;//for Real Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<rNumber4<<endl;
       cout<<"2.    "<<rNumber5<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber4<<"  +  "<<rNumber5<<" = ";
       cout<<rNumber4+rNumber5<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber4<<"  -  "<<rNumber5<<" = ";
       cout<<rNumber4-rNumber5<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber4<<" < "<<rNumber5<<" = ";
       if(rNumber4<rNumber5)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RealNumbers with RationalNumbers-------------"<<endl;//for real numbers with  rational Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<RatNum4<<endl;
       cout<<"2.    "<<rNumber5<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber5<<"  +  "<<RatNum4<<" = ";
       cout<<rNumber5+RatNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber5<<"  -  "<<RatNum4<<" = ";
       cout<<rNumber5-RatNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber5<<" < "<<RatNum4<<" = ";
       if(rNumber5<RatNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RealNumbers with IntegerNumbers-------------"<<endl;//for real numbers with  Integer Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<intNum5<<endl;
       cout<<"2.    "<<rNumber5<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber5<<"  +  "<<intNum5<<" = ";
       cout<<rNumber5+intNum5<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber5<<"  -  "<<intNum5<<" = ";
       cout<<rNumber5-intNum5<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber5<<" < "<<intNum5<<" = ";
       if(rNumber5<intNum5)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RealNumbers with naturalNumbers-------------"<<endl;//for real numbers with  natural Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<natNum4<<endl;
       cout<<"2.    "<<rNumber3<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber3<<"  +  "<<natNum4<<" = ";
       cout<<rNumber3+natNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber3<<"  -  "<<natNum4<<" = ";
       cout<<rNumber3-natNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber3<<" < "<<natNum4<<" = ";
       if(rNumber3<natNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RealNumbers with IrrationalNumbers-------------"<<endl;//for real numbers with  Irrational Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<irrNum2<<endl;
       cout<<"2.    "<<rNumber2<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber2<<"  +  "<<irrNum2<<" = ";
       cout<<rNumber2+irrNum2<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber2<<"  -  "<<irrNum2<<" = ";
       cout<<rNumber2-irrNum2<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber2<<" < "<<irrNum2<<" = ";
       if(rNumber2<irrNum2)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing IrrationalNumbers-------------"<<endl;//for irrational numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<irrNum5<<endl;
       cout<<"2.    "<<irrNum4<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<irrNum5<<"  +  "<<irrNum4<<" = ";
       cout<<irrNum5+irrNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<irrNum5<<"  -  "<<irrNum4<<" = ";
       cout<<irrNum5-irrNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<irrNum5<<" < "<<irrNum4<<" = ";
       if(irrNum5<irrNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RationalNumbers-------------"<<endl;//for rational numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<RatNum4<<endl;
       cout<<"2.    "<<RatNum5<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<RatNum4<<"  +  "<<RatNum5<<" = ";
       cout<<RatNum4+RatNum5<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<RatNum4<<"  -  "<<RatNum5<<" = ";
       cout<<RatNum4-RatNum5<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<RatNum4<<" < "<<RatNum5<<" = ";
       if(RatNum4<RatNum5)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing RationalNumbers  with IntegerNumbers-------------"<<endl;//for Rational Numbers with  Integer Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<RatNum3<<endl;
       cout<<"2.    "<<intNum3<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<RatNum3<<"  +  "<<intNum3<<" = ";
       cout<<RatNum3+intNum3<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<RatNum3<<"  -  "<<intNum3<<" = ";
       cout<<RatNum3-intNum3<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<RatNum3<<" < "<<intNum3<<" = ";
       if(RatNum3<intNum3)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

        cout<<"----------Testing RationalNumbers  with naturalNumbers-------------"<<endl;//for Rational Numbers with  natural Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<RatNum5<<endl;
       cout<<"2.    "<<natNum1<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<RatNum5<<"  +  "<<natNum1<<" = ";
       cout<<RatNum5+natNum1<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<RatNum5<<"  -  "<<natNum1<<" = ";
       cout<<RatNum5-natNum1<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<RatNum5<<" < "<<natNum1<<" = ";
       if(RatNum5<natNum1)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing IntegerNumbers-------------"<<endl;//for Integer Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<intNum3<<endl;
       cout<<"2.    "<<intNum4<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<intNum3<<"  +  "<<intNum4<<" = ";
       cout<<intNum3+intNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<intNum3<<"  -  "<<intNum4<<" = ";
       cout<<intNum3-intNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<intNum3<<" < "<<intNum4<<" = ";
       if(intNum3<intNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing IntegerNumbers with naturalNumbers-------------"<<endl;//for Integer Numbers with  natural Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<natNum4<<endl;
       cout<<"2.    "<<rNumber3<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<rNumber3<<"  +  "<<natNum4<<" = ";
       cout<<rNumber3+natNum4<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<rNumber3<<"  -  "<<natNum4<<" = ";
       cout<<rNumber3-natNum4<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<rNumber3<<" < "<<natNum4<<" = ";
       if(rNumber3<natNum4)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

       cout<<"----------Testing naturalNumbers-------------"<<endl;//for natural Numbers.
       cout<<"----testing << operator:"<<endl;
       cout<<"1.    "<<natNum2<<endl;
       cout<<"2.    "<<natNum1<<endl<<endl;
       cout<<"----testing + operator:"<<endl;
       cout<<natNum2<<"  +  "<<natNum1<<" = ";
       cout<<natNum2+natNum1<<endl<<endl;
       cout<<"----testing - operator:"<<endl;
       cout<<natNum2<<"  -  "<<natNum1<<" = ";
       cout<<natNum2-natNum1<<endl<<endl;
       cout<<"----testing < operator:"<<endl;
       cout<<natNum2<<" < "<<natNum1<<" = ";
       if(natNum2<natNum1)
           cout<<"True!"<<endl;
       else
           cout<<"False!"<<endl;

}
