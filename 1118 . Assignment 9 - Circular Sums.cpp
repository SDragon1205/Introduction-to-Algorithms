
#include<iostream>
#include<math.h>

using namespace std;

int midi(int a, int b)
{
	return a + (b-a)/2;
}

int getansutil(int *st, int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss && qe >= se)
	{
		return st[si];
	}
	if(se < qs || ss > qe)
	{
		return 0;
	}
	int mid = midi(ss, se);
	return getansutil(st, ss, mid, qs, qe, si*2+1) + getansutil(st, mid+1, se, qs, qe, si*2+2);
}

int getans(int *st, int n, int qs, int qe)
{
	return getansutil(st, 0, n-1, qs, qe, 0);
}

int constructutil(int a[], int ss, int se, int *st, int si)
{
	if(ss == se)
	{
		st[si] = a[ss];
		return a[ss];
	}
	
	int mid = midi(ss, se);
	st[si] = constructutil(a, ss, mid, st, si*2+1) + constructutil(a, mid+1, se, st, si*2+2);
		
	return st[si];
}


int *construct(int a[], int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	int *st = new int[max_size];

	constructutil(a, 0, n-1, st, 0);
//	for(int i = 0; i < max_size; i++)
//	{
//		cout << i << ": " << st[i] << endl; 
//	}

	return st;
}

void updateutil(int *st, int ss, int se, int i, int dif, int si)
{
	if(i < ss || i > se)
	{
		return;
	}
	st[si] += dif;
	if(ss != se)
	{
		int mid = midi(ss, se);
		updateutil(st, ss, mid, i, dif, si*2+1);
		updateutil(st, mid+1, se, i, dif, si*2+2);
	}
}

void update(int a[], int *st, int n, int i, int ne)
{
	int dif = ne - a[i];
	a[i] = ne;
	
	updateutil(st, 0, n-1, i, dif, 0);
}

int main()
{
	//cout << "kcndndcnd" << endl;
	int n, m, i, j, k, x;
	int o = 0;
	cin >> n;
	cin >> m;

	int a[n];

	for(x = 0; x < n; x++)
	{
		cin >> a[x];
	}

	int *st = construct(a, n);
	
	for(x = 0; x < m; x++)
	{
		cin >> i;
		cin >> j;
		cin >> k;
		if(0 == i)
		{
			update(a, st, n, j, k);
		}
		else
		{
			if(j > k)
			{
				cout << getans(st, n, 0, k) + getans(st, n, j, n-1) << endl;
			}
			else
			{
				cout << getans(st, n, j, k) << endl;
			}
		}
	}
	
	return 0;
}
