#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    deque<int> d;
    d.push_front(1);
    d.push_back(2);
    cout << d.front() << "\n"; // 1
    cout << d.back() << "\n" ;  // 2
    cout << d[1] << "\n";
    d[1] = 3;
    cout << d[1] << "\n";
    d.pop_front();
    d.pop_back();

    return 0;
}

/*
Resumo do deque:

push_front(valor)
Insere um elemento no início.

push_back(valor)
Insere um elemento no final.

pop_front()
Remove o elemento do início (não retorna o valor).

pop_back()
Remove o elemento do final (não retorna o valor).

front()
Retorna uma referência ao elemento do início.

back()
Retorna uma referência ao elemento do final.

size()
Retorna o número de elementos.

empty()
Retorna true se o deque está vazio.

clear()
Remove todos os elementos.

emplace_front(args...) / emplace_back(args...)
Constrói e insere o elemento diretamente no início ou final.

Acesso por índice:
Permite acessar qualquer elemento com deque[i].

Observações
Permite inserção e remoção eficiente tanto no início quanto no final (O(1)).
Permite acesso por índice como um vetor.
Útil para implementar filas com acesso nas duas extremidades.
*/