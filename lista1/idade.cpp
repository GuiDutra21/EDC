#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    vector<int> idades(3);
    for (int &idade : idades)
    {
        cin >> idade;
    }

    sort(idades.begin(), idades.end());

    cout << idades[1] << "\n";
    
    return 0;
}