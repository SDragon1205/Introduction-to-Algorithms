
#include<iostream>
#include<math.h>

using namespace std;

struct node{
    int oo;
	int ox;
	int xo;
	int xx;
};

int max(int a, int b, int c)
{
	a = (a > b) ? a : b;
	return (a > c) ? a : c;
}

//int getans_oo(node *st, int ss, int se, int qs, int qe, int si);
//int getans_ox(node *st, int ss, int se, int qs, int qe, int si);
//int getans_xo(node *st, int ss, int se, int qs, int qe, int si);
//int getans_xx(node *st, int ss, int se, int qs, int qe, int si);
//
//int getans_oo(node *st, int ss, int se, int qs, int qe, int si)
//{
//	if(qs <= ss && se <= qe)
//	{
//		return st[si].oo;
//	}
//	if(se < qs || ss > qe)
//	{
//		return 0;
//	}
//	if(1 == se - ss)
//	{
//		if(qs == se)
//		{
//			return st[si].xo;
//		}
//		else
//		{
//			return st[si].ox;
//		}
//	}
//
//	int length = (se - ss + 1)/2;
//
//	if(1 == length % 2)
//	{
//		length ++;
//	}
//	if(qe <= ss+length-1)
//	{
//		return getans_oo(st, ss, ss+length-1, qs, qe, si*2+1);
//	}
//	if(qs >= ss+length)
//	{
//		// cout << "dagg" << endl;
//		// cout << "ss: " << ss << endl;
//		// cout << "se: " << se << endl;
//		// cout << "ss+len: " << ss+length << endl;
//		// cout << "qs: " << qs << endl;
//		// cout << "qe: " << qe << endl;
//
//		return getans_oo(st, ss+length, se, qs, qe, si*2+2);
//	}
//	return max(getans_ox(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xo(st, ss+length, se, qs, qe, si*2+2), getans_ox(st, ss, ss+length-1, qs, qe, si*2+1)+getans_oo(st, ss+length, se, qs, qe, si*2+2), getans_oo(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xo(st, ss+length, se, qs, qe, si*2+2));
//	
//}
//
//int getans_ox(node *st, int ss, int se, int qs, int qe, int si)
//{
//	if(qs <= ss && qe >= se)
//	{
//		return st[si].ox;
//	}
//	if(se < qs || ss > qe)
//	{
//		return 0;
//	}
//	if(1 == se - ss)
//	{
//		if(qs == se)
//		{
//			return 0;
//		}
//		else
//		{
//			return st[si].ox;
//		}
//	}
//
//	int length = (se - ss + 1)/2;
//
//	if(1 == length % 2)
//	{
//		length ++;
//	}
//	if(qe <= ss+length-1)
//	{
//		return getans_ox(st, ss, ss+length-1, qs, qe, si*2+1);
//	}
//	if(qs >= ss+length)
//	{
//		return getans_ox(st, ss+length, se, qs, qe, si*2+2);
//	}
//	return max(getans_ox(st, ss, ss+length-1, qs, qe, si*2+1)+getans_ox(st, ss+length, se, qs, qe, si*2+2), getans_ox(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2), getans_oo(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2));
//	
//}
//
//int getans_xo(node *st, int ss, int se, int qs, int qe, int si)
//{
//	if(qs <= ss && qe >= se)
//	{
//		return st[si].xo;
//	}
//	if(se < qs || ss > qe)
//	{
//		return 0;
//	}
//	if(1 == se - ss)
//	{
//		if(qs == se)
//		{
//			return st[si].xo;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	int length = (se - ss + 1)/2;
//
//	if(1 == length % 2)
//	{
//		length ++;
//	}
//	if(qe <= ss+length-1)
//	{
//		return getans_xo(st, ss, ss+length-1, qs, qe, si*2+1);
//	}
//	if(qs >= ss+length)
//	{
//		return getans_xo(st, ss+length, se, qs, qe, si*2+2);
//	}
//	return max(getans_xo(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xo(st, ss+length, se, qs, qe, si*2+2), getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_oo(st, ss+length, se, qs, qe, si*2+2), getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xo(st, ss+length, se, qs, qe, si*2+2));
//	
//}
//
//int getans_xx(node *st, int ss, int se, int qs, int qe, int si)
//{
//	if(qs <= ss && qe >= se)
//	{
//		return st[si].xx;
//	}
//	if(se < qs || ss > qe)
//	{
//		return 0;
//	}
//	if(1 == se - ss)
//	{
//		return 0;
//	}
//
//	int length = (se - ss + 1)/2;
//
//	if(1 == length % 2)
//	{
//		length ++;
//	}
//	if(qe <= ss+length-1)
//	{
//		return getans_xx(st, ss, ss+length-1, qs, qe, si*2+1);
//	}
//	if(qs >= ss+length)
//	{
//		return getans_xx(st, ss+length, se, qs, qe, si*2+2);
//	}
//	return max(getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2), getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_ox(st, ss+length, se, qs, qe, si*2+2), getans_xo(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2));
//	
//}

