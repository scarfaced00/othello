#include <stdio.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
extern gameboard[N][N];
extern int col,row;
void init_othello() //보드 초기화 
//빈 칸=' ', 흰 알='O', 검은색 알='X'
{
	//모든 칸 빈칸으로 
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			gameboard[i][j]=EMPTY; 
	//처음 4개알 두기 
	gameboard[N/2-1][N/2]=BLACK;
	gameboard[N/2-1][N/2-1]=WHITE;
	gameboard[N/2][N/2]=WHITE;
	gameboard[N/2][N/2-1]=BLACK;
}

void print_othello()//배치상태출력 
{
	printf("  0 1 2 3 4 5\n -------------\n");
	//가로줄 하나씩
	for(row=0;row<N;row++)
		{
			printf("%d|",row);//행번호 출력
			for(col=0;col<N;col++)
			{
				if(gameboard[row][col]==' ')
					printf(" |");//gameboard원소가 0이면 공백이 출력되게함
				else
					printf("%c|",gameboard[row][col]);
			}
			//검은색 이면 x, 흰색이면 O,아무것도 없으면 공백출력 
			printf("\n -------------\n"); //행바꾸기 선 
		 }
}
