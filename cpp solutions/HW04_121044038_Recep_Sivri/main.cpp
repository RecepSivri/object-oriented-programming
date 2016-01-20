//HW04_121044038_Recep_Sivri
//
//  HW03_121044038_Recep_Sivri.cpp
//  Created on 22/11/2015
//  Description:
//      in this homework I write a Reversi game using object oriented techniques,
//      in this homework a lot of games can live,user can play more than one games.User can loads or saves game and user can change
//      game.
//
#include <iostream>
#include<vector>
#include <string>
#include <fstream>
using namespace std;
class cell
{
public:
    cell():y(0),x("\0"),ch('.'){}//no parameter constructor for cell class.
    cell(int Y):y(Y),x("\0"),ch('.'){}//one parameter constructor for cell class.
    cell(int Y,string X):y(Y),x("\0"),ch('.'){}//two parameter constructor for cell class.
    cell(int Y,string X,char pch):y(Y),x(X),ch(pch){}//three parameter constructor for cell class.
    void setCell(){y=0,x.assign("\0"),ch='.';}//set cell class with no parameter.
    void setCell(int Y){y=Y,x.assign("\0"),ch='.';}//set cell class with Y coordinate.
    void setCell(int Y,string X){y=Y,x.assign(X),ch='.';}//set cell class with Y coordinate and X coordinate.
    void setCell(int Y,string X,char pch){y=Y,x.assign(X),ch=pch;}//set cell class with Y coordinate,X coordinate and character.
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

class Reversi
{
public:
    Reversi();//no parameter constructor for Reversi class.
    Reversi(int x);//one parameter constructor for Reversi class.
    Reversi(int x,int y);//two parameter constructor for Reversi class.
    void playGame();//plays game start asking size to user and asking coordinate user and plays computer....
    bool compareGames(const Reversi&other)const;//compares two object of Reversi if first argument has
                                                //O piece more than second return 1 else returns 0.
    static int returnLivingCells();//returns livingCells.
    void WriteFile(const string FileName);//writes board to file.
    int ReadFile(const string FileName);//reads board from file.
    void SetLivingCellsForLoad();//when load a game counts livingCells.
    void SetObject(int high,int Row);//creates a new board with new sizes.
    void setLoad(bool value){load=value;}//if game is loaded game load is true else false.
    int GetWitdth(){return gameCells[0].size();}//return width of current board.
    int Gethigh(){return gameCells.size();}//return high of current board.
private:
    void printGameBoard()const;//prints board of game.
    int PlayOneStep(int y,string str,char playerChar,char targetChar);//plays one step for selected pieces.
    int CountMostElement(int x,int y,char playerPiece,char targetPiece)const;//counts max number of pieces for user and computer.
    void play();//plays for computer.
    int play(int y,string str);//plays for user.
    int CheckPlayerStatus()const;//controls if player can plays.
    int CheckComputerStatus()const;//controls if computer can plays.
    int returnNumberOfX()const;//returns number of X pieces from current Reversi object.
    int returnNumberOfO()const;//returns number of O pieces from current Reversi object.
    int ifEndGame()const;//determines if game is end.
    void totalLivingCells();//counts total LivingCells
    void totalLivingCellsConstractor();//count total LivingCells for constructors.
    vector< vector<cell> > gameCells;//two dimensional cell vector.
    static int livingCells;// static variable LivingCells.
    bool load;// if object is loaded game load will be True else False.
};
int Reversi::livingCells=0;//sets Static variable.
int main()
{
    Reversi game1(5,12),game2,game3,game4(30,35),game5(21,35),game6;//define objects.
    string file;
    int choice,result=0,compare,choose2,rcompare;
    game1.setLoad(false);//sets false for not loaded game.
    game2.setLoad(false);
    game3.setLoad(false);
    game4.setLoad(false);
    game5.setLoad(false);
    cout<<"--------------------welcome to Reversi Game!------------------------"<<endl;//testing reversi game.
    while(choice != 8)
    {
        cout<<"please choose choice below:"<<endl;//choices.
        cout<<"1-play game1"<<endl;
        cout<<"2-play game2"<<endl;
        cout<<"3-play game3"<<endl;
        cout<<"4-play game4"<<endl;
        cout<<"5-play game5"<<endl;
        cout<<"6-load game"<<endl;
        cout<<"7-compare games"<<endl;
        cout<<"8-Quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                game1.playGame();//plays game1 object.
                game1.setLoad(true);//sets true for played game.
            break;
            case 2:
                game2.playGame();
                game2.setLoad(true);
            break;
            case 3:
                game3.playGame();
                game3.setLoad(true);
            break;
            case 4:
                game4.playGame();
                game4.setLoad(true);
            break;
            case 5:
                game5.playGame();
                game5.setLoad(true);
            break;
            case 6:
                game6.SetLivingCellsForLoad();//loads game to game6 object.
                cout<<"please enter a filename:"<<endl;
                cin>>file;
                game6.setLoad(true);
                result=game6.ReadFile(file);
                if(result==-1)
                    cout<<file<<" cannot open!"<<endl;
                else
                    game6.playGame();

            break;
            case 7:
                cout<<"please choose first game for compare:"<<endl;//testing compare.
                cout<<"1 -compare game1-game2"<<endl;
                cout<<"2 -compare game1-game3"<<endl;
                cout<<"3 -compare game1-game4"<<endl;
                cout<<"4 -compare game1-game5"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"5 -compare game2-game1"<<endl;
                cout<<"6 -compare game2-game3"<<endl;
                cout<<"7 -compare game2-game4"<<endl;
                cout<<"8 -compare game2-game5"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"9 -compare game3-game1"<<endl;
                cout<<"10-compare game3-game2"<<endl;
                cout<<"11-compare game3-game4"<<endl;
                cout<<"12-compare game3-game5"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"13-compare game4-game1"<<endl;
                cout<<"14-compare game4-game2"<<endl;
                cout<<"15-compare game4-game3"<<endl;
                cout<<"16-compare game4-game5"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"17-compare game5-game1"<<endl;
                cout<<"18-compare game5-game2"<<endl;
                cout<<"19-compare game5-game3"<<endl;
                cout<<"20-compare game5-game4"<<endl;
                cin>>compare;
                switch(compare)
                {
                    case 1:rcompare=game1.compareGames(game2);
                    break;
                    case 2:rcompare=game1.compareGames(game3);
                    break;
                    case 3:rcompare=game1.compareGames(game4);
                    break;
                    case 4:rcompare=game1.compareGames(game5);
                    break;
                    case 5:rcompare=game2.compareGames(game1);
                    break;
                    case 6:rcompare=game2.compareGames(game3);
                    break;
                    case 7:rcompare=game2.compareGames(game4);
                    break;
                    case 8:rcompare=game2.compareGames(game5);
                    break;
                    case 9:rcompare=game3.compareGames(game1);
                    break;
                    case 10:rcompare=game3.compareGames(game2);
                    break;
                    case 11:rcompare=game3.compareGames(game4);
                    break;
                    case 12:rcompare=game3.compareGames(game5);
                    break;
                    case 13:rcompare=game4.compareGames(game1);
                    break;
                    case 14:rcompare=game4.compareGames(game2);
                    break;
                    case 15:rcompare=game4.compareGames(game3);
                    break;
                    case 16:rcompare=game4.compareGames(game5);
                    break;
                    case 17:rcompare=game5.compareGames(game1);
                    break;
                    case 18:rcompare=game5.compareGames(game2);
                    break;
                    case 19:rcompare=game5.compareGames(game3);
                    break;
                    case 20:rcompare=game5.compareGames(game4);
                    break;
                }
                cout<<"result of compare:"<<rcompare<<endl;//return compare result.
            break;
        }
    }
    return 0;
}
void cell::input()
{
    cout<<"please enter a x coordinate:";
    cin>>x;
    cout<<"please enter a y coordinate:";
    cin>>y;
    cout<<"please enter a piece:";
    cin>>ch;
}
void cell::output()const
{
    cout<<"X coordinate:"<<x<<endl;
    cout<<"Y coordinate:"<<y<<endl;
    cout<<"piece of X and Y coordinate:"<<ch<<endl;
}
Reversi::Reversi()
{
    int i,j;
    char str[][2]={"a","b","c","d"};//sets reversi game for 4X4.
    for(i=0;i<4;++i)
        gameCells.push_back(vector<cell>());
    for(j=0;j<4;++j)
    {
        for(i=0;i<4;++i)
            if(i==1&&j==1)//center of board.
                gameCells[j].push_back(cell(j+1,str[i],'O'));
            else
            if(i==1&&j==2)
                gameCells[j].push_back(cell(j+1,str[i],'X'));
            else
            if(i==2&&j==1)
                gameCells[j].push_back(cell(j+1,str[i],'X'));
            else
            if(i==2&&j==2)
                gameCells[j].push_back(cell(j+1,str[i],'O'));
            else
                gameCells[j].push_back(cell(j+1,str[i],'.'));
    }
    totalLivingCellsConstractor();//counts livingCells.
}
void Reversi::printGameBoard()const
{
    int i,j,k=0,l,digit;
    digit=gameCells.size();
    digit=digit/10;//for two digital numbers.
    while(digit>10)
    {
        ++k;
        digit=digit/10;
    }
    ++k;
    for(i=0;i<gameCells.size();++i)//prints board to screen.
    {
        cout<<gameCells[i][0].getCellY()<<" ";
        if(i<9)
        {
            for(l=0;l<k;++l)
                cout<<" ";
        }
        if(gameCells[i].size()<=52)//if number is less or equal 52 prints with this way.
        {
           for(j=0;j<gameCells[i].size();++j)
            cout<<gameCells[i][j].getCellCh()<<" ";
        cout<<endl;
        }
        else// else prints with this way.
        {
           for(j=0;j<gameCells[i].size();++j)
            cout<<" "<<gameCells[i][j].getCellCh()<<" ";
        cout<<endl;
        }

    }
    for(l=0;l<k+2;++l)
            cout<<" ";
    if(gameCells[0].size()<=52)//for X coordinate.
    {
        for(j=0;j<gameCells[0].size();++j)
                cout<<gameCells[0][j].getCellX()<<" ";
    }
    else
    {
        for(j=0;j<gameCells[0].size();++j)
                if(gameCells[0][j].getCellX().size()<2)
                    cout<<" "<<gameCells[0][j].getCellX()<<" ";
                else
                    cout<<gameCells[0][j].getCellX()<<" ";
    }
    cout<<endl;
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
	totalLivingCells();//counts number of living cells.
	return count;
 }
 Reversi::Reversi(int x)
 {
     // sequare constructor.
    int i,j,k=0,l=0,n,t,u=0;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};//alphabet for X coordinate.
    k=sizeof(str)/sizeof(str[0]);// number of elements in str array.
    n=x/k;//counts rate of x and k.
    l=0;
    string str2;
    for(i=0;i<x;++i)//pushes vector.
        gameCells.push_back(vector<cell>());
    for(j=0;j<x;++j)
    {
        for(i=0;i<x;++i)
        {
                if(i<k)
                    str2=str[i];//if i less then size of str array str2 contains one element.
                else
                {
                    if(i/k-1<56)
                        str2=str[i%k]+str[i/k-1];//else  i greater then size of str array str2 contains two element.
                   else
                   {
                       str2=str[i%k];//
                      u=u+1;
                   }
                }

            if(i==(x-1)/2&&j==(x-1)/2)//center of board.
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
            if(i==(x-1)/2&&j==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(i==(x-1)/2+1&&j==(x-1)/2)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(i==(x-1)/2+1&&j==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
                gameCells[j].push_back(cell(j+1,str2,'.'));
            if(t>=52)
                t=k;
        }
    }
    totalLivingCellsConstractor();//counts number of living cells.
 }
 Reversi::Reversi(int x,int y)
 {
     //for different size coordinate constructor.
     int i,j,k=0,l=0,n,t;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);
    n=x/k;
    l=0;
    string str2;
    for(i=0;i<y;++i)
        gameCells.push_back(vector<cell>());
    for(j=0;j<y;++j)
    {
        for(i=0;i<x;++i)
        {
                if(i<k)
                    str2=str[i];//if i less then size of str, str2 contains one element.
                else
                    str2=str[i%k]+str[i/k-1];//else i greater then size of str , str2 contains two elements.
            if(j==(y-1)/2&&i==(x-1)/2)//center of  board.
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
            if(j==(y-1)/2&&i==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
                gameCells[j].push_back(cell(j+1,str2,'.'));
            if(t>=52)
                t=k;
            l=i/k;
        }
    }
    totalLivingCellsConstractor();//counts number of livingCells.
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
void Reversi::play()
{
    //plays for computer.
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string str;
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
		PlayOneStep(coorY+1,str,'X','O');//computer plays one step.
	}
}

int Reversi::play(int y,string str)
{
    //plays for player.
	int i,row=-1,high,result,x=0,x1=0;
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
	high=y-1;
	if(high>=gameCells.size()||high<0)
		return -1;
	if(gameCells[high][row].getCellCh()!='.')
		return -1;

	result=PlayOneStep(high+1,str,'O','X');//if player can plays .
	if(result==0)
        result=-1;//if player cannot  plays returns -1.
    return result;
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
int Reversi::ifEndGame()const
{
    //Terminate game.
    int i,j,counter=0;
    for(i=0;i<gameCells.size();++i)//counts number of . character.
    {
        for(j=0;j<gameCells[i].size();++j)
        {
            if(gameCells[i][j].getCellCh()=='.')
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
    if(CheckComputerStatus()==-1*gameCells.size()*gameCells[0].size()&&CheckPlayerStatus()==-1*gameCells.size()*gameCells[0].size())//determines winner if game ended by no place.
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
int Reversi::returnNumberOfX()const
{
    int i,j,count=0;
    for(i=0;i<gameCells.size();++i)
    {
        for(j=0;j<gameCells[i].size();++j)
        {
            if(gameCells[i][j].getCellCh()=='X')
                ++count;
        }
    }
    return count;//returns number of X pieces.
}
int Reversi::returnNumberOfO()const
{

    int i,j,count=0;
    for(i=0;i<gameCells.size();++i)
    {
        for(j=0;j<gameCells[i].size();++j)
        {
            if(gameCells[i][j].getCellCh()=='O')
                ++count;
        }
    }
    return count;//return number of O pieces.
}
void Reversi::playGame()
{
    int y,k=0,res=0,status=0,high,row,status2=0;
    char ch,ch2;
    string str,a="as";
    string filename;
    if(!load)//if game is loaded game or not.
    {
        cout<<"please enter high and row for game:"<<endl;
        cout<<"high:";
        cin>>high;
        cout<<"row:";
        cin>>row;
        if(row<4 || high<4)
            SetObject(4,4);
        else
            SetObject(high,row);
    }
    printGameBoard();//prints game.
    while(status==0&&status2==0)
    {
        if(CheckPlayerStatus()==-1*gameCells.size()*gameCells[0].size())//checks if player can plays.
        {
                cout<<"you cannot play! computer's turn."<<endl;
        }
        else
        {

            cout<<"please enter a coordinate:";
            cin>>y>>str;
            res=play(y,str);//plays user.
            while(res==-1)//if player enters invalid coordinate asks coordinate again.
            {
                cout<<"please enter a valid coordinate!\n";
                cin>>y>>str;
                res=play(y,str);
            }
            printGameBoard();
        }
        if(CheckComputerStatus()==-1*gameCells.size()*gameCells[0].size())//checks if computer can plays.
        {
                cout<<"computer cannot play! your turn."<<endl;
        }
        else
        {
             cout<<"Computer Plays:"<<endl;
             play();
             printGameBoard();
        }
        status=ifEndGame();
        cout<<"------->total of livingcells of all games:"<<Reversi::returnLivingCells()<<endl;// prints Living Cells for all game.
        cout<<"would you like to quit or game[q-quit s-save c-continue]:"<<endl;
        cin>>ch;
        if(ch!='y' || ch != 'n')//asks to user to save game.
        {
            while(ch!='q' && ch != 's'&& ch != 'c')//if user inputs invalid letters asks again.
            {
                cout<<"would you like to quit or game[q-quit s-save c-continue]:"<<endl;
                cin>>ch;
            }
        }
        if(ch=='s')//if ch equals s character saves game.
        {
            cout<<"please enter a filename:"<<endl;
            cin>>filename;
            WriteFile(filename);
        }
        else
        if(ch=='q')//if ch equals q character quit game.
        {
            status2=4;
        }
        else
        if(ch=='c')//if ch equals c character continue game.
        {
            status2=0;
        }

    }
    if(status==1)
        cout<<"X (Computer) Win!"<<endl;
    else
    if(status==2)
        cout<<"O (User) Win!"<<endl;
    else
    if(status==3)
        cout<<"Draw Game!"<<endl;

}
bool Reversi::compareGames(const Reversi&other)const
{
    return(returnNumberOfO()>other.returnNumberOfO());//returns result of compare games.
}
void Reversi::totalLivingCells()
{
    livingCells=livingCells+1;//increments number of livingCells.
}
void Reversi::totalLivingCellsConstractor()
{
    livingCells=livingCells+4;//increments number of livingCells in constructor.
}
int Reversi::returnLivingCells()
{
    return  livingCells;//returns LivingCells.
}
void Reversi::WriteFile(const string FileName)
{
    ofstream file;
    int i,j;
    file.open(FileName.c_str());//opens file for writing.
    file<<gameCells.size();
    file<<" "<<gameCells[0].size();
    file<<endl;
    for(i=0;i<Gethigh();++i)
    {
        for(j=0;j<GetWitdth();++j)
        {
            file<<gameCells[i][j].getCellCh();//writes Cells.
        }
        file<<endl;
    }
    file.close();//closes file.
}
int Reversi::ReadFile(const string FileName)
{
    ifstream file(FileName.c_str());
    int i,j,k=0,l=0,n,t,x,y,width,high;
    gameCells.clear();//clears vector of gameCell.
    char ch;
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);
    n=x/k;
    l=0;
    string str2;
    if(file.is_open())//checks if file is opened for reading.
    {
        gameCells.clear();
        file>>high;//reads high.
        file>>width;//reads width.
        y=high;
        x=width;
        for(i=0;i<y;++i)
            gameCells.push_back(vector<cell>());
        for(j=0;j<y;++j)
        {
            for(i=0;i<x;++i)
            {
                    if(i<k)
                        str2=str[i];
                    else
                        str2=str[i%k]+str[i/k-1];
                file>>ch;//reads characters.
                if(ch=='O')//if ch equals O character .
                {
                    gameCells[j].push_back(cell(j+1,str2,'O'));
                    totalLivingCells();
                }
                else
                if(ch=='X')//if ch equals X character .
                {
                    gameCells[j].push_back(cell(j+1,str2,'X'));
                    totalLivingCells();
                }
                else
                if(ch=='.')//if ch equals . character .
                {
                    gameCells[j].push_back(cell(j+1,str2,'.'));
                }
                if(t>=52)
                    t=k;
                l=i/k;
            }
        }
        file.close();//close file.
    }
    else
        return -1;
}
void Reversi::SetLivingCellsForLoad()
{
    livingCells=livingCells-returnNumberOfX()-returnNumberOfO();//counts LivingCells for load.
}
void Reversi::SetObject(int high,int Row)
{
    int i,j,k=0,l=0,n,t,x,y;
    x=Row;
    y=high;
    gameCells.clear();//clears vector.
    string str[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    k=sizeof(str)/sizeof(str[0]);//counts size of string array str.
    n=x/k;
    l=0;
    string str2;
    for(i=0;i<y;++i)
        gameCells.push_back(vector<cell>());//creates one dimesional vector.
    for(j=0;j<y;++j)
    {
        for(i=0;i<x;++i)
        {
                if(i<k)
                    str2=str[i];//if size of vector is greater then index str2 contains one element.
                else
                    str2=str[i%k]+str[i/k-1];//if size of vector is lessthen index str2 contains two element.
            if(j==(y-1)/2&&i==(x-1)/2)//center of board.
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
            if(j==(y-1)/2&&i==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2)
                gameCells[j].push_back(cell(j+1,str2,'X'));
            else
            if(j==(y-1)/2+1&&i==(x-1)/2+1)
                gameCells[j].push_back(cell(j+1,str2,'O'));
            else
                gameCells[j].push_back(cell(j+1,str2,'.'));
            if(t>=52)
                t=k;
            l=i/k;
        }
    }
}
