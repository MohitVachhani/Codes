//Disjoint Set Union 
#include<iostream>
using namespace std;
int c[10];
int size[10];
int init()
{
	int i;
	for(i=1;i<=10;i++)
		c[i]=i;
	for(i=0;i<=10;i++)
		size[i]=1;
}
// here is the path compression term used
int root(int a)//find out the root of the element
{
	while(c[a]!=a)
	{
		c[a]=c[c[a]];
		a=c[a];
	}
	return a;
}
//this is the modified function of union 
//it checks the size of both the side of the node
int uni(int a,int b)//union in this b is the root of a
{
	int ra=root(a);
	int rb=root(b);
	if(size[ra]>size[rb])
	{
		c[rb]=c[ra];
		size[ra]=size[ra]+size[rb];
	}
	else
	{
		c[ra]=c[rb];
		size[rb]=size[rb]+size[ra];
	}
}
int find(int a,int b)//it will return 1 if a and b has same roots
{
	if(root(a)==root(b))
		return 1;
	else
		return 0;
}

