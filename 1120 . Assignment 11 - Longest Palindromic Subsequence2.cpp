
#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int dp[7001][7001];

int palindromic(int i, int j, char s[])
{
    if (i == j) //mid
	{
		return 1;
	}
    if (i > j)
	{
		return 0;
	}
    if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

    if (s[i] == s[j]) //same & no ad ++
    {
    	dp[i][j] = palindromic(i+2, j-2, s) + 2;
	}
    else if (palindromic(i+1, j, s) > palindromic(i, j-1, s)) //no same
    {
    	dp[i][j] = palindromic(i+1, j, s);
	}
    else
    {
    	dp[i][j] = palindromic(i, j-1, s);
	}

    return dp[i][j];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

	int n;
	int a, b, i;
	cin >> n;
	char s[n+1];
	for(i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	if(n <= 2)
	{
		cout << "1\n";
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	
	cout << palindromic(1, n, s) << "\n";
    
    return 0;
}
