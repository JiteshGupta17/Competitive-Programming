#include<bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> numbers(101, 0);
        int n; cin >> n;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            numbers[u] += (v - u);
        }

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            numbers[u] -= (u - v);
        }

        vector<vector<int>> graph(101);

        for (int i = 1; i <= 99; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                int posi = i + j;
                if (i + j > 100) continue;
                posi += numbers[posi];

                graph[i].push_back(posi);
            }
        }

        //BFS
        vector<int> dist(101, 0);
        vector<int> visited(101, false);

        visited[1] = true;
        queue<int>q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            if (cur == 100) break;

            for (int ele : graph[cur])
            {
                if (!visited[ele])
                {
                    visited[ele] = true;
                    q.push(ele);
                    dist[ele] = dist[cur] + 1;
                }
            }
        }

        if (!visited[100]) cout << "-1" << endl;
        else cout << dist[100] << endl;

    }
}
