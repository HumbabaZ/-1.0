int countFive(int x,int y)
{
	int i;
	int c; 
	
	for(i=-4;i<=0;i++)
	{
		for(c=i;c<i+5;c++)
		{
			if 		(ME==board[x+c][y])
				countfive[0][i+4].mine++;
			else if	(OTHER==board[x+c][y])
				countfive[0][i+4].others++;
			else if	(EMPTY==board[x+c][y])	
				countfive[0][i+4].empty++;
			else;
			
			if 		(ME==board[x][y+c])
				countfive[1][i+4].mine++;
			else if	(OTHER==board[x][y+c])
				countfive[1][i+4].others++;
			else if	(EMPTY==board[x][y+c])	
				countfive[1][i+4].empty++;
			else;
			
			if 		(ME==board[x+c][y+c])
				countfive[2][i+4].mine++;
			else if	(OTHER==board[x+c][y+c])
				countfive[2][i+4].others++;
			else if	(EMPTY==board[x+c][y+c])	
				countfive[2][i+4].empty++;
			else;	
			
			if 		(ME==board[x+c][y-c])
				countfive[3][i+4].mine++;
			else if	(OTHER==board[x+c][y-c])
				countfive[3][i+4].others++;
			else if	(EMPTY==board[x+c][y-c])	
				countfive[3][i+4].empty++;
			else;					
						 			
		}
	}
	
	return;
}







