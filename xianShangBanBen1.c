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

struct Position theLast; 



/*

 * You should init your AI here

 * �������ʼ�����AI

 */

void initAI(struct Position *last_init)

{

	last_init -> x = 0;
	
	last_init -> y = 0;

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

struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me,struct Position *last_begin)

{

    /*

     * TODO: Write your own ai here!

     * Here is a simple AI which just put chess at empty position!

     * ������������д�����AI�� 

     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 

     */

    int i, j;

    struct Position preferedPos;

    

    for (i = 0; i < BOARD_SIZE; i++)

        for (j = 0; j < BOARD_SIZE; j++)

        {

            if (EMPTY == board[i][j]&&1==board[i][j-1])

            {

                preferedPos.x = i;

                preferedPos.y = j;

                return preferedPos;

            }

        }

    
	last_begin->x =  preferedPos.x;
	
	last_begin->y =  preferedPos.y;

    return preferedPos;

}





/*

 * Game ongoing, the competitor put the chess at the position (otherX, otherY). You should put your chess.

 * You should return a valid Position variable.

 * ��ֽ����У��Է���һ��������(otherX, otherY)��λ�ã��ֵ��������ˡ�

 * �����me��ȡֵֻ������ME(1)����board(����)��ΪME(1)��λ�ñ�ʾ������ӣ�board(����)��ΪOTHER(2)��λ�ñ�ʾ���ֵ����ӡ�

 * ����Ҫ����һ���ṹ��Position����x���Ժ�y������������Ҫ���ӵ�λ�á� 

 */

struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY,struct Position *last_turn)

{

    /*

     * TODO: Write your own ai here!

     * Here is a simple AI which just put chess at empty position!

     * ������������д�����AI�� 

     * ������һ��ʾ��AI����ֻ��Ѱ�ҵ�һ�����µ�λ�ý������ӡ� 

     */

    int i, j;

    struct Position preferedPos;

    

    for (j = 0; j < BOARD_SIZE; i++)

        for (j = 0; j < BOARD_SIZE; j++)

        {
			if (EMPTY == board[i][j])
			{
        		if(last_turn->x!=0||last_turn->y!=0)
        	
        		{
            		if((last_turn->x==i||last_turn->y==j-1))
            	
					{
					
    					preferedPos.x = i;
    			
        				preferedPos.y = j;
        			
        				last_turn->x = i;
        		
        				last_turn->y = j;
        			
        				return preferedPos;
        		
        			}    		
				}
			

            	else if (EMPTY == board[i][j]&&1==board[i][j-1])

            	{

                	preferedPos.x = i;

                	preferedPos.y = j;
                
        			last_turn->x = i;
        		
        			last_turn->y = j;                

                	return preferedPos;

            	}
            
            	else
            	
            	{
                	preferedPos.x = i;
                	
                	preferedPos.y = j;
                	
        			last_turn->x = i;
        		
        			last_turn->y = j;                	
                	
                	return preferedPos;            		
				}
				
			 } 
        
		}

    

    

    return preferedPos;

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

    initAI(&theLast);

}



void turn(int x, int y)

{

    board[x][y] = OTHER;

    

    // AI

    struct Position pos = aiTurn((const char (*)[20])board, ME, x, y, &theLast);

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

    		struct Position pos = aiBegin((const char (*)[20])board, ME,&theLast);

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
