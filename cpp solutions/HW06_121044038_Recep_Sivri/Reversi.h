//HW06_121044038_Recep_Sivri
//
//  Cells.cpp
//  Created on 10/12/2015
//  Description:
//      Header for Reversi class.
//
#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED

#include"Cells.h"
using namespace std;

namespace HW6
{
    class Reversi
    {
    public:
        Reversi();//no parameter constructor for Reversi class.
        Reversi(int x);//one parameter constructor for Reversi class.
        Reversi(int x,int y);//two parameter constructor for Reversi class.
        Reversi(const Reversi & object);//Copy constructor.
        bool compareGames( const Reversi& other)const;//compares two object of Reversi.Call by Referance parameter function.
        bool compareGamesValue(  Reversi other)const;//compares two object of Reversi.Call by Value parameter function.
        static int returnLivingReversiGames();//returns livingCells.
        int ReadFile(const string FileName);//reads board from file.
        void resizeFunction(int high,int Row);//creates a new board with new sizes.
        void printGameBoard()const;//prints board of game.
        int GetWidth()const{return width;}
        int Gethigh()const{return high;}
        cell* GetGameCells()const{return gameCells;}
        Reversi operator++(int ignore);
        Reversi operator++();
        friend ostream& operator<<(ostream& outputStream,const Reversi& object);
        Reversi& operator=(Reversi& other);
        void playGame();
        void play();//plays for computer.
        int play(int y,string str);//plays for user.
        int ifEndGame()const;//determines if game is end.
        int returnNumberOfX()const;//returns number of X pieces from current Reversi object.
        int returnNumberOfO()const;//returns number of O pieces from current Reversi object.
        ~Reversi();
    private:
        int PlayOneStep(int y,string str2,char playerChar,char targetChar);//plays one step for selected pieces.
        int CountMostElement(int x,int y,char playerChar,char targetChar)const;//counts max number of pieces for user and computer.
        int CheckComputerStatus()const;//controls if computer can plays.
        int CheckPlayerStatus()const;//controls if player can plays.
        void totallivingReversiGame();//count total LivingCells for constructors.
        cell * gameCells;
        static int livingReversiGame;
        int capacity;
        int high;
        int width;
    };
    ostream& operator<<(ostream& outputStream,const Reversi& object);
}
#endif // REVERSI_H_INCLUDED
