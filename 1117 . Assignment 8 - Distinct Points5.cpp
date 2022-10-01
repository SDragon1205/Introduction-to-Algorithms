
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

struct point{
    int x;
    int y;
    int z;
    int p;
    int x_bk_index;
    int y_bk_index;
    int z_bk_index;
    int xy_bk_index;
    int yz_bk_index;
    int zx_bk_index;
    int xyz_bk_index;
    point(){}
    point(int cin_x,int cin_y,int cin_z,int cin_p){
        x = cin_x;
        y = cin_y;
        z = cin_z;
        p = cin_p;
    }
};

int xsort(const void *ptr_a, const void *ptr_b){
    point a = *(point *)ptr_a;
    point b = *(point *)ptr_b;
    if(a.x > b.x) 
	{
	  return -1;
	}
	else if (a.x == b.x)
	{
  	  if(a.y > b.y) 
  	  {
  	  	return -1;
	  }
	  else if(a.y == b.y) 
	  {
	  	if(a.z > b.z)	  	
		{
    	  return -1;
		}
		else if(a.z == b.z)
		{
		  return 0;
		}
	  }		
	}
	return 1;
}
int ysort(const void *ptr_a, const void *ptr_b){
    point a = *(point *)ptr_a;
    point b = *(point *)ptr_b;
    if(a.y > b.y) 
	{
	  return -1;
	}
	else if (a.y == b.y)
	{
  	  if(a.z > b.z) 
  	  {
  	  	return -1;
	  }
	  else if(a.z == b.z) 
	  {
	  	if(a.x > b.x)	  	
		{
    	  return -1;
		}
		else if(a.x == b.x)
		{
		  return 0;
		}
	  }		
	}
	return 1;
}
int zsort(const void *ptr_a, const void *ptr_b){
    point a = *(point *)ptr_a;
    point b = *(point *)ptr_b;
    if(a.z > b.z) 
	{
	  return -1;
	}
	else if (a.z == b.z)
	{
  	  if(a.x > b.x) 
  	  {
  	  	return -1;
	  }
	  else if(a.x == b.x) 
	  {
	  	if(a.y > b.y)  	
		{
    	  return -1;
		}
		else if(a.y == b.y)
		{
		  return 0;
		}
	  }		
	}
	return 1;
}
int psort(const void *ptr_a, const void *ptr_b){
    point a = *(point *)ptr_a;
    point b = *(point *)ptr_b;
	if(a.p < b.p) 
	{
	  return -1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	cin.tie(0);
    cin.sync_with_stdio(0);
    
	int n, i;
	cin >> n;
	int x_bk[n], x_bk_size = 0;
	memset(x_bk, 0, sizeof x_bk);
	int y_bk[n], y_bk_size = 0;
	memset(y_bk, 0, sizeof y_bk);
	int z_bk[n], z_bk_size = 0;
	memset(z_bk, 0, sizeof z_bk);
	int xy_bk[n], xy_bk_size = 0;
	memset(xy_bk, 0, sizeof xy_bk);
	int yz_bk[n], yz_bk_size = 0;
	memset(yz_bk, 0, sizeof yz_bk);
	int zx_bk[n], zx_bk_size = 0;
	memset(zx_bk, 0, sizeof zx_bk);
	int xyz_bk[n], xyz_bk_size = 0;
	memset(xyz_bk, 0, sizeof xyz_bk);
	struct point li[n];
	for(i = 0; i < n; i++)
	{
		li[i].p = i;
		cin >> li[i].x;
		cin >> li[i].y;
		cin >> li[i].z;
	}
	qsort((void *)li, n, sizeof(struct point), xsort);
//	for(i = 0; i < n; i++)
//	{
//		cout << li[i].x << " " << li[i].y << " " << li[i].z << endl;
//	}
    li[0].x_bk_index = 0;
    li[0].xy_bk_index = 0;
    li[0].xyz_bk_index = 0;
	for(i = 1; i < n; i++)
	{
		if(li[i].x != li[i-1].x)
		{
			x_bk_size++;
			xy_bk_size++;
			xyz_bk_size++;
			//cout << "fu1" << endl;
		}
		else
		{
			x_bk[x_bk_size]++;
			if(li[i].y != li[i-1].y)
			{
				xy_bk_size++;
				xyz_bk_size++;
				//cout << "fu2" << endl;
			}
			else
			{
				xy_bk[xy_bk_size]++;
				if(li[i].z != li[i-1].z)
				{
					xyz_bk_size++;
					//cout << "fu3" << endl;
				}
				else
				{
					xyz_bk[xyz_bk_size]++;
					//cout << "fu4" << endl;
				}
			}
		}
		li[i].x_bk_index = x_bk_size;
		li[i].xy_bk_index = xy_bk_size;
		li[i].xyz_bk_index = xyz_bk_size;
	}
//	for(i = 0; i < n; i++)
//	{
//		cout << x_bk[i] << endl;
//	}
//	for(i = 0; i < n; i++)
//	{
//		cout << xy_bk[i] << endl;
//	}
//	for(i = 0; i < n; i++)
//	{
//		cout << xyz_bk[i] << endl;
//	}
	qsort((void *)li, n, sizeof(struct point), ysort);
//	for(i = 0; i < n; i++)
//	{
//		cout << li[i].x << " " << li[i].y << " " << li[i].z << endl;
//	}
	li[0].y_bk_index = 0;
	li[0].yz_bk_index = 0;
	for(i = 1; i < n; i++)
	{
		if(li[i].y != li[i-1].y)
		{
			y_bk_size++;
			yz_bk_size++;
		}
		else
		{
			y_bk[y_bk_size]++;
			if(li[i].z != li[i-1].z)
			{
				yz_bk_size++;
			}
			else
			{
				yz_bk[yz_bk_size]++;
			}
		}
		li[i].y_bk_index = y_bk_size;
		li[i].yz_bk_index = yz_bk_size;
	} 
//	for(i = 0; i < n; i++)
//	{
//		cout << y_bk[i] << endl;
//	}
//	for(i = 0; i < n; i++)
//	{
//		cout << yz_bk[i] << endl;
//	}
	qsort((void *)li, n, sizeof(struct point), zsort);
//	for(i = 0; i < n; i++)
//	{
//		cout << li[i].x << " " << li[i].y << " " << li[i].z << endl;
//	}
	li[0].z_bk_index = 0;
	li[0].zx_bk_index = 0;
	for(i = 1; i < n; i++)
	{
		if(li[i].z != li[i-1].z)
		{
			z_bk_size++;
			zx_bk_size++;
		}
		else
		{
			z_bk[z_bk_size]++;
			if(li[i].x != li[i-1].x)
			{
				zx_bk_size++;
			}
			else
			{
				zx_bk[zx_bk_size]++;
			}
		}
		li[i].z_bk_index = z_bk_size;
		li[i].zx_bk_index = zx_bk_size;
	} 
//	for(i = 0; i < n; i++)
//	{
//		cout << z_bk[i] << endl;
//	}
//	for(i = 0; i < n; i++)
//	{
//		cout << zx_bk[i] << endl;
//	}
	qsort((void *)li, n, sizeof(struct point), psort);
//	for(i = 0; i < n; i++)
//	{
//		cout << li[i].x << " " << li[i].y << " " << li[i].z << endl;
//	}
	for(i = 0; i < n; i++)
	{
		cout << (n-1)-(x_bk[li[i].x_bk_index])-(y_bk[li[i].y_bk_index])-(z_bk[li[i].z_bk_index])+(xy_bk[li[i].xy_bk_index])+(yz_bk[li[i].yz_bk_index])+(zx_bk[li[i].zx_bk_index])-(xyz_bk[li[i].xyz_bk_index]) << "\n";
    }
	
	return 0;
}
