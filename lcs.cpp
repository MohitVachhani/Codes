int solve(vector<int>a,vector<int>b)
{
	int i,j;
	int dp[a.size()+1][b.size()+1];
	memset(dp,0,sizeof dp);
	for(i=0;i<=a.size();i++)
	{
		for(j=0;j<=b.size();j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[a.size()][b.size()];
	
}
