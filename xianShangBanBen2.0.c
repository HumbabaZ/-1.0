#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define BOARD_SIZE 20

#define EMPTY 0

#define ME 1

#define OTHER 2



#define TRUE 1

#define FALSE 0



#define MAX_BYTE 10000



#define START "START"

#define PLACE "PLACE"

#define DONE  "DONE"

#define TURN  "TURN" 

#define BEGIN "BEGIN"

#define END   "END"



struct Position

{

    int x;

    int y;

}; 



char buffer[MAX_BYTE] = {0};

char board[BOARD_SIZE][BOARD_SIZE] = {0};



void debug(const char *str)

{

    printf("DEBUG %s\n", str);

    fflush(stdout);

}



/*

 * YOUR CODE BEGIN

 * ��Ĵ��뿪ʼ 

 */

 

/* 

 * You can define your own struct and variable here

 * ����������ﶨ�����Լ��Ľṹ��ͱ���

 */
//�ṹ��

struct count{
	int mine;
	int others;
	int empty;
};

struct thepoint{
	const int FIVE;
	const int FOUR;
	const int preFOUR;
	const int THREE;
	const int blockFOUR;
	const int preTHREE;
	const int TWO;
	const int blockTHREE;
	const int preTWO;
	const int blockpreFOUR;
	const int blockTWO;
	
};
 
//����
 
int table[BOARD_SIZE][BOARD_SIZE]={0};
int menum,othernum;		//������
int mescore[BOARD_SIZE][BOARD_SIZE][4]={0};		//�÷� 
int otherscore[BOARD_SIZE][BOARD_SIZE][4]={0};		//������[]:0--�� 1--�� 2--���Խ��� 3--���Խ���
int totalse,totalother;		//�ܷ� 
int waitlist[BOARD_SIZE][BOARD_SIZE]={0};		//��ѡ�б� 

struct count countfive[4][5]={				//���㵱ǰ�������С��С��Խ����Ͽ�λ��������ӵ���Ŀ 
 								0,0,0								//��һ��[]:0--�� 1--�� 2--���Խ��� 3--���Խ��� 
 								};										//�ڶ���[]��0--��ǰ��λ��countfive�����ֵ�� 

struct thepoint POINT={
						100000,		//FIVE
						80000,		//FOUR
						6000,		//preFOUR
						5000,		//THREE
						4000,		//blockFOUR
						800,		//preTHREE
						650,		//TWO
						500,		//blockTHREE
						250,		//preTWO
						150,		//blockpreFOUR
						50			//blockTWO
};


//����

void waitList();		//��ѡ�б� 
int hasNeibor(int x,int y);		//ֱ������ 
int nextNeibor(int x,int y);	//�������								
void Evaluate(int x,int y);		//����ǰ�����Ӻ�������� 
void countFive(int x,int y);		// ���㵱ǰ�������С��С��Խ����Ͽ�λ��������ӵ���Ŀ 


/*
 * You should init your AI here
 * �������ʼ�����AI
 */
void initAI()
{
	
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
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (EMPTY == board[i][j])
            {
                preferedPos.x = i;
                preferedPos.y = j;
                return preferedPos;
            }
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
    int score[BOARD_SIZE][BOARD_SIZE];
    
    waitList();
    
    for (i = 0; i < BOARD_SIZE; i++)
    {
	   
        for (j = 0; j < BOARD_SIZE; j++)
        {
        	
        	table[i][j]=board[i][j];
        }
    }
    
    for (i = 0; i < BOARD_SIZE; i++)
    {

        for (j = 0; j < BOARD_SIZE; j++)
        {

        	
            if (EMPTY == board[i][j]&&waitlist[i][j]!=0)
            {
            	
            	table[i][j]=ME;
            	
            	countFive(i,j);
            	Evaluate(i,j);
            	
            	
            }
 		}
	}
}

/*

 * YOUR CODE END

 * ��Ĵ������ 

 */



void place(int x, int y, int z)

{

    board[x][y] = z;

}



void done()

{

    printf("OK\n");

    fflush(stdout);

}



void start()

{

    memset(board, 0, sizeof(board));

    initAI();

}



void turn(int x, int y)

{

    board[x][y] = OTHER;

    

    // AI

    struct Position pos = aiTurn((const char (*)[20])board, ME, x, y);

    board[pos.x][pos.y] = ME;

    printf("%d %d\n", pos.x, pos.y);

    fflush(stdout);

}



void end(int x)

{

    

}



void loop()

{

    while (TRUE)

    {

        memset(buffer, 0, sizeof(buffer));

        gets(buffer);

        

        if (strstr(buffer, START))

        {

            start();

        }

        else if (strstr(buffer, PLACE))

        {

            char tmp[MAX_BYTE] = {0};

            int x,  y, z;

            sscanf(buffer, "%s %d %d %d", tmp, &x, &y, &z);

            place(x, y, z);

        }

        else if (strstr(buffer, DONE))

        {

            done();

        }

        else if (strstr(buffer, BEGIN))

        {

    		// AI

    		struct Position pos = aiBegin((const char (*)[20])board, ME);

    		board[pos.x][pos.y] = ME;

    		printf("%d %d\n", pos.x, pos.y);

    		fflush(stdout);

		}

        else if (strstr(buffer, TURN))

        {

            char tmp[MAX_BYTE] = {0};

            int x,  y;

            sscanf(buffer, "%s %d %d", tmp, &x, &y);

            turn(x, y);

        }

        else if (strstr(buffer, END))

        {

            char tmp[MAX_BYTE] = {0};

            int x;

            sscanf(buffer, "%s %d", tmp, &x);

            end(x);

        }

    }

}





int main(int argc, char *argv[]) {

    loop();

    return 0;

}
