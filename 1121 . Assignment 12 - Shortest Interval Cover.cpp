
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int ans(int n, int k, long int p[], int min, int max)
{
	if(min == max)
	{
		return min;
	}
	
	int ck = 1;
	long int cp = 0;
	int mid = min + (max - min)/2;
	for(int i = 0; i < n; i++)
	{
		cp += p[i];
		if(cp > mid)
		{
			cp = 0;
			ck++;
			if(ck > k)
			{
				return ans(n, k, p, mid+1, max);
			}
		}
	}
	
	return ans(n, k, p, min, mid);
}

int main()
{
	int n, k, i;
	cin >> n;
	cin >> k;
	long int p[n];
	for(i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	if(k >= n)
	{
		cout << 0 << "\n";
		return 0;
	}
	sort(p, p+n);
	
//	for(i = 0; i < n; i++) //
//	{
//		cout << p[i] << " ";
//	}
//	cout << "\n";
	
	for(i = 0; i < n-1; i++)
	{
		p[i] = p[i+1] - p[i];
	}
	n--;
	
//	for(i = 0; i < n; i++) //
//	{
//		cout << p[i] << " ";
//	}
//	cout << "\n";
	
	//int min = 1;
	// int max = 2147483647;
	// for(i = 0; i < n; i++)
	// {
	// 	min = (min > p[i]) ? min : p[i];
	// }
	
	cout << ans(n, k, p, 0, 2147483647) << "\n";
	
	return 0;
}
