#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;
    int left = p1 * c1;
    int right = p2 * c2;
    if(left < right)
    {
        cout << "1\n";
    }
    else if(left > right)
    {
        cout << "-1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}