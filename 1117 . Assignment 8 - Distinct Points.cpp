#include <iostream>
#include <string.h>
#include <list>

using namespace std;

#define HASH_SIZE 1000

struct node0
{
	int key;
	int count;
};
struct node1
{
	int key;
	list<node0> dict[HASH_SIZE];
};
struct node2
{
	int key;
	list<node1> dict[HASH_SIZE];
};


int main()
{
    int n;
    int a, b, c, i;
    cin >> n;
    int out[n][3];
    
    list<node0> x[HASH_SIZE];
    list<node0> y[HASH_SIZE];
    list<node0> z[HASH_SIZE];
    
	list<node1> xy[HASH_SIZE];
	list<node1> yz[HASH_SIZE];
	list<node1> zx[HASH_SIZE];
    
	list<node2> xyz[HASH_SIZE];

    for(i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        out[i][0] = a;
        out[i][1] = b;
        out[i][2] = c;
        int hashed_a = a%HASH_SIZE, hashed_b = b%HASH_SIZE, hashed_c = c%HASH_SIZE;
        
        //x ====================================================================================================
        list<node0>::iterator find = x[hashed_a].end();
        for (list<node0>::iterator ix = x[hashed_a].begin(); ix != x[hashed_a].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			find = ix;
    			((*ix).count)++;
    			break;
			}
		}
		if(find == x[hashed_a].end())
		{
			struct node0 temp;
			temp.key = a;
			temp.count = 1;
			x[hashed_a].push_back(temp);
		}
		
		//y ====================================================================================================
        find = y[hashed_b].end();
        for (list<node0>::iterator ix = y[hashed_b].begin(); ix != y[hashed_b].end(); ix++)
    	{
    		if((*ix).key == b)
    		{
    			find = ix;
    			((*ix).count)++;
    			break;
			}
		}
		if(find == y[hashed_b].end())
		{
			struct node0 temp;
			temp.key = b;
			temp.count = 1;
			y[hashed_b].push_back(temp);
		}
        
        //z ====================================================================================================
        find = z[hashed_c].end();
        for (list<node0>::iterator ix = z[hashed_c].begin(); ix != z[hashed_c].end(); ix++)
    	{
    		if((*ix).key == c)
    		{
    			find = ix;
    			((*ix).count)++;
    			break;
			}
		}
		if(find == z[hashed_c].end())
		{
			struct node0 temp;
			temp.key = c;
			temp.count = 1;
			z[hashed_c].push_back(temp);
		}
        
        
        //xy ====================================================================================================
        list<node1>::iterator find1 = xy[hashed_a].end();
        for (list<node1>::iterator ix = xy[hashed_a].begin(); ix != xy[hashed_a].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			find1 = ix;
    			list<node0>::iterator find0 = (*ix).dict[hashed_b].end();
    			for(list<node0>::iterator in = (*ix).dict[hashed_b].begin(); in != (*ix).dict[hashed_b].end(); in++)
    			{
    				if((*in).key == b)
    				{
    					find0 = in;
    					(*in).count++;
    					break;
					}
				}
				if(find0 == (*ix).dict[hashed_b].end())
				{
					struct node0 temp;
					temp.key = b;
					temp.count = 1;
					(*ix).dict[hashed_b].push_back(temp);
				}
    			break;
			}
		}
		if(find1 == xy[hashed_a].end())
		{
			struct node1 temp1;
			struct node0 temp0;
			temp0.key = b;
			temp0.count = 1;
			temp1.key = a;
			temp1.dict[hashed_b].push_back(temp0);
			xy[hashed_a].push_back(temp1);
		}
		
		//yz ====================================================================================================
        find1 = yz[hashed_b].end();
        for (list<node1>::iterator ix = yz[hashed_b].begin(); ix != yz[hashed_b].end(); ix++)
    	{
    		if((*ix).key == b)
    		{
    			find1 = ix;
    			list<node0>::iterator find0 = (*ix).dict[hashed_c].end();
    			for(list<node0>::iterator in = (*ix).dict[hashed_c].begin(); in != (*ix).dict[hashed_c].end(); in++)
    			{
    				if((*in).key == c)
    				{
    					find0 = in;
    					(*in).count++;
    					break;
					}
				}
				if(find0 == (*ix).dict[hashed_c].end())
				{
					struct node0 temp;
					temp.key = c;
					temp.count = 1;
					(*ix).dict[hashed_c].push_back(temp);
				}
    			break;
			}
		}
		if(find1 == yz[hashed_b].end())
		{
			struct node1 temp1;
			struct node0 temp0;
			temp0.key = c;
			temp0.count = 1;
			temp1.key = b;
			temp1.dict[hashed_c].push_back(temp0);
			yz[hashed_b].push_back(temp1);
		}
		
		//zx ====================================================================================================
        find1 = zx[hashed_c].end();
        for (list<node1>::iterator ix = zx[hashed_c].begin(); ix != zx[hashed_c].end(); ix++)
    	{
    		if((*ix).key == c)
    		{
    			find1 = ix;
    			list<node0>::iterator find0 = (*ix).dict[hashed_a].end();
    			for(list<node0>::iterator in = (*ix).dict[hashed_a].begin(); in != (*ix).dict[hashed_a].end(); in++)
    			{
    				if((*in).key == a)
    				{
    					find0 = in;
    					(*in).count++;
    					break;
					}
				}
				if(find0 == (*ix).dict[hashed_a].end())
				{
					struct node0 temp;
					temp.key = a;
					temp.count = 1;
					(*ix).dict[hashed_a].push_back(temp);
				}
    			break;
			}
		}
		if(find1 == zx[hashed_c].end())
		{
			struct node1 temp1;
			struct node0 temp0;
			temp0.key = a;
			temp0.count = 1;
			temp1.key = c;
			temp1.dict[hashed_a].push_back(temp0);
			zx[hashed_c].push_back(temp1);
		}
        
        
        //xyz begin====================================================================================================
        list<node2>::iterator find2 = xyz[hashed_a].end();
        for(list<node2>::iterator out = xyz[hashed_a].begin(); out != xyz[hashed_a].end(); out++)
        {
        	if((*out).key == a)
        	{
        		find2 = out;
        		list<node1>::iterator find1 = (*out).dict[hashed_b].end();
		        for (list<node1>::iterator ix = (*out).dict[hashed_b].begin(); ix != (*out).dict[hashed_b].end(); ix++)
		    	{
		    		if((*ix).key == b)
		    		{
		    			find1 = ix;
		    			list<node0>::iterator find0 = (*ix).dict[hashed_c].end();
		    			for(list<node0>::iterator in = (*ix).dict[hashed_c].begin(); in != (*ix).dict[hashed_c].end(); in++)
		    			{
		    				if((*in).key == c)
		    				{
		    					find0 = in;
		    					(*in).count++;
		    					break;
							}
						}
						if(find0 == (*ix).dict[hashed_c].end())
						{
							struct node0 temp;
							temp.key = c;
							temp.count = 1;
							(*ix).dict[hashed_c].push_back(temp);
						}
		    			break;
					}
				}
				if(find1 == (*out).dict[hashed_b].end())
				{
					struct node1 temp1;
					struct node0 temp0;
					temp0.key = c;
					temp0.count = 1;
					temp1.key = b;
					temp1.dict[hashed_c].push_back(temp0);
					(*out).dict[hashed_b].push_back(temp1);
				}
			}
		}
		if(find2 == xyz[hashed_a].end())
		{
			struct node2 temp2;
			struct node1 temp1;
			struct node0 temp0;
			temp0.key = c;
			temp0.count = 1;
			temp1.key = b;
			temp1.dict[hashed_c].push_back(temp0);
			temp2.key = a;
			temp2.dict[hashed_b].push_back(temp1);
			xyz[hashed_a].push_back(temp2);
		}
    }

    for(i = 0; i < n; i++)
    {
        a = out[i][0];
        b = out[i][1];
        c = out[i][2];
        int xa = 0;
        int yb = 0;
        int zc = 0;
        int xyab = 0;
        int yzbc = 0;
        int zxca = 0;
        int xyzabc = 0;
        int hashed_a = a%HASH_SIZE, hashed_b = b%HASH_SIZE, hashed_c = c%HASH_SIZE;
        //x ====================================================================================================
        for (list<node0>::iterator ix = x[hashed_a].begin(); ix != x[hashed_a].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			xa = (*ix).count;
    			break;
			}
		}
		//y ====================================================================================================
		for (list<node0>::iterator ix = y[hashed_b].begin(); ix != y[hashed_b].end(); ix++)
    	{
    		if((*ix).key == b)
    		{
    			yb = (*ix).count;
    			break;
			}
		}
		//z ====================================================================================================
		for (list<node0>::iterator ix = z[hashed_c].begin(); ix != z[hashed_c].end(); ix++)
    	{
    		if((*ix).key == c)
    		{
    			zc = (*ix).count;
    			break;
			}
		}
		//xy ====================================================================================================
        for (list<node1>::iterator ix = xy[hashed_a].begin(); ix != xy[hashed_a].end(); ix++)
    	{
    		if((*ix).key == a)
    		{
    			for (list<node0>::iterator in = (*ix).dict[hashed_b].begin(); in != (*ix).dict[hashed_b].end(); in++)
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
		//yz ====================================================================================================
		for (list<node1>::iterator ix = yz[hashed_b].begin(); ix != yz[hashed_b].end(); ix++)
    	{
    		if((*ix).key == b)
    		{
    			for (list<node0>::iterator in = (*ix).dict[hashed_c].begin(); in != (*ix).dict[hashed_c].end(); in++)
   			 	{
    				if((*in).key == c)
    				{
    					yzbc = (*in).count;
    					break;
					}
				}
    			break;
			}
		}
		
		//zx ====================================================================================================
		for (list<node1>::iterator ix = zx[hashed_c].begin(); ix != zx[hashed_c].end(); ix++)
    	{
    		if((*ix).key == c)
    		{
    			for (list<node0>::iterator in = (*ix).dict[hashed_a].begin(); in != (*ix).dict[hashed_a].end(); in++)
   			 	{
    				if((*in).key == a)
    				{
    					zxca = (*in).count;
    					break;
					}
				}
    			break;
			}
		}
		
		//xyz ====================================================================================================
		for(list<node2>::iterator out = xyz[hashed_a].begin(); out != xyz[hashed_a].end(); out++)
		{
			if((*out).key == a)
			{
				for (list<node1>::iterator ix = (*out).dict[hashed_b].begin(); ix != (*out).dict[hashed_b].end(); ix++)
		    	{
		    		if((*ix).key == b)
		    		{
		    			for (list<node0>::iterator in = (*ix).dict[hashed_c].begin(); in != (*ix).dict[hashed_c].end(); in++)
		   			 	{
		    				if((*in).key == c)
		    				{
		    					xyzabc = (*in).count;
		    					break;
							}
						}
		    			break;
					}
				}
				break;
			}
		}
        cout << n - xa - yb - zc + xyab + yzbc + zxca - xyzabc << " ";
    }

    return 0;
}
