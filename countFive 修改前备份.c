int countFive(int x,int y)
{
	int i,j;
	int a1,a2,a3,a4;
	int b1,b2,b3,b4;
	
	for(i=-4;i<=0;i++)
	{
		for(j=-4;j<=0;j++)
		{
			
			for(a1=i;a1<5;a1++)
			{
	
				if 		(ME==board[x+a1][y])
					countfive[0][a1+4].mine++;
				else if	(OTHER==board[x+a1][y])
					countfive[0][a1+4].others++;
				else if	(EMPTY==board[x+a1][y])	
					countfive[0][a1+4].empty++;
				else; 
								
			}
			
			for(b2=j;b2<5;b2++)
			{
				
				if     	(ME==board[x][y+b2])
					countfive[1][b2+4].mine++;
				else if	(OTHER==board[x][y+b2])
					countfive[1][b2+4].others++;
				else if	(EMPTY==board[x][y+b2])	
					countfive[1][b2+4].empty++;
				else; 
					
			}			
			
			for(a3=i;a3<5;a3++)
			{
				for(b3=j;b3<5;b3++)
				{
					
					if(ME==board[x+a3][y+b3])
						countfive[2][a3+4].mine++;
					else if(OTHER==board[x+ai][y+b1])
						countfive[2][a3+4].others++;
					else if(EMPTY==board[x+ai][y+b1])	
						countfive[2][a3+4].empty++;
					else;
				}
			}	
			
			for(a4=i;a4<5;a4++)
			{
				for(b4=j;b4<5;b4++)
				{
					
					if(ME==board[x+a4][y-b4])
						countfive[2][a3+4].mine++;
					else if(OTHER==board[x+ai][y+b1])
						countfive[2][a3+4].others++;
					else if(EMPTY==board[x+ai][y+b1])	
						countfive[2][a3+4].empty++;
					else;
				}
			}								
			
		}
	}
}







