#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

bool isValid(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '(')
            st.push(c);
        else
        {
            if (st.empty())
                return false;

            st.pop();
        }
    }

    return (st.empty());
}  

int main()
{
    ios::sync_with_stdio(false);
    vector<string> entradas;
    vector<string> validas;
    vector<string> invalidas;

    int n;

    cin >> n;
    cin.ignore();
    REP( i, 0, n)
    {
        string str;
        getline(cin, str);
        entradas.emplace_back(str);
    }

    for (auto s : entradas)
    {
        if (isValid(s))
        {
            validas.emplace_back(s);
        }
        else
        {
            invalidas.emplace_back(s);
        }
    }

    
    int result = 0;
    int size =  invalidas.size();
    REP(i, 0, size)
    {
        REP(j, 0, size)
        {
            if(i == j)
                continue;
            if(isValid(invalidas[i] + invalidas[j]))
                result++;
        }
    }

    int size2 = validas.size();
    result += size2*(size2-1) + size2;
    cout << result << "\n";

    return 0;
}