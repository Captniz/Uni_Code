#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class Node;

int N;
Node *NIL;

class Node
{
public:
    int data;
    bool is_red; // true for red, false for black
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        is_red = true; // new nodes are red by default
        parent = left = right = NIL;
    }

    Node(int data, Node *dad)
    {
        this->data = data;
        is_red = true; // new nodes are red by default
        parent = dad;
        left = right = NIL;
    }

    Node(int data, bool is_red)
    {
        this->data = data;
        this->is_red = is_red;
        parent = left = right = NIL;
    }

    Node(int data, bool is_red, Node *dad)
    {
        this->data = data;
        this->is_red = is_red;
        parent = dad;
        left = right = NIL;
    }

    bool is_NIL()
    {
        return this == NIL;
    }
};

class RedBlackTree
{
public:
    Node *root;

    RedBlackTree()
    {
        root = NIL;
    }

    RedBlackTree(int data)
    {
        root = new Node(data, false); // root is always black
    }

    // Rotate #################################################################

    Node *rotate_left(Node *target)
    {
        Node *parent = target->parent;
        Node *rightside = target->right;

        target->right = rightside->left;

        if (!rightside->left->is_NIL())
            rightside->left->parent = target;

        rightside->left = target;
        target->parent = rightside;
        rightside->parent = parent;

        if (!parent->is_NIL())
            if (target == parent->left)
                parent->left = rightside;
            else
                parent->right = rightside;
        return rightside;
    }

    Node *rotate_right(Node *target)
    {
        Node *parent = target->parent;
        Node *leftside = target->left;

        target->left = leftside->right;

        if (!leftside->right->is_NIL())
            leftside->right->parent = target;

        leftside->right = target;
        target->parent = leftside;
        leftside->parent = parent;

        if (!parent->is_NIL())
            if (target == parent->left)
                parent->left = leftside;
            else
                parent->right = leftside;
        return leftside;
    }

    // Insert #################################################################

    void insert_balance(Node *target)
    {
        /*
         * target = address of the node to be inserted
         * parent = target's parent
         * grandpa = parent's parent
         * aunt = parent's sibling
         */

        target->is_red = true; // Target is by default red
        while (!target->is_NIL())
        {
            Node *parent = target->parent;
            Node *grandpa = (parent->is_NIL() ? NIL : parent->parent);
            Node *aunt = (grandpa->is_NIL() ? NIL : (parent == grandpa->left ? grandpa->right : grandpa->left));

            if (parent->is_NIL())
            {
                target->is_red = false;
                return;
            }
            if (!parent->is_red)
                return;
            else if (aunt->is_red)
            {
                grandpa->is_red = true;
                parent->is_red = aunt->is_red = false;
                target = grandpa;
            }
            else
            {
                if (target == parent->right && parent == grandpa->left)
                {
                    grandpa->left = rotate_left(parent);
                    target->parent;
                }
                else if (target == parent->left && parent == grandpa->right)
                {
                    grandpa->right = rotate_right(parent);
                    target->parent;
                }
                else
                {
                    if (target == parent->left && parent == grandpa->left)
                        grandpa->left = rotate_right(grandpa);
                    else if (target == parent->right && parent == grandpa->right)
                        grandpa->right = rotate_left(grandpa);
                    parent->is_red = false;
                    grandpa->is_red = true;
                    return;
                }
            }
        }
    }

    void insert_cycle(Node *new_node)
    {
        Node *curr = root;

        for (;;)
            if (curr->data == new_node->data)
                return;
            else if (new_node->data < curr->data)
                if (curr->left->is_NIL())
                {
                    curr->left = new_node;
                    new_node->parent = curr;
                    insert_balance(new_node);
                    return;
                }
                else
                    curr = curr->left;
            else if (curr->right->is_NIL())
            {
                curr->right = new_node;
                new_node->parent = curr;
                insert_balance(new_node);
                return;
            }
            else
                curr = curr->right;
    }

    void insert(int data)
    {
        Node *new_node = new Node(data);

        if (root->is_NIL())
        {
            new_node->is_red = false;
            root = new_node;
        }
        else
            insert_cycle(new_node);
        return;
    }

    void insert(RedBlackTree *data)
    {
        data->root->is_red = true;
        if (root->is_NIL())
        {
            data->root->is_red = false;
            root = data->root;
        }
        else
            insert_cycle(data->root);
        return;
    }

    // Print ##################################################################

    void printRB(Node *curr)
    {
        // ROOT->LEFT->RIGHT

        out << curr->data << " " << (curr->is_red ? "R" : "B") << endl;
        if (!curr->left->is_NIL())
            printRB(curr->left);
        if (!curr->right->is_NIL())
            printRB(curr->right);
        return;
    }

    void printLINK(Node *curr)
    {
        // ROOT->LEFT->RIGHT

        if (!curr->left->is_NIL())
        {
            out << curr->data << " " << curr->left->data << endl;
            printLINK(curr->left);
        }
        if (!curr->right->is_NIL())
        {
            out << curr->data << " " << curr->right->data << endl;
            printLINK(curr->right);
        }
        return;
    }

    void print()
    {
        out << root->data << endl;
        printRB(root);
        printLINK(root);
    }
};

int main()
{
    NIL = new Node(-1, false); // sentinel NIL node, black
    in >> N;

    RedBlackTree *RBT = new RedBlackTree();
    for (int i = 0; i < N; i++)
    {
        int data;
        in >> data;
        RBT->insert(data);
    }

    //RBT->print();

    in.close();
    out.close();
    return 0;
}