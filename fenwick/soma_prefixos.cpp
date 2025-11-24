#include <vector>
using namespace std;

// Os elementos as tem ındices de 1 a N
template <typename T>
vector<T> prefix_sum(const vector<T> &as, int N)
{
    vector<T> ps(N + 1, 0);

    for (size_t i = 1; i <= N; ++i)
        ps[i] = ps[i - 1] + as[i];

    return ps;
}

template <typename T>
T RSQ(const vector<T> &ps, int i, int j)
{
    return ps[j] - ps[i - 1];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

// Nessa implementacao os ́ındices do vetor as vao de 0 a N - 1
template <typename T>
vector<T> prefix_sum(const vector<T> &as)
{
    vector<T> ps(as.size() + 1, 0);

    partial_sum(as.begin(), as.end(), ps.begin() + 1);

    return ps;
}

template <typename T>
T RSQ(const vector<T> &ps, int i, int j)
{
    return ps[j] - ps[i - 1];
}
