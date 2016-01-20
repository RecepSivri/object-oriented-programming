//HW05_121044038_Recep_Sivri implement file
//
//      Created by Recep Sivri on 24/11/2015.
//  Description:
//      This implement file contains all functions of classes.


#include"HW5.h"
using namespace std;
int Reversi::livingCells=0;
void Cell::input()
{
    cout<<"please enter a x coordinate:";
    cin>>x;
    cout<<"please enter a y coordinate:";
    cin>>y;
    cout<<"please enter a piece:";
    cin>>ch;
}
void Cell::output()const
{
    cout<<"X coordinate:"<<x<<endl;
    cout<<"Y coordinate:"<<y<<endl;
    cout<<"piece of X and Y coordinate:"<<ch<<endl;
}

Reversi::Reversi()
{
    int i,j;
    char str[][2]={"a","b","c","d"};
    for(i=0;i<4;++i)
        gameCells.push_back(vector<Cell>());//creates rows
    for(j=0;j<4;++j)
    {
        for(i=0;i<4;++i)//center of board.
            if(i==1&&j==1)
                gameCells[j].push_back(Cell(j+1,str[i],'O'));//creates column.
            else
            if(i==1&&j==2)
                gameCells[j].push_back(Cell(j+1,str[i],'X'));
            else
            if(i==2&&j==1)
                gameCells[j].push_back(Cell(j+1,str[i],'X'));
            else
            if(i==2&&j==2)
                gameCells[j].push_back(Cell(j+1,str[i],'O'));
            else
                gameCells[j].push_back(Cell(j+1,str[i],'.'));
    }
    totalLivingCellsConstractor();
}
ostream& operator<<(ostream& outputStream,const Reversi& game)
{
    int i,j,k=0,l,digit;
    digit=game.gameCells.size();
    digit=digit/10;
    while(digit>10)
    {
        ++k;
        digit=digit/10;//counts digits for display game.
    }
    ++k;
    for(i=0;i<game.gameCells.size();++i)
    {
        outputStream<<game.gameCells[i][0].getCellY()<<" ";
        if(i<9)
        {
            for(l=0;l<k;++l)
                outputStream<<" ";
        }
        if(game.gameCells[i].size()<26)
        {
           for(j=0;j<game.gameCells[i].size();++j)
            outputStream<<game.gameCells[i][j].getCellCh()<<" ";
        outputStream<<endl;
        }
        else
        {
           for(j=0;j<game.gameCells[i].size();++j)
            outputStream<<" "<<game.gameCells[i][j].getCellCh()<<" ";
        outputStream<<endl;
        }

    }
    for(l=0;l<k+2;++l)
            outputStream<<" ";
    if(game.gameCells[0].size()<26)
    {
        for(j=0;j<game.gameCells[0].size();++j)
                outputStream<<game.gameCells[0][j].getCellX()<<" ";
    }
    else
    {
        for(j=0;j<game.gameCells[0].size();++j)
                if(game.gameCells[0][j].getCellX().size()<2)
                    outputStream<<" "<<game.gameCells[0][j].getCellX()<<" ";
                else
                    outputStream<<game.gameCells[0][j].getCellX()<<" ";
    }
    outputStream<<endl;
    return outputStream;
}
 Reversi::Reversi(int x)
 {
    int i,j,k=0,l=0,n,t,u=0;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);
    n=x/k;
    l=0;
    string str2;
    for(i=0;i<x;++i)//construct a new object using alphabet.
        gameCells.push_back(vector<Cell>());
    for(j=0;j<x;++j)
    {
        for(i=0;i<x;++i)
        {
                if(i<k)
                    str2=str[i];
                else
                {
                    if(i/k-1<26)
                        str2=str[i%k]+str[i/k-1];
                    else
                   {
                       str2=str[i%k];
                      u=u+1;
                   }
                }

            if(i==(x-1)/2&&j==(x-1)/2)//center of board.
                gameCells[j].push_back(Cell(j+1,str2,'O'));
            else
            if(i==(x-1)/2&&j==(x-1)/2+1)
                gameCells[j].push_back(Cell(j+1,str2,'X'));
            else
            if(i==(x-1)/2+1&&j==(x-1)/2)
                gameCells[j].push_back(Cell(j+1,str2,'X'));
            else
            if(i==(x-1)/2+1&&j==(x-1)/2+1)
                gameCells[j].push_back(Cell(j+1,str2,'O'));
            else
                gameCells[j].push_back(Cell(j+1,str2,'.'));
            if(t>=52)
                t=k;
        }
    }
    totalLivingCellsConstractor();
 }
 Reversi::Reversi(int x,int y)
 {
     int i,j,k=0,l=0,n,t;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);
    n=x/k;
    l=0;
    string str2;
    for(i=0;i<y;++i)
        gameCells.push_back(vector<Cell>());
    for(j=0;j<y;++j)
    {
        for(i=0;i<x;++i)
        {
                if(i<k)
                    str2=str[i];
                else
                    str2=str[i%k]+str[i/k-1];
            if(j==(y-1)/2&&i==(x-1)/2)
                gameCells[j].push_back(Cell(j+1,str2,'O'));
            else
            if(j==(y-1)/2&&i==(x-1)/2+1)
                gameCells[j].push_back(Cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2)
                gameCells[j].push_back(Cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2+1)
                gameCells[j].push_back(Cell(j+1,str2,'O'));
            else
                gameCells[j].push_back(Cell(j+1,str2,'.'));
            if(t>=52)
                t=k;
            l=i/k;
        }
    }
    totalLivingCellsConstractor();
 }
 bool Cell::operator>=(const Cell& other)const
 {
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
            i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }
         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;
        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(y>=other.y)
         {
             if(y==other.y)
             {
                 if(i>k||i==k)
                    return true;
                 else
                    return false;
             }
         }
         else
            return false;
 }
 bool Cell::operator<=(const Cell& other)const
 {
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
            i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }
         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;
        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(y<=other.y)
         {
             if(y==other.y)
             {
                 if(i<k||i==k)
                    return true;
                 else
                    return false;
             }
         }
         else
            return false;
 }
 bool Cell::operator<(const Cell& other)const
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
    if(y<other.y)
        return true;
    else
    if(y==other.y)
    {
        while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }
         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;

        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(i<k)
            return true;
    }
    return false;
}
bool Cell::operator>(const Cell& other)const
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
    if(y>other.y)
        return true;
    else
    if(y==other.y)
    {
        while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }
         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;
        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(i>k)
            return true;
    }
    return false;
}
bool Cell::operator==(const Cell& other)const
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
        while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }

         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;
        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(y==other.y&&i==k)
            return true;
         else
            return false;
}
bool Cell::operator!=(const Cell& other)const
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,j=0,k=0,l=0;
        while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
         {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
         }

         while(k<52&&other.x.compare(alphabet[k])!=0)
            ++k;
        if(k>=52)
         {
             k=0;
            while(k<52&&alphabet[k].compare(other.x.substr (1,2))!=0)
            ++k;

             while(l<52&&other.x.substr(0,1).compare(alphabet[l])!=0)
            ++l;

            k=(k+1)*52+l;
         }
         if(y==other.y&&i==k)
            return false;
         else
            return true;
}
Cell Cell::operator++()
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str;
    int i=0,j=0,k=0,l=0;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
        }
         ++y;
         ++i;
        if(i<52)
            str=alphabet[i];
        else
        if(i>=52)
        {
            str=alphabet[i%52]+alphabet[i/52-1];
        }
        setCell(y,str);
        return Cell(y,str,getCellCh());
}
Cell Cell::operator++(int)
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str,tempstr;
    int i=0,j=0,k=0,l=0,temp;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;

             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;

            i=(i+1)*52+j;
        }
        temp=y;
        tempstr=x;
         ++y;
         ++i;
        if(i<52)
            str=alphabet[i];
        else
        if(i>=52)
        {
            str=alphabet[i%52]+alphabet[i/52-1];
        }
        setCell(y,str);
        return Cell(temp,tempstr,getCellCh());
}
Cell Cell::operator--()
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str,tempstr;
    int i=0,j=0,k=0,l=0,temp;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;
             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;
            i=(i+1)*52+j;
        }
        --y;
        --i;
        if(i<52)
            str=alphabet[i];
        else
        if(i>=52)
        {
            str=alphabet[i%52]+alphabet[i/52-1];
        }
        setCell(y,str);
        return Cell(y,str,getCellCh());
}
Cell Cell::operator--(int)
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str,tempstr;
    int i=0,j=0,k=0,l=0,temp;
     while(i<52&&x.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(x.substr (1,2))!=0)
            ++i;
             while(j<52&&x.substr(0,1).compare(alphabet[j])!=0)
            ++j;
            i=(i+1)*52+j;
        }
        temp=y;
        tempstr=x;
        --y;
        --i;
        if(i<52)
            str=alphabet[i];
        else
        if(i>=52)
        {
            str=alphabet[i%52]+alphabet[i/52-1];
        }
        setCell(y,str);
        return Cell(temp,tempstr,getCellCh());
}
istream& operator>>(istream& input,Cell& object)
{
    int y;
    string x;
    input>>y>>x;
    object.setCell(y,x);
    return input;
}
ostream& operator<<(ostream& output,const Cell& object)
{
    output<<"x:"<<object.getCellX()<<endl;
    output<<"y:"<<object.getCellY()<<endl;
    return output;
}
Reversi Reversi::operator++()
{
    //plays for computer.
    int result;
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str;
    games.push_back(this->gameCells);
    OldCells.push_back(this->livingCells);
    int i,j,max=0,total=0,coorX=0,coorY=0,count=0;
	for(i=0;i<gameCells.size();++i)
	{
		for(j=0;j<gameCells[i].size();++j)
		{
			total=CountMostElement(j,i,'X','O');
			if(total==-1)
				--count;//if computer can't play count decrement.
			if(total>max)
			{
				max=total;
				coorX=j;
				coorY=i;
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
	if(count!=-1*gameCells.size()*gameCells[i].size())//if computer can plays.
	{
		result=PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
                livingCells=livingCells+1;
	}

	return Reversi(gameCells);
}
Reversi Reversi::operator++(int)
{
    //plays for computer.
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str;
    int result;
    games.push_back(this->gameCells);
    OldCells.push_back(this->livingCells);
    vector< vector<Cell> > gameCells2;
    gameCells2=gameCells;
    int i,j,max=0,total=0,coorX=0,coorY=0,count=0;
	for(i=0;i<gameCells.size();++i)
	{
		for(j=0;j<gameCells[i].size();++j)
		{
			total=CountMostElement(j,i,'X','O');
			if(total==-1)
				--count;//if computer can't play count decrement.
			if(total>max)
			{
				max=total;
				coorX=j;
				coorY=i;
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
	if(count!=-1*gameCells.size()*gameCells[i].size())//if computer can plays.
	{
		result=PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
                livingCells=livingCells+1;
	}
	return Reversi(gameCells2);
}
int Reversi::CheckComputerStatus()const
{
    //scans board for computer if computer can play or not.
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str;
    int i,j,max=0,total=0,coorX=0,coorY=0,count=0;
	for(i=0;i<gameCells.size();++i)
	{
		for(j=0;j<gameCells[i].size();++j)
		{
			total=CountMostElement(j,i,'X','O');
			if(total==-1)
				--count;
		}
	}
	return count;
}
int Reversi::PlayOneStep(int y,string str,char playerChar,char targetChar)
 {
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};//Alphabet for X coordinate.
     int x=0,count=0,x1=0;
     int i,j=0,m=0,n=0;
     --y;

       while(x<52&&str.compare(alphabet[x])!=0)//counts for X coordinate
        ++x;
    if(x>=52)//if size of x larger than size of alphabet counts two letters for x coordinate.
     {
         x=0;
        while(x<52&&alphabet[x].compare(str.substr (1,2))!=0)//selects second argument of X coordinate and count it.
        ++x;

         while(x1<52&&str.substr(0,1).compare(alphabet[x1])!=0)//selects first argument of X coordinate and count it.
        ++x1;

        x=(x+1)*52+x1;//second argument multipled by  52 and added first index of first letter and count X coordinate.

     }
    i=x+1;//for Down
    j=y;
	while(i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetChar)
		++i;
	if(i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x+1)
		{
			gameCells[j][x].getCellCh()=playerChar;
			for(m=x;m<i;++m)
			{
				gameCells[j][m].getCellCh()=playerChar;
			}
			++count;
		}
	}
    j=y;//for Up.
	i=x-1;
	while(i>=0&&gameCells[j][i].getCellCh()==targetChar)
		--i;
	if(i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x-1)
		{
			gameCells[j][x-1].getCellCh()=playerChar;
			gameCells[j][x].getCellCh()=playerChar;
			for(m=i;m<x-1;++m)
			{
				gameCells[j][m].getCellCh()=playerChar;
			}
			++count;
		}
	}
    i=x;//for right.
	j=y+1;
	while(j<gameCells.size()&&gameCells[j][i].getCellCh()==targetChar)
		++j;

	if(j<gameCells.size())
	{
		if(gameCells[j][i].getCellCh()==playerChar&&j!=y+1)
		{
			gameCells[y][i].getCellCh()=playerChar;
			for(m=y+1;m<j;++m)
			{
				gameCells[m][i].getCellCh()=playerChar;
			}
			++count;
		}
	}
    i=x;//for left.
	j=y-1;
	while(j>=0&&gameCells[j][i].getCellCh()==targetChar)
		--j;
	if(j>=0)
	{
		if(gameCells[j][i].getCellCh()==playerChar&&j!=y-1)
		{
			gameCells[y][i].getCellCh()=playerChar;
			gameCells[y-1][i].getCellCh()=playerChar;
			for(m=j;m<y-1;++m)
			{
				gameCells[m][i].getCellCh()=playerChar;
			}
			++count;
		}
	}
	i=x-1;
	j=y-1;//up-left
	while(j>=0&&i>=0&&gameCells[j][i].getCellCh()==targetChar)
	{
		--i;
		--j;
	}
	if(j>=0&&i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x-1&&j!=y-1)
		{

			gameCells[y][x].getCellCh()=playerChar;
			++count;
			m=j;
			n=i;
			while(m<y&&n<x)
			{
				gameCells[m][n].getCellCh()=playerChar;
				++m;
				++n;
			}
		}
	}
    i=x+1;
	j=y+1;//down-right
	while(j<gameCells.size()&&i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetChar)
	{
		++i;
		++j;
	}
	if(j<gameCells.size()&&i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x+1&&j!=y+1)
		{

			++count;
			gameCells[y][x].getCellCh()=playerChar;
			gameCells[y+1][x+1].getCellCh()=playerChar;
			m=y+1;
			n=x+1;
			while(m<j&&n<i)
			{
				gameCells[m][n].getCellCh()=playerChar;
				++m;
				++n;
			}
		}
	}
	i=x+1;
	j=y-1;//left-down.
	while(j>=0&&i<i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetChar)
	{
		++i;
		--j;
	}
	if(j>=0&&i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x+1&&j!=y-1)
		{

			++count;
			gameCells[y][x].getCellCh()=playerChar;
			m=y-1;
			n=x+1;
			while(m>j&&n<i)
			{
				gameCells[m][n].getCellCh()=playerChar;
				++n;
				--m;
			}
		}
	}
	i=x-1;
	j=y+1;//up-right
	while(j<gameCells.size()&&i>=0&&gameCells[j][i].getCellCh()==targetChar)
	{
		--i;
		++j;
	}
	if(j<gameCells.size()&&i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerChar&&i!=x-1&&j!=y+1)
		{

			++count;
			gameCells[y][x].getCellCh()=playerChar;
			gameCells[y+1][x-1].getCellCh()=playerChar;
			m=y+1;
			n=x-1;
			while(m<j&&n>i)
			{
				gameCells[m][n].getCellCh()=playerChar;
				--n;
				++m;
			}
		}
	}

	return count;
 }
