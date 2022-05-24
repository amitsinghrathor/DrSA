#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    bool lthread, rthread;
    node(int data)
    {
        lthread = rthread = true;
        this->data = data;
        left = NULL;
        right = NULL;
    }
    friend class tbst;
};

class tbst
{
public:
    node *root;
    node *d = new node(999);

    tbst()
    {

        root = NULL;
        d->left = root;
    }

    void insert(int val)
    {
        node *p;
        node *ptr = new node(val);
        if (root == NULL)
        {
            root = ptr;
            root->left = d;
            root->right = d;
            cout << "Tree is created!!!" << endl;
        }
        else
        {
            p = root;
            while (true)
            {
                if (val < p->data)
                {
                    if (p->lthread == true)
                    {
                        ptr->left = p->left;
                        ptr->right = p;
                        p->left = ptr;
                        p->lthread = false;
                        cout << "Inserted" << endl;
                        break;
                    }

                    p = p->left;
                }
                else if (val > p->data)
                {
                    if (p->rthread)
                    {
                        ptr->left = p;
                        ptr->right = p->right;
                        p->right = ptr;
                        p->rthread = false;
                        cout << "Inserted!" << endl;
                        break;
                    }
                    p = p->right;
                }
            }
        }
    }
    void Inorder(node *r)

    {
        node *t = r;
        if (t == NULL)
        {
            cout << "The tree is empty!!" << endl;
        }
        else
        {
            while (true)
            {
                while (!t->lthread)
                {
                    t = t->left;
                }
                cout << t->data << " ";
                while (t->rthread)
                {
                    t = t->right;
                    if (t == d)
                    {
                        cout << endl;
                        return;
                    }
                    cout << t->data << " ";
                }
                t = t->right;
            }
        }
    }
};

int main()
{
    int choice, val;
    tbst T;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Insertion in T_BST\n2. Inorder Display\n0. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value you want to insert" << endl;
            cin >> val;
            T.insert(val);
            break;
        case 2:
            cout << "INODER DISPLAY" << endl;
            T.Inorder(T.root);
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}