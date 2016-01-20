//HW01_121044038_Recep_Sivri
//main.cpp
//created on 23/09/2015 by Recep Sivri
//
// this program implements reversi game with user between computer,user enters size of board.

#include<iostream>
using namespace std;
//create2DBoard function creates 2D board with four diagonal pieces in center of board.
//Takes a two dimensional string and size.
void create2DBoard(char string[][20],int size);
//show2DBoard function displays 2d board.
void show2DBoard(char string[][20],int size,char *Alphabet);
//checkCoordinateAndPlayByPlayer function checks coordinates of player and plays one step.
int checkCoordinateAndPlayByPlayer(char string[][20],int size,char*Alphabet,int num,char ch);
//playOneStep function plays one step for computer and player.
int playOneStep(char string[][20],int size,int x,int y,char playerChar,char targetChar);
//PlayComputerOneStep functionchecks coordinates of computer and 
//plays smartly because computer takes largest number of pieces.
int PlayComputerOneStep(char string[][20],int size,int &x,int &y);
//CountMostElement function counts and checks number of move and returns number of take pieces or invalid move.
int CountMostElement(char string[][20],int size,int x,int y,char playerPiece,char targetPiece);
//CheckPlayerStatus function checks valid move from all of board.
int CheckPlayerStatus(char string[][20],int size);
//countPieces function conuts number of pieces.
int countPieces(char string[][20],int size, char piece);
//isFull function checks if board is full.
int isFull(char string[][20],int size);
int main(void)
{
	//alphaber for 2D board
	char alphabet[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','q','p','r','s','t','u','v','w','x','y','z'};
	int size,number,status1=0,counter=0,negSize=0,status2=0,status3=0,x=0,y=0;
	char board[20][20],ch;
	cout<<"please enter a size for 2D board:"<<endl;
	cin>>size;
	negSize=-1*size*size;
	while(size<4||size%2==1||size>20)//checks valid board size 
	{	
		cout<<"please enter again:"<<endl;
		cin>>size;
	}
	create2DBoard(board,size);//creates 2D board
	show2DBoard(board,size,alphabet);//shows board
	do
	{
		do
		{
			status2=CheckPlayerStatus(board,size);//program checks if player have valid move.
			if(status2!=negSize)//check if user have a valid move.
			{
				if(status1==-1)
					cout<<"please enter a valid  Coordinate!"<<endl;
				else
					cout<<"please enter a Coordinate:"<<endl;
				cin>>number>>ch;//user enters coordinates.
				status1=checkCoordinateAndPlayByPlayer(board,size,alphabet,number,ch);//player plays one step and checks coordinates.
			}
			else	
			{
				cout<<"you cannot play Computer's turn!"<<endl;
				status1=0;
			}
			
		}while(status1==-1);
	if(status2!=negSize)
	show2DBoard(board,size,alphabet);//shows 2D board

	status3=PlayComputerOneStep(board,size,x,y);//computer plays one step and checks valid move.
	if(status3==negSize)
	{
		if(isFull(board,size)!=1)
		cout<<"computer cannot play your turn!"<<endl;
	}
	else
	{
		cout<<"now playing computer:\n";
		cout<<"-------------->"<<y+1<<alphabet[x]<<endl;
		show2DBoard(board,size,alphabet);//shows 2D board
	}
	if(status2==negSize&&status3==negSize)
		cout<<"no valid play for two players!"<<endl;
	cout<<endl<<endl;
	++counter;
	}while(isFull(board,size)!=1&&countPieces(board,size,'X')!=0&&countPieces(board,size,'O')!=0&&(status3!=negSize||status2!=negSize));//terminates game.

	//result of game
	if(countPieces(board,size,'X')>countPieces(board,size,'O'))
		cout<<"X(Computer) wins!"<<endl;
	else
	if(countPieces(board,size,'X')<countPieces(board,size,'O'))
		cout<<"O(User) wins!"<<endl;
	else
	if(countPieces(board,size,'X')==countPieces(board,size,'O'))
		cout<<"Draw game!"<<endl;
return 0;
}
void create2DBoard(char string[][20],int size)//creates 2D board.
{
	int i,j;
	for(i=0;i<size;++i)
	{
		for(j=0;j<size;++j)
		{
			if(i==(size/2-1)&&j==(size/2-1))
				string[i][j]='X';
			else
			if(i==(size/2-1)&&j==(size/2))
				string[i][j]='O';
			else
			if(i==(size/2)&&j==(size/2-1))
				string[i][j]='O';
			else
			if(i==(size/2)&&j==(size/2))
				string[i][j]='X';	
			else	
			string[i][j]='.';
		}
	}
}
void show2DBoard(char string[][20],int size,char *Alphabet)//shows 2D board
{
	int i,j;
	cout<<"     ";
	for(i=0;i<size;++i)
	{
		cout<<Alphabet[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<size;++i)
	{	
		if(i<9)
			cout<<i+1<<". "<<"| ";
		else
			cout<<i+1<<"."<<"| ";
		for(j=0;j<size;++j)
		{
			cout<<string[i][j]<<" ";
		}
		cout<<"|";
		if(i==size/2-1)
			cout<<"        X:"<<countPieces(string,size,'X');//write to screen number of pieces.
		if(i==size/2)
			cout<<"        O:"<<countPieces(string,size,'O');
		cout<<endl;
	}

}
int checkCoordinateAndPlayByPlayer(char string[][20],int size,char*Alphabet,int num,char ch)
{
	int i,row=-1,high,result;
	for(i=0;i<size;++i)
	{
		if(Alphabet[i]==ch)
			row=i;
	}
	if(row==-1)//checks coordinat validity.
		return -1;
	high=num-1;
	if(high>=size||high<0)
		return -1;
	if(string[high][row]!='.')
		return -1;
	result=playOneStep(string,size,row,high,'O','X');
	if(result==-1)
		return -1;		
}
int playOneStep(char string[][20],int size,int x,int y,char playerChar,char targetChar)
{	
	int count=0;
	int i,j,m,n;
	j=y;
	i=x+1;//righ
	while(i<size&&string[j][i]==targetChar)
		++i;
	if(i<size)
	{
		if(string[j][i]==playerChar&&i!=x+1)
		{
			string[j][x]=playerChar;
			for(m=x;m<i;++m)
			{
				string[j][m]=playerChar;
			}
			++count;
		}
	}
	j=y;
	i=x-1;//left
	while(i>=0&&string[j][i]==targetChar)
		--i;
	if(i>=0)
	{
		if(string[j][i]==playerChar&&i!=x-1)
		{
			string[j][x-1]=playerChar;
			string[j][x]=playerChar;
			for(m=i;m<x-1;++m)
			{
				string[j][m]=playerChar;
			}
			++count;
		}
	}
	i=x;
	j=y+1;//down
	while(j<size&&string[j][i]==targetChar)
		++j;
	if(j<size)
	{
		if(string[j][i]==playerChar&&j!=y+1)
		{
			string[y][i]=playerChar;
			for(m=y+1;m<j;++m)
			{
				string[m][i]=playerChar;
			}
			++count;
		}
	}
	i=x;
	j=y-1;//up
	while(j>=0&&string[j][i]==targetChar)
		--j;
	if(j>=0)
	{
		if(string[j][i]==playerChar&&j!=y-1)
		{
			string[y][i]=playerChar;
			string[y-1][i]=playerChar;
			for(m=j;m<y-1;++m)
			{
				string[m][i]=playerChar;
			}
			++count;
		}
	}
	i=x-1;
	j=y-1;//up-left
	while(j>=0&&i>=0&&string[j][i]==targetChar)
	{
		--i;
		--j;
	}
	if(j>=0&&i>=0)
	{
		if(string[j][i]==playerChar&&i!=x-1&&j!=y-1)
		{
			string[y][x]=playerChar;
			++count;
			m=j;
			n=i;
			while(m<y&&n<x)
			{
				string[m][n]=playerChar;
				++m;
				++n;
			}
		}
	}
	i=x+1;
	j=y+1;//down-right
	while(j<size&&i<size&&string[j][i]==targetChar)
	{
		++i;
		++j;
	}	
	if(j<size&&i<size)
	{
		if(string[j][i]==playerChar&&i!=x+1&&j!=y+1)
		{
			++count;
			string[y][x]=playerChar;
			string[y+1][x+1]=playerChar;
			m=y+1;
			n=x+1;
			while(m<j&&n<i)
			{
				string[m][n]=playerChar;
				++m;
				++n;
			}
		}
	}
	i=x+1;
	j=y-1;//up-right
	while(j>=0&&i<size&&string[j][i]==targetChar)
	{	
		++i;
		--j;
	}
	if(j>=0&&i<size)
	{
		if(string[j][i]==playerChar&&i!=x+1&&j!=y-1)
		{	
			++count;
			string[y][x]=playerChar;
			m=y-1;
			n=x+1;
			while(m>j&&n<i)
			{
				string[m][n]=playerChar;
				++n;
				--m;
			}		
		}
	}
	i=x-1;
	j=y+1;//down-left
	while(j<size&&i>=0&&string[j][i]==targetChar)
	{	
		--i;
		++j;
	}
	if(j<size&&i>=0)
	{
		if(string[j][i]==playerChar&&i!=x-1&&j!=y+1)
		{	
			++count;
			string[y][x]=playerChar;
			string[y+1][x-1]=playerChar;
			m=y+1;
			n=x-1;
			while(m<j&&n>i)
			{
				string[m][n]=playerChar;
				--n;
				++m;
			}
		}
	}
	if(count==0)
		return -1;
	return count;
}
int PlayComputerOneStep(char string[][20],int size,int &x,int &y)//plays one step for computer and returns coordinates.
{
	int i,j,max=0,total=0,coorX=0,coorY=0,count=0;
	for(i=0;i<size;++i)
	{
		for(j=0;j<size;++j)
		{
			total=CountMostElement(string,size,j,i,'X','O');
			if(total==-1)
				--count;
			if(total>max)
			{
				max=total;
				coorX=j;
				coorY=i;
			}	
		}
	}
	if(count!=-1*size*size)
	{
		x=coorX;
		y=coorY;
		playOneStep(string,size,coorX,coorY,'X','O');
	}
	return count;
}
int CountMostElement(char string[][20],int size,int x,int y,char playerPiece,char targetPiece)//count most pieces.
{
	int count=0;
	int i,j,m,n,a,b;
	i=x;
	j=y;
	i=x+1;
	if(string[y][x]!='.')
		return -1;
	
	while(i<size&&string[j][i]==targetPiece)
		++i;
	if(i<size)
	{
		if(string[j][i]==playerPiece&&i!=x+1)
		{
			for(m=x+1;m<i;++m)
			{
				++count;
			}	
		}
	}
	j=y;
	i=x-1;
	while(i>=0&&string[j][i]==targetPiece)
		--i;
	if(i>=0)
	{
		if(string[j][i]==playerPiece&&i!=x-1)
		{	
			for(m=i;m<x-1;++m)
			{
				++count;
			}
		}
	}
	i=x;
	j=y+1;
	while(j<size&&string[j][i]==targetPiece)
		++j;
	if(j<size)
	{
		if(string[j][i]==playerPiece&&j!=y+1)
		{
			for(m=y+1;m<j;++m)
			{
				++count;
			}	
		}
	}
	i=x;
	j=y-1;
	while(j>=0&&string[j][i]==targetPiece)
		--j;
	if(j>=0)
	{
		if(string[j][i]==playerPiece&&j!=y-1)
		{	
			for(m=j;m<y-1;++m)
			{
				++count;
			}
		}
	}
	i=x-1;
	j=y-1;
	while(j>=0&&i>=0&&string[j][i]==targetPiece)
	{
		--i;
		--j;
	}
	if(j>=0&&i>=0)
	{
		if(string[j][i]==playerPiece&&i!=x-1&&j!=y-1)
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
	while(j<size&&i<size&&string[j][i]==targetPiece)
	{
		++i;
		++j;
	}	
	if(j<size&&i<size)
	{
		if(string[j][i]==playerPiece&&j!=y+1&&i!=x+1)
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
	while(j>=0&&i<size&&string[j][i]==targetPiece)
	{
		++i;
		--j;
	}
	if(j>=0&&i<size)
	{
		if(string[j][i]==playerPiece&&i!=x+1&&j!=y-1)
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
	while(j<size&&i>=0&&string[j][i]==targetPiece)
	{
		--i;
		++j;
	}
	if(j<size&&i>=0)
	{
		if(string[j][i]==playerPiece&&i!=x-1&&j!=y+1)
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
int CheckPlayerStatus(char string[][20],int size)//checks if player have legal move 
{
	int i,j,total=0,status=0;
	for(i=0;i<size;++i)
	{
		for(j=0;j<size;++j)
		{
				status=CountMostElement(string,size,j,i,'O','X');
				
				if(status==-1)
					--total;
				status=0;
			
			
		}
	}
	return total;
}
int countPieces(char string[][20],int size,char piece)//return number of pieces of player or computer.
{
	int i=0,j=0,count=0;
	for(i=0;i<size;++i)
	{
		for(j=0;j<size;++j)
		{
			if(string[i][j]==piece)
				++count;
		}
	}
	return count;
}
int isFull(char string[][20],int size)//checks if board is full.
{
	int i,j,count=0;
	for(i=0;i<size;++i)
	{
		for(j=0;j<size;++j)
		{
			if(string[i][j]!='.')
				++count;
		}
	}
	if(count==size*size)
		return 1;
	else
		return 0;
}
