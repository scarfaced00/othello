#include <stdio.h>


int main() //빈 보드 출력하기 
{
	char color='O';
	int col,row;
	printf("  0 1 2 3 4 5\n -------------\n");
	//가로줄 하나씩
	for(row=0;row<6;row++)
		{
			printf("%d|",row);//행번호 출력
			for(col=0;col<6;col++)
				printf("%c|",color);//검은색 이면 x, 흰색이면 O,아무것도 없으면 공백출력 
			printf("\n -------------\n"); //행바꾸기 선 
		 }
} 
