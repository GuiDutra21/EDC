#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    string s;
    cin >> n >> x >> s;

    string simplified;
    for (char c : s) {
        if (c == 'U' && !simplified.empty() && (simplified.back() == 'L' || simplified.back() == 'R')) {
            simplified.pop_back();
        } else {
            simplified.push_back(c);
        }
    }

    
    for (char c : simplified) {
        if (c == 'U') x /= 2;
        else if (c == 'L') x *= 2;
        else x = x * 2 + 1;
    }

    cout << x << "\n";
    return 0;
}
