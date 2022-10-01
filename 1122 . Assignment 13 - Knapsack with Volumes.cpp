
#include <bits/stdc++.h>

using namespace std;

int dp[501][501][501];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct item
{
	int w, v, p;
};

int main()
{
	int n, w, v;
	cin >> n;
	cin >> w;
	cin >> v;
	item i[501];
	memset(dp, 0, sizeof dp);
	for(int x = 1; x <= n; x++)
	{
		cin >> i[x].w;
		cin >> i[x].v;
		cin >> i[x].p;
	}
	
    for(int x = 1; x <= n; x++)
	{
		//cout << "x: " << x << " ";
	    for(int y = 1; y <= w; y++)
	    {
	    	//cout << "y: " << y << " ";
	    	for(int z = 1; z <= v; z++)
	    	{
	    		//cout << "z: " << z << " ";
		        if(y - i[x].w >= 0 && z - i[x].v >= 0)
		        {
		        	//cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << " ";
		        	dp[x][y][z] = max(dp[x-1][y][z], dp[x-1][y - i[x].w][z - i[x].v] + i[x].p);
		        	//cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << "\n";
				}
				else
				{
					dp[x][y][z] = dp[x-1][y][z];
				}
			}
			//cout << "\n";
	    }
	}
	// for(int x = 1; x <= n; x++)
	// {
	// 	//cout << "x: " << x << " ";
	//     for(int z = 1; z <= v; z++)
	//     {
	//     	//cout << "y: " << y << " ";
	//     	for(int y = 1; y <= w; y++)
	//     	{
	//     		//cout << "z: " << z << " ";
	// 	        if(y - i[x].w >= 0 && z - i[x].v >= 0)
	// 	        {
	// 	        	//cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << " ";
	// 	        	dp[x][y][z] = max(dp[x-1][y][z], dp[x-1][y - i[x].w][z - i[x].v] + i[x].p);
	// 	        	//cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << "\n";
	// 			}
	// 			else
	// 			{
	// 				dp[x][y][z] = dp[x-1][y][z];
	// 			}
	// 		}
	// 		//cout << "\n";
	//     }
	// }

//	for(int x = 0; x <= n; x++)
//	{
//		cout << "x: " << x << " ";
//		for(int y = 0; y <= w; y++)
//		{
//			for(int z = 0; z <= v; z++)
//			{
//				cout << dp[x][y][z] << " ";
//			}
//			cout << "\n";
//		}
//	}
	
	cout << dp[n][w][v] << "\n";
	
	return 0; 
}
