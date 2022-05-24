// Convert given binary search tree into
// threaded binary search  tree. 

#include <iostream>
#include <vector>
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
    node *r;
    node *d = new node(999);
    vector<node *> tr;

    tbst()
    {

        r = NULL;
    }
    void insert(int key)
    {
        node *x = new node(key);
        if (r == NULL)
        {
            r = x;
            d->left = r;
            cout << "Created!!" << endl;
        }
        else
        {
            node *temp = r;
            while (true)
            {
                if (temp->data > key)
                {
                    if (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = x;
                        temp->lthread = false;
                        cout << "Inserted" << endl;
                        break;
                    }
                }
                if (temp->data < key)
                {
                    if (temp->right != NULL)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = x;
                        temp->rthread = false;
                        cout << "Inserted" << endl;
                        break;
                    }
                }
            }
        }
    }

    void inorder(node *root)
    {

        if (root != NULL)
        {
            inorder(root->left);
            tr.push_back(root);
            // cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void convert(node *root)
    {
        inorder(root);
        for (int i = 0; i < tr.size(); i++)
        {
            if (tr[i]->right == NULL)
            {
                if (i == tr.size() - 1)
                {
                    tr[i]->right = d;
                }
                else
                {
                    tr[i]->right = tr[i + 1];
                    tr[i]->rthread = true;
                }
            }
            if (tr[i]->left == NULL)
            {
                if (i == 0)
                {
                    tr[i]->left = d;
                }
                else
                {
                    tr[i]->left = tr[i - 1];
                    tr[i]->lthread = true;
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
            while (t!=d)
            {
                while (!t->lthread)
                {
                    t = t->left;
                }
                cout << t->data << " ";
                if (t->rthread == false)
                {
                    t = t->right;
                }
                else
                {
                    while (t->rthread)
                    {
                        t = t->right;
                        if (t == d)
                        {
                            return;}
                        cout << t->data << " ";
                    }
                    t = t->right;
                }
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
        cout << "1. Insertion in tree\n2. Convert it to TBST\n3. Inorder Display\n0. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value you want to insert" << endl;
            cin >> val;
            T.insert(val);
            break;
        case 2:
            T.convert(T.r);
            cout << "Tree is converted!!" << endl;
            break;
        case 3:
            cout << "INODER DISPLAY" << endl;
            T.Inorder(T.r);
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