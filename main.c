#include <stdio.h>
#include <stdlib.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
#include "head.h"
int gameboard[N][N];
int col,row;
char players[2][10]={"black","white"};
int room_exist(int row, int col)//사용자가 입력한 값이 존재하는 칸인지 
{
	if(row>=0 && row<N && col>=0 && col<N)
		return 1;
}

int player_change(int player)//차례바꾸기 
{
	return (player%2 +1);
}

void input_index(int *row, int *col, int player) //좌표 입력받기 
 {
 	printf("\nput a new %s othello : ",players[player-1]);
 	scanf("%d %d",row,col);
 	while(!flip_ok(*row, *col, player))//뒤집기가 유효하지 않다면 입력다시 
 	{
 		printf("invalid input\n");
 		printf("\nput a new %s othello : ",players[player-1]);
 		scanf("%d %d",row,col);  
	 } 
 }
 void count_colors() //색깔 별 알 개수 체크 
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
void flip(int row, int col, int player)//뒤집기 
{
	int i,j;
	char user, opp;
	//상대편과 사용자 색깔 설정 
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
	gameboard[row][col] = user;
	//입력했을 때 그 칸 세로 위 칸들 뒤집을 수 있을 때 뒤집기 
	i = row - 1;
	while (room_exist(i, col) && gameboard[i][col] == opp) //보드에서 벗어나지않고, 상대방 알이 있으면 계속 위칸 점검 
		i--;
	if (room_exist(i, col) && gameboard[i][col] == user) { //그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기 
		i = row - 1;
		while (gameboard[i][col] == opp) {
			gameboard[i][col] = user;
			i--;
		}
	}
	//입력했을 때 그 칸 세로 아래 칸들 뒤집을 수 있을 때 뒤집기
	i = row + 1;
	while (room_exist(i, col) && gameboard[i][col] == opp) //보드에서 벗어나지않고, 상대방 알이 있으면 계속 아래칸 점검 
		i++;
	if (room_exist(i, col) && gameboard[i][col] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		i = row + 1;
		while (gameboard[i][col] == opp) {
			gameboard[i][col] = user;
			i++;
		}
	}
	//입력했을 때 그 칸 가로 오른쪽 칸들 뒤집을 수 있을 때 뒤집기
	j = col + 1;
	while (room_exist(row, j) && gameboard[row][j] == opp) //보드에서 벗어나지않고, 상대방 알이 있으면 계속 오른쪽칸 점검 
		j++;
	if (room_exist(row, j) && gameboard[row][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		j = col + 1;
		while (gameboard[row][j] == opp) {
			gameboard[row][j] = user;
			j++;
		}
	}
	//입력했을 때 그 칸 가로 왼쪽 칸들 뒤집을 수 있을 때 뒤집기
	j = col - 1;
	while (room_exist(row, j) && gameboard[row][j] == opp) //보드에서 벗어나지않고, 상대방 알이 있으면 계속 왼쪽칸 점검
		j--;
	if (room_exist(row, j) && gameboard[row][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		j = col - 1;
		while (gameboard[row][j] == opp) {
			gameboard[row][j] = user;
			j--;
		}
	}
	//입력했을 때 그 칸 오른쪽 위 대각선 칸들 뒤집을 수 있을 때 뒤집기 
	i = row - 1; //행은 위쪽으로 이동하고 
	j = col + 1; //열은 오른쪽으로 이동 
	while (room_exist(i, j) && gameboard[i][j] == opp) {//보드에서 벗어나지않고, 상대방 알이 있으면 계속 오른쪽 위칸 점검
		i--;
		j++;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		i = row - 1;
		j = col + 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i--;
			j++;
		}
	}
	//입력했을 때 그 칸 오른쪽 아래 대각선 칸들 뒤집을 수 있을 때 뒤집기
	i = row + 1; //행은 아래쪽으로 이동하고 
	j = col + 1; //열은 오른쪽으로 이동 
	while (room_exist(i, j) && gameboard[i][j] == opp) {//보드에서 벗어나지않고, 상대방 알이 있으면 계속 오른쪽 아래칸 점검
		i++;
		j++;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		i = row + 1;
		j = col + 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i++;
			j++;
		}
	}
	//입력했을 때 그 칸 왼쪽 위 대각선 칸들 뒤집을 수 있을 때 뒤집기
	i = row - 1;//행은 위쪽으로 이동하고 
	j = col - 1;//열은 왼쪽으로 이동
	while (room_exist(i, j) && gameboard[i][j] == opp) {//보드에서 벗어나지않고, 상대방 알이 있으면 계속 왼쪽 위칸 점검
		i--;
		j--;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		i = row - 1;
		j = col - 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i--;
			j--;
		}
	}
	//입력했을 때 그 칸 왼쪽 아래 대각선 칸들 뒤집을 수 있을 때 뒤집기
	i = row + 1;//행은 아래쪽으로 이동하고
	j = col - 1;//열은 왼쪽으로 이동
	while (room_exist(i, j) && gameboard[i][j] == opp) {//보드에서 벗어나지않고, 상대방 알이 있으면 계속 왼쪽 아래칸 점검
		i++;
		j--;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//그 인덱스가 보드 벗어나지 않고, 사용자 알이라면 입력값과 그 칸 사이 뒤집기
		i = row + 1;
		j = col - 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i++;
			j--;
		}
	}
}
int flip_ok(int row, int col, int player) //뒤집기가 유효한지 점검 
{
	int i,j;
	char user, opp;
	//상대편과 사용자 색깔 설정 
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
	if(gameboard[row][col]!=EMPTY)//입력좌표값이 비어있지 않으면 유효하지않다 
		return 0; 
}
int main(int argc, char *argv[]) {
	int player=2;//2가white이고 1이black 
	int i,j;
	int col,row;
	char players[2][10]={"black","white"};
	init_othello();//게임초기화 
	while(1)
	{
		print_othello(); //판출력 
		count_colors(); //status출력 
		input_index(&row,&col,player); //좌표입력
		flip(row,col,player);
		player=player_change(player); //차례바꾸기 
	 }  
}

