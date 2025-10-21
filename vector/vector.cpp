#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> vet(3);
    vet.insert(vet.begin() + 2,1);
    for(auto i : vet)
        cout << i << "\n";

    return 0;
}
/*
Resumo do vector
push_back(valor)
Insere um elemento no final.

pop_back()
Remove o elemento do final (não retorna o valor).

size()
Retorna o número de elementos.

empty()
Retorna true se o vetor está vazio.

clear()
Remove todos os elementos.

front() / back()
Retorna referência ao primeiro/último elemento.

Acesso por índice:
Permite acessar/modificar qualquer elemento com vector[i].

at(i)
Acessa o elemento na posição i com verificação de limites.

insert(it, valor)
Insere elemento na posição indicada pelo iterador.

erase(it)
Remove elemento na posição indicada pelo iterador.

resize(n)
Altera o tamanho do vetor.

emplace_back(args...)
Constrói e insere elemento diretamente no final.
*/