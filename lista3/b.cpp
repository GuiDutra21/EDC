#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    stack<char> st;

    cin >> n;
    getline(cin >> ws, s);
    
    string antes;
    string depois;

    for(auto c: s)
    {   

        if (c == ')' and st.empty())
        {
            antes += '(';
        }
        else if (c == ')' and st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    for(int i = st.size(); i > 0; --i)
    {
        depois += ')';
    }

    s += depois;
    s = antes + s;
    cout << s << "\n";

    return 0;
}