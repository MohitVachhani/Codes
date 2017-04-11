#include<iostream>
#include<vector>
#include<utility>
#include<fstream>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int > > >a;
vector<pair<int,pair<int,int> > >b;
int n,e;
int dist[1000]={INT_MAX};
int algo(int s)
{
	dist[s]=0;
	int i,j;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<e;j++)
		{
			if(dist[a.at(j).second.first]!=INT_MAX && dist[a.at(j).second.first]+a.at(j).first<dist[a.at(j).second.second])
				dist[a.at(j).second.second]=dist[a.at(j).second.first]+a.at(j).first;
		}
	}
}
int main()
{
	ifstream cin("testcase.txt");
	cin>>n>>e;
	int x,y,w;
	while(e--)
	{
		cin>>x>>y>>w;
		a.push_back(make_pair(w,make_pair(x,y)));
	}
	int source;
	cin>>source;
	algo(source);
	int i;
	for(i=0;i<n;i++)
		cout<<dist[i];		
}
