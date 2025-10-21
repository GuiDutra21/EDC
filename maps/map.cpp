#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    map<int, int> m1; // Mapa de pares de inteiros vazio

    map<int, char> m2{{1, 'a'}, {2, 'b'}, {3, 'c'}};

    map<int, char> m3(m2); // m3 == m2

    map<int, char> m4(m2.begin(), m2.end()); // m4 == m2

    map<int, char> m5(move(m2)); // m5 == m4, m2 vazio

    map<string, int> m;
    m["abc"] = 1;        // m = { "abc": 1 }
    m.emplace("xyz", 2); // m = { "abc": 1, "xyz": 2 }

    m.erase("xyz"); // m = { "abc": 1 }

    auto it = m.find("xyz"); // it == m.end()

    auto n = m.count("abc"); // n == 1

    m.insert({{"xyz", 2}, {"rst", 3}});

    for (auto [x, y] : m)
        cout << x << ": " << y << endl;

    auto ok = m.empty(); // ok == false
    n = m.size();        // n = 3

    it = m.lower_bound("mno"); // *it == { "rst", 3 };
    it = m.lower_bound("abc"); // *it == { "abc", 1 };
    it = m.upper_bound("zzz"); // *it == m.end();
}
/*
Resumo do map:

insert({chave, valor})
Insere um par chave-valor. Não insere se a chave já existe.

operator[] (chave)
Acessa ou insere o valor associado à chave. Se a chave não existe, cria com valor padrão.
m[1] = "A";        // Insere chave 1 com valor "A"
cout << m[1];      // Imprime "A"

erase(chave) / erase(it) - Remove o elemento pela chave ou pelo iterador.

find(chave) - Retorna um iterador para o elemento com a chave (ou end() se não existir).

count(chave) - Retorna 1 se a chave existe, 0 se não.

size() - Retorna o número de elementos. O(1)

empty() - Retorna true se o map está vazio. O(1)

clear() - Remove todos os elementos.

begin() / end() - Iteradores para o início e o fim do map.

lower_bound(chave) - Iterador para o primeiro elemento ≥ chave.

upper_bound(chave) - Iterador para o primeiro elemento > chave.

emplace(chave, valor) - Insere o par construindo direto no map (mais eficiente para tipos complexos).

Observações:
Elementos são sempre ordenados pela chave.
Não permite chaves repetidas.
Operações de busca, inserção e remoção são O(log n).
Chave e valor podem ser de tipos diferentes (paramétricos).

Dica:
Para acessar o menor chave: map.begin()->first
Para acessar o maior chave: map.rbegin()->first
Para acessar o valor: it->second (onde it é um iterador)

*/