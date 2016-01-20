//HW03_121044038_Recep_Sivri.cpp
//This homework made by Recep Sivri on 20/10/2015.
// main.cpp
// 	 Description:
//In This program we have a Triangle class and Triangle class has some functions This functions finds perimeter angles
// and sides of a Triangle objects and we test this functions.

#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class Triangle
{
public:
	//constructors
	Triangle();
	Triangle(const double side);
	Triangle(const double A,const double B);
	Triangle(const double A,const double B,const double C);
	//setters
	void SetTriangle();
	void SetTriangle(const double A);
	void SetTriangle(const double A,const double B);
	void SetTriangle(const double A,const double B,const double C);
	//getters
	double getAside();
	double getBside();
	double getCside();
	//angle functions
	double angleA();
	double angleB();
	double angleC();
	//input&output
	void input();
	void output();
	//functions of class
	bool isRightAngle();
	double perimeterTriangle();
	double areaTriangle();
	
private:
	double a;
        double b;
        double c;
	void TestTriangleArguments();
};
void callByValueTriangle(Triangle T);
void callByReferanceTriangle(Triangle &T);
int main(void)
{
	//testing Triangle objects.
	Triangle triang1,triang2(4,8,11),triang3(4,4),triang4(5,13,12),triang5(6),triang6;//triang6 for testing input function
	double a=0,b=0,c=0;
	//Testing Triangle sides
	cout<<"----------length of Triangle sides--------------"<<endl;
	cout<<"triangle 1:   ";
	triang1.output();
	cout<<"triangle 2:   ";
	triang2.output();
	cout<<"triangle 3:   ";
	triang3.output();
	cout<<"triangle 4:   ";
	triang4.output();
	cout<<"triangle 5:   ";
	triang5.output();
	//Testing Angles
	cout<<"----------Testing angleA function------------"<<endl;
	cout<<"angle A of triangle 1: "<<triang1.angleA()<<endl;
	cout<<"angle A of triangle 2: "<<triang2.angleA()<<endl;
	cout<<"angle A of triangle 3: "<<triang3.angleA()<<endl;
	cout<<"angle A of triangle 4: "<<triang4.angleA()<<endl;
	cout<<"angle A of triangle 5: "<<triang5.angleA()<<endl;

	cout<<"----------Testing angleB function------------"<<endl;
	cout<<"angle B of triangle 1: "<<triang1.angleB()<<endl;
	cout<<"angle B of triangle 2: "<<triang2.angleB()<<endl;
	cout<<"angle B of triangle 3: "<<triang3.angleB()<<endl;
	cout<<"angle B of triangle 4: "<<triang4.angleB()<<endl;
	cout<<"angle B of triangle 5: "<<triang5.angleB()<<endl;

	cout<<"----------Testing angleC function------------"<<endl;
	cout<<"angle C of triangle 1: "<<triang1.angleC()<<endl;
	cout<<"angle C of triangle 2: "<<triang2.angleC()<<endl;
	cout<<"angle C of triangle 3: "<<triang3.angleC()<<endl;
	cout<<"angle C of triangle 4: "<<triang4.angleC()<<endl;
	cout<<"angle C of triangle 5: "<<triang5.angleC()<<endl;

	//testing perimeter function.

	cout<<"----------Testing perimeterTriangle function------------"<<endl;
	cout<<"perimeter of triangle1: "<<triang1.perimeterTriangle()<<endl;
	cout<<"perimeter of triangle2: "<<triang2.perimeterTriangle()<<endl;
	cout<<"perimeter of triangle3: "<<triang3.perimeterTriangle()<<endl;
	cout<<"perimeter of triangle4: "<<triang4.perimeterTriangle()<<endl;
	cout<<"perimeter of triangle5: "<<triang5.perimeterTriangle()<<endl;

	//testing area function.

	cout<<"----------Testing areaTriangle function------------"<<endl;
	cout<<"area of triangle1: "<<triang1.areaTriangle()<<endl;
	cout<<"area of triangle2: "<<triang2.areaTriangle()<<endl;
	cout<<"area of triangle3: "<<triang3.areaTriangle()<<endl;
    cout<<"area of triangle4: "<<triang4.areaTriangle()<<endl;
	cout<<"area of triangle5: "<<triang5.areaTriangle()<<endl;

	//Testing right function.

	cout<<"----------Testing isRightAngle function------------"<<endl;
	if(triang1.isRightAngle())
		cout<<"triang1 is  a right angle."<<endl;
	else
		cout<<"triang1 is not a right angle!"<<endl;
	if(triang2.isRightAngle())
		cout<<"triang2 is  a right angle."<<endl;
	else
		cout<<"triang2 is not a right angle!"<<endl;
	if(triang3.isRightAngle())
		cout<<"triang3 is  a right angle."<<endl;
	else
		cout<<"triang3 is not a right angle!"<<endl;
	if(triang4.isRightAngle())
		cout<<"triang4 is  a right angle."<<endl;
	else
		cout<<"triang4 is not a right angle!"<<endl;
	if(triang5.isRightAngle())
		cout<<"triang5 is  a right angle."<<endl;
	else
		cout<<"triang5 is not a right angle!"<<endl;


	cout<<"Implementing call by value and Call by referance:"<<endl;
	triang2.output();
	cout<<"value of sides not changed:(Call by value)"<<endl;
	triang2.output();
	callByValueTriangle(triang2);
	cout<<"value of sides changed:(Call by referance)"<<endl;
	callByReferanceTriangle(triang2);
	triang2.output();
	cout<<"Testing valid Triangle:"<<endl;
	cout<<"please enter a side:";
	cin>>a;
	cout<<"please enter b side:";
	cin>>b;
	cout<<"please enter c side:";
	cin>>c;
	triang6.SetTriangle(a,b,c);
	return 0;
}
//Functions of Triangle Class.
Triangle::Triangle()
{
	a=1.0;
	b=1.0;
	c=1.0;
	TestTriangleArguments();
}
Triangle::Triangle(const double A)
{
	a=A;
	b=A;
	c=A;
	TestTriangleArguments();
}
Triangle::Triangle(const double A,const double B)
{
	a=A;
	b=B;
	c=1.0;
	TestTriangleArguments();
}
Triangle::Triangle(const double A,const double B,const double C)
{
	a=A;
	b=B;
	c=C;
	TestTriangleArguments();

}
void Triangle::SetTriangle()
{
	a=1.0;
	b=1.0;
	c=1.0;
	TestTriangleArguments();

}
void Triangle::SetTriangle(const double A)
{
	a=A;
	b=1.0;
	c=1.0;
	TestTriangleArguments();
}
void Triangle::SetTriangle(const double A,const double B)
{
	a=A;
	b=B;
	c=1.0;
	TestTriangleArguments();
}
void Triangle::SetTriangle(const double A,const double B,const double C)
{
	a=A;
	b=B;
	c=C;
	TestTriangleArguments();

}
double Triangle::getAside()
{
	return a;
}
double Triangle::getBside()
{
	return b;
}
double Triangle::getCside()
{
	return c;
}
void Triangle::input()
{
	cout<<"please enter a side:";
	cin>>a;
	cout<<"please enter b side:";
	cin>>b;
	cout<<"please enter c side:";
	cin>>c;
	TestTriangleArguments();

}
void Triangle::output()
{
	cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
}
double Triangle::perimeterTriangle()
{
	return a+b+c;
}
bool Triangle::isRightAngle()
{
	if(a*a==b*b+c*c)
		return true;
	else
	if(b*b==c*c+a*a)
		return true;
	else
	if(c*c==b*b+a*a)
		return true;
	else
		return false;
}
double Triangle::angleA()
{
	return acos((b*b+c*c-a*a)/(2*b*c))/(3.141593/180.0);//using cosinus theorem for compute angles
}
double Triangle::angleB()
{
	return acos((a*a+c*c-b*b)/(2*a*c))/(3.141593/180.0);
}
double Triangle::angleC()
{
	return acos((a*a+b*b-c*c)/(2*a*b))/(3.141593/180.0);
}
double Triangle::areaTriangle()
{
	return sin(angleA()*(3.141593/180.0))*b*c/2;
}
void Triangle::TestTriangleArguments()
{
	double a,b,c,diffA,diffB,diffC;//using angle theorem for determine if Triangle object is a triangle.
	a=getAside();
	b=getBside();
	c=getCside();
	int i=0;
	diffA=b-c;
	if(diffA<0)
		diffA=-1*diffA;
	diffB=a-c;
	if(diffB<0)
		diffB=-1*diffB;
	diffC=a-b;
	if(diffC<0)
		diffC=-1*diffC;

	if(diffA<a&&a<b+c)
		++i;
	if(diffB<b&&b<a+c)
		++i;
	if(diffC<c&&c<a+b)
		++i;
	if(i<3)
	{
		cerr<<"a:"<<getAside()<<" b:"<<getBside()<<" c:"<<getCside()<<" is not a triangle!"<<endl;
		exit(1);
	}
}
void callByValueTriangle(Triangle T)
{
	T.SetTriangle(1.0,1.0,1.0);
}
void callByReferanceTriangle(Triangle &T)
{
	T.SetTriangle(1.0,1.0,1.0);
}