#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<fstream>
using namespace std;
#define INF (1<<20)
struct comp
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)
	{
		return a.second>b.second;
	}
};
priority_queue <pair<int,int> , vector<pair<int,int> > , comp > q; 
bool F[100001];
vector<pair<int,int>  > a[100001]; 
int d[100001];
vector<int> b[100001];
int vi[100001];
void dfs(int s)
{
	vi[s]=1;
	int i;
	for(i=0;i<b[s].size();i++)
	{
		if(vi[b[s].at(i)]==0)
			dfs(b[s].at(i));
	}
}
int main()
{
	//ifstream cin("testcase.txt");
	int n,e;
	int u,i,v,w,sz;
	cin>>n>>e;
	int x,y;
	while(e--)
	{
		cin>>x>>y;
		a[x].push_back(make_pair(y,0));
		a[y].push_back(make_pair(x,1));// for undirected graph
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for(i=1;i<=n;i++)
		vi[i]=0;
	dfs(1);
	int flag=0;
	
	for(i=1;i<=n;i++)
		if(vi[i]==0)
			flag=1;
	if(flag==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	int source=1;
	for(i=1;i<=n;i++)
		d[i]=INF;
	d[source]=0;
	q.push(make_pair(source,0));
	
	while(!q.empty())
	{
		u=q.top().first;
		q.pop();
		if(F[u])
			continue;
		sz=a[u].size();
		for(i=0;i<sz;i++)
		{
			v=a[u][i].first;
			w=a[u][i].second;	
			if(!F[v] && d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push(make_pair(v,d[v]));
			}
		}
		F[u]=1;
	}
	
	cout<<d[n]<<endl;	
}
