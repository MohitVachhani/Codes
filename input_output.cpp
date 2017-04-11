#include<iostream>
#include<fstream>
using namespace std;
//remeber the code and the input file should be in same folder
int main()
{
	ifstream cin("testcase.txt");//used for taking input in the file
	ofstream cout("answer.txt");//used for taking the output and printing in the file
	int t;
	cin>>t;
	while(t>0)
	{
		int a;
		cin>>a;
		cout<<a+1<<endl;
		t--;
	}
}