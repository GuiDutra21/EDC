#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int vet[n];
    int left = 1, right = n-2;
    bool igual = true;

    for(int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    int referencia = vet[0] + vet[n-1];
    while (left <= right)
    {
        if(vet[left] + vet[right] != referencia)
        {
            igual = false;
            break;
        }

        left++;
        right--;
    }
    
    if(igual)
        cout << "S\n";
    else
        cout << "N\n";
    
    return 0;
}