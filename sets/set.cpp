#include <set>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    // Tipos de contrutores

    set<int> s1; // Conjunto de inteiros vazio

    string s{"Teste"};
    set<char> s2(s.begin() + 1, s.end()); // s2 = { 'e', 's', 't', 'e'}

    set<char> s3(s2); // s3 == s2

    set<char> s4(move(s3)); // s4 == s2, s3 vazio

    set<double> s5{2.0, 1.5, 3.7}; // s5 = { 1.5, 2.0, 3.7 }

    return 0;
}
/*

Resumo do Set:

insert(valor) - Insere um elemento. Não permite duplicados.

erase(valor) / erase(it) - Remove um elemento pelo valor ou pelo iterador.

find(valor) - Retorna um iterador para o elemento igual a valor (ou end() se não existir).

count(valor) - Retorna 1 se o elemento existe, 0 se não.

size() - Retorna o número de elementos. O(1)

empty() - Retorna true se o set está vazio. O(1)

clear() -Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do set.

lower_bound(valor)- Iterador para o primeiro elemento ≥ valor.

upper_bound(valor)- Iterador para o primeiro elemento > valor.

emplace(args...)- Insere elemento construindo direto no set (mais eficiente para tipos complexos).

Observações
Elementos são sempre ordenados.
Não permite elementos repetidos.
Operações de busca, inserção e remoção são O(log n).

Dica:
Para acessar o menor elemento: *s.begin()
Para acessar o maior elemento: *prev(s.end()) ou *--s.end()

*/