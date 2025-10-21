#include <iostream>

using namespace std;
int main()
{   
    ios::sync_with_stdio(false);
    char result;
    int  acc = 0;
    for(int i = 0; i < 6; i++)
    {
        cin >> result;
        if(result == 'V')
        {
            acc++;
        }
    }

    if(acc > 4)
    {
        cout << "1\n";
    }
    else if(acc > 2)
    {
        cout << "2\n";
    }
    else if(acc > 0)
    {
        cout << "3\n";
    }
    else
        cout << "-1\n";

    return 0;
}