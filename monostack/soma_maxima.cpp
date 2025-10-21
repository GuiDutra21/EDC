#include <vector>
using namespace std;

using ll = long long;

// pge usando programacao dinamica
auto pge(const vector<ll> &as)
{
    auto N = (int)as.size();
    vector<ll> dp(N, -1);

    for (int i = 1; i < N; ++i)
    {
        ll j = i - 1;

        while (j >= 0 and as[j] <= as[i]) // Se o elemento anterior for menor que o atual
            j = dp[j];                    // Pulamos para o maior a esqueda dele

        dp[i] = j; // Armazena ou o maior ou uma posicao invalida
    }

    return dp;
}

// ngee(next greater or equal element) usando programacao dinamica
auto ngee(const vector<ll> &as)
{
    auto N = (int)as.size();
    vector<ll> dp(N, N);

    for (int i = N - 2; i >= 0; --i)
    {
        ll j = i + 1;

        while (j < N and as[j] < as[i]) // Se o elemento posterior for menor que o atual
            j = dp[j];                   // Pulamos para o maior a direita dele

        dp[i] = j; // Armazena ou o maior ou uma posicao invalida
    }
    return dp;
}

auto sum_of_subarray_maximums(const vector<ll> &as)
{
    auto N = (int)as.size();
    auto L = pge(as), R = ngee(as);
    ll sum = 0;

    for (int i = 0; i < N; ++i)
        sum += as[i] * (i - L[i]) * (R[i] - i);
    return sum;
}