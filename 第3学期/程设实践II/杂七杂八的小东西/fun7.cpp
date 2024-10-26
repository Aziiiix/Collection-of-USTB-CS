int fun7(int a,int b)
{
	if(a)
	{
		if(b>=a)
		{
			if(b==a)
			return 0;
			
			else
			return 2*fun7(*(a+8),b)+1;
		}
		else
		return 2*fun7(*(a+4),b);
	}
	else
	return -1;
 } 
