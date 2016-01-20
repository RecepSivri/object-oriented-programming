//HW05_121044038_Recep_Sivri.h
//
//      Created by Recep Sivri on 24/11/2015.
//  Description:
//      This header file includes Reversi and Cell classes and this clases includes some operator overloaded
//      functions.

#ifndef HW5_H
#define	HW5_H

#include <iostream>
#include<vector>
#include <string>
#include<cmath>
class Cell
{
public:
    Cell():y(0),x("\0"),ch('.'){}//no parameter constructor.
    Cell(int Y):y(Y),x("\0"),ch('.'){}// one parameter constructor.
    Cell(int Y,std::string X):y(Y),x("\0"),ch('.'){}//two parameter constructor.
    Cell(int Y,std::string X,char pch):y(Y),x(X),ch(pch){}//three parameter constructor.
    void setCell(){y=0,x.assign("\0"),ch='.';}//setter no parameter.
    void setCell(int Y){y=Y,x.assign("\0"),ch='.';}//setter one parameter.
    void setCell(int Y,std::string X){y=Y,x.assign(X),ch='.';}//setter two parameter.
    void setCell(int Y,std::string X,char pch){y=Y,x.assign(X),ch=pch;}//setter three parameter.
    std::string getCellX()const {return x;}//getter for  X coordinate.
    int getCellY()const {return y;}//getter for Y coordinate.
    char& getCellCh(){return ch;}//getter for content of cell (return referance of content).
    const char getCellCh()const{return ch;}//getter for value of content of cell.
    bool operator>(const Cell& other)const;// operator > returns true if left argument of > greater then right.
    bool operator<(const Cell& other)const;//operator < returns true if left argument of > less then right.
    bool operator>=(const Cell& other)const;// operator > returns true if left argument of > greater then right or equal.
    bool operator<=(const Cell& other)const;//operator < returns true if left argument of > less then right or equal.
    bool operator==(const Cell& other)const;//operator < returns true if arguments are equal.
    bool operator!=(const Cell& other)const;//operator < returns true if arguments are not equal.
    Cell operator++();// increments x and y coordinate by one.
    Cell operator++(int);// increments x and y coordinate by one.
    Cell operator--();// decrements x and y coordinate by one.
    Cell operator--(int);// decrements x and y coordinate by one.
    friend std::istream& operator>>(std::istream& input,Cell& object);//read Cell objects from user
    friend std::ostream& operator<<(std::ostream& input,const Cell& object);//prints Cell objects to screen.
    void input();//input.
    void output()const;//output.

private:
   int y;// y coordinate.
   std::string x;//x coordinate.
   char ch;// content of coordinate.
};

class Reversi
{
public:

    Reversi();//no parameter constructor.
    Reversi(int x);//one parameter constructor.
    Reversi(int x,int y);// two parameter constructor.
    Reversi(std::vector< std::vector<Cell> > gameCells2);//constructor for return value.
    Reversi operator++();//plays game one step for computer.
    Reversi operator++(int);//plays game one step for computer.
    Reversi operator--();//increments game one step.
    Reversi operator--(int);//increments game one step.
    Reversi operator+=(Cell coordinate);//plays game one step for user.
    int CheckComputerStatus()const;//computer computer status.
    void totalLivingCellsConstractor();//counts living cell for constructor.
    int PlayOneStep(int y,std::string str,char playerChar,char targetChar);//plays one step.
    int CountMostElement(int x,int y,char playerPiece,char targetPiece)const;//counts most pieces to take.
    int CheckPlayerStatus()const;//controls player status.
    Cell operator[](std::string coordinate);//indexing operator.
    Cell operator()(std::string coordinate);//function call operator.
    static int getLivngCells(){return livingCells;}//return livingcells
private:
    friend std::ostream& operator<<(std::ostream& outputStream,const Reversi& game);//prints game.
    std::vector< std::vector<Cell> > gameCells;//two dimensional board size.
    static int livingCells;//livingCells.
    std::vector<int> OldCells;//before game's livingCells.
    std::vector<std::vector< std::vector<Cell> > > games;//three dimensional vector for before game.
};

#endif	/* HW5_H */

