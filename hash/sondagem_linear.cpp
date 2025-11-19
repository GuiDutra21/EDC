#include <bits/stdc++.h>

using namespace std;

template <typename I, size_t T>
class HashSet
{
private:
    size_t mod(const I &a, int b) { return ((a % b) + b) % b; }
    size_t h(const I &K) { return mod(K, T); }
    size_t N(const I &K, size_t i) { return mod(h(K) + i, T); }

    vector<I> xs;
    bitset<T> used;

public:
    HashSet() : xs(T) {}
    bool insert(const I &K)
    {
        if (used.count() == T)
            return false;

        for (size_t i = 0; i < T; ++i)
        {
            auto pos = N(K, i);

            if (not used[pos])
            {
                xs[pos] = K;
                used[pos] = true;
                break;
            }
        }

        return true;
    }
};
