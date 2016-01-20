//HW06_121044038_Recep_Sivri
//
//  Cells.cpp
//  Created on 10/12/2015
//  Description:
//      Implementations for Cell class.
//

#include"Cells.h"
#include"Reversi.h"
namespace HW6
{

    void cell::output()const// output for Cell class.
    {
        cout<<"X coordinate:"<<x<<endl;
        cout<<"Y coordinate:"<<y<<endl;
        cout<<"piece of X and Y coordinate:"<<ch<<endl;
    }
    void cell::input()// input for Cell class.
    {
        cout<<"please enter a x coordinate:";
        cin>>x;
        cout<<"please enter a y coordinate:";
        cin>>y;
        cout<<"please enter a piece:";
        cin>>ch;
    }
}
