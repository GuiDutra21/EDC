#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
using namespace std;

template <typename T>
class MonoStack
{
public:
    MonoStack(int start_idx = 0, int inc = 1) : pos(start_idx), invalid(start_idx - inc), inc(inc) {}
    int push(const T &x)
    {
        while (not st.empty() and st.top().second <= x) // Pilha não-crescente
            st.pop();

        auto i = st.empty() ? invalid : st.top().first;
        st.emplace(pos, x);
        pos += inc;

        return i;
    }

    void pop() { st.top(); };
    auto top() const { return st.top(); }
    bool empty() const { return st.empty(); }

private:
    stack<pair<int, T>> st;
    int pos, invalid, inc;
};

// pge = previous greater element
auto pge(const vector<int> &xs)
{
    MonoStack<int> ms;
    vector<int> ans;

    for (auto x : xs)
        ans.emplace_back(ms.push(x));

    return ans;
}

// nge = next greater element
// Faz o mesmo que o nge, mas comeca da direita para a esquerda
auto nge(const vector<int> &xs)
{
    MonoStack<int> ms(6,-1);
    vector<int> ans;
    auto temp(xs);
    reverse(temp.begin(), temp.end());

    for (auto x : temp)
        ans.insert(ans.begin(), ms.push(x));

    return ans;
}

int main()
{
    vector<int> as{1, 4, 3, 4, 2, 1, 3};
    auto is = pge(as);
    
    cout << "i:  ";
    for (size_t i = 0; i < as.size(); ++i)
    cout << setw(2) << i << (i + 1 == as.size() ? '\n' : ' ');
    
    cout << "as: ";
    for (size_t i = 0; i < as.size(); ++i)
    cout << setw(2) << as[i] << (i + 1 == as.size() ? '\n' : ' ');
    
    cout << "pge:";
    for (size_t i = 0; i < as.size(); ++i)
    cout << setw(2) << is[i] << (i + 1 == as.size() ? '\n' : ' ');
    
    is.clear();
    is = nge(as);

    cout << "nge:";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << is[i] << (i + 1 == as.size() ? '\n' : ' ');
}