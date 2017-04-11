//kmp algorithm
//for searching of substring in a main string
// m+n time
// this code will only give output whether the substring is present or not
#include<iostream>
using namespace std;
int main()
{
	string b;//the main text
	cin>>b;
	string a;//pattern to be searched
	cin>>a;
	int count[a.length()];
	int i;
	for(i=0;i<a.length();i++)
	count[i]=0;
	int j=0;
	for(i=1;i<a.length();i++)
	{
		if(a.at(j)==a.at(i))
		{
			count[i]=j+1;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j=count[j-1];
				i--;
			}
			else
				count[i]=0;
		}
	}
	//for(i=0;i<a.length();i++)
	//cout<<count[i];
	//cout<<endl;
	int k=0,m=0;
	
	while(m< b.length() && k<a.length())
	{
		if(b.at(m)==a.at(k))
		{
			m++;
			k++;
		}
		else
		{
			if(k!=0)
			k=count[k-1];
			else
			m++;
		}
	}
	if(k==a.length())
	cout<<"yes";
	else
	cout<<"no";
}
