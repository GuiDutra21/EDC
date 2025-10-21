// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     multiset<int> ms;

//     int n;
//     cin >> n;
//     int q;
//     int x;
//     int c;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> q;
//         if (q == 1)
//         {
//             cin >> x;
//             ms.insert(x);
//         }
//         else if (q == 2)
//         {
//             cin >> x;
//             cin >> c;
//             auto lb = ms.lower_bound(x);
//             auto ub = ms.upper_bound(x);
//             int number = distance(lb, ub);
//             int menor = min(c, number);
//             auto range = ms.equal_range(x);
//             int removed = 0;
//             for (auto it = lb; it != ub && removed < menor; ++removed)
//                 ms.erase(it++);
//         }
//         else
//         {
//             int menor = *ms.begin();
//             int maior = *--ms.end();
//             cout << (maior - menor) << "\n";
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, long long> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        else if (q == 2)
        {
            int x, c;
            cin >> x >> c;
            auto it = mp.find(x);
            if (it != mp.end())
            {
                int number = it->second;
                int m = min(c, number);
                it->second -= m;
                if (it->second == 0)
                {
                    mp.erase(it);
                }
            }
        }

        else
        {
            int menor = mp.begin()->first;
            int maior = mp.rbegin()->first;
            cout << (maior - menor) << "\n";
        }
    }
    return 0;
}
