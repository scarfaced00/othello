#include <stdio.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
extern gameboard[N][N];
extern int col,row;
void init_othello() //���� �ʱ�ȭ 
//�� ĭ=' ', �� ��='O', ������ ��='X'
{
	//��� ĭ ��ĭ���� 
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			gameboard[i][j]=EMPTY; 
	//ó�� 4���� �α� 
	gameboard[N/2-1][N/2]=BLACK;
	gameboard[N/2-1][N/2-1]=WHITE;
	gameboard[N/2][N/2]=WHITE;
	gameboard[N/2][N/2-1]=BLACK;
}

void print_othello()//��ġ������� 
{
	printf("  0 1 2 3 4 5\n -------------\n");
	//������ �ϳ���
	for(row=0;row<N;row++)
		{
			printf("%d|",row);//���ȣ ���
			for(col=0;col<N;col++)
			{
				if(gameboard[row][col]==' ')
					printf(" |");//gameboard���Ұ� 0�̸� ������ ��µǰ���
				else
					printf("%c|",gameboard[row][col]);
			}
			//������ �̸� x, ����̸� O,�ƹ��͵� ������ ������� 
			printf("\n -------------\n"); //��ٲٱ� �� 
		 }
}
