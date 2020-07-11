#include<stdio.h>//**��ӡ������ͷ�ļ�**
#include<stdlib.h>
#include<time.h>//**���������������time����ͷ�ļ�**
#define ROW 3//**�˴���define����3��3�е�����**
#define COL 3

void game();
void menu(); 
void InitBoard(char Board[ROW][COL],int row,int col);//**�������̵ĺ�������**
void DisplayBoard(char Board[ROW][COL],int row,int col);//**��ӡ���̵ĺ���������**
void Computermove(char Board[ROW][COL],int row,int col);//**�����ƶ��ĺ�������**
void Playermove(char Board[ROW][COL],int row,int col);//**����ƶ��ĺ�������**
char IsWin(char Board[ROW][COL],int row,int col);//**�жϵ��Ի��������û�л����Ϸʤ���ĺ�������**
int IsFull(char Board[ROW][COL],int row,int col);//**�ж��Ƿ�ƽ�ֵĺ�������**

/*������������������������������������������������������������������������������������
�������Ǿ�ʵ����ͷ�ļ�����Ϸ�����߼����֣�������������Ҫʵ������Ҫ����Ϸ���֣�ͷ�ļ��е��Զ��庯���������Ƕ�����game.c��һһʵ�֡�
��������������������������������������������������������������������������������������������
������������ĵ�һ��������InitBoard�������˺�����������ǾŸ����ӵĳ�ʼ�������ǽ�����ȫ����ʼ��Ϊ�ո�*/
//���ȱ�дһ���򵥵���Ϸ�߼�

int main()
{
	int input;
	srand((unsigned int)time(NULL)); //**ʵ�ֵ���������������潲��**
	do
	{
		menu();//**��Ϸ�����ȴ�ӡһ���˵�**
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();//**ʵ����Ϸ�ĺ���**
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("������������������\n");
			break;

		}
	}while(input);
	return 0;
}

/*����������������������������������������������������
���²��ַ�����������֮�ϼ���

��ɼ��߼�������Ӧ��ɲ˵��Ĵ�ӡ�Լ�game���������Ĳ��֣�*/
void menu()
{
	printf("******************\n");
	printf("***1.��Ϸ��ʼ*****\n");
	printf("***0.��Ϸ�˳�*****\n");
	printf("******************\n");

}
void game()//**�������ֽ���game.c���ֽ��н�һ������**
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
		printf("����Ӯ\n");
	}
	else if(ret=='0')
	{
		printf("���Ӯ\n");
	}
	else if(ret=='q')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(Board,ROW,COL);
}


void InitBoard(char Board[ROW][COL],int row,int col)        //**���ͺ�����Board[ROW][COL]����ָ�룬row��colΪ���ܵ���ʽ����**
{
	int i=0;//**ʹ�ü򵥵�ѭ�����**
	for(i=0; i<row; i++)
	{
		int j=0;
		for(j=0; j<col; j++)
			Board[i][j]=' ';
	}
}
/*ʵ�������ǻ�����ʹ�ø������memset������
{
memset(&board[0][0],' ',col*row*board[0][0]);//�˴���������Ľ���
}*/

/*������������������������������������������������������������
���Ŵ�ӡ���ǵ����̵ķָ���
������������������������������������������������������������
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

/*������������������������������������������������������������������������
���������Ǿ�Ҫ��ʼ����˻���ս���߼�
������������������������������������������������������������������������-*/
//�����ƶ�

void Computermove(char Board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("������\n");
	while(1)
	{
		x=rand()%row;//**rand������Ϊ�õ������������**
	    y=rand()%col;
	if(Board[x][y]==' ')
	 {
		Board[x][y]='X';	break;
	 }
 }
}

//����ƶ�


void Playermove(char Board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("�����\n");//**�˴�Ϊ�����������������ɲ���**
	while(1)
	{
		printf("����������\n");
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
			printf("���걻ռ������������\n");
		}

	}
	else
	{
		printf("������������������\n");
	}
	}
}
char IsWin(char Board[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0; i<row; i++)
	{
        if(Board[i][0]==Board[i][1]&&Board[i][1]==Board[i][2]&&Board[i][0]!=' ')//**��3������**
			return Board[i][0];//**ֻҪ�����ؿո���Ϸ����**
	}
	for(i=0; i<col; i++)
	{
        if(Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]&&Board[0][i]!=' ')//**��3������**
			return Board[0][i];
	}
	if(Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2]&&Board[2][2]!=' ')//**�Խ�������**
	{
		return Board[1][1];
	}

	if(Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0]&&Board[2][0]!=' ')
	{
		return Board[1][1];
	}
	if(IsFull(Board,row,col))//**�����ж��Ƿ����ƽ��**
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




