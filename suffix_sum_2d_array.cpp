#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int solve(int x1,int y1,int x2,int y2)
{
	int ans=a[x2][y2];
	int left=0;
	int upper=0;
	int leftupper=0;
	if(y1>0 && x1>0)
		leftupper+=a[x1-1][y1-1];
	if(y1>0 )
		left+=a[x1][y1-1];
	if( x1>0)
		upper+=a[x1-1][y1];
	return ans-left-upper+leftupper;
}	
int main()
{
	//ifstream cin("testcase.txt");
	int i,j;
	int n,m;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	for(i=1;i<n;i++)
		a[i][0]+=a[i-1][0];
	for(i=1;i<m;i++)
		a[0][i]+=a[0][i-1];
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	int q;
	cin>>q;
	
	int x1,y1,x2,y2;
	while(q--)
	{
		cin>>x1>>y1>>x2>>y2;
		cout<<solve(x1,y1,x2,y2);
		cout<<endl;
	}
}
