#include <bits/stdc++.h>
#define li long int
using namespace std;
//Use min priority queue and modify this code
int main()
{
    li x,n;
    cin>>x,n;
    vector<li>ar;
    for(li i=0;i<n;i++)
    {
        int val;
        cin>>val;
        ar.push_back(val);
    }
    li prefixsum[n];
    prefixsum[0]=ar[0];
    for(li i=1;i<n;i++)
        prefixsum[i]=(ar[i]);
    li postfixsum[n];
    postfixsum[n-1]=(ar[n-1]);
    for(li i=n-2;i>=0;i--)
        prefixsum[i]=(ar[i]);
    for(li i=0;i<n-1;i++)
}