node getansutil(node *st, int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss && qe >= se)
	{
		return st[si];
	}
	
	int length = (se - ss + 1)/2;
	if(1 == length % 2)
	{
		length ++;
	}
	
//	if(se < qs || ss > qe)
//	{
//		return 0;
//	}

	node sub;
	if(1 == se - ss)
	{
		if(se == qs)
		{
			//cout << "e3" << endl;
			sub.oo = st[si].xo;
			sub.ox = 0;
			sub.xo = st[si].xo;
			sub.xx = 0;
		}
		else
		{
			//cout << "e4" << endl;
			sub.oo = st[si].ox;
			sub.ox = st[si].ox;
			sub.xo = 0;
			sub.xx = 0;
		}
		return sub;
	}
	
	if(qe <= ss+length-1)
	{
		//cout << "e1" << endl;
		return getansutil(st, ss, ss+length-1, qs, qe, si*2+1);
	}
	if(qs >= ss+length)
	{
		//cout << "e2" << endl;
		return getansutil(st, ss+length, se, qs, qe, si*2+2);
	}

	node lc = getansutil(st, ss, ss+length-1, qs, qe, si*2+1);
	node rc = getansutil(st, ss+length, se, qs, qe, si*2+2);
	sub.oo = max(lc.ox+rc.xo, lc.ox+rc.oo, lc.oo+rc.xo);
	sub.ox = max(lc.ox+rc.ox, lc.ox+rc.xx, lc.oo+rc.xx);
	sub.xo = max(lc.xo+rc.xo, lc.xx+rc.xo, lc.xx+rc.oo);
	sub.xx = max(lc.xx+rc.xx, lc.xo+rc.xx, lc.xx+rc.ox);
	
	return sub;
	//return max(getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2), getans_xx(st, ss, ss+length-1, qs, qe, si*2+1)+getans_ox(st, ss+length, se, qs, qe, si*2+2), getans_xo(st, ss, ss+length-1, qs, qe, si*2+1)+getans_xx(st, ss+length, se, qs, qe, si*2+2));
	
}

int getans(node *st, int n, int qs, int qe)
{
//	int oo = getans_oo(st, 0, n-1, qs, qe, 0);
//	int ox = getans_ox(st, 0, n-1, qs, qe, 0);
//	int xo = getans_xo(st, 0, n-1, qs, qe, 0);
//	int xx = getans_xx(st, 0, n-1, qs, qe, 0);
	// cout << "oo: " << oo << endl;
	// cout << "ox: " << ox << endl;
	// cout << "xo: " << xo << endl;
	// cout << "xx: " << xx << endl;
	
	node ans = getansutil(st, 0, n-1, qs, qe, 0);

	ans.oo = max(ans.oo, ans.ox, ans.xo);
	return (ans.oo > ans.xx) ? ans.oo : ans.xx;
}

