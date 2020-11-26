void init_othello() //보드 초기화 
/*빈 칸=' ', 흰 알='O', 검은색 알='X'*/ 
{
	//모든 칸 빈칸으로 
	int i,j;
	for(i-0;i<N;i++)
		for(j=0;j<N;++)
			gameboard[i][j]=EMPTY; 
	//처음 4개알 두기 
	gameboard[N/2-1][N/2]=White;
	gameboard[N/2-1][N/2-1]=Black;
	gameboard[N/2][N/2]=Black;
	gameboard[N/2][N/2-1]=White;
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

int is_room_exist(int row, int col)//사용자가 입력한 값이 존재하는 칸인지 
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
