
#include <iostream>

using namespace std;

#define max 1000000

int mmax(int a, int b)
{
	return (a > b) ? a : b;
}

int test(int a[], int n, int t)
{
	//cout << "n: " << n << endl;
	int j = 1;
	if(a[0] > n)
	{
		return 0;
	}
	int x = a[0];
	for(int i = 1; i < t; i++)
	{
		if(a[i] > n)
		{
			return 0;
		}
		else
		{
			x += a[i] + 1;
			//cout << "a[ " << i << "]: " << a[i] << endl; 
			//cout << "x: " << x << endl; 
			//cout << "\n";
			if(x > n)
			{
				x = a[i];
				j++;
				//cout << "j: " << j << endl;
				//cout << "x: " << x << endl; 
				//cout << "\n";
				if(j > 24)
				{
					return 0;
				}
			}
		}
		
	}
	
	return 1;
}

int help(int a[], int s, int b, int t)
{
	if(s == b)
	{
		return s;
	}
	else if(test(a, (s+b)/2, t))
	{
		//cout << "up: " << (s+b)/2 << endl;
		return help(a, s, (s+b)/2, t);
	}
	else
	{
		//cout << "down: " << ((s+b)/2)+1 << endl;
		return help(a, ((s+b)/2)+1, b, t);
	}
}

int main()
{
    int t, i;
    int ans = 0;
    cin >> t;

    int a[t];
    string str;
    for(i = 0; i < t; i++)
    {
        cin >> str;
        a[i] = str.length();
        //cout << a[i] << endl;
    }

    if(t <= 24)
    {
    	for(i = 0; i < t; i++)
    	{
    		ans = mmax(ans, a[i]);
		}
    }
    else
    {
    	ans = help(a, 0, max, t);
	}
	
	cout << ans << endl;
    
    return 0;
}
