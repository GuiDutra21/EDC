#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, x,p,l;

    cin >> n;
    int chinelos[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        chinelos[i] = x; 
    }

    int qtdVendas = 0;
    cin >> p;

    for(int i = 0; i < p; ++i)
    {
        cin >> l;
        if(chinelos[l - 1] > 0)
        {
            qtdVendas++;
            chinelos[l - 1]--;
        }
    }   

    cout << qtdVendas << "\n";
    
    return 0;
}