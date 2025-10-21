#include <iostream>
#define REP(i, a, b) for(int(i) = (a); (i) < (b); (i)++)

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

    int qtdPicos = 0;

    REP(i, 1, n - 1)
    {
        if(vet[i] < vet[i - 1] && vet[i] < vet[ i + 1])
            qtdPicos++; 
    }

    cout << (qtdPicos < 1 ? "N\n" : "S\n");

    return 0;
}