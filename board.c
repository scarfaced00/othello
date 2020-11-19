#include <stdio.h>
#define N 6
int gameboard[N][N]; 
int main() //빈 보드 출력하기 
/*빈 칸=0, 흰 알='O', 검은색 알='X'*/ 
{
	int col,row;//열과 행 
	printf("  0 1 2 3 4 5\n -------------\n");
	//가로줄 하나씩
	for(row=0;row<6;row++)
		{
			printf("%d|",row);//행번호 출력
			for(col=0;col<6;col++)
			{
				if(gameboard[row][col]==0)
					printf(" |");//gameboard원소가 0이면 공백이 출력되게함
				else
					printf("%d|",gameboard[row][col]);
			}
			//검은색 이면 x, 흰색이면 O,아무것도 없으면 공백출력 
			printf("\n -------------\n"); //행바꾸기 선 
		 }
} 
