#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // Tipos de construtores

    unordered_map<int, string> um1; // Mapa vazio

    unordered_map<int, string> um2 = {{1, "um"}, {2, "dois"}, {3, "três"}}; // Inicialização com lista

    unordered_map<int, string> um3(um2); // um3 == um2

    unordered_map<int, string> um4(move(um3)); // um4 == um2, um3 vazio

    return 0;
}
/*

Resumo do unordered_map:

insert({chave, valor}) - Insere um par chave-valor. Não insere se a chave já existe. O(1) médio, O(n) pior caso

operator[] (chave) - Acessa ou insere o valor associado à chave. Se a chave não existe, cria com valor padrão. O(1) médio, O(n) pior caso

at(chave) - Acessa o valor associado à chave. Lança exceção se a chave não existe. O(1) médio, O(n) pior caso

erase(chave) / erase(it) - Remove o elemento pela chave ou pelo iterador. O(1) médio, O(n) pior caso

find(chave) - Retorna um iterador para o elemento com a chave (ou end() se não existir). O(1) médio, O(n) pior caso

count(chave) - Retorna 1 se a chave existe, 0 se não. O(1) médio, O(n) pior caso

size() - Retorna o número de elementos. O(1)

empty() - Retorna true se o unordered_map está vazio. O(1)

clear() - Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do unordered_map (ordem não garantida).

emplace(chave, valor) - Insere o par construindo direto no unordered_map (mais eficiente para tipos complexos).

bucket_count() - Retorna o número de buckets na tabela hash.

load_factor() - Retorna o fator de carga (size / bucket_count).

max_load_factor() - Retorna ou define o fator de carga máximo antes de rehash.

rehash(n) - Define o número mínimo de buckets.

reserve(n) - Reserva espaço para pelo menos n elementos.

Observações:
- Elementos NÃO são ordenados pela chave (usa hash table).
- Não permite chaves repetidas.
- Operações de busca, inserção e remoção são O(1) em média, O(n) no pior caso.
- Não suporta lower_bound() ou upper_bound() (não há ordem).
- Mais rápido que map para operações básicas.
- Usa mais memória que map.
- Chave e valor podem ser de tipos diferentes (paramétricos).

Dica:
Para iterar (ordem não garantida):
for (auto& [chave, valor] : um) 
    cout << chave << ": " << valor << "\n";

Acessar elementos:
- it->first (chave)
- it->second (valor)

Diferença principal do map:
- unordered_map: hash table, O(1) médio, SEM ordem
- map: árvore balanceada, O(log n), COM ordem nas chaves

*/