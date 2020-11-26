#include <stdio.h>
#include <stdlib.h>
#define N 6
#define EMPTY ' '
#define White 79 //'O'
#define Black 88 //'X'
int gameboard[N][N];
int col,row;


/* run this program using the console pauser or add your own getch, system("pause") or input loop*/

void init_othello()//게임초기화 
{
	
}
void print_othello()//배치상태출력 
{
	printf("\n STATUS - WHITE : %d, BLACK : %d",status_w,status_b);
}
void check_result()//결과 출력 
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
int player_change(int player)
{
	return (playere%2 +1);
}
int main(int argc, char *argv[]) {
	int player=2;
	
	int i,j;
	init_othello();//게임초기화 
	
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
_Bool isThereRoom()//빈칸이 있는지 확인 
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
