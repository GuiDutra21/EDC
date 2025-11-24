#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BITree
{
private:
    vector<T> ts;
    size_t N;

public:
    BITree(const vector<T>& arr) : N(arr.size())
    {
        ts.assign(N + 1, 0);

        for (size_t i = 1; i <= N; i++)
            add(i, arr[i - 1]);  // arr é 0-based
    }

    T RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }
    
    void add(size_t i, const T& x)
    {
        if(x == 0)
            return;
        
        while (i <= N)
        {   
            ts[i] += x;
            i += LSB(i);
        }
    }

private:
    int LSB(int n) { return n & (-n); }

    T RSQ(int i)
    {
        T sum = 0;

        while (i >= 1)
        {   
            sum += ts[i];
            i -= LSB(i);
        }
        
        return sum;
    }

};

int main()
{
    vector<int> arr = {2,0,1,3,-1,5,-2,4};

    BITree<int> fen(arr);

    cout << fen.RSQ(3,7) << "\n"; // soma de 3 a 7

    return 0;
}
