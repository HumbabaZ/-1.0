void waitList(int *pwaitlist,const char board[BOARD_SIZE][BOARD_SIZE])
{
	int i,j;
	
	for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
        {
        	if(EMPTY=board[x][y])
        	{
            	if(hasNeibor(i,j,(const char (*)[20])board) 		//寻找周围有棋子的空位 
        			*(pwaitlist+i*BOARD_SIZE+j)=1;
        		/*if(nextNeibor(i,j,(const char (*)[20])board)
        			*(pwaitlist+i*BOARD_SIZE+j)=1;  */  		
			}

		}
		
	return;
 } 
 
 
 int hasNeibor(int x,int y，const char board[BOARD_SIZE][BOARD_SIZE])
 {
 	int s;
 	
 	if(x==0&&y==0)
 		s=board[x+1][y+1]+board[x][y+1]+board[x+1][y];
	else if(x==0&&y==BOARD_SIZE) 
		s=board[x-1][y+1]+board[x][y+1]+board[x-1][y];
	else if(x==BOARD_SIZE&&y==0)
		s=board[x+1][y-1]+board[x+1][y]+board[x][y-1];
	else if(x==BOARD_SIZE&&y==BOARD_SIZE)
		s=board[x-1][y-1]+board[x-1][y]+board[x][y-1];
	else if(x==0)
		board[x][y-1]+board[x][y+1]+board[x+1][y-1]+board[x+1][y]+board[x+1][y+1];
	else if(y==0)
		board[x-1][y]+board[x-1][y+1]+board[x][y+1]+board[x+1][y]+board[x+1][y+1];
	else if(x==BOARD_SIZE)
		board[x-1][y-1]+ board[x-1][y]+board[x-1][y+1]+board[x][y-1]+board[x][y+1];
	else if(y==BOARD_SIZE)
		board[x-1][y-1]+ board[x-1][y]+board[x][y-1]+board[x+1][y-1]+board[x+1][y];
	else
	{
 		s=board[x-1][y-1]+ board[x-1][y]+board[x-1][y+1]+board[x][y-1]
		 +board[x][y+1]+board[x+1][y-1]+board[x+1][y]+board[x+1][y+1];
 		

	if(s==0)
 		return 0;
	else
		return 1;		
 		
 		
 }
 
 
 
 
 
 
 
 
