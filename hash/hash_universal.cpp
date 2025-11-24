// Hash Universal
#include <bits/stdc++.h>

using namespace std;

template <typename I, size_t T>
class HashSet
{
private:
    size_t mod(const I &a, int b)
    {
        auto r = a % b;
        return r < 0 ? r + b : r;
    }

    size_t h(const I &K) { return mod(a * K + b, p); }
    size_t N(const I &K, size_t i) { return mod(h(K) + i, T); }

    vector<I> xs;
    I p, a, b; // P deve ser primo e deve ser maior que T
    bitset<T> used;

public:
    HashSet(const I &pv) : xs(T), p(pv), a(rand() % (p - 1) + 1), b(rand() % p) {}

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