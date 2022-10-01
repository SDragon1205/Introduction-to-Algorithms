#include<iostream>
#include<queue>
#include <bits/stdc++.h>
#include <list>

struct Node
{
    int b, d;
};

bool operator<(Node n1, Node n2)
{
    return n1.d > n2.d;
}

list<Node> w[10000];   // adjacency matrix
int ua[10000];
int va[10000];
int wa[10000];
//int parent[10000];
bool visit[10000];

void dijkstra_with_priority_queue(int source, int d[])
{
    for (int i=0; i<9; i++)
    {
        visit[i] = false;
    }
    for (int i=0; i<9; i++)
    {
        d[i] = 1e9;
    }

    priority_queue<Node> pq;

    d[source] = 0;
    //parent[source] = source;
    pq.push((Node){source, d[source]});
 
    for (int i=0; i<9; i++)
    {
        int a = -1;
        while (!pq.empty() && visit[a = pq.top().b])
            pq.pop();
 
        if (a == -1) break;
        visit[a] = true;
 
        for (int b=0; b<9; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
            {
                d[b] = d[a] + w[a][b];
                //parent[b] = a;
                pq.push((Node){b, d[b]});
            }
    }
}


int main()
{
    int n, m, u, v, w, i, j, k;
    cin >> n >> m >> u >> v >> w;
    for(int a = 0; a < m; a++)
    {
        cin >> i;
        cin >> j;
        cin >> w[i][j];
    }
    dijkstra_with_priority_queue(u, ua);
    dijkstra_with_priority_queue(v, va);
    dijkstra_with_priority_queue(w, wa);
    int uv = ua[v];
    int uw = ua[w];
    int vu = va[u];
    int vw = va[w];
    int wu = wa[u];
    int wv = wa[v];
    int ans1 = uv + vw + wu;
    int ans2 = uw + wv + vu;

    if(ans1 > 3000)
    {
        ans1 = -1;
    }
    if(ans2 > 3000)
    {
        ans2 = -1;
    }

    if(ans1 < ans2)
    {
        cout << ans1 << "\n";
    }
    else
    {
        cout << ans2 << "\n";
    }
    

    return 0;
}
