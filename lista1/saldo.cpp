#include <iostream>

using namespace std;

int main()

{
    ios::sync_with_stdio(false);
    int n, s, menor = 0, saldo, mov;

    cin >> n >> s;
    menor = s;
    saldo = s;

    for(int i = 0; i < n; i++)
    {
        cin >> mov;
        saldo += mov;
        if(saldo < menor)
            menor = saldo;
    }

    cout << menor << "\n";
    
    return 0;
}