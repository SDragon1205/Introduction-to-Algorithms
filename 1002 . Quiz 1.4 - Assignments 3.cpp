#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct ass
{
	int s, d, t;
	ass(){}
    ass(int _s,int _d,int _t){
        s=_s;
        d=_d;
        t=_t;
    }
};

vector<ass> a;
//ass a[20001];

bool asort(ass &n1,ass &n2){
    return (n1.d < n2.d);// || ((n1.d == n2.d)&&(n1.t < n2.t)) || ((n1.d == n2.d)&&(n1.t == n2.t)&&(n1.s < n2.s));
}

//int compare(const void *a, const void *b)//�o�禡�O qsort �һݪ�����禡
//{
//      ass c = *(ass *)a;
//      ass d = *(ass *)b;
//      if(c.d < d.d) {return -1;}               //�Ǧ^ -1 �N�� a < b
//      else if (c.d == d.d) {return 0;}      //�Ǧ^   0 �N�� a = b
//      else return 1;                          //�Ǧ^  1 �N�� a>b
//}
int dp[30001];

int main()
{
	int n, w, v;
	cin >> n;
	int maxd = 0;
	int s = 0, d = 0, t = 0;
    a.push_back(ass(s, d, t));
	for(int x = 1; x <= n; x++)
	{
		cin >> s;
		cin >> d;
		cin >> t;
		a.push_back(ass(s,d,t));
        maxd = max(maxd, d);
	}
	sort(a.begin(), a.end(), asort);
	// for(int i = 0; i <= n; i++)
	// {
	// 	cout << a[i].s << " " << a[i].d << " " << a[i].t << "\n";
	// }
//	qsort((void *)a, n, sizeof(a[0]), compare);
	//int dp[n+1][maxd+1];
	// for(int z = 0; z < a[0].t; z++)
	// {
	// 	dp[0][z] = 0;
	// }
	// for(int z = a[0].t; z <= maxd; z++)
	// {
	// 	dp[0][z] = a[0].s;
	// }
    for(int x = 1; x <= n; x++)
	{
		//cout << "x: " << x << " ";
	    for(int y = maxd; y >= 0; y--)
	    {
	    	//cout << "y: " << y << " ";
		    if(y - a[x].t >= 0 && y <= a[x].d)
		    {
		    	//cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << " ";
		    	dp[y] = max(dp[y], dp[y - a[x].t] + a[x].s);
		        //cout << "dp[" << y << "][" << z << "]: " << dp[y][z] << "\n";
			}
			// else
            // {
			// 	dp[y] = dp[y-1];
			// }
			//cout << "\n";
	    }
	}
	
//    for(int y = 0; y <= maxd; y=y+100)
//    {
//        for(int x = 0; x < n; x++)
//        {
//            cout << dp[x][y] << " ";
//        }
//        cout << "\n";
//    }
	int da = 0;
	for(int i = 0; i <= maxd; i++)
	{
		da = max(da, dp[i]);
	}
	cout << da << "\n";
	//cout << dp[maxd] << "\n";
	
	return 0; 
}
