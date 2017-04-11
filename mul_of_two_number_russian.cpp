// mul of two number using russian peasant algo
#include<iostream>
using namespace std;
long long int result(long long int a,long long int b)
{
	long long int q=min(a,b);
	long long int r,res;
	if(q==b)
		r=a;
	else
		r=b;
	while(q>0)
	{
		if(q&1)
			res=res+r;
		r=r<<1;
		q=q>>1;
	}
	return res;
}

int main()
{
	long long int a,b;
	cin>>a>>b;
	cout<<result(a,b)%1000000007<<endl;
	
}
