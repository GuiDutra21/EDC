#include <iostream>
#include <bits/stdc++.h>
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;
int main()
{   
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> lists(n);
    int a, b;

    REP(i, 0, m)
    {
        cin >> a >> b;
        lists[a - 1].emplace_back(b - 1);
        lists[b - 1].emplace_back(a - 1);
    }
    
    REP(k, 0, n)
    {
        sort(lists[k].begin(), lists[k].end());
        int s = lists[k].size();
        cout << lists[k].size();

        for (int j = 0; j < s; j++)
        {

            cout << " " << lists[k][j] + 1; 
        }
        cout << "\n";
    }

    return 0;
}
