//it is a segment tree of finding a minimum range between two number in a array
//This algo works in O(logn)->range query
//The size of the segment array willbe 2*n+1
#include<iostream>
#include<fstream>
using namespace std;
int n;
int st[1000];
int a[1000];
//ss->starting point of the segment tree
//se->ending point of the segement tree
//l->starting point of the query
//r->ending point of the query

int get_mid(int a,int b)
{
	return a+(b-a)/2;
}
//suppose the new value is 4 and the current value is 2 so diff will be 4-2=2
//this updates only one value at a time 
//for multiple value upgrade we can use this multiple time
int update(int ss,int se,int i,int diff,int si)//index at which change is required
{
	if(i<ss|| i>se)
		return 0;
	st[si]=st[si]+diff;// this updates the value
	if(se!=ss)
	{
		int mid=get_mid(ss,se);
		update(ss,mid,i,diff,2*si+1);
		update(mid+1,se,i,diff,2*si+2);
	}
}
//
int queries(int ss,int se,int l,int r,int index)
{
	if(l<=ss && r>=se)
		return st[index];
	if(se<l || ss>r)
		return INT_MAX;// this value can be changed as per question
	int mid=get_mid(ss,se);
	return min(queries(ss,mid,l,r,2*index+1),queries(mid+1,se,l,r,2*index+2));
}
int construct_st(int a[],int ss,int se,int si)// si the index of the segment tree at which the value is stored 
{
	if(ss==se)
	{
		st[si]=a[ss];
		return a[ss];
	}
	int mid=get_mid(ss,se);
	st[si]=min(construct_st(a,ss,mid,2*si+1),construct_st(a,mid+1,se,2*si+2));// for sum instead of min use +
	return st[si];
}

int main()
{
	//ifstream cin("testcase.txt");
	//int n;
	cin>>n;
	//int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	int l,r;
	cin>>l>>r;
	//segement tree is created
	construct_st(a,0,n-1,0);
	
	for(i=0;i<2*n+1;i++)
		cout<<st[i]<<" ";
	
	cout<<endl;
	cout<<queries(0,n-1,l,r,0)<<endl;

}
