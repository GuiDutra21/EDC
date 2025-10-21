#include <bits/stdc++.h>

using namespace std;

bool matrioska(const vector<int>& xs)
{
    stack<int> s;

    for (auto x : xs)
    {
        if (x < 0) // Todo abre eh empilhado
        {
            s.push(x);
        }
        else // Fecha
        {
            // Soma os que ja foram fechados dentro do atual
            int stacked = 0;
            while (not s.empty() and s.top() > 0) {
                stacked += s.top();
                s.pop();
            }

            // Se a soma ultrapassar o elemento atual
            // Ou se nao tiver nada na pilha
            // Ou se o top nao corresponder ao de abrir
            // Retorna falso
            if (stacked >= x or s.empty() or s.top() != -x)
                return false;

            // Quando fecha o brinquedo atual, coloco ele postivo na pilha
            // Assim o proximo que for fechar vai somar ele e
            // Verificar a soma no laco de cima
            s.pop();
            s.push(x);
        }
    }

    while (not s.empty() and s.top() > 0)
        s.pop();

    return s.empty();
}

int main()
{
    ios::sync_with_stdio(false);

    string line;

    while (getline(cin, line))
    {
        istringstream is(line);

        vector<int> xs;

        // lê todos os inteiros de is e os coloca no vetor xs
        copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(xs));

        cout << ":-" << (matrioska(xs) ? ") Matrioshka!" : "( Try again.") << '\n';
    }

    return 0;
}