// int max2(int a, int b)
// {
// 	return (a > b) ? a : b;
// }

int midi(int a, int b)
{
	return a + (b-a)/2;
}

int constructutil_oo(int a[], int ss, int se, node *st, int si);
int constructutil_ox(int a[], int ss, int se, node *st, int si);
int constructutil_xo(int a[], int ss, int se, node *st, int si);
int constructutil_xx(int a[], int ss, int se, node *st, int si);

int constructutil_oo(int a[], int ss, int se, node *st, int si)
{
	if(st[si].oo > 0)
	{
		return st[si].oo;
	}
	if(ss == se)
	{
		st[si].oo = 0;
		return 0;
	}
	
	int mid = midi(ss, se);
	st[si].oo = max(constructutil_ox(a, ss, mid, st, si*2+1)+constructutil_xo(a, mid+1, se, st, si*2+2), constructutil_ox(a, ss, mid, st, si*2+1)+constructutil_oo(a, mid+1, se, st, si*2+2), constructutil_oo(a, ss, mid, st, si*2+1)+constructutil_xo(a, mid+1, se, st, si*2+2));
	
	return st[si].oo;
}

int constructutil_ox(int a[], int ss, int se, node *st, int si)
{
	if(st[si].ox > 0)
	{
		return st[si].ox;
	}
	if(ss == se)
	{
		st[si].ox = a[ss*2];
		return a[ss*2];
	}
	
	int mid = midi(ss, se);
	st[si].ox = max(constructutil_ox(a, ss, mid, st, si*2+1)+constructutil_ox(a, mid+1, se, st, si*2+2), constructutil_ox(a, ss, mid, st, si*2+1)+constructutil_xx(a, mid+1, se, st, si*2+2), constructutil_oo(a, ss, mid, st, si*2+1)+constructutil_xx(a, mid+1, se, st, si*2+2));
	
	return st[si].ox;
}

int constructutil_xo(int a[], int ss, int se, node *st, int si)
{
	if(st[si].xo > 0)
	{
		return st[si].xo;
	}
	if(ss == se)
	{
		st[si].xo = a[ss*2+1];
		return a[ss*2+1];
	}
	
	int mid = midi(ss, se);
	st[si].xo = max(constructutil_xo(a, ss, mid, st, si*2+1)+constructutil_xo(a, mid+1, se, st, si*2+2), constructutil_xx(a, ss, mid, st, si*2+1)+constructutil_xo(a, mid+1, se, st, si*2+2), constructutil_xx(a, ss, mid, st, si*2+1)+constructutil_oo(a, mid+1, se, st, si*2+2));
	
	return st[si].xo;
}

int constructutil_xx(int a[], int ss, int se, node *st, int si)
{
	if(st[si].xx > 0)
	{
		return st[si].xx;
	}
	if(ss == se)
	{
		st[si].xx = 0;
		return 0;
	}
	
	int mid = midi(ss, se);
	st[si].xx = max(constructutil_xx(a, ss, mid, st, si*2+1)+constructutil_xx(a, mid+1, se, st, si*2+2), constructutil_xo(a, ss, mid, st, si*2+1)+constructutil_xx(a, mid+1, se, st, si*2+2), constructutil_xx(a, ss, mid, st, si*2+1)+constructutil_ox(a, mid+1, se, st, si*2+2));
	
	return st[si].xx;
}

node *construct(int a[], int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	node *st = new node[max_size];
	for(int i = 0; i < max_size; i++)
	{
		st[i].oo = -1;
		st[i].ox = -1;
		st[i].xo = -1;
		st[i].xx = -1;
	}
	constructutil_oo(a, 0, n-1, st, 0);
	constructutil_ox(a, 0, n-1, st, 0);
	constructutil_xo(a, 0, n-1, st, 0);
	constructutil_xx(a, 0, n-1, st, 0);
	// for(int i = 0; i < max_size; i++)
	// {
	// 	cout << "oo[" << i << "]: " << st[i].oo << endl;
	// 	cout << "ox[" << i << "]: " << st[i].ox << endl;
	// 	cout << "xo[" << i << "]: " << st[i].xo << endl;
	// 	cout << "xx[" << i << "]: " << st[i].xx << endl;
	// }

	return st;
}

