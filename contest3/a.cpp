#include <iostream>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int idx = -1;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if(s[i] == 'a')
        {
            idx = i + 1;
            break;
        }
    }
    cout << idx << '\n';
    return 0;
}