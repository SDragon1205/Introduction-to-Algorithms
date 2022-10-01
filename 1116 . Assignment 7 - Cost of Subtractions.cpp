
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void MaxHeap_insert(unsigned long a[], int as, int x){
    a[as] = x;
	// if(x > l[1])
	// {
	// 	swap(l[1], l[ls]);
	// }
	int root = as / 2;
	while(a[root] < a[as])
	{
		swap(a[root], a[as]);
		root /= 2;
		as /= 2;
	}
}

void MaxHeap_remove_root(unsigned long a[], int as){
	int root = 1;
	int lc = root * 2;
	int rc = lc + 1;
 	swap(a[root], a[as]);
	a[as] = 0;
	//cout << "a[rc]: " << a[rc] << endl;
	//cout << "a[lc]: " << a[lc] << endl;
	while(a[root] < a[lc] || a[root] < a[rc])
	{
		if(a[lc] > a[rc])
		{
			swap(a[root], a[lc]);
			root = lc;
			//cout << "a1" << endl;
		}
		else
		{
			swap(a[root], a[rc]);
			root = rc;
			//cout << "a2" << endl;
		}
		lc = root * 2;
		rc = lc + 1;
		
		if(rc > as)
		{
			if(lc <= as)
			{
				if(a[lc] > a[root])
					swap(a[root], a[lc]);
			}
			break;
		}
	}
}

int main()
{
	int n, x;
	cin >> n;
	unsigned long a[n+1];
	memset(a, 0, sizeof a);
	a[0] = 2147483648;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		MaxHeap_insert(a, i, x);
	}
	
	unsigned long ans = 0;
	int l1;
	int l2;
	while(a[2] != 0)
	{
		l1 = a[1];
		MaxHeap_remove_root(a, n);
		n--;
		l2 = a[1];
		MaxHeap_remove_root(a, n);
		n--;
		
		ans += (l1 - l2);
		if(l1 != l2)
		{
			n++;
			MaxHeap_insert(a, n, (l1 - l2));
		}
//		cout << "ans: " << ans << endl;
//		for(int i = 1; i <= n; i++)
//		{
//			cout << "a[" << i << "]: " << a[i] << endl;
//		}
	}
	ans += a[1];
	
	cout << ans << endl;
	
	return 0;
}
