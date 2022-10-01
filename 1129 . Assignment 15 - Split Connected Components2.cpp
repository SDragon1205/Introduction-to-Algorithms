#include <bits/stdc++.h>
#include <list>

using namespace std;

int dj[5000][5000];
int ans[500000];
int p[5000][2]; //[place][size]

int find(int x)
{
	if(x == p[x][0])
	{
		return x;
	}
	return p[x][0] = find(p[x][0]);
}

void uni(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		if(p[pa][1] >= p[pb][1])
		{
			p[pb][0] = pa;
			p[pa][1] += p[pb][1];
		}
		else
		{
			p[pa][0] = pb;
			p[pb][1] += p[pa][1];
		}
	}
}

int main()
{
	//cin.tie(0);
    //cin.sync_with_stdio(0);
	
	int a, b;
	int n, m, q, u, v, i, j;
	cin >> n >> m >> q;
	int edge[m][2];
    
    int xi = 0;
    for(int x = 0; x < m; ++x) //note edge
    {
    	cin >> u >> v;
    	if(u != v)
    	{
    		if(u > v)
    		{
    			swap(u, v);
			}
			edge[xi][0] = u;
			edge[xi][1] = v;
			dj[u][v]++;
			xi++;
		}
	}
//	for(int x = 0; x < xi; ++x)
//	{
//		cout << "edge: " << edge[x][0] << ", " << edge[x][1] << "\n";
//	} 

//	int ans_l = 0;
	int ope[q][2];
	for(int x = 0; x < q; ++x) // note operate
	{
		cin >> i >> j;
//		if(i < 0)
//		{
//			ans_l++;
//		}
		if(i >= 0)
		{
			if(i > j)
    		{
    			swap(i, j);
			}
			dj[i][j]--;
		}
		ope[x][0] = i;
		ope[x][1] = j;
	}
//	for(int x = 0; x < q; ++x)
//	{
//		cout << "ope: " << ope[x][0] << ", " << ope[x][1] << "\n";
//	}
	
	for(int x = 0; x < n; ++x)
	{
		p[x][0] = x;
		p[x][1] = 1;
	}
//	for(int x = 0; x < n; ++x)
//	{
//		cout << "p: " << p[x][0] << ", " << p[x][1] << "\n";
//	}
	
	for(int x = 0; x < xi; ++x) //start union
    {
		a = edge[x][0];
		b = edge[x][1];
		if(dj[a][b] >= 1)
		{
			uni(a, b);
		}
		//cout << "dj[" << a << "][" << b << "]: " << dj[a][b] << "\n";
	}
//	for(int x = 0; x < n; ++x)
//	{
//		cout << "n: " << p[x][0] << ", " << p[x][1] << "\n";
//	}
	
	int ansl = 0;
	for(int x = q-1; x >= 0; --x) // anti operate
	{
		a = ope[x][0];
		b = ope[x][1];
		if(a < 0)
		{
			ans[ansl] = p[find(b)][1];
			ansl++;
		}
		else
		{
			if(++dj[a][b] >= 1)
			{
				uni(a, b);
			}
		}
//		cout << "op: " << a << ", " << b << "\n";
//		for(int x = 0; x < n; ++x)
//		{
//			cout << "n: " << p[x][0] << ", " << p[x][1] << "\n";
//		}
	}

	for(int x = ansl-1; x >= 0; --x)
	{
		cout << ans[x] << "\n";
	}
	
    return 0;
}