int Reversi:: CountMostElement(int x,int y,char playerPiece,char targetPiece)const
{
    //counts most pieces for X or O.
	int count=0;
	int i,j,m,n,a,b;
	i=x;
	j=y;
	i=x+1;
	if(gameCells[y][x].getCellCh()!='.')
		return -1;

	while(i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetPiece)
		++i;
	if(i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&i!=x+1)
		{
			for(m=x+1;m<i;++m)
			{
				++count;
			}
		}
	}
	j=y;
	i=x-1;
	while(i>=0&&gameCells[j][i].getCellCh()==targetPiece)
		--i;
	if(i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&i!=x-1)
		{
			for(m=i;m<x-1;++m)
			{
				++count;
			}
		}
	}
	i=x;
	j=y+1;
	while(j<gameCells.size()&&gameCells[j][i].getCellCh()==targetPiece)
		++j;
	if(j<gameCells.size())
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&j!=y+1)
		{
			for(m=y+1;m<j;++m)
			{
				++count;
			}
		}
	}
	i=x;
	j=y-1;
	while(j>=0&&gameCells[j][i].getCellCh()==targetPiece)
		--j;
	if(j>=0)
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&j!=y-1)
		{
			for(m=j;m<y-1;++m)
			{
				++count;
			}
		}
	}
	i=x-1;
	j=y-1;
	while(j>=0&&i>=0&&gameCells[j][i].getCellCh()==targetPiece)
	{
		--i;
		--j;
	}
	if(j>=0&&i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&i!=x-1&&j!=y-1)
		{
			m=j;
			n=i;
			while(m<y-1&&n<x-1)
			{
				++m;
				++n;
				++count;
			}
		}
	}
	i=x+1;
	j=y+1;
	while(j<gameCells.size()&&i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetPiece)
	{
		++i;
		++j;
	}
	if(j<gameCells.size()&&i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&j!=y+1&&i!=x+1)
		{
			m=y+1;
			n=x+1;
			while(m<j&&n<i)
			{
				++count;
				++m;
				++n;
			}
		}
	}
	i=x+1;
	j=y-1;
	while(j>=0&&i<gameCells[j].size()&&gameCells[j][i].getCellCh()==targetPiece)
	{
		++i;
		--j;
	}
	if(j>=0&&i<gameCells[j].size())
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&i!=x+1&&j!=y-1)
		{
			m=y-1;
			n=x+1;
			while(m>j&&n<i)
			{
				++count;
				++n;
				--m;
			}
		}
	}
	i=x-1;
	j=y+1;
	while(j<gameCells.size()&&i>=0&&gameCells[j][i].getCellCh()==targetPiece)
	{
		--i;
		++j;
	}
	if(j<gameCells.size()&&i>=0)
	{
		if(gameCells[j][i].getCellCh()==playerPiece&&i!=x-1&&j!=y+1)
		{
			m=y+1;
			n=x-1;
			while(m<j&&n>i)
			{
				++count;
				--n;
				++m;
			}
		}
	}

	if(count==0)
		return -1;
	return count;
}
 Reversi::Reversi(vector< vector<Cell> > gameCells2)//sets Reversi object for return value.
{
    int i,j,k=0,l=0,n,t;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);
    n=gameCells2[0].size()/k;
    l=0;
    string str2;
    for(i=0;i<gameCells2.size();++i)
        gameCells.push_back(vector<Cell>());
    for(j=0;j<gameCells2.size();++j)
    {
        for(i=0;i<gameCells2[j].size();++i)
        {
                if(i<k)
                    str2=str[i];
                else
                    str2=str[i%k]+str[i/k-1];
                gameCells[j].push_back(Cell(j+1,str2,gameCells2[j][i].getCellCh()));

            if(t>=52)
                t=k;
            l=i/k;
        }
    }
}
Reversi Reversi::operator--()//before the game.
{
    if(games.size()==0)
        cout<<"you cannnot decrement game!"<<endl;
    else
    {
       this->gameCells=*(games.end()-1);
       this->livingCells=*(OldCells.end()-1);
        games.pop_back();
        OldCells.pop_back();
    }
    return *this;
}
Reversi Reversi::operator--(int)//before the game.
{
    Reversi obj;
    obj=*this;
    if(games.size()==0)
        cout<<"you cannot dicrement game!"<<endl;
    else
    {
        this->gameCells=*(games.end()-1);
        this->livingCells=*(OldCells.end()-1);
        games.pop_back();
        OldCells.pop_back();
    }
    return obj;
}

