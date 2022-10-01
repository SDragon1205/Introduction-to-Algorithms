#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

//int max(int a, int b)
//{
//	return (a > b) ? a : b;
//}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

	int n, i, j, ni = -1, nj = -1;
	int a, b;
	cin >> n;
	char s1[n+1];
	char s2[n+1];
	for(i = 1; i <= n; i++)
	{
		cin >> s1[i];
		s2[n+1-i] = s1[i];
	}
	if(n <= 2)
	{
		cout << "1\n";
		return 0;
	}
//	
//	for(i = 1; i <= n; i++)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << "\n";
//	for(i = 1; i <= n; i++)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << "\n";
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	int p1[n+1][n+1];
	int p2[n+1][n+1];
	for(i=0; i<=n; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	memset(p1, -1, sizeof(p1));
	memset(p2, -1, sizeof(p2));
	
//	int t;
//	for(i = 1; i<=n-1; i++)
//	{
//		if(s1[i] == s2[1])
//		{
//			t = i;
//			for(i = i; i<=n-1; i++)
//			{
//				dp[i][1] = 2;
//				p1[i][1] = t;
//            	p2[i][1] = 1;
//			}
//		}
//	}
//	for(j = 1; j<=n-1; j++)
//	{
//		if(s1[1] == s2[j])
//		{
//			t = j;
//			for(j = j; j<=n-1; j++)
//			{
//				dp[1][j] = 2;
//				p1[1][j] = 1;
//            	p2[1][j] = t;
//			}
//		}
//	}
	
//	int ti, tj, w;
//	w = 2;
    for (i=1; i<=n-1; i++)
    {
        for (j=1; j+i<=n; j++)
        {
            if(s1[i] == s2[j]) // same
            {
            	if(i+j == n || i-1 == p1[i-1][j-1] || j-1 == p2[i-1][j-1] || dp[i-1][j]==dp[i-1][j-1] + 2 || dp[i][j-1]==dp[i-1][j-1] + 2) //adjacent // || dp[i-1][j]==dp[i-1][j-1] + 2 || dp[i][j-1]==dp[i-1][j-1] + 2
            	{
            		if (dp[i-1][j] < dp[i][j-1])
                	{
                  	    dp[i][j] = dp[i][j-1];
                    	p1[i][j] = p1[i][j-1];
                    	p2[i][j] = p2[i][j-1];
                	}
                	else
                	{
                    	dp[i][j] = dp[i-1][j];
                    	p1[i][j] = p1[i-1][j];
                    	p2[i][j] = p2[i-1][j];
                	}
				}
				else
				{
					dp[i][j] = dp[i-1][j-1] + 2;
					p1[i][j] = i;
					p2[i][j] = j;
//					t = j;
//					for(tj = j+1; tj<=n-1-i; tj++)
//					{
//						dp[i][tj] = dp[i][tj-1];
//						p1[i][tj] = i;
//            			p2[i][tj] = t;
//					}
//					t = i;
//					for(ti = i+1; ti<=n-1-j; ti++)
//					{
//						dp[ti][j] = dp[ti-1][j];
//						p1[ti][j] = t;
//            			p2[ti][j] = j;
//					}
//					j = n+1;
//					w++;
				}
            }
            else //no same
            {
                if (dp[i-1][j] < dp[i][j-1])
                {
                    dp[i][j] = dp[i][j-1];
                    p1[i][j] = p1[i][j-1];
                    p2[i][j] = p2[i][j-1];
                }
                else// if(dp[i-1][j] > dp[i][j-1])
                {
                    dp[i][j] = dp[i-1][j];
                    p1[i][j] = p1[i-1][j];
                    p2[i][j] = p2[i-1][j];
                }
//                else
//                {
//                	if(p1[i-1][j] == i-1)
//                	{
//                		dp[i][j] = dp[i][j-1];
//                    	p1[i][j] = p1[i][j-1];
//                    	p2[i][j] = p2[i][j-1];
//					}
//					else
//					{
//						
//					}
//				}
            }
        }
 	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j+i<=n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j+i<=n;j++)
		{
			cout << p1[i][j] << " ";
		}
		cout << "\n";
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j+i<=n;j++)
		{
			cout << p2[i][j] << " ";
		}
		cout << "\n";
	}
	

	int ans; //= max(dp[n-1][1], dp[1][n-1]);
	for(i=1; i<=n-1; i++) // mid+1
	{
		if(dp[i][n-i] >= ans)
		{
//			if(dp[i-2][n-i-1] == dp[i][n-i])
//			{
//				ans = dp[i][n-i]+1;
//				continue;
//			}
//			else if(dp[i-1][n-i-2] == dp[i][n-i])
//			{
//				ans = dp[i][n-i]+1;
//				continue;
//			}
			if(n-p2[i][n-i]-p1[i][n-i]>=3)
			{
				dp[i][n-i]++;
			}
			ans = dp[i][n-i];
		}
	}
	
    cout << ans << "\n";
    
    return 0;
}
