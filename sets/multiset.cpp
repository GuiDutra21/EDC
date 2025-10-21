
#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> ms{1, 2, 2, 2, 3};
    auto n = ms.count(2); // n = 3
    auto it = ms.find(2);

    ms.erase(it);    // ms = { 1, 2, 2, 3 }
    n = ms.count(2); // n = 2
    ms.erase(2);
    ms.count(2); // n = 0

    ms.insert({2, 2, 2, 2});
    auto [a, b] = ms.equal_range(2);

    for (auto i = a; i != b; ++i)
        cout << *i << '\n'; // 2 2 2 2

    return 0;
}

/*
Resumo do multiset:

insert(valor) - Insere um elemento. Permite elementos repetidos.

erase(valor) / erase(it) - Remove todos os elementos iguais a valor ou apenas o elemento apontado pelo iterador.

find(valor) - Retorna um iterador para um elemento igual ao valor (ou end() se não existir).

count(valor) - Retorna quantas vezes valor aparece no multiset.

size() - Retorna o número de elementos. O(1)

empty() - Retorna true se o multiset está vazio. O(1)

clear() - Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do multiset.

lower_bound(valor) - Iterador para o primeiro elemento ≥ valor.

upper_bound(valor) - Iterador para o primeiro elemento > valor.

equal_range(valor) - Retorna um par de iteradores para o intervalo de todos os elementos iguais a valor.

emplace(args...) - Insere elemento construindo direto no multiset (mais eficiente para tipos complexos).

Observações
Elementos são sempre ordenados.
Permite elementos repetidos.
Operações de busca, inserção e remoção são O(log n).

Dica:
Para acessar o menor elemento: *ms.begin()
Para acessar o maior elemento: *prev(ms.end()) ou *--ms.end()

*/