#include "ai.h"

/*
 * YOUR CODE BEGIN
 * 你的代码开始
 */
 
/* 
 * You can define your own struct and variable here
 * 你可以在这里定义你自己的结构体和变量
 */

int testboard[BOARD_SIZE][BOARD_SIZE];
int menum,othernum;		//落子数
int me_score[BOARD_SIZE][BOARD_SIZE][4];		//得分 
int other_score[BOARD_SIZE][BOARD_SIZE][4];
int total_me,total_other;		//总分 


/*
 * You should init your AI here
 * 在这里初始化你的AI
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
 * 棋局开始，首先由你来落子
 * 请注意：只有在当棋局初始化后，轮到你落子时才会触发这个函数。如果在棋局初始化完毕后，轮到对手落子，则这个函数不会被触发。详见项目要求。
 * 在这里，me的取值只可能是ME(1)，即board(棋盘)上为ME(1)的位置表示你的棋子，board(棋盘)上为OTHER(2)的位置表示对手的棋子。
 * 你需要返回一个结构体Position，在x属性和y属性填上你想要落子的位置。 
 */
struct Position aiBegin(const char board[BOARD_SIZE][BOARD_SIZE], int me)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * 代做：在这里写下你的AI。 
     * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。 
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
 * 棋局进行中，对方上一步落子在(otherX, otherY)的位置，轮到你落子了。
 * 在这里，me的取值只可能是ME(1)，即board(棋盘)上为ME(1)的位置表示你的棋子，board(棋盘)上为OTHER(2)的位置表示对手的棋子。
 * 你需要返回一个结构体Position，在x属性和y属性填上你想要落子的位置。 
 */
struct Position aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me, int otherX, int otherY)
{
    /*
     * TODO: Write your own ai here!
     * Here is a simple AI which just put chess at empty position!
     * 代做：在这里写下你的AI。 
     * 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。 
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
 * 你的代码结束 
 */
