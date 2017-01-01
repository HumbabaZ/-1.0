void Evaluate(int x,int y)
{
	int n1;
	
	if(Five(x,y))
	{
		mescore[x][y][j]+=PONIT.FIVE;
	}
	
	if(Four(x,y))
	{
		int mescore[x][y][j]+=PONIT.FOUR;	
	}
	
	n1=preFour(x,y);
	if(n1)
	{		
		int mescore[x][y][j]+=PONIT.preFOUR*n1;
	}
}


