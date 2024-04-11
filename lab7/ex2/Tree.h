#include <iostream>

template <typename T>
int compare(T firstValue, T secondValue)
{
    if (firstValue < secondValue)
        return -1;
    else if (firstValue > secondValue)
        return 1;
    else
        return 0;
}

template <typename T>
struct Node
{
    T value;
    Node<T>** children;
    int nrChildren;
};

template <class T>
class Tree
{
public:
    Node<T>* root;
    int maxNrChildren;
public:
    Tree(int nrChildren)
    {
        this->maxNrChildren = nrChildren;
        root = nullptr;
    }

    void add_node(Node<T>* parent, T value)
    {
        if (parent == nullptr)
        {
            root = new Node<T>;
            root->value = value;
            root->nrChildren = 0;
            root->children = nullptr; 
        }
        else if (parent->nrChildren < maxNrChildren) 
        {
            parent->children[parent->nrChildren] = new Node<T>;
            parent->children[parent->nrChildren]->value = value;
            parent->children[parent->nrChildren]->nrChildren = 0;
            parent->children[parent->nrChildren]->children = nullptr; 
            parent->nrChildren++;
        }
    }

    Node<T>* get_node(Node<T>* parent)
    {
        if (parent != nullptr)
            return parent;
        else
            return root;
    }

    void delete_node(Node<T>* node)
    {
        if (node == nullptr)
            return;

        for (int i = 0; i < node->nrChildren; i++)
            delete_node(node->children[i]);

        delete[] node->children;
        delete node;
    }

    Node<T>* find(Node<T>* node, bool (*compare)(const T&, const T&), const T& value)
    {
        if (!node)
            return nullptr;

        if (compare(node->value, value) == 0) 
            return node;

        for (int i = 0; i < node->nrChildren; ++i)
        {
            Node<T>* found = find(node->children[i], compare, value);
            if (found)
                return found;
        }

        return nullptr;
    }

    void insert(Node<T>* parent, int index, T value)
    {
        for (int i = parent->nrChildren; i > index; --i)
            parent->children[i] = parent->children[i - 1];

        parent->children[index] = new Node<T>;
        parent->children[index]->value = value;
        parent->children[index]->nrChildren = 0;
        parent->children[index]->children = nullptr; 

        parent->nrChildren++;
    }

    void sort(Node<T>* parent, int (*compare)(T, T))
    {
        if (!parent || !compare)
            return;

        for (int i = 0; i < parent->nrChildren - 1; ++i)
        {
            for (int j = i + 1; j < parent->nrChildren; ++j)
            {
                if (compare(parent->children[i]->value, parent->children[j]->value) > 0)
                {
                    T temp = parent->children[i]->value;
                    parent->children[i]->value = parent->children[j]->value;
                    parent->children[j]->value = temp;
                }
            }
        }
    }

    int count(Node<T>* node)
    {
        if (!node)
            return 0;

        int counter = node->nrChildren;
        for (int i = 0; i < node->nrChildren; ++i)
            counter += count(node->children[i]);

        return counter;
    }
};