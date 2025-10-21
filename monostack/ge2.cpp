#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <iomanip>
using namespace std;

// Implementação do maior elemento à esquerda e à direita
// Possivel apenas se os elementos da sequencia sejam todos distintos
auto ge(const vector<int> &as)
{
    auto N = (int)as.size();
    vector<int> pge(N, -1), nge(N, N);
    stack<int> st;
    for (int i = 0; i < N; ++i)
    {

        while (not st.empty() and as[st.top()] <= as[i]) // Pilha não-crescente
        {
            nge[st.top()] = i; // O atual é o próximo maior à direita do topo
            st.pop();          // Remove o menor, porque já achou seu "próximo maior"
        }

        if (not st.empty())
            pge[i] = st.top(); // Se ainda sobrou algo na pilha, o topo da pilha é o maior à esquerda

        st.emplace(i); // Empilha o índice atual
    }
    return make_pair(pge, nge);
}

// pge usando programacao dinamica
auto pge_dp(const vector<int> &as)
{
    auto N = (int)as.size();
    vector<int> dp(N, -1);

    for (int i = 1; i < N; ++i)
    {
        auto j = i - 1;

        while (j >= 0 and as[j] <= as[i]) // Se o elemento anterior for menor que o atual
            j = dp[j];                    // Pulamos para o maior a esqueda dele

        dp[i] = j; // Armazena ou o maior ou uma posicao invalida
    }

    return dp;
}

// nge usando programacao dinamica
auto nge_dp(const vector<int> &as)
{
    auto N = (int)as.size();
    vector<int> dp(N, N);

    for (int i = N - 2; i >= 0; --i)
    {
        auto j = i + 1;

        while (j < N and as[j] <= as[i]) // Se o elemento posterior for menor que o atual
            j = dp[j];                   // Pulamos para o maior a direita dele

        dp[i] = j; // Armazena ou o maior ou uma posicao invalida
    }
    return dp;
}

int main()
{
    vector<int> as{2, 1, 4, 3};
    auto is = ge(as);

    cout << "i:  ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << i << (i + 1 == as.size() ? '\n' : ' ');

    cout << "as: ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "pge:";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << is.first[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "nge:";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << is.second[i] << (i + 1 == as.size() ? '\n' : ' ');

    // Apenas limpa o vetor antigo e chama as outras funcoes de programcao dinamica
    is.first.clear();
    is.second.clear();

    is.first = pge_dp(as);
    is.second = nge_dp(as);

    cout << "pge_dp:";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << is.first[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "nge_dp:";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << is.second[i] << (i + 1 == as.size() ? '\n' : ' ');
}