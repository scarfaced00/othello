#include <stdio.h>
#include <stdlib.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
int gameboard[N][N];
int col,row;



/* run this program using the console pauser or add your own getch, system("pause") or input loop*/

void init_othello() //보드 초기화 
/*빈 칸=' ', 흰 알='O', 검은색 알='X'*/ 
{
	//모든 칸 빈칸으로 
	int i,j;
	for(i-0;i<N;i++)
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

/*void check_result()//결과 출력 
{
	printf(" : : flip result : :\n");
	printf("W: %d E: %d N: %d S: %d NW: %d NE: %d SW: %d SE: %d\n",);
	printf("%s has flipped %d othellos!\n");
}
int ok()
{
  int i,j;
  int status_w,status_b; 
  for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            if(gameboard[i][j]==0)
                return 1;
    }
}
*/
int player_change(int player)//차례바꾸기 
{
	return (player%2 +1);
}
/*
int isGameEnd()
{
	if
 } 
 */
int main(int argc, char *argv[]) {
	int player=2;//2가white이고 1이black 
	int i,j;
	char players[2][10]={"black","white"};
	init_othello();//게임초기화 
	print_othello();
	count_colors();
	printf("\nput a new %s othello\n",players[player-1]);
}
	/*
	while (isGameEnd==0){ //game종료 조건 확인 
	print_othello();//배치상태출력 
	count_colors();
	if(isThereRoom)//칸이 비어있다면
		{
			
		}
	 	continue;
		
	if(ok()==1)//보드판에 0이 있다면(꽉차지 않았다면) 
  {
    continue;
    }
    printf("put a new %s othello:",colors[0]);
    scanf("%d %d",&x,&y);
    gameboard[x][y]=1;
    printf("%d",gameboard[x][y]);
    if(gameboard[x][y])
}
	return 0;
}
*/
/*_Bool isThereRoom()//빈칸이 있는지 확인 
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gameboard[i][j]==' ')
			return 0;
		}
	 }
	return 1; 
}
*/
void count_colors()
{
	int black=0;
	int white=0;
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gameboard[N][N]==BLACK)
				black++;
			else if(gameboard[N][N]==WHITE)
				white++;
		}
	}
	printf("\nSTATUS - WHITE : %d, BLACK : %d\n",white,black);
}
/*
void flip(int row, int col, int player)
{
	int i,j;
	char user, opp;
	if(player==1)
	{
		user=BLACK;
		opp=WHITE;
	}
	else
	{
		user=WHITE;
		opp=BLACK;
	}
	//입력 칸의 왼쪽 가로 해당되는 알 뒤집기 
	i=col-1;
	while(gameboard[row][i]==user) //왼쪽 가로에 사용자 알 있으면 계속 왼쪽으로 
		i--;
	if(gamebaord[row][i]==opp)//왼쪽 가로 점검하다 상대방 알 만나면 
	{
		i=col-1; 
		while(gameboard[row][i]==opp)//왼쪽가로에 있는 상대방말을 모두 사용자의 알로 변경 
		{
			gameboard[row][i]=user;
			i--;
		}
	}
 } 
 */
