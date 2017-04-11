	int max1=b[0];
		int max2=b[0];
		for(i=1;i<n;i++)
		{
			max1=max(b[i],max1+b[i]);
			max2=max(max1,max2);
		}
		cout<<max2+count1<<endl;
		
