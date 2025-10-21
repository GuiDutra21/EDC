#include <iostream>
#include <set>

#define REP(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;

int main()
{
    set<int> aposta, sorteio;
    int x;

    REP (i, 0, 5)
    {
        cin >> x;
        aposta.insert(x);
    }

    REP (i, 0, 5)
    {
        cin >> x;
        sorteio.insert(x);
    }

    int acertos = 0;
    for (int i : aposta)
    {
        if (sorteio.count(i))
            acertos++;
    }

    if (acertos == 6)
        cout << "sena\n";

    else if (acertos == 5)
        cout << "quina\n";

    else if (acertos == 4)
        cout << "quadra\n";

    else if (acertos == 3)
        cout << "terno\n";

    else
        cout << "azar\n";

    return 0;
}