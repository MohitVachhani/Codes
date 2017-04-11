#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int node,edge;
	cin>>node>>edge;
	int i,j,x,y;
	int a[node][node];
	for(i=1;i<=node;i++)
	{
		for(j=1;j<=node;j++)
		a[i][j]=0;
	}
	for(i=1;i<=edge;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;	
	}
	//matrix is formed
	for(i=1;i<=node;i++)
	{
		for(j=1;j<=node;j++)
		cout<<a[i][j];
		cout<<endl;
	}
	int start=1;
	stack<int> s;
	s.push(start);
	int visited[node];
	for(i=1;i<=node;i++)
	visited[i]=0;
	//0->unvisited
	visited[start]=1;
	while(s.empty()!=true)
	{
		int v=s.top();
		s.pop();
		cout<<v<<endl;
		for(i=1;i<=node;i++)
		{
			if(a[v][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				s.push(i);
			}
		}
	}
}