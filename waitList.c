void waitList()
{
	int i,j;
	
	for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
        {
        	if(EMPTY=board[x][y])
        	{
            	if(hasNeibor(i,j) 		//寻找周围有棋子的空位 
        			waitlist[i][j]=10;
        		if(nextNeibor(i,j)
        			waitlist[i][j]=1;  	
			}

		}
		
	return;
 } 
 
 
 int nextNeibor(int x,int y)
 {
 	int s
 	
 	if ((x==0&&y==0)||(x==0&&y==1)||(x==1&&y==0)||(x==1&&y==1))
 		s=board[x+2][y+2]+board[x][y+2]+board[x+2][y];
	else if((x==0&&y==BOARD_SIZE)||(x==1&&y==BOARD_SIZE)||(x==0&&y==BOARD_SIZE-1)||(x==1&&y==BOARD_SIZE-1))
		s=board[x-2][y+2]+board[x][y+2]+board[x-2][y];
	else if((x==BOARD_SIZE&&y==0)||(x==BOARD_SIZE&&y==1)||(x==BOARD_SIZE-1&&y==0)||(y==1&&x==BOARD_SIZE-1))
		s=board[x+2][y-2]+board[x+2][y]+board[x][y-2];
	else if((x==BOARD_SIZE&&y==BOARD_SIZE)||(x==BOARD_SIZE-1&&y==BOARD_SIZE)||(x==BOARD_SIZE&&y==BOARD_SIZE-1)||(x==BOARD_SIZE-1&&y==BOARD_SIZE-1))
		s=board[x-2][y-2]+board[x-2][y]+board[x][y-2];
	else if(x==0||x==1)
		s=board[x][y-2]+board[x][y+2]+board[x+2][y-2]+board[x+2][y]+board[x+2][y+2];
	else if(y==0||y==1)
		s=board[x-2][y]+board[x-2][y+2]+board[x][y+2]+board[x+2][y]+board[x+2][y+2];
	else if(x==BOARD_SIZE||x==BOARD_SIZE-1)
		s=board[x-2][y-2]+ board[x-2][y]+board[x-2][y+2]+board[x][y-2]+board[x][y+2];
	else if(y==BOARD_SIZE||y==BOARD_SIZE-1)
		s=board[x-2][y-2]+ board[x-2][y]+board[x][y-2]+board[x+2][y-2]+board[x+2][y];
	else
 		s=board[x-2][y-2]+ board[x-2][y]+board[x-2][y+2]+board[x][y-2]
		 +board[x][y+2]+board[x+2][y-2]+board[x+2][y]+board[x+2][y+2];
 		

	if(s==0)
 		return 0;
	else
		return 1;		
	
 }
 
 
 int hasNeibor(int x,int y)
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
		s=board[x][y-1]+board[x][y+1]+board[x+1][y-1]+board[x+1][y]+board[x+1][y+1];
	else if(y==0)
		s=board[x-1][y]+board[x-1][y+1]+board[x][y+1]+board[x+1][y]+board[x+1][y+1];
	else if(x==BOARD_SIZE)
		s=board[x-1][y-1]+ board[x-1][y]+board[x-1][y+1]+board[x][y-1]+board[x][y+1];
	else if(y==BOARD_SIZE)
		s=board[x-1][y-1]+ board[x-1][y]+board[x][y-1]+board[x+1][y-1]+board[x+1][y];
	else
 		s=board[x-1][y-1]+ board[x-1][y]+board[x-1][y+1]+board[x][y-1]
		 +board[x][y+1]+board[x+1][y-1]+board[x+1][y]+board[x+1][y+1];
 		

	if(s==0)
 		return 0;
	else
		return 1;		
 		
 		
 }
 
 
 
 
 
 
 
 
