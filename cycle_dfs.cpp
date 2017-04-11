#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int v[100001]={0};
vector<int> answer[100001];
int level[100001]={0};
bool prime [1000001];
int flag=0;
void debug(int a){cout<<a<<endl;}
int sieve(int a){memset(prime,true,sizeof(prime));int p,i;for(p=2;p*p<=a;p++){if(prime[p]==true){for(i=p*2;i<=a;i+=p)prime[i]=false;}}return 0;}
int dfs(int s,int p)
{
	v[s]=1;
	int i;
	for(i=0;i<answer[s].size();i++)
	{
		if(answer[s].at(i)==p)
			continue;
		if(v[answer[s].at(i)]==0)
			dfs(answer[s].at(i),s);
		else
			flag=true;		
	}
	//return false;
}
int main()
{
	//your code goes here
	//input for the testcase 
	//ifstream cin("testcase.txt");
	//ofstream cout("output.txt");	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
	int t,i,j;
	//cin>>t;
	t=1;
	int counter1=0;
	while(t--)
	{
		counter1++;
		int n,k;
		cin>>n>>k;
		int x,y;
		while(k--)
		{
			cin>>x>>y;
			answer[x].push_back(y);
			answer[y].push_back(x);
		}		
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				flag=false;
				dfs(i,-1);
				if(flag==false)
					ans++;
			}
		}
		cout<<ans;
		//cout<<"Case #"<<counter1<<" ";
		//print your final answer here
		//cout<<fixed<<setprecision(5)<<answer<<endl;
		cout<<endl;	
	}	
}

