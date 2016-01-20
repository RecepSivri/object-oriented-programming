//HW06_121044038_Recep_Sivri
//
//  Cells.cpp
//  Created on 10/12/2015
//  Description:
//      header for Cell class.
//
#ifndef CELLS_H_INCLUDED
#define CELLS_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

namespace HW6
{
    class cell
    {
    public:
        cell():y(0),x("\0"),ch('.'){}//no parameter constructor for cell class.
        cell(int Y):y(Y),x("\0"),ch('.'){}//one parameter constructor for cell class.
        cell(int Y,string X):y(Y),x(X),ch('.'){}//two parameter constructor for cell class.
        cell(int Y,string X,char pch):y(Y),x(X),ch(pch){}//three parameter constructor for cell class.
        void setCell(){y=0,x.assign("\0"),ch='.';}//set cell class with no parameter.
        void setCell(int Y){y=Y,x.assign("\0"),ch='.';}//set cell class with Y coordinate.
        void setCell(int Y,string X){y=Y,x.assign(X),ch='.';}//set cell class with Y coordinate and X coordinate.
        void setCell(int Y,string X,char pch){y=Y,x.assign(X),ch=pch;}//set cell class with Y coordinate,X coordinate and character.
        void setCell(char pch){ch=pch;}
        string getCellX()const {return x;}//returns X coordinate.
        int getCellY()const {return y;}//returns Y coordinate.
        char& getCellCh(){return ch;}//returns content of coordinates referance.
        const char getCellCh()const{return ch;}//returns content of coordinates value.
        void input();//input for  cell class.
        void output()const;//output for  cell class.

    private:
       int y;// Y coordinate.
       string x;//X coordinate.
       char ch;//content of Y and Y coordinates.
    };

}

#endif // CELLS_H_INCLUDED
