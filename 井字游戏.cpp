#include<stdio.h>//**打印函数的头文件**
#include<stdlib.h>
#include<time.h>//**电脑生成随机数的time函数头文件**
#define ROW 3//**此处用define定义3行3列的棋盘**
#define COL 3

void game();
void menu(); 
void InitBoard(char Board[ROW][COL],int row,int col);//**定义棋盘的函数声明**
void DisplayBoard(char Board[ROW][COL],int row,int col);//**打印棋盘的函数的声明**
void Computermove(char Board[ROW][COL],int row,int col);//**电脑移动的函数声明**
void Playermove(char Board[ROW][COL],int row,int col);//**玩家移动的函数声明**
char IsWin(char Board[ROW][COL],int row,int col);//**判断电脑或者玩家有没有获得游戏胜利的函数声明**
int IsFull(char Board[ROW][COL],int row,int col);//**判断是否平局的函数声明**

/*——————————————————————————————————————————
以上我们就实现了头文件和游戏大体逻辑部分，接下来我们则要实现最重要的游戏部分，头文件中的自定义函数声明我们都将在game.c中一一实现。
——————————————————————————————————————————————
首先来看定义的第一个函数，InitBoard函数，此函数将完成我们九个格子的初始化，我们将格子全部初始化为空格：*/
//首先编写一个简单的游戏逻辑

int main()
{
	int input;
	srand((unsigned int)time(NULL)); //**实现电脑生成随机数后面讲解**
	do
	{
		menu();//**游戏进入先打印一个菜单**
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();//**实现游戏的函数**
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;

		}
	}while(input);
	return 0;
}

/*——————————————————————————
以下部分放置于主函数之上即可

完成简单逻辑后我们应完成菜单的打印以及game（）函数的部分：*/
void menu()
{
	printf("******************\n");
	printf("***1.游戏开始*****\n");
	printf("***0.游戏退出*****\n");
	printf("******************\n");

}
void game()//**函数部分将在game.c部分进行进一步讲解**
{
	char Board[ROW][COL]={0};
	char ret;
	InitBoard(Board,ROW,COL);
	DisplayBoard(Board,ROW,COL);
	while(1)
	{
		Computermove(Board,ROW,COL);
		ret=IsWin(Board,ROW,COL);
		if(ret !=' ')
			break;
		DisplayBoard(Board,ROW,COL);
        Playermove(Board,ROW,COL);
		ret=IsWin(Board,ROW,COL);
		if(ret !=' ')
			break;
		DisplayBoard(Board,ROW,COL);
	
	}
	if(ret=='X')
	{
		printf("电脑赢\n");
	}
	else if(ret=='0')
	{
		printf("玩家赢\n");
	}
	else if(ret=='q')
	{
		printf("平局\n");
	}
	DisplayBoard(Board,ROW,COL);
}


void InitBoard(char Board[ROW][COL],int row,int col)        //**空型函数，Board[ROW][COL]接受指针，row，col为接受的形式参数**
{
	int i=0;//**使用简单的循环语句**
	for(i=0; i<row; i++)
	{
		int j=0;
		for(j=0; j<col; j++)
			Board[i][j]=' ';
	}
}
/*实际上我们还可以使用更方便的memset函数：
{
memset(&board[0][0],' ',col*row*board[0][0]);//此处不做过多的介绍
}*/

/*——————————————————————————————
接着打印我们的棋盘的分割线
——————————————————————————————
*/
void DisplayBoard(char Board[ROW][COL],int row,int col)

{
	int i=0;
	for(i=0; i<row; i++)
	{
		int j=0;
		for(j=0; j<col; j++)
		{
			printf(" %c ",Board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if(i<row-1)
		{
		for(j=0; j<col; j++)
		{
			printf("---");
		if(j<col-1)
			printf("|");
		}
		printf("\n");}		
	}
}

/*————————————————————————————————————
紧接着我们就要开始完成人机对战的逻辑
————————————————————————————————————-*/
//电脑移动

void Computermove(char Board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("电脑走\n");
	while(1)
	{
		x=rand()%row;//**rand（）即为让电脑生成随机数**
	    y=rand()%col;
	if(Board[x][y]==' ')
	 {
		Board[x][y]='X';	break;
	 }
 }
}

//玩家移动


void Playermove(char Board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("玩家走\n");//**此处为玩家自行输入坐标完成操作**
	while(1)
	{
		printf("请输入坐标\n");
	    scanf("%d%d",&x,&y);
	if(x>=1&&x<=row&&y>=1&&y<=col)
	{
		if(Board[x-1][y-1]==' ')
		{
			Board[x-1][y-1]='0';
			break;
		}
		else
		{
			printf("坐标被占用请重新输入\n");
		}

	}
	else
	{
		printf("输入有误请重新输入\n");
	}
	}
}
char IsWin(char Board[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0; i<row; i++)
	{
        if(Board[i][0]==Board[i][1]&&Board[i][1]==Board[i][2]&&Board[i][0]!=' ')//**行3个相连**
			return Board[i][0];//**只要不返回空格游戏继续**
	}
	for(i=0; i<col; i++)
	{
        if(Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]&&Board[0][i]!=' ')//**列3个相连**
			return Board[0][i];
	}
	if(Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2]&&Board[2][2]!=' ')//**对角线相连**
	{
		return Board[1][1];
	}

	if(Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0]&&Board[2][0]!=' ')
	{
		return Board[1][1];
	}
	if(IsFull(Board,row,col))//**这里判断是否出现平局**
	{
		return 'Q';
	}
	return ' ';}
int IsFull(char Board[ROW][COL],int row,int col)
	{
		int i=0;
		for(i=0; i<row; i++)
		{
			int j=0;
			for(j=0; j<col; j++)
			{
				if(Board[i][j]==' ')
					return 0;

			}
		}
		return 1;
	}




