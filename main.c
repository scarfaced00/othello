#include <stdio.h>
#include <stdlib.h>
#define N 6
int gameboard[N][N];


/* run this program using the console pauser or add your own getch, system("pause") or input loop*/

void init_othello()//�����ʱ�ȭ 
{
	
}
void print_othello()//��ġ������� 
{
	printf("\n STATUS - WHITE : %d, BLACK : %d",status_w,status_b);
}
void check_result()//��� ��� 
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
int main(int argc, char *argv[]) {
	int i,j;
	while (isGameEnd==0){
	print_othello();
	if(ok()==1)//�����ǿ� 0�� �ִٸ�(������ �ʾҴٸ�) 
  {
    continue;
    }
    printf("put a new white othello:");
    scanf("%d %d",&x,&y);
    gameboard[x][y]=1;
    printf("%d",gameboard[x][y]);
    if()
}
	return 0;
}

