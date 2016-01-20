//HW06_121044038_Recep_Sivri
//
//  Reversi.cpp
//  Created on 10/12/2015
//  Description:
//    Implementation file for Reversi Class.
//


#include"Cells.h"
#include"Reversi.h"
namespace HW6// namespace for this homework.
{
    int Reversi::livingReversiGame=0;// initial livingReversiGame.
    Reversi::Reversi()//default constructor
    {
        string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int i,j=0,k=0,temp=0,l,m=-1,n=0;
        high=4;
        width=4;
        capacity=16;
        gameCells= new cell[capacity];
        for(i=0;i<4*4;++i)
        {
                k=i%4;
                if(k==0)
                {
                    m=m+1;
                }

                if(temp<m)
                {
                    n=m;
                }
                temp=m;
                if(n==1&j==1)
                    gameCells[i].setCell(n,str[j],'O');
                else
                if(n==1&j==2)
                    gameCells[i].setCell(n,str[j],'X');
                else
                if(n==2&j==1)
                    gameCells[i].setCell(n,str[j],'X');
                else
                if(n==2&j==2)
                    gameCells[i].setCell(n,str[j],'O');
                else
                    gameCells[i].setCell(n,str[j]);
                ++j;
                if(j==4)
                    j=0;
        }
        totallivingReversiGame();
    }
    Reversi::Reversi(int x) //one parameter constructor.
    {
        string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string str2;
        int i,j=0,k=0,temp=0,l,m=-1,n=0,a,r;
        l=0;
        high=x;
        width=x;
        capacity=x*x;
        gameCells= new cell[capacity];
        for(i=0;i<capacity;++i)
        {
                k=i%x;
                if(k==0)
                {
                    m=m+1;
                }

                if(temp<m)
                {
                    n=m;
                }
                temp=m;
                if(j<52)
                    str2=str[j];//if i less then size of str, str2 contains one element.
                else
                    str2=str[j%52]+str[j/52-1];
                if(n==high/2-1&j==width/2-1)
                    gameCells[i].setCell(n,str2,'O');
                else
                if(n==high/2-1&j==width/2)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2-1)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2)
                    gameCells[i].setCell(n,str2,'O');
                else
                    gameCells[i].setCell(n,str2);
                ++j;
                if(j==width)
                    j=0;
        }
        totallivingReversiGame();
    }
    Reversi::Reversi(int x,int y):high(x),width(y),capacity(x*y)//two parameter constructor.
    {
        string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int i,j=0,k=0,temp=0,l,m=-1,n=0;
        string str2;
        high=x;
        width=y;
        capacity=x*y;
        gameCells= new cell[capacity];
        for(i=0;i<capacity;++i)
        {
                k=i%width;
                if(k==0)
                {
                    m=m+1;
                }

                if(temp<m)
                {
                    n=m;
                }
                temp=m;
                if(j<52)
                    str2=str[j];//if i less then size of str, str2 contains one element.
                else
                    str2=str[j%52]+str[j/52-1];
                if(n==high/2-1&j==width/2-1)
                    gameCells[i].setCell(n,str2,'O');
                else
                if(n==high/2-1&j==width/2)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2-1)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2)
                    gameCells[i].setCell(n,str2,'O');
                else
                    gameCells[i].setCell(n,str2);
                ++j;
                if(j==width)
                    j=0;
        }
        totallivingReversiGame();
    }
    Reversi:: Reversi( const Reversi & object):high(object.high),width(object.width),capacity(object.width*object.high)//copy constructor.
    {
        cout<<"uses copy construcor!"<<endl;
        totallivingReversiGame();
        int i;
        gameCells= new cell[capacity];
        for(i=0;i<capacity;++i)
            gameCells[i]=object.gameCells[i];
    }
    void Reversi::printGameBoard()const//printing board.
    {
        int i,j,k=0,l=0,digit,m=0,n=0,temp=0,s,y=0,h;
        digit=high;
        digit=digit/10;//for two digital numbers.
        while(digit>10)
        {
            ++y;
            digit=digit/10;
        }
        ++y;
        for(i=0;i<capacity;++i)//prints board to screen.
        {
                if(i==0)
                {
                    for(h=0;h<y+2;++h)
                        cout<<" ";
                    if(width>52)
                    {
                        for(j=0;j<width;++j)
                        {   if(gameCells[j+1].getCellX().size()==1)
                                cout<<gameCells[j].getCellX()<<"  ";
                            else
                            if(gameCells[j+1].getCellX().size()==2)
                                cout<<gameCells[j].getCellX()<<" ";
                        }
                        cout<<endl;
                    }
                    else
                    {
                        for(j=0;j<width;++j)
                        {
                            cout<<gameCells[j].getCellX()<<" ";
                        }
                        cout<<endl;
                    }
                }
                k=i%width;
                if(k==0)
                {
                    m=m+1;
                }
                if(temp<m)
                {
                    n=m;
                    cout<<gameCells[i].getCellY()+1<<" ";
                    if(n<10)
                    {
                        for(h=0;h<y;++h)
                            cout<<" ";
                    }
                    if(width>52)
                    {
                        for(s=i;s<i+width;++s)
                        cout<<gameCells[s].getCellCh()<<"  ";
                        cout<<endl;
                    }
                    else
                    {
                        for(s=i;s<i+width;++s)
                        cout<<gameCells[s].getCellCh()<<" ";
                        cout<<endl;
                    }
                }
                temp=m;
        }
        cout<<endl;
    }
    Reversi& Reversi::operator=(Reversi& other)//assigment operator.
    {
        int i;
        if(capacity !=other.capacity)
        {
            delete [] gameCells;
            gameCells= new cell[other.capacity];
        }
        high=other.high;
        width=other.width;
        capacity=other.capacity;
        for(i=0;i<capacity;++i)
        {
            gameCells[i]=other.gameCells[i];
        }
        return *this;
    }
    Reversi::~Reversi()//Destructor.
    {
        delete [] gameCells;
        high=0;
        width=0;
        cout<<livingReversiGame--<<"number of living Reversi games."<<endl;
    }
    int Reversi::PlayOneStep(int y,string str2,char playerChar,char targetChar)//plays one step.
    {
        string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int t=0,z=0,count=0,t1=0;
        int i,j=0,k=0,temp=0,l,m=-1,n=0,g=0;
        while(t<52&&str[t].compare(str2)!=0)
            ++t;
         if(t>=52)//if size of x larger than size of alphabet counts two letters for x coordinate.
         {
             t=0;
            while(t<52&&str[t].compare(str2.substr (1,2))!=0)//selects second argument of X coordinate and count it.
            ++t;

             while(t1<52&&str2.substr(0,1).compare(str[t1])!=0)//selects first argument of X coordinate and count it.
            ++t1;

            t=(t+1)*52+t1;//second argument multipled by  52 and added first index of first letter and count X coordinate.

         }
        z=y-1;
        i=t;//for Down
        j=z*width+width;
        while(j<capacity&&gameCells[j+t].getCellCh()==targetChar)
        {
                j=j+width;
                ++count;
        }
        if(j<capacity)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&j!=z*width+width)
            {
                gameCells[z*width+i].getCellCh()=playerChar;
                for(m=z*width+width;m<j;m=m+width)
                {
                    gameCells[m+i].getCellCh()=playerChar;
                }
            }
        }
        z=y-1;
        i=t;//for Down
        j=z*width-width;
        while(j>=0&&gameCells[j+t].getCellCh()==targetChar)
        {
            ++count;
            j=j-width;
        }

        if(j>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&j!=z*width-width)
            {
                gameCells[z*width+i].getCellCh()=playerChar;
                for(m=z*width-width;m>j;m=m-width)
                {
                    gameCells[m+i].getCellCh()=playerChar;
                }
            }
        }
        z=y-1;
        i=t-1;
        j=z*width;
        while(i>=0&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++count;
            --i;
        }

        if(i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1)
            {
                gameCells[j+t-1].getCellCh()=playerChar;
                gameCells[j+t].getCellCh()=playerChar;
                for(m=i;m<t-1;++m)
                {
                    gameCells[j+m].getCellCh()=playerChar;
                }
            }
        }
        z=y-1;
        i=t+1;//for Down
        j=z*width;
        while(i<width&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++count;
            ++i;
        }

        if(i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1)
            {
                gameCells[j+t].getCellCh()=playerChar;
                for(m=t;m<i;++m)
                {
                    gameCells[j+m].getCellCh()=playerChar;
                }
            }
        }
        z=y-1;
        i=t-1;
        j=z*width-width;
        while(j>=0&&i>=0&&gameCells[j+i].getCellCh()==targetChar)
        {
            --i;
            ++count;
            j=j-width;
        }
        if(j>=0&&i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1&&j!=z*width-width)
            {

                gameCells[z*width+t].getCellCh()=playerChar;
                m=j;
                n=i;
                while(m<z*width&&n<t)
                {
                    gameCells[m+n].getCellCh()=playerChar;
                    m=m+width;
                    ++n;
                }
            }
        }
        z=y-1;
        i=t+1;
        j=z*width+width;
        while(j<capacity&&i<width&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++count;
            ++i;
            j=j+width;
        }
        if(j<capacity&&i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1&&j!=z*width+width)
            {
                gameCells[z*width+t].getCellCh()=playerChar;
                gameCells[z*width+width+t+1].getCellCh()=playerChar;
                m=z*width+width;;
                n=t+1;
                while(m<j&&n<i)
                {
                    gameCells[m+n].getCellCh()=playerChar;
                    m=m+width;
                    ++n;
                }
            }
        }
        z=y-1;
        i=t+1;
        j=z*width-width;
        while(j>=0&&i<width&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++i;
            j=j-width;
            ++count;
        }
        if(j>=0&&i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1&&j!=z*width-width)
            {
                gameCells[z*width+t].getCellCh()=playerChar;
                m=z*width-width;
                n=t+1;
                while(m>j&&n<i)
                {
                    gameCells[m+n].getCellCh()=playerChar;
                    ++n;
                    m=m-width;
                }
            }
        }
        z=y-1;
        i=t-1;
        j=z*width+width;
        while(j<capacity&&i>=0&&gameCells[j+i].getCellCh()==targetChar)
        {
            --i;
            ++count;
            j=j+width;
        }
        if(j<capacity&&i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1&&j!=z*width+width)
            {
                gameCells[z*width+t].getCellCh()=playerChar;
                gameCells[z*width+width+t-1].getCellCh()=playerChar;
                m=z*width+width;
                n=t-1;
                while(m<j&&n>i)
                {
                    gameCells[m+n].getCellCh()=playerChar;
                    --n;
                    m=m+width;
                }
            }
        }
        if(count==0)
            count=-1;
        return count;

    }
    int Reversi::CountMostElement(int x,int y,char playerChar,char targetChar)const//counts most pieces.
    {

        int count=0;
        int i,j,m,n,a,b,t,z;
        t=x;
        if(gameCells[y*width+x].getCellCh()!='.')
            return -1;
        ++y;
        z=y-1;
        i=t+1;
        j=z*width;
        while(i<width&&gameCells[j+i].getCellCh()==targetChar)
            ++i;
        if(i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1)
            {
                for(m=t;m<i;++m)
                {
                    ++count;
                }
                ++count;
            }
        }
        z=y-1;
        i=t-1;
        j=z*width;
        while(i>=0&&gameCells[j+i].getCellCh()==targetChar)
            --i;
        if(i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1)
            {
                for(m=i;m<t-1;++m)
                {
                    ++count;
                }
                ++count;
                ++count;
            }
        }
        z=y-1;
        i=t;//for Down
        j=z*width+width;
        while(j<capacity&&gameCells[j+t].getCellCh()==targetChar)
            j=j+width;
        if(j<capacity)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&j!=z*width+width)
            {
                for(m=z*width+width;m<j;m=m+width)
                {
                   ++count;
                }
                ++count;
            }
        }
        z=y-1;
        i=t;//for Down
        j=z*width-width;
        while(j>0&&gameCells[j+t].getCellCh()==targetChar)
            j=j-width;
        if(j>0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&j!=z*width-width)
            {
                for(m=z*width-width;m>j;m=m-width)
                {
                    ++count;
                }
                ++count;
            }
        }
        z=y-1;
        i=t-1;
        j=z*width-width;
        while(j>=0&&i>=0&&gameCells[j+i].getCellCh()==targetChar)
        {
            --i;
            j=j-width;
        }
        if(j>=0&&i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1&&j!=z*width-width)
            {
                ++count;
                m=j;
                n=i;
                while(m<z*width&&n<t)
                {
                    ++count;
                    m=m+width;
                    ++n;
                }
            }
        }
        z=y-1;
        i=t+1;
        j=z*width+width;
        while(j<capacity&&i<width&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++i;
            j=j+width;
        }
        if(j<capacity&&i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1&&j!=z*width+width)
            {
                ++count;
                ++count;
                m=z*width+width;;
                n=t+1;
                while(m<j&&n<i)
                {
                    ++count;
                    m=m+width;
                    ++n;
                }
            }
        }
        z=y-1;
        i=t+1;
        j=z*width-width;
        while(j>=0&&i<width&&gameCells[j+i].getCellCh()==targetChar)
        {
            ++i;
            j=j-width;
        }
        if(j>=0&&i<width)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t+1&&j!=z*width-width)
            {
                ++count;
                m=z*width-width;
                n=t+1;
                while(m>j&&n<i)
                {
                    ++count;
                    ++n;
                    m=m-width;
                }
            }
        }
        z=y-1;
        i=t-1;
        j=z*width+width;
        while(j<capacity&&i>=0&&gameCells[j+i].getCellCh()==targetChar)
        {
            --i;
            j=j+width;
        }
        if(j<capacity&&i>=0)
        {
            if(gameCells[j+i].getCellCh()==playerChar&&i!=t-1&&j!=z*width+width)
            {
                ++count;
                ++count;
                m=z*width+width;
                n=t-1;
                while(m<j&&n>i)
                {
                    ++count;
                    --n;
                    m=m+width;
                }
            }
        }
        if(count==0)
            return -1;
        else
            return count;
    }
    int Reversi::CheckPlayerStatus()const//checks player status.
    {
        int i,j,total=0,status=0,k;
        for(i=0;i<capacity;i=i+width)
        {
            k=i/width;
            for(j=0;j<width;++j)
            {
                    status=CountMostElement(j,k,'O','X');
                    if(status==-1)
                        --total;
                    status=0;
            }
        }
        return total;//returns negative number of board size .
    }
    int Reversi::CheckComputerStatus()const//checks computer status.
    {
        int i,j,total=0,status=0,k;
        for(i=0;i<capacity;i=i+width)
        {
            k=i/width;
            for(j=0;j<width;++j)
            {
                    status=CountMostElement(j,k,'X','O');
                    if(status==-1)
                        --total;
                    status=0;
            }
        }
        return total;//returns negative number of board size .
    }
    void Reversi::play()//plays one step for computer.
    {
        string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string str;
        int i,j,max=0,total=0,coorX=0,coorY=0,count=0,k;
        for(i=0;i<capacity;i=i+width)
        {
            k=i/width;
            for(j=0;j<width;++j)
            {
                total=CountMostElement(j,k,'X','O');
                if(total==-1)
                    --count;//if computer can't play count decrement.
                if(total>max)
                {
                    max=total;
                    coorX=j;
                    coorY=k;
                }
            }
        }
        if(coorX<52)
        {
            str=alphabet[coorX%52];
        }
        else
        {
            str=alphabet[coorX%52]+alphabet[coorX/52-1];
        }
        if(count!=-1*capacity)//if computer can plays.
        {
            PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
        }
    }
    int Reversi::play(int y,string str)//plays one step for player.
    {
        //plays for player.
        int i,row=-1,high2,result,x=0,x1=0;
        string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        if(x<52)
         {
            while(x<52&&str.compare(alphabet[x])!=0)
            ++x;
            row=x;
         }
         else
        if(x>=52)
         {
             x=0;
            while(str[1]!=alphabet[x][0])
            ++x;
             while(str[0]!=alphabet[x1][0])
            ++x1;
            row=(x+1)*52+x1;

         }
        if(row==-1)//checks coordinat validity.
            return -1;
        high2=y-1;
        if(high2>=high||high2<0)
            return -1;
        if(gameCells[high2*width+row].getCellCh()!='.')
            return -1;

        result=PlayOneStep(high2+1,str,'O','X');//if player can plays .
        if(result==0)
            result=-1;//if player cannot  plays returns -1.
        return result;
    }
    void Reversi::totallivingReversiGame()//calculates total living reversi game board.
    {
        livingReversiGame=livingReversiGame+1;
    }
    int Reversi::returnLivingReversiGames()//return total number of living reversi game board.
    {
        return livingReversiGame;
    }
    int Reversi::ifEndGame()const// determines if game ended.
    {
        int i,j,counter=0,k;
        for(i=0;i<capacity;i=i+width)//counts number of . character.
        {
            for(j=0;j<width;++j)
            {
                if(gameCells[i+j].getCellCh()=='.')
                    ++counter;
            }
        }
        if(counter==0)//determines winner.
        {
            if(returnNumberOfO()<returnNumberOfX())
                return 1;
            else
            if(returnNumberOfO()>returnNumberOfX())
                return 2;
              else
            if(returnNumberOfO()==returnNumberOfX())
                return 3;
        }
        if(CheckComputerStatus()==-1*capacity&&CheckPlayerStatus()==-1*capacity)//determines winner if game ended by no place.
        {
             if(returnNumberOfO()<returnNumberOfX())
                return 1;
            else
            if(returnNumberOfO()>returnNumberOfX())
                return 2;
              else
            if(returnNumberOfO()==returnNumberOfX())
                return 3;
        }
        return 0;
    }
    int Reversi::returnNumberOfX()const// return number of X pieces
    {
        int i,j,counter=0,k;
        for(i=0;i<capacity;i=i+width)//counts number of . character.
        {
            for(j=0;j<width;++j)
            {
                if(gameCells[i+j].getCellCh()=='X')
                    ++counter;
            }
        }
        return counter;
    }
    int Reversi::returnNumberOfO()const//return number of O pieces.
    {
        int i,j,counter=0,k;
        for(i=0;i<capacity;i=i+width)//counts number of . character.
        {
            for(j=0;j<width;++j)
            {
                if(gameCells[i+j].getCellCh()=='O')
                    ++counter;
            }
        }
        return counter;
    }
    void Reversi::playGame()//plays game until game ended.
    {

        int y,status=0,status2=0,result,High,Row,status3;
        char ch;
        string x;
        cout<<"please enter high:";
        cin>>High;
        cout<<"please enter row:";
        cin>>Row;
        resizeFunction(High,Row);
        printGameBoard();

        do
        {
            if(CheckPlayerStatus()==-1*capacity)//checks if player can plays.
            {
                    cout<<"you cannot play! computer's turn."<<endl;
            }
            else
            {
                cout<<"please enter a coordinate:"<<endl;
                cin>>y>>x;
                status2=play(y,x);
                while(status2==-1)
                {
                   cout<<"please enter valid coordinate!"<<endl;
                   cin>>y>>x;
                   status2=play(y,x);
                }
                printGameBoard();
            }
            if(CheckComputerStatus()==-1*capacity)//checks if player can plays.
            {
                    cout<<"computer cannot play! your turn."<<endl;
            }
            else
            {
                    play();
                    printGameBoard();
            }
            do
            {
                cout<<"Exit Game ? [y/n]"<<endl;
                cin>>ch;
            }while(!(ch=='y' || ch =='n'));
            if(ch=='y')
                status3=4;
            else
            if(ch=='n')
                status3=ifEndGame();
        }while(status3==0);
        result=ifEndGame();

        if(result==1)
        cout<<"X (Computer) Win!"<<endl;
        else
        if(result==2)
            cout<<"O (User) Win!"<<endl;
        else
        if(result==3)
            cout<<"Draw Game!"<<endl;
    }
    void Reversi::resizeFunction(int y,int x)//resizes game.
    {
        string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int i,j=0,k=0,temp=0,l,m=-1,n=0;
        string str2;
        delete [] gameCells;
        if(x<4 || y<4)
        {
            x=4;
            y=4;
        }
        high=x;
        width=y;
        capacity=x*y;
        gameCells= new cell[capacity];
        for(i=0;i<capacity;++i)
        {
                k=i%width;
                if(k==0)
                {
                    m=m+1;
                }

                if(temp<m)
                {
                    n=m;
                }
                temp=m;
                if(j<52)
                    str2=str[j];//if i less then size of str, str2 contains one element.
                else
                    str2=str[j%52]+str[j/52-1];
                if(n==high/2-1&j==width/2-1)
                    gameCells[i].setCell(n,str2,'O');
                else
                if(n==high/2-1&j==width/2)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2-1)
                    gameCells[i].setCell(n,str2,'X');
                else
                if(n==high/2&j==width/2)
                    gameCells[i].setCell(n,str2,'O');
                else
                    gameCells[i].setCell(n,str2);
                ++j;
                if(j==width)
                    j=0;
        }
    }
    bool Reversi::compareGames(const  Reversi& other)const//compares games call by reference.
    {
        return returnNumberOfO()>other.returnNumberOfO();
    }
    bool Reversi::compareGamesValue( Reversi other)const//compares games call by value.
    {
        return returnNumberOfO()>other.returnNumberOfO();
    }
    Reversi Reversi::operator++()//plays game one step for computer.
    {
        string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string str;
        int i,j,max=0,total=0,coorX=0,coorY=0,count=0,k;
        for(i=0;i<capacity;i=i+width)
        {
            k=i/width;
            for(j=0;j<width;++j)
            {
                total=CountMostElement(j,k,'X','O');
                if(total==-1)
                    --count;//if computer can't play count decrement.
                if(total>max)
                {
                    max=total;
                    coorX=j;
                    coorY=k;
                }
            }
        }
        if(coorX<52)
        {
            str=alphabet[coorX%52];
        }
        else
        {
            str=alphabet[coorX%52]+alphabet[coorX/52-1];
        }
        if(count!=-1*capacity)//if computer can plays.
        {
            PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
        }
        return *this;
    }
    ostream& operator<<(ostream& outputStream,const Reversi& object)//prints game board.
    {
        int i,j,k=0,l=0,digit,m=0,n=0,temp=0,s,y=0,h;
        cell *gameCells;
        gameCells=object.GetGameCells();
        digit=object.Gethigh();
        digit=digit/10;//for two digital numbers.
        while(digit>10)
        {
            ++y;
            digit=digit/10;
        }
        ++y;
        for(i=0;i<object.Gethigh()*object.GetWidth();++i)//prints board to screen.
        {
                if(i==0)
                {
                    for(h=0;h<y+2;++h)
                        outputStream<<" ";
                    if(object.GetWidth()>52)
                    {
                        for(j=0;j<object.GetWidth();++j)
                        {   if(gameCells[j+1].getCellX().size()==1)
                                outputStream<<gameCells[j].getCellX()<<"  ";
                            else
                            if(gameCells[j+1].getCellX().size()==2)
                                outputStream<<gameCells[j].getCellX()<<" ";
                        }
                        outputStream<<endl;
                    }
                    else
                    {
                        for(j=0;j<object.GetWidth();++j)
                        {
                            outputStream<<gameCells[j].getCellX()<<" ";
                        }
                        outputStream<<endl;
                    }
                }
                k=i%object.GetWidth();
                if(k==0)
                {
                    m=m+1;
                }
                if(temp<m)
                {
                    n=m;
                    outputStream<<gameCells[i].getCellY()+1<<" ";
                    if(n<10)
                    {
                        for(h=0;h<y;++h)
                            outputStream<<" ";
                    }
                    if(object.GetWidth()>52)
                    {
                        for(s=i;s<i+object.GetWidth();++s)
                        outputStream<<gameCells[s].getCellCh()<<"  ";
                        outputStream<<endl;
                    }
                    else
                    {
                        for(s=i;s<i+object.GetWidth();++s)
                        outputStream<<gameCells[s].getCellCh()<<" ";
                        outputStream<<endl;
                    }
                }
                temp=m;
        }
        outputStream<<endl;
        return outputStream;
    }
    Reversi Reversi::operator++(int ignore)//plays game one step for computer.
    {
        string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        string str;
        Reversi temp(*this);
        int i,j,max=0,total=0,coorX=0,coorY=0,count=0,k;
        for(i=0;i<capacity;i=i+width)
        {
            k=i/width;
            for(j=0;j<width;++j)
            {
                total=CountMostElement(j,k,'X','O');
                if(total==-1)
                    --count;//if computer can't play count decrement.
                if(total>max)
                {
                    max=total;
                    coorX=j;
                    coorY=k;
                }
            }
        }
        if(coorX<52)
        {
            str=alphabet[coorX%52];
        }
        else
        {
            str=alphabet[coorX%52]+alphabet[coorX/52-1];
        }
        if(count!=-1*capacity)//if computer can plays.
        {
            PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
        }
        return temp;
    }
}
