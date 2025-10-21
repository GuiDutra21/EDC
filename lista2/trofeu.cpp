#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> vet;
    int i;

    while (cin >> i)
    {
        vet.push_back(i);
    }

    int qtdTrofeu = 0;
    int qtdPlaca = 0;
    int primeiro = vet[0];
    int segundo = -1;
    for (auto i : vet)
    {
        if (i == primeiro)
            qtdTrofeu++;
        else if (segundo == -1)
        {
            segundo = i;
            qtdPlaca++;
        }
        else if (i == segundo)
            qtdPlaca++;
    }

    cout << qtdTrofeu << " " << qtdPlaca << "\n";
    return 0;
}