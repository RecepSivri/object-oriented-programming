//HW06_121044038_Recep_Sivri
//
//  main.cpp
//  Created on 10/12/2015
//  Description:
//      in this homework I write a Reversi game using object oriented techniques,
//      in this homework a lot of games can live and using dynamic arrays.
//
#include"Cells.h"
#include"Reversi.h"
using namespace std;
using namespace HW6;//namespace for this homework.
int main()
{
    Reversi game1,game2(15),game3(8),game4(9,5),game5(12,11);//objects for testing functions.
    cell coor1(5),coor2(5,"a");
    int choose2,coory,choose3=0,choose4=0,choose5=0,choose6=0,choose7=0,choose8=0,choose9=0,choose10=0;//choices for switch.
    string str;
    cout<<"----------please choose a element in list for test:---------"<<endl;
    while(choose6 != 10)//Testing functions and objects.
    {
        cout<<"1 -testing game1"<<endl;
        cout<<"2 -testing game2"<<endl;
        cout<<"3 -testing game3"<<endl;
        cout<<"4 -testing game4"<<endl;
        cout<<"5 -testing game5"<<endl;
        cout<<"6 -testing cell1"<<endl;
        cout<<"7 -testing operator="<<endl;
        cout<<"8 -testing copy constructor"<<endl;
        cout<<"9 -testing  number of living Reversi games"<<endl;
        cout<<"10-Quit"<<endl;
        cin>>choose6;
        switch(choose6)//switches.
        {
            case 1:
            while(choose2!=9)
            {
                cout<<"     1-test operator<< for game1"<<endl;
                cout<<"     2-test operator++(pre increment) for game1"<<endl;
                cout<<"     3-test operator++(post increment) for game1"<<endl;
                cout<<"     4-test playGame function for game1"<<endl;
                cout<<"     5-test compareGames game1-game2"<<endl;
                cout<<"     6-test compareGames game1-game3"<<endl;
                cout<<"     7-test compareGames game1-game4"<<endl;
                cout<<"     8-test compareGames game1-game5"<<endl;
                cout<<"     9-Exit"<<endl;
                cin>>choose2;
                switch(choose2)
                {
                    case 1:cout<<game1;
                    break;
                    case 2:cout<<"test for operator++(pre increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<++game1;
                            cout<<"result this:"<<endl;
                            cout<<game1;
                    break;
                    case 3:cout<<"test for operator++(post increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<game1++;
                            cout<<"result this:"<<endl;
                            cout<<game1;
                    break;
                    case 4:game1.playGame();
                    break;
                    case 5:cout<<game1.compareGames(game2)<<endl;
                    break;
                    case 6:cout<<game1.compareGames(game3)<<endl;
                    break;
                    case 7:cout<<game1.compareGames(game4)<<endl;
                    break;
                    case 8:cout<<game1.compareGames(game5)<<endl;
                    break;
                }
            }
            choose2=0;
            break;
            case 2:
            while(choose7!=9)
            {
                cout<<"     1-test operator<< for game2"<<endl;
                cout<<"     2-test operator++(pre increment) for game2"<<endl;
                cout<<"     3-test operator++(post increment) for game2"<<endl;
                cout<<"     4-test playGame function for game2"<<endl;
                cout<<"     5-test compareGames game2-game1"<<endl;
                cout<<"     6-test compareGames game2-game3"<<endl;
                cout<<"     7-test compareGames game2-game4"<<endl;
                cout<<"     8-test compareGames game2-game5"<<endl;
                cout<<"     9-Exit"<<endl;
                cin>>choose7;
                switch(choose7)
                {
                    case 1:cout<<game2;
                    break;
                    case 2:cout<<"test for operator++(pre increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<++game2;
                            cout<<"result this:"<<endl;
                            cout<<game2;
                    break;
                    case 3:cout<<"test for operator++(post increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<game2++;
                            cout<<"result this:"<<endl;
                            cout<<game2;
                    break;
                    case 4:game2.playGame();
                    break;
                    case 5:cout<<game2.compareGames(game1)<<endl;
                    break;
                    case 6:cout<<game2.compareGames(game3)<<endl;
                    break;
                    case 7:cout<<game2.compareGames(game4)<<endl;
                    break;
                    case 8:cout<<game2.compareGames(game5)<<endl;
                    break;
                }
            }
            choose7=0;
            break;
            case 3:
            while(choose8!=9)
            {
                cout<<"     1-test operator<< for game3"<<endl;
                cout<<"     2-test operator++(pre increment) for game3"<<endl;
                cout<<"     3-test operator++(post increment) for game3"<<endl;
                cout<<"     4-test playGame function for game3"<<endl;
                cout<<"     5-test compareGames game3-game1"<<endl;
                cout<<"     6-test compareGames game3-game2"<<endl;
                cout<<"     7-test compareGames game3-game4"<<endl;
                cout<<"     8-test compareGames game3-game5"<<endl;
                cout<<"     9-Exit"<<endl;
                cin>>choose8;
                switch(choose8)
                {
                    case 1:cout<<game3;
                    break;
                    case 2:cout<<"test for operator++(pre increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<++game3;
                            cout<<"result this:"<<endl;
                            cout<<game3;
                    break;
                    case 3:cout<<"test for operator++(post increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<game3++;
                            cout<<"result this:"<<endl;
                            cout<<game3;
                    break;
                    case 4:game3.playGame();
                    break;
                    case 5:cout<<game3.compareGames(game1)<<endl;
                    break;
                    case 6:cout<<game3.compareGames(game2)<<endl;
                    break;
                    case 7:cout<<game3.compareGames(game4)<<endl;
                    break;
                    case 8:cout<<game3.compareGames(game5)<<endl;
                    break;
                }
            }
            choose8=0;
            break;
            case 4:
            while(choose9!=9)
            {
                cout<<"     1-test operator<< for game4"<<endl;
                cout<<"     2-test operator++(pre increment) for game4"<<endl;
                cout<<"     3-test operator++(post increment) for game4"<<endl;
                cout<<"     4-test playGame function for game4"<<endl;
                cout<<"     5-test compareGames game4-game1"<<endl;
                cout<<"     6-test compareGames game4-game2"<<endl;
                cout<<"     7-test compareGames game4-game3"<<endl;
                cout<<"     8-test compareGames game4-game5"<<endl;
                cout<<"     9-Exit"<<endl;
                cin>>choose9;
                switch(choose9)
                {
                    case 1:cout<<game4;
                    break;
                    case 2:cout<<"test for operator++(pre increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<++game4;
                            cout<<"result this:"<<endl;
                            cout<<game4;
                    break;
                    case 3:cout<<"test for operator++(post increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<game4++;
                            cout<<"result this:"<<endl;
                            cout<<game4;
                    break;
                    case 4:game4.playGame();
                    break;
                    case 5:cout<<game4.compareGames(game1)<<endl;
                    break;
                    case 6:cout<<game4.compareGames(game2)<<endl;
                    break;
                    case 7:cout<<game4.compareGames(game3)<<endl;
                    break;
                    case 8:cout<<game4.compareGames(game5)<<endl;
                    break;
                }
            }
            choose9=0;
            break;
            case 5:
            while(choose10!=9)
            {
                cout<<"     1-test operator<< for game5"<<endl;
                cout<<"     2-test operator++(pre increment) for game5"<<endl;
                cout<<"     3-test operator++(post increment) for game5"<<endl;
                cout<<"     4-test playGame function for game5"<<endl;
                cout<<"     5-test compareGames game5-game1"<<endl;
                cout<<"     6-test compareGames game5-game2"<<endl;
                cout<<"     7-test compareGames game5-game3"<<endl;
                cout<<"     8-test compareGames game5-game4"<<endl;
                cout<<"     9-Exit"<<endl;
                cin>>choose10;
                switch(choose10)
                {
                    case 1:cout<<game5;
                    break;
                    case 2:cout<<"test for operator++(pre increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<++game5;
                            cout<<"result this:"<<endl;
                            cout<<game5;
                    break;
                    case 3:cout<<"test for operator++(post increment):"<<endl;
                            cout<<"returning this:"<<endl;
                            cout<<game5++;
                            cout<<"result this:"<<endl;
                            cout<<game5;
                    break;
                    case 4:game5.playGame();
                    break;
                    case 5:cout<<game5.compareGames(game1)<<endl;
                    break;
                    case 6:cout<<game5.compareGames(game2)<<endl;
                    break;
                    case 7:cout<<game5.compareGames(game3)<<endl;
                    break;
                    case 8:cout<<game5.compareGames(game4)<<endl;
                    break;
                }
            }
            choose10=0;
            break;
            case 6:
            while(choose3 != 3)
            {
                cout<<"     1- Testing setter for cell object."<<endl;
                cout<<"     2- Testing output for cell object."<<endl;
                cout<<"     3- Exit."<<endl;
                cin>>choose3;
                switch(choose3)
                {
                       case 1:
                       cout<<"please enter a coordinate:"<<endl;
                        cin>>coory>>str;
                       coor1.setCell(coory,str);
                       break;
                       case 2:
                        coor1.output();
                       break;
                }
            }
            choose3=0;
            break;
            case 7:
            while(choose4 != 6)
            {
                cout<<"     1 -game1=game2"<<endl;
                cout<<"     2 -game1=game3"<<endl;
                cout<<"     3 -game1=game4"<<endl;
                cout<<"     4 -game1=game5"<<endl;
                cout<<"     5 -game2=game3"<<endl;
                cout<<"     6 -Exit"<<endl;
                cin>>choose4;
                switch(choose4)
                {
                    case 1:
                    cout<<"before assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    game1=game2;
                    cout<<"after assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    break;
                    case 2:
                    cout<<"before assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    game1=game3;
                    cout<<"after assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    break;
                    case 3:
                    cout<<"before assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    game1=game4;
                    cout<<"after assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    break;
                    case 4:
                    cout<<"before assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    game1=game5;
                    cout<<"after assignment"<<endl;
                    cout<<"game1:"<<endl;
                    cout<<game1;
                    break;
                    case 5:
                    cout<<"before assignment"<<endl;
                    cout<<"game2:"<<endl;
                    cout<<game2;
                    game2=game3;
                    cout<<"after assignment"<<endl;
                    cout<<"game2:"<<endl;
                    cout<<game2;
                    break;
                }
            }
            choose4=0;
            break;
            case 8:
            while(choose5!=3)
            {
                cout<<"     1- testing Copy constructor for Call by value."<<endl;
                cout<<"     2- testing Copy constructor for Call by referance."<<endl;
                cout<<"     3-Exit."<<endl;
                cin>>choose5;
                switch(choose5)
                {
                    case 1:
                    cout<<"compares game1 and game2 with compareGames call by value."<<endl;
                       cout<<"result:"<<game1.compareGamesValue(game2)<<endl;
                    break;
                    case 2:
                    cout<<"compares game1 and game2 with compareGames call by referance."<<endl;
                       cout<<"result:"<<game1.compareGames(game2)<<endl;
                    break;
                }
            }
            choose5=0;
            break;
            case 9:
                  cout<<"number of living Reversi Games:"<<Reversi::returnLivingReversiGames()<<endl;
            break;
        }
    }

}
