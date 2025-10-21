#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int w,h;
    cin >> h >> w;
    int salvei = 0;
    pair<int, int> c1;
    pair<int, int > c2;

    char c;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> c;
            if(c == 'o')
            {
                // cout << i;
                if(!salvei)
                {
                    c1.first = i;
                    c1.second = j;
                    salvei = 1;
                }
                else
                {
                    c2.first = i;
                    c2.second = j;
                }
            }
        }
    }

    // cout << "c1:" << c1.first << c1.second << "\n";
    // cout << "c2:" << c2.first << c2.second << "\n";
    int result = 0;

    result += abs(c1.first - c2.first) + abs(c1.second - c2.second);
    cout << result << "\n";

    return 0;
}
