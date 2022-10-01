
#include <bits/stdc++.h>

using namespace std;

struct p4
{
	long int one;
	long int two;
	long int three;
	long int four;
    p4(){}
    p4(long int cin_one, long int cin_two, long int cin_three, long int cin_four){
        one = cin_one;
        two = cin_two;
        three = cin_three;
        four = cin_four;
    }
};

struct pairs
{
    long int fir;
    long int sec;
    long int sum;
    pairs(){}
    pairs(long int cin_fir,long int cin_sec,long int cin_sum){
        fir = cin_fir;
        sec = cin_sec;
        sum = cin_sum;
    }
};

int compare_p4(const void *ptr_a , const void *ptr_b)
{
	p4 a = *(p4 *)ptr_a;
    p4 b = *(p4 *)ptr_b;
	if(a.one < b.one)
	{
		return -1;
	}
    else if(a.one == b.one)
	{
		if(a.two < b.two)
		{
			return -1;
		}
    	else if(a.two == b.two)
		{
			if(a.three < b.three)
			{
				return -1;
			}
    		else if(a.three == b.three)
			{
				if(a.four < b.four)
				{
					return -1;
				}
    			else if(a.four == b.four)
				{
					return 0;
				}
    			return 1;
			}
    		return 1;
		}
    	return 1;
	}
    return 1;
}

int compare(const void *ptr_a, const void *ptr_b)
{
	pairs a = *(pairs *)ptr_a;
    pairs b = *(pairs *)ptr_b;
	if(a.sum < b.sum)
	{
		return -1;
	}
    else if(a.sum == b.sum)
	{
		if(a.fir < b.fir)
		{
			return -1;
		}
    	else if(a.fir == b.fir)
		{
			if(a.sec < b.sec)
			{
				return -1;
			}
    		else if(a.sec == b.sec)
			{
				return 0;
			}
    		return 1;
		}
    	return 1;
	}
    return 1;
}

bool nosame(struct pairs a, struct pairs b)
{
    if (a.fir == b.fir || a.fir == b.sec || a.sec == b.fir || a.sec == b.sec)
    {
        return false;
    }
    return true;
}

void findFourElements(long int arr[], int n, long int X)
{
    int i, j;

    int p_size = (n * (n - 1)) / 2;
    struct pairs p[p_size];
    p4 ans[p_size];
    ans[0].one = -1;
    int ap = 0;
    
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            p[k].sum = arr[i] + arr[j];
            p[k].fir = i;
            p[k].sec = j;
            k++;
        }
    }

    qsort(p, p_size, sizeof(p[0]), compare);
 
    i = 0;
    j = p_size - 1;
    int in, jn;
    while (i < j) {
        if ((p[i].sum + p[j].sum == X) && nosame(p[i], p[j])){
        	if(p[i].sum != p[j].sum)
        	{
        		in = i;
        		jn = j;
				while(p[in+1].sum == p[i].sum)
        		{
        			in++;
				}
				while(p[jn-1].sum == p[j].sum)
        		{
        			jn--;
				}
				for(int ii = i; ii <= in; ii++)
				{
					for(int jj = j; jj >= jn; jj--)
					{
						if(nosame(p[ii], p[jj]))
						{
							ans[ap].one = p[ii].fir;
							ans[ap].two = p[ii].sec;
							ans[ap].three = p[jj].fir;
							ans[ap].four = p[jj].sec;
							ap++;
						}
					}
				}
				i = in + 1;
				j = jn - 1;
			}
			else
			{
				in = i + 1;
				while(in <= j)
				{
					if((p[i].sum + p[in].sum == X) && nosame(p[i], p[in]))
					{
						ans[ap].one = p[i].fir;
						ans[ap].two = p[i].sec;
						ans[ap].three = p[in].fir;
						ans[ap].four = p[in].sec;
						ap++;
					}
					in++;
				}
				i = j; //jump out while
			}
        }
        else if (p[i].sum + p[j].sum < X)
        {
        	i++;
		}
        else
        {
        	j--;
		}
    }
    
    if(ans[0].one != -1)
    {
    	for(i = 0; i < ap; i++)
    	{
    		if(ans[i].one > ans[i].two)
    		{
    			swap(ans[i].one, ans[i].two);
			}
			if(ans[i].one > ans[i].three)
    		{
    			swap(ans[i].one, ans[i].three);
			}
			if(ans[i].one > ans[i].four)
    		{
    			swap(ans[i].one, ans[i].four);
			}
			if(ans[i].two > ans[i].three)
    		{
    			swap(ans[i].two, ans[i].three);
			}
			if(ans[i].two > ans[i].four)
    		{
    			swap(ans[i].two, ans[i].four);
			}
			if(ans[i].three > ans[i].four)
    		{
    			swap(ans[i].three, ans[i].four);
			}
		}
		qsort(ans, ap-1, sizeof(ans[0]), compare_p4);
    	cout << ans[0].one << " " << ans[0].two << " " << ans[0].three << " " << ans[0].four << endl;
	}
	else
	{
		cout << "-1" << endl; 
	}
    //cout << p[i].fir << " " << p[i].sec << " " << p[j].fir << " " << p[j].sec << endl;
    //cout << "-1" << endl;
}

int main()
{
    int n;
    long int s;
	cin >> n;
	long int a[n];
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
    
    findFourElements(a, n, s);
    return 0;
}
 
