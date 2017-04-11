#include<iostream>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;
string str_rev(string g)
{
	int i,j,len;
	char x;
	len=g.size();
	i=0,j=len-1;
	while(i<j)
	{
		x=g[i];
		g[i]=g[j];
		g[j]=x;
		i++;
		j--;
	}
	return g;
}
 
string addition(string a,string b){
	string c,d,e;
	int len1,len2,i=0,k,mod,div=0,j;
	char ch;
	a=str_rev(a);
	b=str_rev(b);
	len1=a.size();
	len2=b.size();
	if(len1>=len2){
		c=a;
		d=b;
	}
	else
	{
		c=b;
		d=a;
	}
	while(len1 && len2)
	{
		k=c[i]+d[i]-96+div;
		mod=k%10;
		div=k/10;
		ch=mod+48;
		e.push_back(ch);
		len1--;
		len2--;
		i++;
		
	}
	int remlen=abs(len1-len2);
	
	while(remlen--)
	{
		k=c[i]-48+div;
		mod=k%10;
		div=k/10;
		ch=mod+48;
		e.push_back(ch);
		i++;
	}
	if(div!=0)
	//e[i++]=div+48;
	{
		ch=div+48;
		e.push_back(ch);
	}
	
	e=str_rev(e);
	return e;
	}
string multiplication(string a,string b)
{
	string x;
	if(b.size()>a.size())
	{
		x=a;
		a=b;
		b=x;
	}
		string s[10],c=a,d;
	int i,j;
	s[0]='0';
	s[1]=a;
	for(i=2;i<=9;i++)
	{
		c=addition(c,a);
		s[i]=c;
	}
	int l1=b.size();
	c=s[b[l1-1]-48];
	for(i=1;i<l1;i++)
	{
		d=s[b[l1-1-i]-48];
		d.append(i,'0');
		c=addition(c,d);
	}
	return c;
	
}
int main(){
	string x,y;
	cin>>x>>y;
	cout<<multiplication(x,y);
	cout<<endl;
	return 0;
	
}
