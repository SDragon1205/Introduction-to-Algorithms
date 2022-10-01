
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void a_merge(long int a[][2], int p, int m, int q)
{
	int n1 = m - p + 1;
	int n2 = q - m;
    int i, j;

    long int L[n1][2];
    long int R[n2][2];

    for(int i = 0; i < n1; i++)
    {
        L[i][0] = a[p+i][0];
        L[i][1] = a[p+i][1];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i][0] = a[m+1+i][0];
        R[i][1] = a[m+1+i][1];
    }

    i = n1 - 1;
    j = n2 - 1;
    int k = q;
    while(i >= 0 && j >=0)
    {
        if(L[i][0] <= R[j][0])
        {
            a[k][0] = R[j][0];
            a[k][1] = R[j][1] + n1 - 1 - i;
            j--;
        }
        else
        {
            a[k][0] = L[i][0];
            a[k][1] = L[i][1];
            i--;
        }
        k--;
    }
    while (i >= 0) { 
        a[k][0] = L[i][0];
        a[k][1] = L[i][1];
        i--;
        k--;
    } 
    while (j >= 0) { 
        a[k][0] = R[j][0];
        a[k][1] = R[j][1] + n1 - 1 - i;
        j--;
        k--;
    }
}

void a_merge_sort(long int a[][2], int p, int q)
{
	if(p < q)
	{
		int m = (p + q) / 2;
		a_merge_sort(a, p, m);
		a_merge_sort(a, m + 1, q);
		a_merge(a, p, m, q);
	}
}

void b_merge(long int a[][2], int p, int m, int q)
{
	int n1 = m - p + 1;
	int n2 = q - m;
    int i, j;

    long int L[n1][2];
    long int R[n2][2];

    for(int i = 0; i < n1; i++)
    {
        L[i][0] = a[p+i][0];
        L[i][1] = a[p+i][1];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i][0] = a[m+1+i][0];
        R[i][1] = a[m+1+i][1];
    }

    i = 0;
    j = 0;
    int k = p;
    while(i < n1 && j < n2)
    {
        if(R[j][0] < L[i][0])
        {
            a[k][0] = R[j][0];
            a[k][1] = R[j][1];
            j++;
        }
        else
        {
            a[k][0] = L[i][0];
            a[k][1] = L[i][1] + j;
            i++;
        }
        k++;
    }
    while (i < n1) { 
        a[k][0] = L[i][0];
        a[k][1] = L[i][1] + j;
        i++;
        k++;
    } 
    while (j < n2) { 
        a[k][0] = R[j][0];
        a[k][1] = R[j][1];
        j++;
        k++;
    }
}

void b_merge_sort(long int a[][2], int p, int q)
{
	if(p < q)
	{
		int m = (p + q) / 2;
		b_merge_sort(a, p, m);
		b_merge_sort(a, m + 1, q);
		b_merge(a, p, m, q);
	}
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    long int a[t][2];
    long int b[t][2];
    int i;
    for (i = 0; i < t; i++){
        cin >> a[i][0];
        b[i][0] = a[i][0];
        a[i][1] = 0;
        b[i][1] = 0;
    }
	
    a_merge_sort(a, 0, t-1);
    b_merge_sort(b, 0, t-1);
    for(i = 0; i < t; i++)
    {
        cout << a[i][0] << " " << a[i][1] << endl;
    }
    for(i = 0; i < t; i++)
    {
        cout << b[i][0] << " " << b[i][1] << endl;
    }

    long int ans = 0;
    
    for(i = 0; i < t; i++)
    {
    	ans += a[i][1] * b[i][1];
    }

    cout << ans << endl;


    return 0;
}
