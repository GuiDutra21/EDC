#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> xs{40, 68, 15, 99, 24, 6, 51, 77};

    priority_queue<int, vector<int>, greater<int>> q(xs.begin(), xs.end()); // Heap de minimo

    while (not q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }

    cout << '\n'; // 6 15 24 40 51 68 77 99

    return 0;
}

int main()
{
    vector<int> xs{40, 68, 15, 99, 24, 6, 51, 77};

    priority_queue<int> p; // Por padrao eh uma heap de maximo

    for (auto x : xs)
        p.push(x);

    while (not p.empty())
    {
        cout << p.top() << ' ';
        p.pop();
    }

    cout << '\n'; // 99 77 68 51 40 24 15 6
}

/*
Resumo da priority_queue:

push(valor) - Insere um elemento na fila de prioridade.

pop() - Remove o elemento do topo (maior ou menor, dependendo do comparador).

top()- Retorna o elemento do topo (maior ou menor).

size() - Retorna o número de elementos.

empty() - Retorna true se a fila está vazia.

Construtores

priority_queue<T>: heap de máximo (maior elemento no topo).
priority_queue<T, vector<T>, greater<T>>: heap de mínimo (menor elemento no topo).

Observações
Não permite acesso direto aos outros elementos, só ao topo.
Não permite remoção de elementos arbitrários, só do topo.
Operações de inserção e remoção são O(log n).
Útil para algoritmos que precisam sempre do maior (ou menor) elemento rapidamente.

*/