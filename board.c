#include <stdio.h>


int main() //�� ���� ����ϱ� 
{
	char color='O';
	int col,row;
	printf("  0 1 2 3 4 5\n -------------\n");
	//������ �ϳ���
	for(row=0;row<6;row++)
		{
			printf("%d|",row);//���ȣ ���
			for(col=0;col<6;col++)
				printf("%c|",color);//������ �̸� x, ����̸� O,�ƹ��͵� ������ ������� 
			printf("\n -------------\n"); //��ٲٱ� �� 
		 }
} 
