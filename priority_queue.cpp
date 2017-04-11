//How to use priority queue.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	priority_queue<int> q;
	for(int i=0;i<n;i++)
		q.push(a[i]);
		//less reverse sort
		//greater smaller to bigger sort
	//pair wise priority queue 
	//priority assigned as per the first element of the pair same as sort
	priority_queue<pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > q2;
	for(int i=0;i<n;i++)
		q2.push(make_pair(i,a[i]));
	while(!q2.empty())
	{
		cout<<q2.top().first<<" ";
		q2.pop();
	}
}
