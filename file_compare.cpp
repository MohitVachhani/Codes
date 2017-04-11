#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	fstream file1("testcase.txt"), file2("answer.txt");
	char string1[256], string2[256];
	int j; j = 0;
	int flag=1;
	while(!file1.eof())
	{
		file1.getline(string1,256);
		file2.getline(string2,256);
		j++;
		if(strcmp(string1,string2) != 0)
		{
			cout<<"File are not same"<<endl;
		}
		else
			flag=0;
	}
        if(flag==0)
        	cout<<"The file is same"<<endl;
		return 0;
}
