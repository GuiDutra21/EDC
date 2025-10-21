#include <iostream>
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n,x;
    cin >> n;
    int ranking[n];

    REP(i, 0, n)
    {
        cin >> x;
        ranking[x-1] = i + 1;
    }

    for(auto i : ranking)
    {
        cout << i << "\n";
    }
    
    return 0;
}