
#include <iostream>
#include <queue>

using namespace std;

int mainn()
{
    ios::sync_with_stdio(false);

    queue<int> q;
    q.push(10);
    cout << q.front(); // 10
    q.pop();
    return 0;
}
/*
Resumo da queue:

push(valor)
Insere um elemento no final da fila.

pop()
Remove o elemento do início da fila (não retorna o valor).

front()
Retorna uma referência ao elemento do início da fila.

back()
Retorna uma referência ao elemento do final da fila.

size()
Retorna o número de elementos.

empty()
Retorna true se a fila está vazia.

emplace(args...)
Constrói e insere o elemento diretamente no final da fila.

Observações
Estrutura FIFO (First In, First Out).
Não permite acesso direto aos outros elementos, só ao início (front()) e ao final (back()).
Não permite remoção de elementos arbitrários, só do início.
Operações de inserção, remoção e acesso ao início/final são O(1).
*/