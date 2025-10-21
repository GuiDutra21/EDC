template <typename T>
class BST
{
private:
    struct Node
    {
        T info;
        Node *left, *right;
    };

    Node *root;

public:
    BST() : Node(nullptr) {}

    void insert(const T info)
    {
        Node *node =  root;
        Node *prev = nullptr;

        while(node)
        {
            prev = node;
            if(node -> info == info)
                return
            else if(info < node -> info)
                node = node -> left;
            else
                node = node -> right;
        }

        node = new Node {info, nullptr, nullptr};

        if(!root)
            root = node;
        else if(info < prev -> info)
            prev -> left = node;
        else
            prev -> right = node;
    }
};