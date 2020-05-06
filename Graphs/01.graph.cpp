#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int val, int wt)
    {
        this->v = val;
        this->w = wt;
    }

    Edge()
    {
    }
};

vector<vector<Edge *>> graph(7, vector<Edge *>());

void addedge(int u, int v, int w)

{

    if (u < 0 || v < 0 || u > graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " =>";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j]->v << "," << graph[i][j]->w << ")";
        }
        cout << endl;
    }
}

void removeEdge(int u, int v)
{

    for (int k = 0; k < graph[u].size(); k++)
    {
        if (graph[u][k]->v == v)
        {
            graph[u].erase(graph[u].begin() + k);
        }
    }

    for (int k = 0; k < graph[v].size(); k++)
    {
        if (graph[v][k]->v == u)
        {
            graph[v].erase(graph[v].begin() + k);
        }
    }
}

void removeVertex(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(graph[u][i]->v, u);
    }
}

bool hasPath(int src, int des, vector<bool> &visited, string ans)
{
    // if (visited[src])
    //     return false;

    if (src == des)
    {
        cout << ans << endl;
        return true;
    }

    visited[src] = true;
    bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
        {
            res = res || hasPath(v, des, visited, ans + to_string(v) + "->");
        }
    }
    return res;
}

void hasPath_allPath(int src, int des, vector<bool> &visited, string ans)
{
    // if (visited[src])
    //     return;

    if (src == des)
    {
        cout << ans << endl;
        return;
    }

    visited[src] = true;
    // bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            hasPath_allPath(v, des, visited, ans + "->" + to_string(v));
    }

    visited[src] = false;
}

void preorderGraph(int src, vector<bool> &visited, string ans)
{

    cout << src << " - " << ans << endl;

    visited[src] = true;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            preorderGraph(v, visited, ans + "->" + to_string(v));
    }

    visited[src] = false;
}

void postOrderGraph(int src, vector<bool> &visited, string ans)
{
    if (visited[src])
        return;

    visited[src] = true;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        postOrderGraph(v, visited, ans + "->" + to_string(v));
    }
    cout << src << " - " << ans << endl;

    visited[src] = false;
}

int finalWt = -1;
string fpath = "";
void path_with_maxWeight(int src, int des, int wt, vector<bool> &visited, string ans)
{
    // int maxWt = 0;

    if (src == des)
    {

        if (wt > finalWt)
        {
            finalWt = wt;
            fpath = ans;
        }

        return;
    }

    visited[src] = true;
    // bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        int w = e->w;
        if (!visited[v])
            path_with_maxWeight(v, des, w + wt, visited, ans + to_string(v) + "->");
    }

    visited[src] = false;
}

int maxWt = 100000;
string path = "";
void path_with_lightestWeight(int src, int des, int wt, vector<bool> &visited, string ans)
{

    if (src == des)
    {
        if (wt < maxWt)
        {
            maxWt = wt;
            path = ans;
            //return;
            //cout<<ans << "@" << maxWt<<endl;
        }

        return;
    }

    visited[src] = true;
    // bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        int w = e->w;
        if (!visited[v])
            path_with_lightestWeight(v, des, w + wt, visited, ans + to_string(v) + "->");
    }

    visited[src] = false;
}

void hamiltonianPath(int src, vector<bool> &visited, string ans, int currCount, int maxCount)
{
    if (currCount == maxCount - 1)
    {
        cout << ans << endl;
        return;
    }

    visited[src] = true;
    // bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            hamiltonianPath(v, visited, ans + to_string(v) + "->", currCount + 1, maxCount);
    }

    visited[src] = false;
}

void hamiltonianCycle(int src, int oriSrc, vector<bool> &visited, string ans, int currCount, int maxCount)
{
    if (currCount == maxCount - 1)
    {
        for (Edge *e : graph[src])
        {
            if (e->v == oriSrc)
            {
                cout << "Cycle";
            }
        }
        return;
    }

    visited[src] = true;
    // bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            hamiltonianCycle(v, oriSrc, visited, ans + to_string(v) + "->", currCount + 1, maxCount);
    }

    visited[src] = false;
}

