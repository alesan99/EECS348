public int countPositive (int[] x)
{
//Effects: If x==null throw NullPointerException
//	else return the number of 
// 		positive elements in x
	int count = 0;
	for (int i=0; i < x.length; i++)
	{
		if (x[i] > 0)
		{
			count++;
		}
	}
	return count;
}