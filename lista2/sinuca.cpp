#include <iostream>

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

    while (n > 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            vet[i] = vet[i] * vet[i + 1];
        }
        n--;
    }

    cout << (vet[0] == -1 ? "branca\n" : "preta\n");
    return 0;
}