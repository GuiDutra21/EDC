#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);

    int n,p;

    cin >> n;
    cin >> p;

    int raiz = log(n) / log(p);

    cout << raiz << "\n";

    return 0;
}