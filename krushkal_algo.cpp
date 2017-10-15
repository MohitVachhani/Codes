//krushkal algo
//mst
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int,pair<int,int> > > a;
int b[10];
bool comp(const pair<int,pair<int,int> > &x,const pair<int,pair<int,int> > &y) // this is the function which is used to sort by second element.
{
	return x.first>y.first;
}
int init(int n)
{
	int i;
	for(i=1;i<=n;i++)
		b[i]=i;
}
int root(int c)
{
	while(b[c]!=c)
	{
		b[c]=b[b[c]];
		c=b[c];
	}
	return c;
}
int uni(int r,int l)
{
	int ra=root(r);
	int rb=root(l);
	b[rb]=b[ra];
}
int result(int x,int y)
{
	if(root(x)==root(y))
		return 1;
	else
		return 0;
}
int algo()
{
	int x,y;
	int cost=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(result(a.at(i).second.first,a.at(i).second.second)==0)
		{
			cost+=a.at(i).first;
			uni(a.at(i).second.first,a.at(i).second.second);
		}
	}
	return cost;
}
int main()
{
	cin>>n;
	init(n);
	int x,y,weight;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>x>>y>>weight;
		a.push_back(make_pair(weight,make_pair(x,y)));
	}			
	sort(a.begin(),a.end(),comp);
}