int Reversi::CheckPlayerStatus()const
{
    // scans board for player if player play or not.
	int i,j,total=0,status=0;
	for(i=0;i<gameCells.size();++i)
	{
		for(j=0;j<gameCells[i].size();++j)
		{
				status=CountMostElement(j,i,'O','X');
				if(status==-1)
					--total;
				status=0;
		}
	}
	return total;//returns negative number of board size .
}
Reversi Reversi::operator+=(Cell coordinate)//plays game with taking  cell from user. 
{
    games.push_back(this->gameCells);
    OldCells.push_back(this->livingCells);
	int y,i,row=-1,high,result,x=0,x1=0,status=0;
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	string str;
	str=coordinate.getCellX();
	y=coordinate.getCellY();
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
	high=y-1;
	if(high>=gameCells.size()||high<0||row>=gameCells[0].size()||row<0)
    {
        cout<<"invalid Cell!"<<endl;
        status=-1;
    }
    else
	if(gameCells[high][row].getCellCh()!='.')
    {
        status=-1;
        cout<<"you cannot play!"<<endl;
    }
    else
    {
       result=PlayOneStep(high+1,str,'O','X');//if player can plays .
       if(result!=0)
            livingCells=livingCells+1;
        if(result==0)
            cout<<"you cannot play!"<<endl;
    }

    return Reversi(gameCells);
}
Cell Reversi::operator[](std::string coordinate)//returns cell by tokening string.
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,number=0,j=0,k=0,l=0;
    vector<char>integers;
    string str;
    while(coordinate[i]=='1'||coordinate[i]=='2'||coordinate[i]=='3'||coordinate[i]=='4'||coordinate[i]=='5'||coordinate[i]=='6'||
          coordinate[i]=='7'||coordinate[i]=='8'||coordinate[i]=='9'||coordinate[i]=='0')
          {
            integers.push_back(coordinate[i]);
             ++i;
          }
    for(i=0;i<integers.size();++i)
    {
       number=number+(integers[i]-48)*pow(10,integers.size()-1-i);
    }
    str=&coordinate[i];
    i=0;
    while(i<52&&str.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(str.substr (1,2))!=0)
            ++i;
             while(j<52&&str.substr(0,1).compare(alphabet[j])!=0)
            ++j;
            i=(i+1)*52+j;
        }
    if(gameCells.size()>=number&&gameCells[0].size()>=i)
        return Cell(number,str,gameCells[number-1][i].getCellCh());
    else
        return Cell(-1000,"-1000",'.');
}
Cell Reversi::operator()(std::string coordinate)//returns cell by tokening string.
{
     string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int i=0,number=0,j=0,k=0,l=0;
    vector<char>integers;
    string str;
    while(coordinate[i]=='1'||coordinate[i]=='2'||coordinate[i]=='3'||coordinate[i]=='4'||coordinate[i]=='5'||coordinate[i]=='6'||
          coordinate[i]=='7'||coordinate[i]=='8'||coordinate[i]=='9'||coordinate[i]=='0')
          {
            integers.push_back(coordinate[i]);
             ++i;
          }
    for(i=0;i<integers.size();++i)
    {
       number=number+(integers[i]-48)*pow(10,integers.size()-1-i);
    }
    str=&coordinate[i];
    i=0;
    while(i<52&&str.compare(alphabet[i])!=0)
        ++i;
        if(i>=52)
        {
             i=0;
            while(i<52&&alphabet[i].compare(str.substr (1,2))!=0)
            ++i;
             while(j<52&&str.substr(0,1).compare(alphabet[j])!=0)
            ++j;
            i=(i+1)*52+j;
        }
    if(gameCells.size()>number&&gameCells[0].size()>i)
        return Cell(number,str,gameCells[number-1][i].getCellCh());
    else
        return Cell(-1000,"-1000",'.');
}
void Reversi::totalLivingCellsConstractor()//counts number of livingCell when object is creating.
{
    livingCells=livingCells+4;//increments number of livingCells in constructor.
}
