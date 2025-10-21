#include <iostream>
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int vet[n];

    for (auto &i : vet)
    {
        cin >> i;
    }

    if (vet[0] > 8)
    {
        cout << "N\n";
        return 0;
    }

    REP(i, 1, n)
    {
        if (vet[i] - vet[i - 1] > 9)
        {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";

    return 0;
}