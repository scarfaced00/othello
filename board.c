#define N 6
void init_othello() //���� �ʱ�ȭ 
/*�� ĭ=' ', �� ��='O', ������ ��='X'*/ 
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
 
extern void print_othello()//��ġ������� 
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

int room_exist(int row, int col)//����ڰ� �Է��� ���� �����ϴ� ĭ���� 
{
	if(row>=0 && row<N && col>=0 && col<N)
		return 1;
}

int flip_ok(int row, int col, int player) //������ �� �ִ� �Է����� 
{
	int i, j
	int ok;
	char user, opp; 
	//����ڿ� ����� ���� 
	if(player==1)
	{
		user=BLACK;
		opp=WHITE; 
	 } 
	else{
		user=WHITE;
		opp=BLACK;
	}
	gameboard[row][col]=user;
	
	
	//�Է��� ���� ���� ����
	i=col-1;
	ok=0;
	while(room_exist(row,i) && gameboard[row][i]==opp)//��ĭ���� �����ϴ� ĭ�̰� ���� �������ϸ� 
	{
		i--; //��ĭ���������� 
		ok=1;
	}
	if(room_exist(row,i) && gameboard[row][i])==user) //�����ϴ� ĭ�̰� ����� ���� ���� 
	{
		return 1;
	}
}
