#include <iostream>
#include <bits/stdc++.h>
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v1;

    int x;
    REP(i, 0, n)
    {
        cin >> x;
        v1.push_back(x);
    }

    prev_permutation(v1.begin(), v1.end());

    for (auto val : v1)
        cout << val << " ";
    cout << "\n";
    return 0;
}