//============================================================================

class bfsOb
{

public:
    int vtx = 0;
    int wtSofar = 0;
    string pathSofar = " ";

    bfsOb(int vtx, int wtSofar, string pathSofar)
    {
        this->vtx = vtx;
        this->wtSofar = wtSofar;
        this->pathSofar = pathSofar;
    }

    bfsOb()
    {
    }
};

void bfs_shortestPath(int src, int des, vector<bool> vis)
{

    int cycleNo = 0;
    int length = 0;
    int level = 0;
    //int des=;

    bool ispath = false;

    queue<bfsOb> que;

    bfsOb s(src, 0, to_string(src));
    bfsOb nul(-1, -1, "");
    que.push(s);
    que.push(nul);

    while (!que.empty())
    {
        bfsOb rpair = que.front();
        que.pop();

        if (vis[rpair.vtx])
        {
            cout << "Cycle " << cycleNo << " : " << rpair.pathSofar << endl;
            cycleNo++;
        }

        vis[rpair.vtx] = true;

        if (rpair.vtx == des && !ispath)
        {
            cout << "Shortest Path is :" << rpair.pathSofar << " with Weight So Far " << rpair.wtSofar << "  And Level is:" << level << endl;
            ispath = true;
        }

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
            {
                bfsOb pair(e->v, rpair.wtSofar + e->w, rpair.pathSofar + "->" + to_string(e->v));
                que.push(pair);
            }
        }

        if (que.front().vtx == nul.vtx && que.front().pathSofar == nul.pathSofar && que.front().wtSofar == nul.wtSofar)
        {
            level++;
            que.pop();
            if (!que.empty())
                que.push(nul);
        }
    }
}

void Efficientbfs_shortestPath(int src, int des, vector<bool> vis)
{

    bool ispath = false;

    queue<bfsOb> que;

    bfsOb s(src, 0, to_string(src));
    vis[s.vtx] = true;
    que.push(s);

    while (!que.empty())
    {
        bfsOb rpair = que.front();
        que.pop();

        if (rpair.vtx == des && !ispath)
        {
            cout << "Shortest Path is :" << rpair.pathSofar << " with Weight So Far = " << rpair.wtSofar << endl;
            ispath = true;
        }

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
            {
                bfsOb pair(e->v, rpair.wtSofar + e->w, rpair.pathSofar + "->" + to_string(e->v));
                que.push(pair);
            }
        }
    }
}
void Connected()
{
    int cntConnected = 0;
    vector<bool> isVisited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        queue<int> q;
        if (isVisited[i])
            continue;

        cntConnected++;
        cout << "Connected Component " << cntConnected << "  :  ";

        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (!isVisited[cur])
                cout << cur << " ";
            isVisited[cur] = true;
            for (Edge *c : graph[cur])
            {
                if (!isVisited[c->v])
                {
                    q.push(c->v);
                }
            }
        }
        cout << endl;
    }

    // cout<<cntConnected;
}


class partite_pair
{
public:
    int vtx = -1;
    int colour = -1;

    partite_pair(int vtx, int colour)
    {
        this->vtx = vtx;
        this->colour = colour;
    }

    partite_pair()
    {
    }
};

bool bipartite(int src, vector<int> &vis)
{

    list<partite_pair> que;
    partite_pair root(src, 0);
    que.push_back(root);

    bool res = false;

    while (que.size() > 0)
    {
        //remove vertex
        partite_pair rpair = que.front();
        que.pop_front();

        if (vis[rpair.vtx] != -1)
        {
            if (vis[rpair.vtx] != rpair.colour)
            {
                cout << rpair.vtx << " -> "
                     << "Not Bipartite" << endl;
                res = false;
            }
            else
            {
                cout << rpair.vtx << " -> "
                     << "Bipartite" << endl;
            }

            
            continue;
        }

        vis[rpair.vtx] = rpair.colour;

        for (Edge *e : graph[rpair.vtx])
        {

            if (vis[e->v] == -1)
            {
                int new_colour = (rpair.colour + 1) % 2;
                partite_pair npair(e->v, new_colour);
                que.push_back(npair);
            }
        }
    }
    return res;
}

