#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "-1 ";
	vector<int> v;
	v.push_back(a[0]);
	int p = a[0];
	int pa = -1;
	for(int i = 1; i < n; i++)
	{
		//cout << i << "=\n";
		int k = a[i];
		if(k < p)
		{
			cout << p << " ";
			v.push_back(k);
			pa = p;
		}
		else if(k == p)
		{
			cout << pa << " ";
		}
		else
		{
			while(v.empty() != true)
			{
				if(k >= v.back())
				{
					v.pop_back();
				}
				else
				{
					cout << v.back() << " ";
					pa = v.back();
					break;
				}
			}
			if(v.empty() == true)
			{
				cout << "-1 ";
				pa = -1;
			}
			v.push_back(k);
		}
		p = k;
	}
	cout << "\n";
	 
	return 0;
} 
