

int Five(int x,int y)
{
	int i,j;
	
	for(j=0;j<4;j++)
	{
		for(i=0;i<5;i++)
		{
			if (5==countfive[j][i].mine)
			{
				return 1;
			}
		 } 

	}
	
	return 0;
}

int Four(int x,int y)
{
	int i,j;
	
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			if (4==countfive[j][i].mine&&1==countfive[j][i].empty
				&&4==countfive[j][i+1].mine&&1==countfive[j][i+1].empty)
			{
				return 1;
			}
		 } 

	}
	
	return 0;
}

int preFour(int x,int y)
{
	int x,y;
	int c;
	
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			if (4==countfive[j][i].mine&&1==countfive[j][i].empty
				&&3==countfive[j][i+1].mine)
			{				
				c++;
				break;
			}
		 } 

	}
	
	return c;	
}

int Three(int x,int y)
{
	int x,y;
	int c;
	
	for(j=0;j<4;j++)
	{
		for(i=0;i<3;i++)
		{
			if (3==countfive[j][i].mine&&2==countfive[j][i].empty
				&&3==countfive[j][i+1].mine&&2==countfive[j][i+1].empty
				&&3==countfive[j][i+2].mine&&2==countfive[j][i+2].empty)
			{				
				c++;
				break;
			}
		 } 

	}
	
	return c;	
}









