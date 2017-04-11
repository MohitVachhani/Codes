int v[n]={0};
int bfs(int s)
{
	queue<long long int>q;
	q.push(s);
	level[s]=0;
	v[s]=1;
	long long int i;
	while(!q.empty())
	{
		long long int p=q.front();
		q.pop();
		for(i=0;i<answer[p].size();i++)
		{
			if(v[answer[p].at(i)]==0)
			{
				level[answer[p].at(i)]=level[p]+1;
				q.push(answer[p].at(i));
				v[answer[p].at(i)]=1;	
			}	
		}	
	}	
	
}
