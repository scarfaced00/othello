void init_othello() //���� �ʱ�ȭ 
/*�� ĭ=' ', �� ��='O', ������ ��='X'*/ 
{
	//��� ĭ ��ĭ���� 
	int i,j;
	for(i-0;i<N;i++)
		for(j=0;j<N;++)
			gameboard[i][j]=EMPTY; 
	//ó�� 4���� �α� 
	gameboard[N/2-1][N/2]=White;
	gameboard[N/2-1][N/2-1]=Black;
	gameboard[N/2][N/2]=Black;
	gameboard[N/2][N/2-1]=White;
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

int is_room_exist(int row, int col)//����ڰ� �Է��� ���� �����ϴ� ĭ���� 
{
	if(row>=0 && row<N && col>=0 && col<N)
		return 1;
}

int move_ok(int row, int col, char player) 
{
	int i, j
	int ok;
	char user, opp; 
	
}
