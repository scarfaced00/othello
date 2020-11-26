#include <stdio.h>
#include <stdlib.h>
#define N 6
#define EMPTY ' '
#define WHITE 79 //'O'
#define BLACK 88 //'X'
int gameboard[N][N];
int col,row;
char players[2][10]={"black","white"};
int room_exist(int row, int col)//����ڰ� �Է��� ���� �����ϴ� ĭ���� 
{
	if(row>=0 && row<N && col>=0 && col<N)
		return 1;
}

void init_othello() //���� �ʱ�ȭ 
//�� ĭ=' ', �� ��='O', ������ ��='X'
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

int player_change(int player)//���ʹٲٱ� 
{
	return (player%2 +1);
}

void input_index(int *row, int *col, int player) //��ǥ �Է¹ޱ� 
 {
 	printf("\nput a new %s othello : ",players[player-1]);
 	scanf("%d %d",row,col);
 	while(!flip_ok(*row, *col, player))//�����Ⱑ ��ȿ���� �ʴٸ� �Է´ٽ� 
 	{
 		printf("invalid input\n");
 		printf("\nput a new %s othello : ",players[player-1]);
 		scanf("%d %d",row,col);  
	 } 
 }
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
void flip(int row, int col, int player)//������ 
{
	int i,j;
	char user, opp;
	//������ ����� ���� ���� 
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
	//�Է����� �� �� ĭ ���� �� ĭ�� ������ �� ���� �� ������ 
	i = row - 1;
	while (room_exist(i, col) && gameboard[i][col] == opp) //���忡�� ������ʰ�, ���� ���� ������ ��� ��ĭ ���� 
		i--;
	if (room_exist(i, col) && gameboard[i][col] == user) { //�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������ 
		i = row - 1;
		while (gameboard[i][col] == opp) {
			gameboard[i][col] = user;
			i--;
		}
	}
	//�Է����� �� �� ĭ ���� �Ʒ� ĭ�� ������ �� ���� �� ������
	i = row + 1;
	while (room_exist(i, col) && gameboard[i][col] == opp) //���忡�� ������ʰ�, ���� ���� ������ ��� �Ʒ�ĭ ���� 
		i++;
	if (room_exist(i, col) && gameboard[i][col] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		i = row + 1;
		while (gameboard[i][col] == opp) {
			gameboard[i][col] = user;
			i++;
		}
	}
	//�Է����� �� �� ĭ ���� ������ ĭ�� ������ �� ���� �� ������
	j = col + 1;
	while (room_exist(row, j) && gameboard[row][j] == opp) //���忡�� ������ʰ�, ���� ���� ������ ��� ������ĭ ���� 
		j++;
	if (room_exist(row, j) && gameboard[row][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		j = col + 1;
		while (gameboard[row][j] == opp) {
			gameboard[row][j] = user;
			j++;
		}
	}
	//�Է����� �� �� ĭ ���� ���� ĭ�� ������ �� ���� �� ������
	j = col - 1;
	while (room_exist(row, j) && gameboard[row][j] == opp) //���忡�� ������ʰ�, ���� ���� ������ ��� ����ĭ ����
		j--;
	if (room_exist(row, j) && gameboard[row][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		j = col - 1;
		while (gameboard[row][j] == opp) {
			gameboard[row][j] = user;
			j--;
		}
	}
	//�Է����� �� �� ĭ ������ �� �밢�� ĭ�� ������ �� ���� �� ������ 
	i = row - 1; //���� �������� �̵��ϰ� 
	j = col + 1; //���� ���������� �̵� 
	while (room_exist(i, j) && gameboard[i][j] == opp) {//���忡�� ������ʰ�, ���� ���� ������ ��� ������ ��ĭ ����
		i--;
		j++;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		i = row - 1;
		j = col + 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i--;
			j++;
		}
	}
	//�Է����� �� �� ĭ ������ �Ʒ� �밢�� ĭ�� ������ �� ���� �� ������
	i = row + 1; //���� �Ʒ������� �̵��ϰ� 
	j = col + 1; //���� ���������� �̵� 
	while (room_exist(i, j) && gameboard[i][j] == opp) {//���忡�� ������ʰ�, ���� ���� ������ ��� ������ �Ʒ�ĭ ����
		i++;
		j++;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		i = row + 1;
		j = col + 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i++;
			j++;
		}
	}
	//�Է����� �� �� ĭ ���� �� �밢�� ĭ�� ������ �� ���� �� ������
	i = row - 1;//���� �������� �̵��ϰ� 
	j = col - 1;//���� �������� �̵�
	while (room_exist(i, j) && gameboard[i][j] == opp) {//���忡�� ������ʰ�, ���� ���� ������ ��� ���� ��ĭ ����
		i--;
		j--;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		i = row - 1;
		j = col - 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i--;
			j--;
		}
	}
	//�Է����� �� �� ĭ ���� �Ʒ� �밢�� ĭ�� ������ �� ���� �� ������
	i = row + 1;//���� �Ʒ������� �̵��ϰ�
	j = col - 1;//���� �������� �̵�
	while (room_exist(i, j) && gameboard[i][j] == opp) {//���忡�� ������ʰ�, ���� ���� ������ ��� ���� �Ʒ�ĭ ����
		i++;
		j--;
	}
	if (room_exist(i, j) && gameboard[i][j] == user) {//�� �ε����� ���� ����� �ʰ�, ����� ���̶�� �Է°��� �� ĭ ���� ������
		i = row + 1;
		j = col - 1;
		while (gameboard[i][j] == opp) {
			gameboard[i][j] = user;
			i++;
			j--;
		}
	}
}
int flip_ok(int row, int col, int player) //�����Ⱑ ��ȿ���� ���� 
{
	int i,j;
	char user, opp;
	//������ ����� ���� ���� 
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
	if(gameboard[row][col]!=EMPTY)//�Է���ǥ���� ������� ������ ��ȿ�����ʴ� 
		return 0; 
}
int main(int argc, char *argv[]) {
	int player=2;//2��white�̰� 1��black 
	int i,j;
	int col,row;
	char players[2][10]={"black","white"};
	init_othello();//�����ʱ�ȭ 
	while(1)
	{
		print_othello(); //����� 
		count_colors(); //status��� 
		input_index(&row,&col,player); //��ǥ�Է�
		flip(row,col,player);
		player=player_change(player); //���ʹٲٱ� 
	 }  
}

