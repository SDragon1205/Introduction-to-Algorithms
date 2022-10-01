#include <bits/stdc++.h>
#include <string.h>
#include <list>

using namespace std;
struct node0
{
	int key;
	int count;
};
struct node1
{
	int key;
	list<node1> dict[1000];
};
struct node2
{
	int key;
	list<node2> dict[1000];
};


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    int a, b, c, i;
    cin >> n;
    int out[n][3];
    list<node0> x[1000];
    int y[n+1];
    memset(y, 0, sizeof y);
    int z[n+1];
    memset(z, 0, sizeof z);
	list<node1> xy[1000];
    int yz[n+1][n+1];
    memset(yz, 0, sizeof yz);
    int zx[n+1][n+1];
    memset(zx, 0, sizeof zx);
    int xyz[n+1][n+1][n+1];
    memset(xyz, 0, sizeof xyz);

    for(i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        out[i][0] = a;
        out[i][1] = b;
        out[i][2] = c;
        int hashed_index = a%1000, hashed_index1 = b%1000, hashed_index2 = c%1000;
        list<node0>::iterator find = x[hashed_index].end();
        for (list<node0>::iterator ix = x[hashed_index].begin(); ix != x[hashed_index].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			find = ix;
    			((*ix).count)++;
    			break;
			}
		}
		if(find == x[hashed_index].end())
		{
			struct node0 temp;
			temp.key = a;
			temp.count = 1;
			x[hashed_index].push_back(temp);
		}
		
        y[b]++;
        z[c]++;
        
        hashed_index = a%1000;
        hashed_index1 = b%1000;
        list<node1>::iterator find1 = xy[hashed_index].end();
        for (list<node1>::iterator ix = xy[hashed_index].begin(); ix != xy[hashed_index].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			find1 = ix;
    			list<node0>::iterator find0 = (*ix).dict[hashed_index1].end();
    			for(list<node0>::iterator in = (*ix).dict[hashed_index1].begin(); in != (*ix).dict[hashed_index1].end(); in++)
    			{
    				if((*in).key == b)
    				{
    					find0 = in;
    					(*in).count++;
    					break;
					}
				}
				if(find0 == (*ix).dict[hashed_index1].end())
				{
					struct node0 temp;
					temp.key = b;
					temp.count = 1;
					(*ix).dict[hashed_index1].push_back(temp);
				}
    			break;
			}
		}
		if(find1 == xy[hashed_index].end())
		{
			struct node1 temp1;
			struct node0 temp0;
			temp0.key = b;
			temp0.count = 1;
			temp1.key = a;
			temp1.dict[hashed_index1] = temp0;
			xy[hashed_index].push_back(temp1);
		}
		
        yz[b][c]++;
        zx[c][a]++;
        xyz[a][b][c]++;
    }

    for(i = 0; i < n; i++)
    {
        a = out[i][0];
        b = out[i][1];
        c = out[i][2];
        int xa = 0;
        int xyab = 0;
        int hashed_index = = a%1000, hashed_index1 = b%1000, hashed_index2= c%1000;
        for (list<node0>::iterator ix = x[hashed_index].begin(); ix != x[hashed_index].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			xa = (*ix).count;
    			break;
			}
		}
        for (list<node1>::iterator ix = xy[a%1000].begin(); ix != x[a%1000].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			for (list<node0>::iterator in = (*ix).dict[hashed_index1].begin(); in != (*ix).dict[hashed_index1].end(); in++)
   			 	{
    				if((*in).key == b)
    				{
    					xyab = (*in).count;
    					break;
					}
				}
    			break;
			}
		}
        cout << n - xa - y[b] - z[c] + xyab + yz[b][c] + zx[c][a] - xyz[a][b][c] << " ";
    }

    return 0;
}
