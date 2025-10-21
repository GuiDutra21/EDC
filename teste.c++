#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;
int main()
{
    vector<std::pair<int, int>> vec = {
        {3, 2}, {1, 4}, {3, 1}, {2, 3}, {1, 2}};

    sort(vec.begin(), vec.end());

    for(auto v : vec)
    {
        cout << v.first << " " << v.second << "\n";
    }
    return 0;
}