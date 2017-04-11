//mode of given set of numbers without hashing
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> a;
	int n,i,b,j;
	cin>>n;
	vector <int> flag;
	vector <int>  number;
	for(i=0;i<n;i++)
	{
		flag.push_back(0);
	}
	for(i=0;i<n;i++)
	{
		cin>>b;
		a.push_back(b);
	}
	for(i=0;i<n;i++)
	{
		int f=0;
		for(j=0;j<n;j++)
		{		
			if(a[i]==a[j] && flag[j]==0)
			{
				flag[i]=1;
				flag[j]=1;
				f++;		
			}
		
		}
		number.push_back(f);
	}
	int count=0;
	for(i=0;i<n;i++)
	{
		if(number[i]==0)
		count++;
	}
	
	vector<int> flag2;
	for(i=0;i<n;i++)
	flag2.push_back(0);
	vector<int> non_repeating_number;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j]&& flag2[i]==0)
			{
				flag2[j]=1;
			}
		
		}
		if(flag2[i]==0)
		{
			non_repeating_number.push_back(a[i]);
		}	
	}

	for(i=0;i<n-count;i++)
	cout<<non_repeating_number[i]<<"  "<<number[i]<<endl;
}