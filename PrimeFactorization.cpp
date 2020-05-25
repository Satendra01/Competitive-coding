#include<bits/stdc++.h>
using namespace std;

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	int size=1000+1;
	vector<int>arr(size,-1);
	for(int i=2;i<=size-1;i++)
	{
		for(int j=i;j<=size-1;j+=i)
		if(arr[j]==-1)
			arr[j]=i;
		if(arr[i]==-1)
			arr[i]=i;
	}
	cout<<"Test";
	int element;
	cin>>element;
	
	while(element!=1)
	{
		cout<<arr[element]<<"*";
		element=element/arr[element];
		
	}
}