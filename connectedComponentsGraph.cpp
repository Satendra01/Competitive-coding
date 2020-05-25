#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
 int find(int node,int *parent)
 {
     while(parent[node]!=-1)
     node=parent[node];
     return node;
 }
 void Union(int nodeA,int nodeB,int *parent,int *hmap)
 {
     while(parent[nodeA]!=-1)
     nodeA=parent[nodeA];
     while(parent[nodeB]!=-1)
     nodeB=parent[nodeB];
     hmap[nodeA]+=hmap[nodeB];
     parent[nodeB]=nodeA;
 }
vector<int> componentsInGraph(vector<vector<int>> gb) {
    int N=gb.size();
    int parent[2*N+1];
    for(int i=1;i<=2*N;i++)
    parent[i]=-1;
    int hmap[2*N+1];
    for(int i=1;i<=2*N;i++)
    hmap[i]=1;
    
    for(int i=0;i<N;i++)
    {
        int gi=find(gb[i][0],parent);
        int bi=find(gb[i][1],parent);
        if(gi!=bi)
        Union(gi,bi,parent,hmap);
    }
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=1;i<=2*N;i++)
    {
        if(hmap[i]>1 && hmap[i]>max)
        {
            min=max;
            max=hmap[i];
            
        }
    }
    cout<<min<<" "<<max;
    vector<int>res;
    res.push_back(min);
    res.push_back(max);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = componentsInGraph(gb);

    // for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
    //     fout << SPACE[SPACE_itr];

    //     if (SPACE_itr != SPACE.size() - 1) {
    //         fout << " ";
    //     }
    // }

    // fout << "\n";

    fout.close();

    return 0;
}
