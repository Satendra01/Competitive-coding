#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,t;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>m>>n>>t;
        vector<vector<int>>charms;
        for(int i=0;i<m;i++)
        {
            vector<int>charm;
            for(int j=0;j<n;j++)
            {
                int val;
                cin>>val;
                charm.push_back(val);
            }
            charms.push_back(charm);
        }
        vector<vector<int>>generosity;
        for(int i=0;i<t;i++)
        {
            int nop;
            cin>>nop;
            vector<int>v;
            for(int i=0;i<nop;i++)
            {
                int val;
                cin>>val;
                v.push_back(val);
            }
            generosity.push_back(v);
        }
        int k;
        cin>>k;
        solve(charms,generosity,k);
    }
    
    
}

