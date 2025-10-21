// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     int a, b, c;
// //     vector<int> vet;
// //     cin >> a;
// //     vet.emplace_back(a);
// //     cin >> b;
// //     vet.emplace_back(b);
// //     cin >> c;
// //     vet.emplace_back(c);

// //     sort(vet.begin(), vet.end());

// //     if (vet.at(1) == b)
// //         cout << "yes";
// //     else
// //         cout << "no";
// //     return 0;
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     int a, b, c;
//     int maior = 0;
//     int menor = 0;
//     cin >> a;
//     cin >> b;
//     cin >> c;

//     if(b >= a)
//         maior++;
//     else
//         menor++;

//     if( b > c)
//         maior++;
//     else
//         menor++;

//     if(maior == 1 and menor == 1)
//     {
//         cout << "yes\n";
//         return 0;
//     }

//     cout << "no\n";
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    if (v[1] == b)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}