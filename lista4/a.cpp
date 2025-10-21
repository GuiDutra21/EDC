#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    int value = 1;
    for(int i = 0; i < n; i++)
    {
        value = value + k < value * 2 ? value + k :  value * 2;
    }

    cout << value << "\n";

    return 0;
}