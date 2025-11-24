#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

template <typename T>
class BITree
{
public:
    //  ́E preciso adicionar um elemento sentinela na  ́ultima posic ̧ ̃ao para evitar o
    // erro 'off-by-one'na implementac ̧ ̃ao de range_add()
    BITree(size_t n) : ts(n + 2, 0), N(n) {}

    ll value_at(int i) { return RSQ(i); }

    void range_add(size_t i, size_t j, ll x)
    {
        add(i, x);
        add(j + 1, -x);
    }

    // Método auxiliar para imprimir o array
    void print_array(int n)
    {
        cout << "Array: [";
        for (int i = 1; i <= n; i++)
        {
            cout << value_at(i);
            if (i < n) cout << ", ";
        }
        cout << "]\n";
    }

private:
    vector<T> ts;
    size_t N;

    int LSB(int n) { return n & (-n); }
    ll RSQ(int i)
    {
        ll sum = 0;

        while (i >= 1)
        {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

    void add(size_t i, ll x)
    {
        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;  // Tamanho do array
    BITree<ll> fen(n);

    cout << "=== Fenwick Tree - Range Add, Point Query ===\n\n";

    // Array inicial (todos zeros)
    cout << "Array inicial:\n";
    fen.print_array(n);
    cout << "\n";

    // Operação 1: adicionar 5 ao intervalo [2, 5]
    cout << "Operação: range_add(2, 5, 5)\n";
    cout << "Adiciona 5 a todos os elementos do índice 2 ao 5\n";
    fen.range_add(2, 5, 5);
    fen.print_array(n);
    cout << "\n";

    // Operação 2: adicionar 3 ao intervalo [4, 8]
    cout << "Operação: range_add(4, 8, 3)\n";
    cout << "Adiciona 3 a todos os elementos do índice 4 ao 8\n";
    fen.range_add(4, 8, 3);
    fen.print_array(n);
    cout << "\n";

    // Operação 3: adicionar -2 ao intervalo [1, 3]
    cout << "Operação: range_add(1, 3, -2)\n";
    cout << "Subtrai 2 de todos os elementos do índice 1 ao 3\n";
    fen.range_add(1, 3, -2);
    fen.print_array(n);
    cout << "\n";

    // Consultas individuais
    cout << "=== Consultas Individuais ===\n";
    cout << "value_at(1) = " << fen.value_at(1) << "\n";
    cout << "value_at(3) = " << fen.value_at(3) << "\n";
    cout << "value_at(5) = " << fen.value_at(5) << "\n";
    cout << "value_at(7) = " << fen.value_at(7) << "\n";
    cout << "value_at(10) = " << fen.value_at(10) << "\n";
    cout << "\n";

    // Exemplo interativo
    cout << "=== Exemplo Interativo ===\n";
    cout << "Testando mais operações:\n\n";
    
    BITree<ll> fen2(5);
    
    cout << "Array inicial: ";
    fen2.print_array(5);
    
    fen2.range_add(1, 5, 10);
    cout << "Após range_add(1, 5, 10): ";
    fen2.print_array(5);
    
    fen2.range_add(2, 4, -3);
    cout << "Após range_add(2, 4, -3): ";
    fen2.print_array(5);
    
    fen2.range_add(3, 3, 7);
    cout << "Após range_add(3, 3, 7): ";
    fen2.print_array(5);

    return 0;
}