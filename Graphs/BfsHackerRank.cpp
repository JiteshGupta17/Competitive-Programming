#include<bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/bfsshortreach/problem

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
        vector<vector<int>> graph(n);

        int m; cin >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int src; cin >> src;
        src--;

        vector<bool> visited(n, false);
        vector<int> ans(n, -1);
        ans[src] = 0;
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (int ele : graph[node])
            {
                if (!visited[ele])
                {
                    visited[ele] = true;
                    ans[ele] = 1 + ans[node];
                    q.push(ele);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i == src) continue;
            if (ans[i] == -1) cout << ans[i] << " ";
            else cout << 6 * ans[i] << " ";
        }
        cout << endl;
    }
}
