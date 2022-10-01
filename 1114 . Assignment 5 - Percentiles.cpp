
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;



void MaxHeap_insert(unsigned long l[], int ls, int x){
    l[ls] = x;
	// if(x > l[1])
	// {
	// 	swap(l[1], l[ls]);
	// }
	int root = ls / 2;
	while(l[root] < l[ls])
	{
		swap(l[root], l[ls]);
		root /= 2;
		ls /= 2;
	}
}

void MinHeap_insert(unsigned long r[], int rs, int x){
    r[rs] = x;
	// if(x < r[1])
	// {
	// 	swap(r[1], r[rs]);
	// }
	int root = rs / 2;
	while(r[root] > r[rs])
	{
		swap(r[root], r[rs]);
		root /= 2;
		rs /= 2;
	}
}

void MinHeap_remove_root(unsigned long r[], int rs){
	int root = 1;
	int lc = root * 2;
	int rc = lc + 1;
	//cout << "r[root]: " << r[root] << endl;
	//cout << "r[rs]: " << r[rs] << endl;
 	swap(r[root], r[rs]);
	r[rs] = 2147483648;
	//cout << "r[rc]: " << r[rc] << endl;
	//cout << "r[lc]: " << r[lc] << endl;
	if(lc <= 500000){
		if(rc <= 500000){
			while(r[root] > r[lc] || r[root] > r[rc])
			{
				if(r[lc] < r[rc])
				{
					swap(r[root], r[lc]);
					root = lc;
					//cout << "a1" << endl;
				}
				else
				{
					swap(r[root], r[rc]);
					root = rc;
					//cout << "a2" << endl;
				}
				lc = root * 2;
				rc = lc + 1;
				if(rc > 500000)
				{
					if(lc > 500000)
					{
						break;
					}
					else if(r[root] > r[lc])
					{
						swap(r[root], r[lc]);
					}
				}
				//cout << "a3" << endl;
			}
		}
		else if(r[root] > r[lc])
		{
			swap(r[root], r[lc]);
		}
	}
}

void Heap_swap(unsigned long l[], unsigned long r[], int ls, int rs)
{
	swap(l[1], r[1]);
	int root = 1;
	int lc = root * 2;
	int rc = lc + 1;
	if(lc <= 500000){
		if(rc <= 500000){
			while(l[root] < l[lc] || l[root] < l[rc])
			{
				if(l[lc] > l[rc])
				{
					swap(l[root], l[lc]);
					root = lc;
					//cout << "a1" << endl;
				}
				else
				{
					swap(l[root], l[rc]);
					root = rc;
					//cout << "a2" << endl;
				}
				lc = root * 2;
				rc = lc + 1;
				if(rc > 500000)
				{
					if(lc > 500000)
					{
						break;
					}
					else if(r[root] < r[lc])
					{
						swap(r[root], r[lc]);
					}
				}
				//cout << "a3" << endl;
			}
		}
		else if(r[root] < r[lc])
		{
			swap(r[root], r[lc]);
		}
	}
}

int main()
{
	int n, i;
	cin >> n;
	unsigned long l[500001];
	unsigned long r[500001];
	memset(l, 0, sizeof l);
	for(i = 1; i <= 500000; i++)
	{
		r[i] = 2147483648;
	}
	//cout << "r[3]: " << r[3] << endl;
	l[0] = 2147483648;
	r[0] = 0;
	int k1;
	cin >> k1;
	int k2 = 100 - k1;
	
	int x;
	int ls = 0;
	int rs = 0;
	// cin >> x;
	// if(0 == k1)
	// {
	// 	r[1] = x;
	// 	rs++;
	// }
	// else
	// {
	// 	l[1] = x;
	// 	ls++;
	// }

	if(k1 == 0)
	{
		for(i = 1; i <=n; i++)
		{
			cin >> x;
			if(x == 0)
			{
				cout << r[1] << endl;
			}
			else
			{
				rs++;
				MinHeap_insert(r, rs, x);
			}
		}
	}
	else if(k1 == 100)
	{
		for(i = 1; i <=n; i++)
		{
			cin >> x;
			if(x == 0)
			{
				cout << l[1] << endl;
			}
			else
			{
				ls++;
				MaxHeap_insert(l, ls, x);
			}
		}
	}
	else
	{
		for(i = 1; i <=n; i++)
		{
			cin >> x;
			if(x == 0)
			{
				cout << l[1] << endl;
			}
			else
			{
				rs++;
				MinHeap_insert(r, rs, x);
				while(ls * k2 < rs * k1)
				{
					ls++;
					MaxHeap_insert(l, ls, r[1]);
					MinHeap_remove_root(r, rs);
					rs--;
				}
				if(l[1] > r[1])
				{
					Heap_swap(l, r, ls, rs);
				}
			}

			// cout << "ls: " << ls << endl;
			// cout << "rs: " << rs << endl;
			// cout << "l[1]:" << l[1] << endl;
			// cout << "r[1]:" << r[1] << endl;
		}
	}
	
	return 0;
}
