#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BITree
{
private:
    size_t N;
    vector<T> ts;

public:
    BITree(size_t n) : N(n), ts(n + 1, 0) {}

    const vector<T> &get_tree() const { return ts; }

    T RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    void add(size_t i, T x)
    {
        if (x == 0 || i == 0)
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

template <typename T>
long long count_inversions(const vector<T> &as)
{
    T M = *max_element(as.begin(), as.end());

    BITree<long long> ft(M);

    long long inversions = 0;

    for (size_t i = 0; i < as.size(); ++i)
    {
        // Quantos elementos maiores já apareceram ?
        inversions += ft.RSQ(as[i] + 1, M);

        // Marca "apareceu um as[i]"
        ft.add(as[i], 1);
    }

    // cout << "Fenwick Tree final: ";
    // const auto &t = ft.get_tree();
    // for (size_t i = 1; i < t.size(); i++)
    //     cout << t[i] << " ";
    // cout << "\n";

    return inversions;
}

template <typename T>
long long count_inversions_compression(const vector<T> &as)
{
    set<T> xs(as.begin(), as.end());
    map<T, int> f;
    size_t N = 0;

    for (const auto &x : xs)
        f[x] = ++N;

    BITree<T> ft(N);
    long long inversions = 0;

    for (const auto &a : as)
    {
        inversions += ft.RSQ(f[a] + 1, N);
        ft.add(f[a], 1);
    }

    return inversions;
}

int main()
{
    // vector<int> v1 = {3, 3, 1, 2};
    vector<int> v1 = {1, 6, 8, 3, 2, 5};
    cout << "Array: 3 1 2\n";
    cout << "Inversoes = " << count_inversions(v1) << "\n\n";
    cout << "Inversoes = " << count_inversions_compression(v1) << "\n\n";

    vector<int> v2 = {5, 3, 2, 4, 1};
    cout << "Array: 5 3 2 4 1\n";
    cout << "Inversoes = " << count_inversions(v2) << "\n\n";
    cout << "Inversoes = " << count_inversions_compression(v2) << "\n\n";

    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << "Array: 1 2 3 4 5\n";
    cout << "Inversoes = " << count_inversions(v3) << "\n\n";

    vector<int> v4 = {5, 4, 5, 3, 2, 1};
    cout << "Array: 5 4 3 2 1\n";
    cout << "Inversoes = " << count_inversions(v4) << "\n\n";
    cout << "Inversoes = " << count_inversions_compression(v4) << "\n\n";

    return 0;
}
