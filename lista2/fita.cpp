#include <iostream>

constexpr int LIMITE = 10001;

using namespace std;
int main()
{
    ios:: sync_with_stdio(false);

    int n;

    cin >> n;
    int vet[n];
    
    // for(int i = 0; i < n; i++)
    // {

    // }
    for(auto &i : vet)
    {
        cin >> i;
    }

    // Vetor das distancias
    int dist[n];

    // Calcula a distancia de todos os elementos para o zero mias proximo a esquerda
    int last_left = -1;
    for(int i = 0; i < n; ++i)
    {
        if(vet[i] == 0)
        {
            last_left = i;
            dist[i] = 0;
        }
        else if (last_left == -1)
        {
            dist[i] = LIMITE;
        }
        else
        {
            dist[i] = i - last_left;
        }
        
    }
    
    // Calcula a distancia de todos os elementos para o zero mias proximo a diretia e armazena em dist se a distancia for menor da que achada anteriormente
    int last_right = n;
    for(int i = n - 1; i > - 1; --i)
    {
        if(vet[i] == 0)
        {
            last_right = i;
            dist[i] = 0;
        }
        else if (last_right == n)
        {
            continue;
        }
        
        else if (dist[i] > last_right - i)
        {
            dist[i] = last_right - i;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        dist[i] = min(dist[i], 9);
        cout << dist[i] << (i == n - 1 ? "\n" : " ");
    }

    return 0;
}