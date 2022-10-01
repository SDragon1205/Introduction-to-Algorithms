
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int find_digit(int y, double n, double d, int d1, int d2)
{
	int m = (d1 + d2) / 2;
	double m1 = n + (d * m);
	//cout << "m1: " << m1 << endl;
	if(d2 == d1 + 1)
	{
		return d1;
	}
	
	if(m1*exp(m1) <= y)
	{
		return find_digit(y, n, d, m, d2);
	}
	else
	{
		return find_digit(y, n, d, d1, m);
	}
	
}

double W(double y) {
    double ans = find_digit(y, 0, 1, 0, 19);
    //cout << "ans: " << ans << endl;
    double x = 1;
    for(int i = 0; i < 12; i++)
    {
    	x *= 0.1;
    	//cout << "i: " << i << ", x: " << x << ", ans: " << ans << endl;
    	ans += x * find_digit(y, ans, x, 0, 10);
	}
	
	return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        double y;
        cin >> y;
        cout << fixed << setprecision(12) << W(y) << endl;
    }
    return 0;
}
