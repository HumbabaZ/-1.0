#include "ai.h"

/*
 * YOUR CODE BEGIN
 * ��Ĵ��뿪ʼ
 */
 
/* 
 * You can define your own struct and variable here
 * ����������ﶨ�����Լ��Ľṹ��ͱ���
 */

int testboard[BOARD_SIZE][BOARD_SIZE];
int menum,othernum;		//������
int me_score[BOARD_SIZE][BOARD_SIZE][4];		//�÷� 
int other_score[BOARD_SIZE][BOARD_SIZE][4];
int total_me,total_other;		//�ܷ� 


/*
 * You should init your AI here
 * �������ʼ�����AI
 */
void initAI()
{
	int i,j;
	
	total_me=0;total_other=0;
	
	for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
        {
        	me_score[i][j][4]=0;
        	other_score[i][j][4]=0;
        }
}

/*
 * Game Start, you will put the first chess.
 * Warning: This method will only be called when after the initialize ofi the  map, it is your turn to put the chess. 
 * Or this method will not be called.
 * You should return a valid Position variable.
 * ��ֿ�ʼ����������������
 * ��ע�⣺ֻ���ڵ���ֳ�ʼ�����ֵ�������ʱ�Żᴥ������������������ֳ�ʼ����Ϻ��ֵ��������ӣ�������������ᱻ�����������ĿҪ��
 * �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
 * ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á� 
 */
struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * ������������д�����AI�� 
     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 
     */
    int i, j;
    int points; 
    struct Position preferedPos;
    
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (EMPTY == board[i][j])
            {
                preferedPos.x = i;
                preferedPos.y = j;
                return preferedPos;
            }
        }
    
    return preferedPos;
}

/*
 * Game ongoing, the competitor put the chess at the position (otherX, otherY). You should put your chess.
 * You should return a valid Position variable.
 * ��ֽ����У��Է���һ��������(otherX, otherY)��λ�ã��ֵ��������ˡ�
 * �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�
 * ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á� 
 */
struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * ������������д�����AI�� 
     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 
     */
    int i, j;
    struct Position preferedPos;
    int points;
    
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (EMPTY == board[i][j])
            {
            	testboard[i][j]==1;
            	
            }
            	
    
    
}

/*
 * YOUR CODE END
 * ��Ĵ������ 
 */
