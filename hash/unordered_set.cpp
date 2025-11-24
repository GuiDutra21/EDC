#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // Tipos de construtores

    unordered_set<int> us1; // Conjunto de inteiros vazio

    string s{"Teste"};
    unordered_set<char> us2(s.begin() + 1, s.end()); // us2 = { 'e', 's', 't' } (sem ordem)

    unordered_set<char> us3(us2); // us3 == us2

    unordered_set<char> us4(move(us3)); // us4 == us2, us3 vazio

    unordered_set<double> us5{2.0, 1.5, 3.7}; // us5 = { elementos sem ordem garantida }

    return 0;
}
/*

Resumo do unordered_set:

insert(valor) - Insere um elemento. Não permite duplicados. O(1) médio, O(n) pior caso

erase(valor) / erase(it) - Remove um elemento pelo valor ou pelo iterador. O(1) médio, O(n) pior caso

find(valor) - Retorna um iterador para o elemento igual a valor (ou end() se não existir). O(1) médio, O(n) pior caso

count(valor) - Retorna 1 se o elemento existe, 0 se não. O(1) médio, O(n) pior caso

size() - Retorna o número de elementos. O(1)

empty() - Retorna true se o unordered_set está vazio. O(1)

clear() - Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do unordered_set (ordem não garantida).

emplace(args...) - Insere elemento construindo direto no unordered_set (mais eficiente para tipos complexos).

bucket_count() - Retorna o número de buckets na tabela hash.

load_factor() - Retorna o fator de carga (size / bucket_count).

max_load_factor() - Retorna ou define o fator de carga máximo antes de rehash.

rehash(n) - Define o número mínimo de buckets.

reserve(n) - Reserva espaço para pelo menos n elementos.

Observações:
- Elementos NÃO são ordenados (usa hash table).
- Não permite elementos repetidos.
- Operações de busca, inserção e remoção são O(1) em média, O(n) no pior caso.
- Não suporta lower_bound() ou upper_bound() (não há ordem).
- Mais rápido que set para operações básicas.
- Usa mais memória que set.

Dica:
Para iterar (ordem não garantida):
for (auto x : us) cout << x << " ";

Diferença principal do set:
- unordered_set: hash table, O(1) médio, SEM ordem
- set: árvore balanceada, O(log n), COM ordem

*/