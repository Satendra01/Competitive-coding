#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>pr;
vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<int>distance(n+1,INT_MAX);
    vector<int>visited(n+1,-1);
    
    distance[s]=0;
    priority_queue<pr,vector<pr>,greater<pr>>pq;//for Minheap implementation using priority queue
    list<pair<int,int>>*adj=new list<pair<int,int>>[n+1];

    for(long int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(make_pair(v,edges[i][2]));
        adj[v].push_back(make_pair(u,edges[i][2]));
    }
    pq.push({0,s});
    vector<int>result(n+1,-1);
    result[s]=-1;
    while(!pq.empty())
    {
        int src=pq.top().second;
        if(src!=s)
        {
            result[src]=distance[src];
            
        }
        visited[src]=1;
        pq.pop();
        
        list<pair<int,int>>::iterator it;
        for(it=adj[src].begin();it!=adj[src].end();it++)
        {
            int node=(*it).first;
            if(visited[node]==1)
            continue;
            int weight=(*it).second;
            
            if(distance[node]>(distance[src]+weight))
                {
                    distance[node]=distance[src]+weight;
                    pq.push(make_pair(distance[node],node));
                }

        }
    }  
    vector<int>finalar;
    for(int i=1;i<=n;i++)
    {
        if(i!=s)
        finalar.push_back(result[i]);
        //cout<<result[i]<<endl;
    } 
    return finalar;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
