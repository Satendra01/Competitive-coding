#include<bits/stdc++.h>
using namespace std;
#define forloop(n) for( int i=0;i<n;i++)
struct interval
{
	int start,end;
};
bool compareInterval(interval i1,interval i2)
{
	return (i1.start>i2.start);
}
int main()
{
	interval arr[]={{6,8},{1,9},{2,4},{4,7}};
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n,compareInterval);
	
	forloop(n)
	cout<<arr[i].start<<","<<arr[i].end<<endl;
	return 0;
}
