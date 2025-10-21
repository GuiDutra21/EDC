#include <iostream>
#include <stack>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    char x;
    cin >> n;
    stack<char> st;

    while(n > 0)
    {
        cin >> x;
        if(st.empty() or (st.top() - '0' + x - '0' != 1))
        {   
            st.push(x);
        }
        else
        {
            st.pop();
        }
        n--;
    }
    cout << st.size() << "\n";

    return 0;
}