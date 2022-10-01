#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n;
	cin >> n;
	int ans = 0;
	int p;
	for(int i = 0; i < n; i++)
	{
		cin >> p;
		ans = (ans > p) ? ans : p;
	}
	
	cout << ans;
	
	return 0;
}
