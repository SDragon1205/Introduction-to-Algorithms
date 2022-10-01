#include <bits/stdc++.h>
using namespace std;

int twoSum(vector<int> &a, int target) {
    int ans = 0;
    map<int,int> hash;
    for(int i = 0; i < a.size(); i++)
    {
    	if(hash[target - a[i]] && hash[target - a[i]] != i)
    	{
    		ans++;
		}
		else
		{
			hash[a[i]] = i;
		}
	}
	return ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int x = 0; x < n; x++) {
        cin >> a[x];
    }
    cout << twoSum(a, target) << '\n';
}