int find(int f, int l, int r, int re)
{
	if(l == r)
	{
		return re;
	}
	else if(f <= midi(l, r))
	{
		return find(f, l, midi(l, r), re*2+1);
	}
	else
	{
		return find(f, midi(l, r)+1, r, re*2+2);
	}
}

int root(int a)
{
	return (a-1)/2;
}

void update(node *st, int j, int k, int n)
{
	int f = j / 2;
	f = find(f, 0, n-1, 0);
	if(0 == j%2)
	{
		st[f].ox = k;
	}
	else
	{
		st[f].xo = k;
	}
	f = root(f);
	while(f > 0)
	{
		st[f].oo = max(st[f*2+1].ox+st[f*2+2].xo, st[f*2+1].ox+st[f*2+2].oo, st[f*2+1].oo+st[f*2+2].xo);
		st[f].ox = max(st[f*2+1].ox+st[f*2+2].ox, st[f*2+1].ox+st[f*2+2].xx, st[f*2+1].oo+st[f*2+2].xx);
		st[f].xo = max(st[f*2+1].xo+st[f*2+2].xo, st[f*2+1].xx+st[f*2+2].xo, st[f*2+1].xx+st[f*2+2].oo);
		st[f].xx = max(st[f*2+1].xx+st[f*2+2].xx, st[f*2+1].xo+st[f*2+2].xx, st[f*2+1].xx+st[f*2+2].ox);
		f = root(f);
	}
	
	st[f].oo = max(st[f*2+1].ox+st[f*2+2].xo, st[f*2+1].ox+st[f*2+2].oo, st[f*2+1].oo+st[f*2+2].xo);
	st[f].ox = max(st[f*2+1].ox+st[f*2+2].ox, st[f*2+1].ox+st[f*2+2].xx, st[f*2+1].oo+st[f*2+2].xx);
	st[f].xo = max(st[f*2+1].xo+st[f*2+2].xo, st[f*2+1].xx+st[f*2+2].xo, st[f*2+1].xx+st[f*2+2].oo);
	st[f].xx = max(st[f*2+1].xx+st[f*2+2].xx, st[f*2+1].xo+st[f*2+2].xx, st[f*2+1].xx+st[f*2+2].ox);
	// for(int i = 0; i < 10; i++)
	// {
	// 	cout << "oo[" << i << "]: " << st[i].oo << endl;
	// 	cout << "ox[" << i << "]: " << st[i].ox << endl;
	// 	cout << "xo[" << i << "]: " << st[i].xo << endl;
	// 	cout << "xx[" << i << "]: " << st[i].xx << endl;
	// }
}

int main()
{
	//cout << "kcndndcnd" << endl;
	int n, m, i, j, k, x;
	int o = 0;
	cin >> n;
	cin >> m;
	if(1 == n%2)
	{
		o = 1;
		n++;
	}
	int a[n];
	if(1 == o)
	{
		a[n-1] = 0;
		for(x = 0; x < n-1; x++)
		{
			cin >> a[x];
		}
	}
	else
	{
		for(x = 0; x < n; x++)
		{
			cin >> a[x];
		}
	}
	
	n /= 2;
	node *st = construct(a, n);
	
	for(x = 0; x < m; x++)
	{
		cin >> i;
		cin >> j;
		cin >> k;
		if(0 == i)
		{
			//a[j] = k;
			update(st, j, k, n);
		}
		else
		{
			n *= 2;
			cout << getans(st, n, j, k) << endl;
			n /= 2;
		}
	}
	
	return 0;
}
