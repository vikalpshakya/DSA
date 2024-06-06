/*
Time complexity: O(nlogn)
Space complexity: O(n) 
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    int prefix[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] = arr[i];
        if (i)
            prefix[i] += prefix[i - 1];
    }
    long long ans = 0;
    map<int, int> mp;
    mp[0]++;
    for (int r = 0; r < n; r++)
    {
        ans += mp[pre[r] - x];
        mp[pre[r]]++;
    }
    cout << ans << endl;
}


// -------IF ASKED TO PRINT THOSE SUBARAYS ALSO ------// 


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    int prefix[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] = arr[i];
        if (i)
            prefix[i] += prefix[i - 1];
    }
    long long ans = 0;
    map<int, vector<int>> mp;
    mp[0].push_back(0);
    for (int r = 0; r < n; r++)
    {
        for (auto l : mp[prefix[r] - x])
        {
            cout << l << ":" << r << endl;
        }
        mp[prefix[r]].push_back(r + 1);
    }
    cout << ans << endl;
}
