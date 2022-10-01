#include <bits/stdc++.h>

using namespace std;

unsigned long dp[501][501];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct item
{
	int w, v, p;
};

int knapsack(item i[], int n, int w, int v)
{
    if(n < 0 || w <= 0 || v <= 0)
	{
		return 0;
	}

    if(dp[w][v])
	{
		return dp[w][v];
	}

    return dp[w][v] = max(knapsack(i, n-1, w-i[n].w, v-i[n].v) + i[n].p, knapsack(i, n-1, w, v));
}

int main()
{
	int n, w, v;
	cin >> n;
	cin >> w;
	cin >> v;
	item i[n];
	memset(dp, 0, sizeof dp);
	for(int x = 0; x < n; x++)
	{
		cin >> i[x].w;
		cin >> i[x].v;
		cin >> i[x].p;
	}
	
	
//	for(int x = 0; x <= w; x++)
//	{
//		for(int y = 0; y <= v; y++)
//		{
//			cout << dp[x][y] << " ";
//		}
//		cout << "\n";
//	}
	
	cout << knapsack(i, n-1, w, v) << "\n";
	
	return 0; 
}
