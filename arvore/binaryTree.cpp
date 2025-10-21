// Implementacao usando ponteiro
template <typename T>

class BinaryTree
{
private:
    struct Node
    {
        T info;
        Node *left, *right;
    };

    Node *root;

public:
    BinaryTree() : root(nullptr) {}
};

// Implementacao usando vetor
#include <vector>

template <typename T>
class BinaryTree
{
private:
    std::vector<T> nodes;
    
    int left(int p) { return 2 * p; }
    int right(int p) { return 2 * p + 1; }
    int parent(int i) { return i / 2; }

public:
    // O indice zero nao ́e utilizado, mas deve estar alocado
    BinaryTree() : nodes(1) {}
};
