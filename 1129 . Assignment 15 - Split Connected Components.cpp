#include <bits/stdc++.h>
#include <list>

using namespace std;

int dj[5000][5000];
int ans[500000];

void DFSUtil(list<int> *adj, int v, bool visited[], int *ans)
{
    visited[v] = true;
    *ans += 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
    	if (!visited[*i])
    	{
    		DFSUtil(adj, *i, visited, ans);
		} 
	} 
}

int connectedComponents(list<int> *adj, int j, int n)
{
    bool* visited = new bool[n];
    int ans = 1;
    for (int v = 0; v < n; v++)
    {
    	visited[v] = false;
	}
    visited[j] = true;

    list<int>::iterator i;
    for (i = adj[j].begin(); i != adj[j].end(); ++i)
    {
    	if (!visited[*i])
    	{
    	    DFSUtil(adj, *i, visited, &ans);	
		}
	}
        
    delete[] visited;
    return ans;
}
 
void addEdge(list<int> *adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void deleteEdge(list<int> *adj, int u, int v)
{
	for (list<int>::iterator i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		if (*i == v)
		{
			adj[u].erase(i);
			break;
		}
	}
}

int main()
{
	cin.tie(0);
    cin.sync_with_stdio(0);
	
	int n, m, q, u, v, i, j;
	cin >> n >> m >> q;
    list<int>* adj = new list<int>[n];
    
    for(int x = 0; x < m; ++x)
    {
    	cin >> u >> v;
    	if(u != v)
    	{
    		addEdge(adj, u, v);
		}
	}


	for(int x = 0; x < q; ++x)
	{
		cin >> i >> j;
		if(i < 0)
		{
			cout << connectedComponents(adj, j, n) << "\n";
			
		}
		else
		{
			deleteEdge(adj, i, j);
			deleteEdge(adj, j, i);
		}

	}
 
    return 0;
}
