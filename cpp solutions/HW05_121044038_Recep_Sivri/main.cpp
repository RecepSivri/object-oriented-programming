//HW05_121044038_Recep_Sivri main file
//
//      Created by Recep Sivri on 24/11/2015.
//  Description:
//      This main file contains Tests of Reversi objects and Cell objects.
#include"HW5.h"

using namespace std;

int main(int argc, char** argv) {

    Cell coor1(1,"ab"),coor2(3,"cd"),coor3(123,"f"),coor4(34,"h"),coor5(89,"df"),value;//Cell object.
    string str;
    int choose,choose2,select1,select2;
    Reversi game(12,14),game2(5),game3(9),game4(12,12),game5;//Reversi object.
    cout<<"-------------Testing Cell objects---------------------"<<endl;//testing for Cells
    do
    {
            cout<<"please select objects:"<<endl;//selecting object comparing and using operator overloads.
            cout<<"1- coor1-coor2"<<endl;
            cout<<"2- coor3-coor4"<<endl;
            cout<<"3- coor1-coor5"<<endl;
            cout<<"4- Testing Reversi objects"<<endl;
            cout<<"5- Quit the program"<<endl;
            cin>>select1;
            switch(select1)
            {
                case 1:
                cout<<"-------testing for >>(stream extraction operator)--------------------"<<endl;
                cout<<"please enter a coor1:"<<endl;
                cin>>coor1;
                cout<<"please enter a coor2:"<<endl;
                cin>>coor2;
                cout<<"-------testing for <<(stream insertion operator)--------------------"<<endl;
                cout<<"coor1:"<<endl;
                cout<<coor1;
                cout<<"coor2:"<<endl;
                cout<<coor2;
                cout<<"------------------testing for ==(equal operator)--------------------"<<endl;
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1==coor2)
                {
                    cout<<"coor1 and coor2 is equal."<<endl;
                }
                else
                {
                    cout<<"coor1 and coor2 is not equal!"<<endl;
                }
                cout<<"------------------testing for !=(not equal operator)-----------------"<<endl;
                coor1.setCell(122,"a");//setting new values.
                coor2.setCell(12,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1!=coor2)
                {
                    cout<<"coor1 and coor2 is not equal!"<<endl;
                }
                else
                {
                    cout<<"coor1 and coor2 is equal."<<endl;
                }
                cout<<"------------------testing for <(less then operator)-----------------"<<endl;
                coor1.setCell(132,"ab");
                coor2.setCell(112,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1<coor2)
                {
                    cout<<"coor1 is less then coor2."<<endl;
                }
                else
                {
                    cout<<"coor1 is not less then coor2!"<<endl;
                }
                cout<<"------------------testing for >(greater then operator)-----------------"<<endl;
                coor1.setCell(12,"at");
                coor2.setCell(12,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1>coor2)//checking operator overloading operators.
                {
                    cout<<"coor1 is greater then coor2."<<endl;
                }
                else
                {
                    cout<<"coor1 is not greater then coor2!"<<endl;
                }
                cout<<"------------------testing for >=(greater then operator)-----------------"<<endl;
                coor1.setCell(13,"ar");
                coor2.setCell(12,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1>=coor2)
                {
                    cout<<"coor1 is greater equal then coor2."<<endl;
                }
                else
                {
                    cout<<"coor1 is not greater equal then coor2!"<<endl;
                }
                cout<<"------------------testing for <=(less then operator)-----------------"<<endl;
                coor1.setCell(12,"ar");
                coor2.setCell(12,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor2:"<<endl<<coor2<<endl;
                if(coor1<=coor2)
                {
                    cout<<"coor1 is less equal then coor2."<<endl;
                }
                else
                {
                    cout<<"coor1 is not less equal then coor2!"<<endl;
                }

                cout<<"------------------testing for ++(pre increment operator)-----------------"<<endl;
                coor1.setCell(12,"a");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before pre incrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of pre increment:\n"<<++coor1<<endl;
                cout<<"after pre incrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for ++(post increment operator)-----------------"<<endl;
                coor1.setCell(12,"a");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before post incrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of post increment:\n"<<coor1++<<endl;
                cout<<"after post incrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for --(pre decrement operator)-----------------"<<endl;
                coor1.setCell(15,"vb");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before pre decrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of pre decrement:\n"<<--coor1<<endl;
                cout<<"after pre decrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for --(post decrement operator)-----------------"<<endl;
                coor1.setCell(56,"xs");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before post decrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of post decrement:\n"<<coor1--<<endl;
                cout<<"after post decrementing:\n"<<coor1<<endl;
                break;
                case 2:
                cout<<"-------testing for >>(stream extraction operator)--------------------"<<endl;
                cout<<"please enter a coor3:"<<endl;
                cin>>coor3;
                cout<<"please enter a coor4:"<<endl;
                cin>>coor4;
                cout<<"-------testing for <<(stream insertion operator)--------------------"<<endl;
                cout<<"coor3:"<<endl;
                cout<<coor3;
                cout<<"coor4:"<<endl;
                cout<<coor4;
                cout<<"------------------testing for ==(equal operator)--------------------"<<endl;
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3==coor4)
                {
                    cout<<"coor3 and coor4 is equal."<<endl;
                }
                else
                {
                    cout<<"coor3 and coor4 is not equal!"<<endl;
                }
                cout<<"------------------testing for !=(not equal operator)-----------------"<<endl;
                coor3.setCell(22,"ad");
                coor4.setCell(12,"as");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3!=coor4)
                {
                    cout<<"coor3 and coor4 is not equal!"<<endl;
                }
                else
                {
                    cout<<"coor3 and coor4 is equal."<<endl;
                }
                cout<<"------------------testing for <(less then operator)-----------------"<<endl;
                coor3.setCell(12,"a");
                coor4.setCell(112,"as");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3<coor4)
                {
                    cout<<"coor3 is less then coor4."<<endl;
                }
                else
                {
                    cout<<"coor3 is not less then coor4!"<<endl;
                }
                cout<<"------------------testing for >(greater then operator)-----------------"<<endl;
                coor3.setCell(42,"ae");
                coor4.setCell(68,"ys");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3>coor4)
                {
                    cout<<"coor3 is greater then coor4."<<endl;
                }
                else
                {
                    cout<<"coor3 is not greater then coor4!"<<endl;
                }
                cout<<"------------------testing for >=(greater then operator)-----------------"<<endl;
                coor3.setCell(133,"jr");
                coor4.setCell(102,"al");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3>=coor4)
                {
                    cout<<"coor3 is greater equal then coor4."<<endl;
                }
                else
                {
                    cout<<"coor3 is not greater equal then coor4!"<<endl;
                }
                cout<<"------------------testing for <=(less then operator)-----------------"<<endl;
                coor3.setCell(16,"ay");
                coor4.setCell(52,"rs");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"coor4:"<<endl<<coor4<<endl;
                if(coor3<=coor4)
                {
                    cout<<"coor3 is less equal then coor4."<<endl;
                }
                else
                {
                    cout<<"coor3 is not less equal then coor4!"<<endl;
                }

                cout<<"------------------testing for ++(pre increment operator)-----------------"<<endl;
                coor3.setCell(76,"bh");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"before pre incrementing:\n"<<coor3<<endl;
                cout<<"return coor3 of pre increment:\n"<<++coor3<<endl;
                cout<<"after pre incrementing:\n"<<coor3<<endl;

                cout<<"------------------testing for ++(post increment operator)-----------------"<<endl;
                coor3.setCell(178,"ag");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"before post incrementing:\n"<<coor3<<endl;
                cout<<"return coor3 of post increment:\n"<<coor3++<<endl;
                cout<<"after post incrementing:\n"<<coor3<<endl;

                cout<<"------------------testing for --(pre decrement operator)-----------------"<<endl;
                coor3.setCell(181,"gh");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"before pre decrementing:\n"<<coor3<<endl;
                cout<<"return coor3 of pre decrement:\n"<<--coor3<<endl;
                cout<<"after pre decrementing:\n"<<coor3<<endl;

                cout<<"------------------testing for --(post decrement operator)-----------------"<<endl;
                coor3.setCell(87,"lr");
                cout<<"coor3:"<<endl<<coor3<<endl;
                cout<<"before post decrementing:\n"<<coor3<<endl;
                cout<<"return coor3 of post decrement:\n"<<coor3--<<endl;
                cout<<"after post decrementing:\n"<<coor3<<endl;
                break;
                case 3:
                cout<<"-------testing for >>(stream extraction operator)--------------------"<<endl;
                cout<<"please enter a coor1:"<<endl;
                cin>>coor1;
                cout<<"please enter a coor5:"<<endl;
                cin>>coor5;
                cout<<"-------testing for <<(stream insertion operator)--------------------"<<endl;
                cout<<"coor1:"<<endl;
                cout<<coor1;
                cout<<"coor5:"<<endl;
                cout<<coor5;
                cout<<"------------------testing for ==(equal operator)--------------------"<<endl;
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1==coor5)
                {
                    cout<<"coor1 and coor5 is equal."<<endl;
                }
                else
                {
                    cout<<"coor1 and coor5 is not equal!"<<endl;
                }
                cout<<"------------------testing for !=(not equal operator)-----------------"<<endl;
                coor1.setCell(2,"mh");
                coor5.setCell(12,"ns");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1!=coor5)
                {
                    cout<<"coor1 and coor5 is not equal!"<<endl;
                }
                else
                {
                    cout<<"coor1 and coor5 is equal."<<endl;
                }
                cout<<"------------------testing for <(less then operator)-----------------"<<endl;
                coor1.setCell(162,"at");
                coor5.setCell(12,"as");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1<coor5)
                {
                    cout<<"coor1 is less then coor5."<<endl;
                }
                else
                {
                    cout<<"coor1 is not less then coor5!"<<endl;
                }
                cout<<"------------------testing for >(greater then operator)-----------------"<<endl;
                coor1.setCell(12,"a");
                coor5.setCell(85,"s");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1>coor5)
                {
                    cout<<"coor1 is greater then coor5."<<endl;
                }
                else
                {
                    cout<<"coor1 is not greater then coor5!"<<endl;
                }
                cout<<"------------------testing for >=(greater then operator)-----------------"<<endl;
                coor1.setCell(13,"tr");
                coor5.setCell(122,"yl");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1>=coor5)
                {
                    cout<<"coor1 is greater equal then coor5."<<endl;
                }
                else
                {
                    cout<<"coor1 is not greater equal then coor5!"<<endl;
                }
                cout<<"------------------testing for <=(less then operator)-----------------"<<endl;
                coor1.setCell(6,"ag");
                coor5.setCell(2,"s");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"coor5:"<<endl<<coor5<<endl;
                if(coor1<=coor5)
                {
                    cout<<"coor1 is less equal then coor5."<<endl;
                }
                else
                {
                    cout<<"coor1 is not less equal then coor5!"<<endl;
                }

                cout<<"------------------testing for ++(pre increment operator)-----------------"<<endl;
                coor1.setCell(7,"b");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before pre incrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of pre increment:\n"<<++coor1<<endl;
                cout<<"after pre incrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for ++(post increment operator)-----------------"<<endl;
                coor1.setCell(18,"g");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before post incrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of post increment:\n"<<coor1++<<endl;
                cout<<"after post incrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for --(pre decrement operator)-----------------"<<endl;
                coor1.setCell(11,"h");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before pre decrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of pre decrement:\n"<<--coor1<<endl;
                cout<<"after pre decrementing:\n"<<coor1<<endl;

                cout<<"------------------testing for --(post decrement operator)-----------------"<<endl;
                coor1.setCell(8,"r");
                cout<<"coor1:"<<endl<<coor1<<endl;
                cout<<"before post decrementing:\n"<<coor1<<endl;
                cout<<"return coor1 of post decrement:\n"<<coor1--<<endl;
                cout<<"after post decrementing:\n"<<coor1<<endl;
                break;
                case 4:
                    select1=4;
                break;
                case 5:
                    return 0;
                break;
            }


        }while(select1!=4);
    cout<<"---------------Testing Reversi Objects and functions------------"<<endl;//testing for Reversi Objects.
    do
    {
        cout<<"please choose games:"<<endl;//chooses.
        cout<<"1-game1"<<endl;
        cout<<"2-game2"<<endl;
        cout<<"3-game3"<<endl;
        cout<<"4-game4"<<endl;
        cout<<"5-game5"<<endl;
        cout<<"6-quit"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
            do
            {
                cout<<"please enter operations for game1:"<<endl;//chooses for operations
                cout<<"1-testing for <<(stream insertion operator)"<<endl;
                cout<<"2-testing for ++(pre increment operator)"<<endl;
                cout<<"3-testing for ++(post increment operator)"<<endl;
                cout<<"4-testing for +=(Add AND assignment)"<<endl;
                cout<<"5-testing for --(pre decrement operator)"<<endl;
                cout<<"6-testing for --(post decrement operator)"<<endl;
                cout<<"7-testing for [](index operator)"<<endl;
                cout<<"8-testing for ()(function call  operator)"<<endl;
                cout<<"9-Exit testing game1"<<endl;
                cin>>choose2;
                switch(choose2)//switches.
                {
                    case 1:cout<<"-------testing for Reversi <<(stream insertion operator)--------------------"<<endl;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 2:cout<<"---------testing for Reversi ++(pre increment operator)---------------------"<<endl;
                    cout<<"returning value of pre increment operator:"<<endl;
                    cout<<++game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre incrementing:"<<endl;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 3:cout<<"---------testing for Reversi ++(post increment operator)---------------------"<<endl;
                    cout<<"returning value of post increment operator:"<<endl;
                    cout<<game++;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post incrementing:"<<endl;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 4:
                    cout<<"---------testing for Reversi +=(Add AND assignment)---------------------"<<endl;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"please enter a coordinate:"<<endl;
                    cin>>value;
                    game+=value;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 5:
                    cout<<"---------testing for Reversi --(pre decrement operator)---------------------"<<endl;
                    cout<<"returning value of pre decrement operator:"<<endl;
                    cout<<--game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre decrementing:"<<endl;
                    cout<<game;
                    break;
                    case 6:
                    cout<<"---------testing for Reversi --(post decrement operator)---------------------"<<endl;
                    cout<<"returning value of post decrement operator:"<<endl;
                    cout<<game--;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post decrementing:"<<endl;
                    cout<<game;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 7:
                    cout<<"---------testing for Reversi operator[] ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game[str];
                    cout<<value;
                    break;
                    case 8:
                    cout<<"---------testing for Reversi operator() ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game(str);
                    cout<<value;
                    break;
                }
            }while(choose2!=9);
            break;
            case 2:
            do
            {
                cout<<"please enter operations for game2:"<<endl;
                cout<<"1-testing for <<(stream insertion operator)"<<endl;
                cout<<"2-testing for ++(pre increment operator)"<<endl;
                cout<<"3-testing for ++(post increment operator)"<<endl;
                cout<<"4-testing for +=(Add AND assignment)"<<endl;
                cout<<"5-testing for --(pre decrement operator)"<<endl;
                cout<<"6-testing for --(post decrement operator)"<<endl;
                cout<<"7-testing for [](index operator)"<<endl;
                cout<<"8-testing for ()(function call  operator)"<<endl;
                cout<<"9-Exit testing game1"<<endl;
                cin>>choose2;
                switch(choose2)
                {
                    case 1:cout<<"-------testing for Reversi <<(stream insertion operator)--------------------"<<endl;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 2:cout<<"---------testing for Reversi ++(pre increment operator)---------------------"<<endl;
                    cout<<"returning value of pre increment operator:"<<endl;
                    cout<<++game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre incrementing:"<<endl;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 3:cout<<"---------testing for Reversi ++(post increment operator)---------------------"<<endl;
                    cout<<"returning value of post increment operator:"<<endl;
                    cout<<game2++;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post incrementing:"<<endl;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 4:
                    cout<<"---------testing for Reversi +=(Add AND assignment)---------------------"<<endl;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"please enter a coordinate:"<<endl;
                    cin>>value;
                    game2+=value;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 5:
                    cout<<"---------testing for Reversi --(pre decrement operator)---------------------"<<endl;
                    cout<<"returning value of pre decrement operator:"<<endl;
                    cout<<--game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre decrementing:"<<endl;
                    cout<<game2;
                    break;
                    case 6:
                    cout<<"---------testing for Reversi --(post decrement operator)---------------------"<<endl;
                    cout<<"returning value of post decrement operator:"<<endl;
                    cout<<game2--;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post decrementing:"<<endl;
                    cout<<game2;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 7:
                    cout<<"---------testing for Reversi operator[] ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game2[str];
                    cout<<value;
                    break;
                    case 8:
                    cout<<"---------testing for Reversi operator() ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game2(str);
                    cout<<value;
                    break;
                }
            }while(choose2!=9);
            break;
            case 3:
            do
            {
                cout<<"please enter operations for game3:"<<endl;
                cout<<"1-testing for <<(stream insertion operator)"<<endl;
                cout<<"2-testing for ++(pre increment operator)"<<endl;
                cout<<"3-testing for ++(post increment operator)"<<endl;
                cout<<"4-testing for +=(Add AND assignment)"<<endl;
                cout<<"5-testing for --(pre decrement operator)"<<endl;
                cout<<"6-testing for --(post decrement operator)"<<endl;
                cout<<"7-testing for [](index operator)"<<endl;
                cout<<"8-testing for ()(function call  operator)"<<endl;
                cout<<"9-Exit testing game1"<<endl;
                cin>>choose2;
                switch(choose2)
                {
                    case 1:cout<<"-------testing for Reversi <<(stream insertion operator)--------------------"<<endl;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 2:cout<<"---------testing for Reversi ++(pre increment operator)---------------------"<<endl;
                    cout<<"returning value of pre increment operator:"<<endl;
                    cout<<++game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre incrementing:"<<endl;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 3:cout<<"---------testing for Reversi ++(post increment operator)---------------------"<<endl;
                    cout<<"returning value of post increment operator:"<<endl;
                    cout<<game3++;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post incrementing:"<<endl;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 4:
                    cout<<"---------testing for Reversi +=(Add AND assignment)---------------------"<<endl;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"please enter a coordinate:"<<endl;
                    cin>>value;
                    game3+=value;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 5:
                    cout<<"---------testing for Reversi --(pre decrement operator)---------------------"<<endl;
                    cout<<"returning value of pre decrement operator:"<<endl;
                    cout<<--game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre decrementing:"<<endl;
                    cout<<game3;
                    break;
                    case 6:
                    cout<<"---------testing for Reversi --(post decrement operator)---------------------"<<endl;
                    cout<<"returning value of post decrement operator:"<<endl;
                    cout<<game3--;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post decrementing:"<<endl;
                    cout<<game3;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 7:
                    cout<<"---------testing for Reversi operator[] ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game3[str];
                    cout<<value;
                    break;
                    case 8:
                    cout<<"---------testing for Reversi operator() ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game3(str);
                    cout<<value;
                    break;
                }
            }while(choose2!=9);
            break;
            case 4:
            do
            {
                cout<<"please enter operations for game4:"<<endl;
                cout<<"1-testing for <<(stream insertion operator)"<<endl;
                cout<<"2-testing for ++(pre increment operator)"<<endl;
                cout<<"3-testing for ++(post increment operator)"<<endl;
                cout<<"4-testing for +=(Add AND assignment)"<<endl;
                cout<<"5-testing for --(pre decrement operator)"<<endl;
                cout<<"6-testing for --(post decrement operator)"<<endl;
                cout<<"7-testing for [](index operator)"<<endl;
                cout<<"8-testing for ()(function call  operator)"<<endl;
                cout<<"9-Exit testing game1"<<endl;
                cin>>choose2;
                switch(choose2)
                {
                    case 1:cout<<"-------testing for Reversi <<(stream insertion operator)--------------------"<<endl;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 2:cout<<"---------testing for Reversi ++(pre increment operator)---------------------"<<endl;
                    cout<<"returning value of pre increment operator:"<<endl;
                    cout<<++game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre incrementing:"<<endl;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 3:cout<<"---------testing for Reversi ++(post increment operator)---------------------"<<endl;
                    cout<<"returning value of post increment operator:"<<endl;
                    cout<<game4++;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post incrementing:"<<endl;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 4:
                    cout<<"---------testing for Reversi +=(Add AND assignment)---------------------"<<endl;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"please enter a coordinate:"<<endl;
                    cin>>value;
                    game4+=value;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 5:
                    cout<<"---------testing for Reversi --(pre decrement operator)---------------------"<<endl;
                    cout<<"returning value of pre decrement operator:"<<endl;
                    cout<<--game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre decrementing:"<<endl;
                    cout<<game4;
                    break;
                    case 6:
                    cout<<"---------testing for Reversi --(post decrement operator)---------------------"<<endl;
                    cout<<"returning value of post decrement operator:"<<endl;
                    cout<<game4--;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post decrementing:"<<endl;
                    cout<<game4;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 7:
                    cout<<"---------testing for Reversi operator[] ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game4[str];
                    cout<<value;
                    break;
                    case 8:
                    cout<<"---------testing for Reversi operator() ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game4(str);
                    cout<<value;
                    break;
                }
            }while(choose2!=9);
            break;
            case 5:
            do
            {
                cout<<"please enter operations for game5:"<<endl;
                cout<<"1-testing for <<(stream insertion operator)"<<endl;
                cout<<"2-testing for ++(pre increment operator)"<<endl;
                cout<<"3-testing for ++(post increment operator)"<<endl;
                cout<<"4-testing for +=(Add AND assignment)"<<endl;
                cout<<"5-testing for --(pre decrement operator)"<<endl;
                cout<<"6-testing for --(post decrement operator)"<<endl;
                cout<<"7-testing for [](index operator)"<<endl;
                cout<<"8-testing for ()(function call  operator)"<<endl;
                cout<<"9-Exit testing game1"<<endl;
                cin>>choose2;
                switch(choose2)
                {
                    case 1:cout<<"-------testing for Reversi <<(stream insertion operator)--------------------"<<endl;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 2:cout<<"---------testing for Reversi ++(pre increment operator)---------------------"<<endl;
                    cout<<"returning value of pre increment operator:"<<endl;
                    cout<<++game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre incrementing:"<<endl;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 3:cout<<"---------testing for Reversi ++(post increment operator)---------------------"<<endl;
                    cout<<"returning value of post increment operator:"<<endl;
                    cout<<game5++;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post incrementing:"<<endl;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 4:
                    cout<<"---------testing for Reversi +=(Add AND assignment)---------------------"<<endl;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"please enter a coordinate:"<<endl;
                    cin>>value;
                    game5+=value;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 5:
                    cout<<"---------testing for Reversi --(pre decrement operator)---------------------"<<endl;
                    cout<<"returning value of pre decrement operator:"<<endl;
                    cout<<--game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after pre decrementing:"<<endl;
                    cout<<game5;
                    break;
                    case 6:
                    cout<<"---------testing for Reversi --(post decrement operator)---------------------"<<endl;
                    cout<<"returning value of post decrement operator:"<<endl;
                    cout<<game5--;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    cout<<"after post decrementing:"<<endl;
                    cout<<game5;
                    cout<<"number of livincells:"<<Reversi::getLivngCells()<<endl;
                    break;
                    case 7:
                    cout<<"---------testing for Reversi operator[] ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game5[str];
                    cout<<value;
                    break;
                    case 8:
                    cout<<"---------testing for Reversi operator() ---------------------"<<endl;
                    cout<<"please enter a coordinate :"<<endl;
                    cin>>str;
                    cout<<"result:"<<endl;
                    value=game5(str);
                    cout<<value;
                    break;
                }
            }while(choose2!=9);//quits program.
            break;

        }
    }while(choose!=6);//exits object.5
    
    return 0;
}

