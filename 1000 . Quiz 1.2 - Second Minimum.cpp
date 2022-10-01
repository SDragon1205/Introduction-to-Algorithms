//#include <bits/stdc++.h>
#include<iostream>
#include<math.h>

using namespace std;

struct node{
	int fir;
	int sec;
};

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int sec4(int a, int b, int c, int d)
{
	int e;
	if(a > b)
	{
		e = a;
		a = b;
		b = e;
	}
	if(a > c)
	{
		e = a;
		a = c;
		c = e;
	}
	if(a > d)
	{
		e = a;
		a = d;
		d = e;
	}
	if(b > c)
	{
		e = c;
		c = b;
		b = e;
	}
	if(b > d)
	{
		e = d;
		d = b;
		b = e;
	}

	return b;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int mid(int a, int b)
{
	return a+((b-a)/2);
}

node construct_u(int a[], int ss, int se, node* st, int si)
{
	if(ss == se)
	{
		st[si].fir = a[ss];
		return st[si];
	}
	if(st[si].fir != 1000000001 && st[si].sec != 1000000001)
	{
		return st[si];
	}
	
	int mi = mid(ss, se);
	node s1 = construct_u(a, ss, mi, st, si*2+1);
	node s2 = construct_u(a, mi+1, se, st, si*2+2);
	st[si].fir = min(s1.fir, s2.fir);
	st[si].sec = sec4(s1.fir, s2.fir, s1.sec, s2.sec);
	
	return st[si];
}

node* construct(int a[], int n)
{
	int x = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,x)-1;
	
	node* st = new node[size];
	for(int x = 0; x < size; x++)
	{
		st[x].fir = 1000000001;
		st[x].sec = 1000000001;
	}
	construct_u(a, 0, n-1, st, 0);
	// for(int x = 0; x < size; x++)
	// {
	// 	cout << st[x].fir << " " << st[x].sec << "\n";
	// }
	
	return st;
}

node getansutil(node* st, int ss, int se, int qs, int qe, int si)
{
	if(qs <= ss && se <= qe)
	{
		//cout << "sub[" << ss << "][" << se << "]: " << st[si].fir << " & " << st[si].sec << endl;
		return st[si];
	}
	if(ss > qe || se < qs)
	{
		node no;
		no.fir = 1000000001;
		no.sec = 1000000001;
		//cout << "sub[" << ss << "][" << se << "]: " << no.fir << " & " << no.sec << endl;
		return no;
	}
	
	node sub;
	int mi = mid(ss, se);
	node s1 = getansutil(st, ss, mi, qs, qe, si*2+1);
	node s2 = getansutil(st, mi+1, se, qs, qe, si*2+2);
	sub.fir = min(s1.fir, s2.fir);
	sub.sec = sec4(s1.fir, s2.fir, s1.sec, s2.sec);
	//cout << "sub[" << ss << "][" << se << "]: " << sub.fir << " & " << sub.sec << endl;
	return sub;
}

int getans(node *st, int n, int qs, int qe)
{
	node s = getansutil(st, 0, n-1, qs, qe, 0);
	return s.sec;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n, m;
	cin >> n;
	cin >> m;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	node* st = construct(a, n);
	int i, j;
	for(int x = 0; x < m; x++)
	{
		cin >> i;
		cin >> j;
		cout << getans(st, n, i, j) << "\n";
	}

	
	return 0;
}
