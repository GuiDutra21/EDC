#include <bits/stdc++.h>
using namespace std;

tuple<int,int,long long> factor23_and_core(long long x) {
    int c2 = 0, c3 = 0;
    while (x % 2 == 0) { x /= 2; c2++; }
    while (x % 3 == 0) { x /= 3; c3++; }
    return {c2, c3, x}; // x é o core
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if(!(cin >> n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> c2(n), c3(n);
    vector<long long> core(n);
    for (int i=0;i<n;i++) {
        auto [x2, x3, cr] = factor23_and_core(a[i]);
        c2[i] = x2; c3[i] = x3; core[i] = cr;
    }

    for (int i=1;i<n;i++) {
        if (core[i] != core[0]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    int min2 = *min_element(c2.begin(), c2.end());
    int min3 = *min_element(c3.begin(), c3.end());
    long long ans = 0;
    for (int i=0;i<n;i++) ans += (c2[i] - min2) + (c3[i] - min3);
    cout << ans << "\n";
    return 0;
}
