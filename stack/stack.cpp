#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << "\n"; // 30
    s.pop();    
    return 0;
}

/*
Resumo da stack:

push(valor)
Insere um elemento no topo da pilha.

pop()
Remove o elemento do topo (não retorna o valor).

top()
Retorna uma referência ao elemento do topo, mas sem remover

size()
Retorna o número de elementos.

empty()
Retorna true se a pilha está vazia.

emplace(args...)
Constrói e insere o elemento diretamente no topo.

Observações
Estrutura LIFO (Last In, First Out).
Não permite acesso direto aos outros elementos, só ao topo.
Não permite remoção de elementos arbitrários, só do topo.
Operações de inserção, remoção e acesso ao topo são O(1).
*/