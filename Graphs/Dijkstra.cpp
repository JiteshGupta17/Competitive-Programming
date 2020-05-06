#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0;i<m;i++)
        {
            int u,v,wt;
            cin>>u>>v>>wt;
            u--;v--;

            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        int src; cin>>src;
        src--;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<bool> visited(n,false);
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            if (visited[cur.second])
                continue;

            visited[cur.second] = true;
            
            for(pair<int,int> child : graph[cur.second])
            {
                if(dist[child.first] > dist[cur.second] + child.second)
                {
                    dist[child.first] = dist[cur.second] + child.second;
                    pq.push({dist[child.first],child.first});
                }
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(i==src) continue;
            if(dist[i]==INT_MAX) cout<<"-1"<<" ";
            else cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
}

