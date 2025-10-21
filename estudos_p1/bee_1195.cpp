// Tinha que construir a arvore e rodar as travessias pos,pre e in
#include <iostream>
using namespace std;

struct BST
{
    struct Node
    {
        int info;
        Node *left, *right;
    };

    Node *root;

    BST() : root(nullptr) {}

    void inorder(const Node *node) const
    {
        if (node)
        {
            inorder(node->left);
            cout << ' '<< node->info;
            inorder(node->right);
        }
    }
    void preorder(const Node *node) const
    {
        if (node)
        {
            cout << ' '<< node->info;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(const Node *node) const
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << ' '<< node->info;
        }
    }
    void insert(int info)
    {
        Node **node = &root;

        while (*node)
        {
            if ((*node)->info == info)
                return;
            else if (info < (*node)->info)
                node = &(*node)->left;
            else
                node = &(*node)->right;
        }

        *node = new Node{info, nullptr, nullptr};
    }
};
int main()
{
    ios::sync_with_stdio(false);

    int C;
    cin >> C;

    for (int test = 1; test <= C; ++test)
    {
        int N;
        cin >> N;

        BST tree;

        while (N--)
        {
            int info;
            cin >> info;

            tree.insert(info);
        }
        cout << "Case " << test << ":\n";

        cout << "Pre.:";
        tree.preorder(tree.root);
        cout << "\n";

        cout << "In..:";
        tree.inorder(tree.root);
        cout << "\n";

        cout << "Post:";
        tree.postorder(tree.root);
        cout << "\n\n";
    }

    return 0;
}