//Dijkstra Algorithm
// vector<vector<Edge*>> dgraph(7,vector<Edge*>());
// void addedge(int u,int v,int w){

//     if(u<0  || v<0 || u>graph.size() || v>=graph.size())
//         return;

//     dgraph[u].push_back(new Edge(v,w));
//     dgraph[v].push_back(new Edge(u,w));

// }

// void display(){
//     for(int i=0;i<dgraph.size();i++){
//         cout<<i<<" =>";
//         for(int j=0;j<dgraph[i].size();j++){
//             cout<<"("<<dgraph[i][j]->v<<","<<dgraph[i][j]->w<<")";
//         } cout<<endl;
//     }
// }

class D_pair
{
public:
    int vtx = 0;
    int pvtx = 0;
    int wt = 0;
    int wtSoFar = 0;
    string path = "";

    D_pair(int vtx, int pvtx, int wt, int wtSoFar, string path)
    {
        this->vtx = vtx;
        this->pvtx = pvtx;
        this->wt = wt;
        this->wtSoFar = wtSoFar;
        this->path = path;
    }

    D_pair()
    {
    }
};

bool operator<(const D_pair &d1, const D_pair &d2)
{
    return d1.wtSoFar > d2.wtSoFar;
}

void dijikstra()
{
    priority_queue<D_pair> pq;
    pq.push(D_pair(0, -1, 0, 0, "0"));
    vector<bool> vis(graph.size(), false);
    while (!pq.empty())
    {
        D_pair rpair = pq.top();
        pq.pop();
        if (rpair.pvtx != -1)
        {
            addedge(rpair.vtx, rpair.pvtx, rpair.wt);
        }

        vis[rpair.vtx] = true;
        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
            {
                pq.push(D_pair(e->v, rpair.vtx, e->w, rpair.wtSoFar + e->w, rpair.path + " " + to_string(e->v)));
            }
        }
    }

    display();
}

int main()
{
    addedge(0, 1, 10);
    addedge(0, 3, 10);
    addedge(2, 1, 10);
    addedge(2, 3, 40);
    addedge(3, 4, 2);
    addedge(4, 5, 2);
    addedge(4, 6, 8);
    addedge(5, 6, 3);
    // addedge(2,5,14);

    // display();
    //removeEdge(4,5);
    //display();
    //removeVertex(3);
    //display();

    //==============================================================
    // //Ques. Print all path between Source and Destination
    // vector<bool> visited(7, false);
    // hasPath(0, 6, visited, to_string(0) + "->");
    //  hasPath_allPath(0,6,visited,"0");

    //==============================================================

    //Ques.Print Preorder and Postorder of Tree
    //  vector<bool> visited(7,false);
    //  preorderGraph(0,visited,"0");

    // vector<bool> visited(7,false);
    // postOrderGraph(0,visited,"0");

    //=================================================================

    //Ques.Find path with maxWeight and Lightest Weight
    // vector<bool> visited(7,false);
    // path_with_maxWeight(0,6,0,visited,"0->");
    // cout<<fpath<<" ->"<<finalWt<<endl;

    // vector<bool> visited(7,false);
    // path_with_lightestWeight(0,6,0,visited,"0->");
    // cout<<path<<" ->"<<maxWt<<endl;

    //===================================================================

    //    vector<bool> visited(7,false);
    //     hamiltonianPath(0,visited,"0->",0,7);

    // addedge(2,5,14);
    // vector<bool> visited(7,false);
    // hamiltonianCycle(0,0,visited,"0->",0,7);

    //===============================================================

    //vector<bool> visited(7, false);
    // bfs_shortestPath(0,6,visited);
    //Efficientbfs_shortestPath(0,6,visited);

    //==========================================================

   // Connected();

   //====================================================

    vector<int> visited(7,-1);
    bipartite(0,visited);

    //dijikstra();
}