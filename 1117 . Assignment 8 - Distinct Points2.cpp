#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int a, b, c, i;
    cin >> n;
    int out[n][3];
    
    map<int, int> x;

    map<int, int> y;

    map<int, int> z;

    map<int, map<int, int> > xy;

    map<int, map<int, int> > yz;

    map<int, map<int, int> > zx;

	map<int, map<int, map<int, int> > > xyz;


    for(i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
		out[i][0] = a;
        out[i][1] = b;
        out[i][2] = c;
		/*

        if(x.find(a) == x.end())
        {
        	x[a] = 1;
		}
		else
		{
			++x[a];
		}
		
        if(y.find(b) == y.end())
        {
        	y[b] = 1;
		}
		else
		{
			++y[b];
		}
		
        if(z.find(c) == z.end())
        {
        	z[c] = 1;
		}
		else
		{
			++z[c];
		}
		
        if(xy.find(a) == xy.end() || xy[a].find(b) == xy[a].end())
        {
			xy[a][b] = 1;
		}
		else
		{
			++ xy[a][b];
		}
        if(yz.find(b) == yz.end() || yz[b].find(c) == yz[b].end())
        {
			yz[b][c] = 1;
		}
		else
		{
			++ yz[b][c];
		}
        if(zx.find(c) == zx.end() || zx[c].find(a) == zx[c].end())
        {
			zx[c][a] = 1;
		}
		else
		{
			++ zx[c][a];
		}

        if(xyz.find(a) == xyz.end() || xyz[a].find(b) == xyz[a].end() || xyz[a][b].find(c) == xyz[a][b].end())
        {
			xyz[a][b][c] = 1;
		}
		else
		{
			++ xyz[a][b][c];
		}
		*/
        x[a]++;
        y[b]++;
        z[c]++;
        xy[a][b]++;
        yz[b][c]++;
        zx[c][a]++;
        xyz[a][b][c]++;
    }

    a = out[0][0];
    b = out[0][1];
    c = out[0][2];
	cout << n - x[a] - y[b] - z[c] + xy[a][b] + yz[b][c] + zx[c][a] - xyz[a][b][c];
    for(i = 1; i < n; i++)
    {
        a = out[i][0];
        b = out[i][1];
        c = out[i][2];
        cout << " " << n - x[a] - y[b] - z[c] + xy[a][b] + yz[b][c] + zx[c][a] - xyz[a][b][c];
    }
	cout << endl;
	
    return 0;
}
