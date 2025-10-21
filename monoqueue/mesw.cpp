
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Menores elementos em uma janela movel de tamanho k
auto mesw(int n, int k, const vector<int> &xs)
{
    deque<int> q;

    // Cria uma fila nao-descrescente para a primeira janela
    for (int i = 0; i < k; ++i)
    {
        while (not q.empty() and xs[q.back()] >= xs[i])
            q.pop_back();

        q.emplace_back(i);
    }

    vector<int> ms{xs[q.front()]};

    for (int L = 0, R = k; R < n; ++L, ++R)
    {
        if (q.front() == L)
            q.pop_front();

        while (not q.empty() and xs[q.back()] >= xs[R])
            q.pop_back();

        q.emplace_back(R);
        ms.emplace_back(xs[q.front()]);
    }
    return ms;
}

int main()
{
    int n, k;
    vector<int> xs = {4, 1, 3, 4, 2, 1, 3};
    n = xs.size();
    k = 3;

    auto ms = mesw(n, k, xs);
    for (size_t i = 0; i < ms.size(); ++i)
        cout << ms[i] << (i + 1 == ms.size() ? '\n' : ' ');

    return 0;
}