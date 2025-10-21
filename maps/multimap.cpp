#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    multimap<int, int> ms{{1, 1}, {1, 2}, {1, 2}, {1, 3}, {2, 1}, {2, 2}};

    auto n = ms.count(1); // n = 4
    n = ms.count(2); // n = 2

    // 1: 1, 1: 2, 1: 2, 1: 3, 2: 1, 2: 2
    for (auto [k, v] : ms)
        cout << k << ": " << v << ", ";
    cout << endl;

    // ms[1] = 4; // Erro de compilacao!

    ms.erase(1);

    // 2: 1, 2: 2
    for (auto [k, v] : ms)
        cout << "--- " << k << ": " << v << endl;

    return 0;
}

/*

Resumo de multimap:

insert({chave, valor}) - Insere um par chave-valor. Permite chaves repetidas.

erase(chave) / erase(it) - Remove todos os pares com a chave ou apenas o elemento apontado pelo iterador.

find(chave) - Retorna um iterador para o primeiro elemento com a chave (ou end() se não existir).

count(chave)- Retorna quantos elementos têm a chave.

size()- Retorna o número de elementos.

empty()- Retorna true se o multimap está vazio.

clear()- Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do multimap.

lower_bound(chave) - Iterador para o primeiro elemento ≥ chave.

upper_bound(chave) - Iterador para o primeiro elemento > chave.

equal_range(chave) - Retorna um par de iteradores para o intervalo de todos os elementos com a chave.

emplace(chave, valor) - Insere o par construindo direto no multimap.

Observações
Elementos são ordenados pela chave.
Permite múltiplos valores para a mesma chave.
Não suporta acesso por índice (mm[chave] não funciona).
Operações de busca, inserção e remoção são O(log n).

Dica:
Para percorrer todos os valores de uma chave:
    auto [it1, it2] = mm.equal_range(chave);
    for (auto it = it1; it != it2; ++it)
        cout << it->second << " ";
*/