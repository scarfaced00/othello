#include <stdio.h>
#define N 6
int gameboard[N][N]; 
int main() //�� ���� ����ϱ� 
/*�� ĭ=0, �� ��='O', ������ ��='X'*/ 
{
	int col,row;//���� �� 
	printf("  0 1 2 3 4 5\n -------------\n");
	//������ �ϳ���
	for(row=0;row<6;row++)
		{
			printf("%d|",row);//���ȣ ���
			for(col=0;col<6;col++)
			{
				if(gameboard[row][col]==0)
					printf(" |");//gameboard���Ұ� 0�̸� ������ ��µǰ���
				else
					printf("%d|",gameboard[row][col]);
			}
			//������ �̸� x, ����̸� O,�ƹ��͵� ������ ������� 
			printf("\n -------------\n"); //��ٲٱ� �� 
		 }
} 
