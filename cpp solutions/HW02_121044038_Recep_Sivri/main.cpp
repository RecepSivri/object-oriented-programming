//HW02_121044038_Recep_Sivri
//main.cpp
//created on 19/10/2015 by Recep Sivri
//This program finds and returns index of mode of arrays which type of int,double,char and DayOfYear,Person classes.

#include<iostream>
using namespace std;

class DayOfYear
{
public:
	void setDayOfYear(int m,int d);
	void output();
	int month;
	int day;
};
class Person
{
public:
	void setPerson(int n,int a,double s);
	void output();
	int number;
	int age;
	double salary;
};
bool compareForDouble(const void* num1,const void* num2);
bool compareForInt(const void* num1,const void* num2);
bool compareForChar(const void* num1,const void* num2);
bool compareForDayOfYear(const void* num1,const void* num2);
bool compareForPerson(const void* num1,const void* num2);
int return_mode(const void*base,size_t num,size_t size,bool (*equals)(const void*, const void*));
int main(void)
{
	
	int res,i;//res is returned index.
	int arr[]={1,3,3,1,1,1,1,4,4,4,4,4,4,4,5,3,1,7,3};//int array
	char arrC[]={'a','b','c','d','e','e','e','b','b','b','b','e','e','e'};//char array
	double arrD[]={1.0,1.0,1.0,2.0,2.0,2.1,2.1,2.1,2.1,2.1,2.1,3.1,3.1,3.1,4.2,4.2,4.2,4.2,4.2,4.2,4.2,5.4};//Double array
	DayOfYear arrDy[12];//DayOfYear array
	Person arrP[12];//Person Array

	arrDy[0].setDayOfYear(12,1);//setting DayOfYear array.
	arrDy[1].setDayOfYear(4,2);
	arrDy[2].setDayOfYear(7,15);
	arrDy[3].setDayOfYear(9,15);
	arrDy[4].setDayOfYear(9,12);
	arrDy[5].setDayOfYear(9,12);
	arrDy[6].setDayOfYear(11,15);
	arrDy[7].setDayOfYear(11,15);
	arrDy[8].setDayOfYear(11,15);
	arrDy[9].setDayOfYear(11,15);
	arrDy[10].setDayOfYear(4,2);
	arrDy[11].setDayOfYear(7,15);

	arrP[0].setPerson(123123321,21,12.0000);//setting Person array.
	arrP[1].setPerson(121765412,22,11.0000);
	arrP[2].setPerson(23456781,32,43.00000);
	arrP[3].setPerson(12312312,40,11.00000);
	arrP[4].setPerson(12312312,21,21.00000);
	arrP[5].setPerson(12312312,40,11.00000);
	arrP[6].setPerson(23456781,32,43.00000);
	arrP[7].setPerson(12312312,40,11.00000);
	arrP[8].setPerson(123123321,21,12.0000);
	arrP[9].setPerson(121765412,22,11.0000);
	arrP[10].setPerson(23456781,32,43.00000);
	arrP[11].setPerson(12312312,40,11.00000);
	//start to test

	//For int
	cout<<"------------1.TEST FOR INT---------------"<<endl;
	cout<<"array of int: ";
	for(i=0;i<19;++i)
		cout<<arr[i]<<"  ";
	cout<<endl<<endl;

	res=return_mode(arr,19,sizeof(int),compareForInt);
		cout<<res<<". index most currence For int."<<endl;

	//For Double
	cout<<"------------2.TEST FOR DOUBLE---------------"<<endl;
	cout<<"array of double: ";
	for(i=0;i<22;++i)
		cout<<arrD[i]<<" ";
	cout<<endl<<endl;

	res=return_mode(arrD,22,sizeof(double),compareForDouble);
		cout<<res<<". index most currence For Double."<<endl;

	//For Char
	cout<<"------------3.TEST FOR CHAR---------------"<<endl;
	cout<<"array of char: ";
	for(i=0;i<14;++i)
		cout<<arrC[i]<<" ";
	cout<<endl<<endl;

	res=return_mode(arrC,14,sizeof(char),compareForChar);
		cout<<res<<". index most currence For Char."<<endl;

	
	cout<<"------------4.TEST FOR DayOfYear--------------"<<endl;
	for(i=0;i<12;++i)
		arrDy[i].output();
	cout<<endl;
	//For DayOfYear.
		res=return_mode(arrDy,12,sizeof(DayOfYear),compareForDayOfYear);
		cout<<res<<". index most currence For DayOfYear."<<endl;


	cout<<"------------5. TEST FOR Person--------------"<<endl;
	for(i=0;i<12;++i)
		arrP[i].output();
	cout<<endl;
	//For Person.
	res=return_mode(arrP,12,sizeof(Person),compareForPerson);
		cout<<res<<". index most currence For Person."<<endl;

}
//returns idex of mode of arrays.
int return_mode(const void*base,size_t num,size_t size,bool (*equals)(const void*, const void*))	
{

    unsigned char *start=(unsigned char *)base;//casting void pointer to unsigned char pointer this is start adress of array.
    unsigned char *end=start+(num*size);//calculating end of the array address.
    unsigned char *ptr,*ptr2;
    int count=0,max=0;

	for(ptr=start;ptr<end;ptr=ptr+(size))
    {
    	for(ptr2=start;ptr2<end;ptr2=ptr2+(size))
   	    {
	    		if(equals(ptr,ptr2))
	    			++count;//counting currences
    	}
    	if(count>max)
    		max=count;//max currence
    	count=0;
    }
    for(ptr=start;ptr<end;ptr=ptr+(size))
    {
    	for(ptr2=start;ptr2<end;ptr2=ptr2+(size))
   	    {
	    		if(equals(ptr,ptr2))
	    			++count;
    	}
    	if(count==max)//if equals max currence returns index of mode.
    		return (ptr-start)/size;
    	count=0;
    }
}
//Compare Functions for int,double,char,DayOfYear(month,day),Person(Number,Age,Salary).
bool compareForInt(const void* num1,const void* num2)
{
	int a,b;
	a=*(int*)num1;
	b=*(int*)num2;
	if(a==b)
		return true;
	else
		return false;
}
bool compareForDouble(const void* num1,const void* num2)
{
	double a,b;
	a=*(double*)num1;
	b=*(double*)num2;
	if(a==b)
		return true;
	return false;
}
bool compareForChar(const void* num1,const void* num2)
{
	char a,b;
	a=*(char*)num1;
	b=*(char*)num2;
	if(a==b)
		return true;
	return false;
}
bool compareForDayOfYear(const void* num1,const void* num2)
{
	DayOfYear a,b;
	a=*(DayOfYear*)num1;
	b=*(DayOfYear*)num2;
	if(a.month==b.month&&a.day==b.day)
		return true;
	else
		return false;
}
bool compareForPerson(const void* num1,const void* num2)
{
	Person a,b;
	a=*(Person*)num1;
	b=*(Person*)num2;
	if(a.number==b.number&&a.age==b.age&&a.salary==b.salary)
		return true;
	else
		return false;
}
//Functions of classes
void DayOfYear::output()
{
	cout<<"month:"<<month<<"  Day:"<<day<<endl;
}
void Person::output()
{
	cout<<"number:"<<number<<" age:"<<age<<" salary:"<<salary<<endl;
}
void DayOfYear::setDayOfYear(int m,int d)
{
	month=m;
	day=d;
}
void Person::setPerson(int n,int a,double s)
{
	number=n;
	age=a;
	salary=s;
}