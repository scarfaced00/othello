#include <stdio.h>
#include <stdlib.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
#include "head.h"
extern int gameboard[N][N];
int col,row;
char players[2][10]={"black","white"};
int is_room_exist(int row, int col)//����ڰ� �Է��� ���� �����ϴ� ĭ���� 
{
	if(row>=0 && row<N && col>=0 && col<N)
		return 1;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop*/

/*
void init_othello() //���� �ʱ�ȭ 
//�� ĭ=' ', �� ��='O', ������ ��='X'
{
	//��� ĭ ��ĭ���� 
	int i,j;
	for(i-0;i<N;i++)
		for(j=0;j<N;j++)
			gameboard[i][j]=EMPTY; 
	//ó�� 4���� �α� 
	gameboard[N/2-1][N/2]=BLACK;
	gameboard[N/2-1][N/2-1]=WHITE;
	gameboard[N/2][N/2]=WHITE;
	gameboard[N/2][N/2-1]=BLACK;
}
*/
/*
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

*/
/*void check_result()//��� ��� 
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
/*int player_change(int player)//���ʹٲٱ� 
{
	return (player%2 +1);
}
/*
int isGameEnd()
{
	if
 } 
 */
void input_index(int *row, int *col, int player) //��ǥ �Է¹ޱ� 
 {
 	printf("\nput a new %s othello : ",players[player-1]);
 	scanf("%d %d",row,col);
 	while(!room_exist(row,col))//���������ʴ�ĭ�̸� ��� �Է¹��� 
 	{
 		printf("Non existent coordinate\n");
 		printf("\nput a new %s othello : ",players[player-1]);
 		scanf("%d %d",row,col);  
	 } 
 }
int main(int argc, char *argv[]) {
	int player=2;//2��white�̰� 1��black 
	int i,j;
	int col,row;
	char players[2][10]={"black","white"};
	//char players[2][10]={"black","white"};
	init_othello();//�����ʱ�ȭ 
	print_othello(); 
	count_colors();
	//printf("\nput a new %s othello : ",players[player-1]);
	input_index(&row,&col,player); //��ǥ�Է� 
}
	/*
	while (isGameEnd==0){ //game���� ���� Ȯ�� 
	print_othello();//��ġ������� 
	count_colors();
	if(isThereRoom)//ĭ�� ����ִٸ�
		{
			
		}
	 	continue;
		

/*_Bool isThereRoom()//��ĭ�� �ִ��� Ȯ�� 
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
void count_colors() //���� �� �� ���� üũ 
{
	int black=0;
	int white=0;
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(gameboard[i][j]==BLACK)
				black++;
			else if(gameboard[i][j]==WHITE)
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
	//�Է� ĭ�� ���� ���� �ش�Ǵ� �� ������ 
	i=col-1;
	while(gameboard[row][i]==user) //���� ���ο� ����� �� ������ ��� �������� 
		i--;
	if(gamebaord[row][i]==opp)//���� ���� �����ϴ� ���� �� ������ 
	{
		i=col-1; 
		while(gameboard[row][i]==opp)//���ʰ��ο� �ִ� ���渻�� ��� ������� �˷� ���� 
		{
			gameboard[row][i]=user;
			i--;
		}
	}
 } 
 */
