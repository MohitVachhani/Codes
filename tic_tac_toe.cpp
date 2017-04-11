#include<iostream>
using namespace std;
int print(int a[][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;		
	}
}
int check(int a[][3],int b)
{
	if(a[0][0]==a[0][1] && a[0][1]==a[0][2] && a[0][1]==b)
		return 1;
	else if(a[1][0]==a[1][1] && a[1][1]==a[1][2] && a[1][1]==b)
		return 1;
	else if(a[2][0]==a[2][1] && a[2][1]==a[2][2] && a[2][1]==b)
		return 1;
	else if(a[0][0]==a[1][0] && a[1][0]==a[2][0] &&a[1][0]==b)
		return 1;
	else if(a[0][1]==a[1][1] && a[1][1]==a[2][1] && a[1][1]==b)
		return 1;
	else if(a[0][2]==a[1][2] && a[1][2]==a[2][2]  && a[1][2]==b)
		return 1;	
	else if(a[1][1]==a[0][0] && a[0][0]==a[2][2] && a[0][0]==b)
		return 1;
	else if(a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[2][0]==b)
		return 1;
	else
		return 0;
}
int main()
{
	int a[3][3]={0};
	int i,j;
	cout<<"For reference please see to the following command"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout<<"a["<<i<<"]["<<j<<"]"<<"   ";
		cout<<endl;		
	}
	cout<<"For input"<<endl;
	cout<<"Three number with a space between them"<<endl;
	cout<<"First number denote the player number"<<endl;
	cout<<"Rest two number will denote the position of the box"<<endl;
	cout<<"Like for example"<<endl;
	cout<<"1 2 2"<<endl;
	cout<<" Player 1 will keep mark at 2,2"<<endl;
	print(a);	
	cout<<"Player 1 ->1"<<endl;
	cout<<"Player 2 ->2"<<endl;
	cout<<"Start the game player 1"<<endl;
	int count=0;
	int q,w,e;
	while(count<10)
	{
		cin>>q>>w>>e;
		if(count%2==0 && q==2)
		{
			cout<<"The player has done cheating so game is closed"<<endl;
			break;
		}
		if(count%2!=0 && q==1)
		{
			cout<<"The player has done cheating so game is closed"<<endl;
			break;
		}
		if(count%2==0 && q==1)
		{
			a[w][e]=1;
			cout<<endl;
			print(a);
			cout<<endl;
		}
		if(count%2!=0 && q==2)
		{
			a[w][e]=2;
			cout<<endl;
			print(a);
			cout<<endl;
		}
		if(count>=3)
		{
			if(check(a,1)==1)
			{
				cout<<"Player 1 won the game"<<endl;
				cout<<"To reopen the game please run the programe again"<<endl;
				break;	
			}	
			if(check(a,2)==1)
			{
				cout<<"Player 2 won the game"<<endl;
				cout<<"To reopen the game please run thr programe again"<<endl;
				break;	
			}
		}
		count++;
	}
}
