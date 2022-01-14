#include <bits/stdc++.h>
using namespace std;

struct TreapNode
{
    int data, value;
    TreapNode *leftchild, *rightchild;
};

TreapNode *rightRotate(TreapNode *q)
{
    TreapNode *p = q->leftchild, *T = p->rightchild;

    p->rightchild = q;
    q->leftchild = T;

    return p;
}

TreapNode *leftRotate(TreapNode *p)
{
    TreapNode *q = p->rightchild, *T = q->leftchild;


    q->leftchild = p;
    p->rightchild = T;

    return q;
}

TreapNode* newNode(int data)
{
    TreapNode* temp = new TreapNode;
    temp->data = data;
    temp->value = rand()%100;
    temp->leftchild = temp->rightchild = NULL;
    return temp;
}


TreapNode* insert(TreapNode* root, int data)
{
    if (!root)
        return newNode(data);


    if (data <= root->data)
    {

        root->leftchild = insert(root->leftchild, data);


        if (root->leftchild->value > root->value)
            root = rightRotate(root);
    }
    else
    {

        root->rightchild = insert(root->rightchild, data);


        if (root->rightchild->value > root->value)
            root = leftRotate(root);
    }
    return root;
}



TreapNode* search(TreapNode* root, int data)
{

    if (root == NULL || root->data == data)
        return root;


    if (root->data < data)
        return search(root->rightchild, data);


    return search(root->leftchild, data);
}


TreapNode* deleteNode(TreapNode* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->leftchild = deleteNode(root->leftchild, data);
    else if (data > root->data)
        root->rightchild = deleteNode(root->rightchild, data);


    else if (root->leftchild == NULL)
    {
        TreapNode *temp = root->rightchild;
        delete(root);
        root = temp;
    }

    else if (root->rightchild == NULL)
    {
        TreapNode *temp = root->leftchild;
        delete(root);
        root = temp;
    }

    else if (root->leftchild->value < root->rightchild->value)
    {
        root = leftRotate(root);
        root->leftchild = deleteNode(root->leftchild, data);
    }
    else
    {
        root = rightRotate(root);
        root->rightchild = deleteNode(root->rightchild, data);
    }

    return root;
}


void build(TreapNode* root)
{
    if (root)
    {
        build(root->leftchild);
        cout << "data: "<< root->data << " => value: "
             << root->value;
        if (root->leftchild)
            cout << " => left child: " << root->leftchild->data;
        if (root->rightchild)
            cout << " => right child: " << root->rightchild->data;
        cout << endl;
        build(root->rightchild);
    }
}



int main()
{
    srand(time(NULL));

    struct TreapNode *root = NULL;

    cout << "\n\t\t\t\t\aWELCOME TO THE TREAP MANAGEMENT PROJECT\t\a\n\n";


    while(1)
    {
        cout << "1. INSERT\n";
        cout << "2. SEARCH\n";
        cout << "3. DELETE\n";
        cout << "4. RETURN TO MAIN MENU\n";
        cout << "5. EXIT\n";

        cout <<"\nEnter your choice:" <<endl;
        int input;
        cin >> input;


        switch(input)
        {
        case 1:

        {

            int tn, in;
            cout << "Enter total number of insertion: \n";
            cin >> tn;

            for(int i=1; i <= tn; i++)
            {
                cout << "Enter " << i << " number: ";
                cin >> in;
                root = insert(root, in);

            }
            cout << "\nBuilt Tree: \n";
            build(root);

            cout<<endl;
        }
        break;
        case 2:
            if (root == NULL)
            {
                cout<<"\nTree is empty, nothing to search\n\n"<<endl;
                continue;
            }

            {

                cout << "\nEnter number to search in treap: \n";
                int sec;
                cin >> sec;

                TreapNode *res = search(root, sec);
                (res == NULL)? cout << "\n" << sec << " Not Found\n": cout << "\n" << sec << " Found\n";
                cout<<endl;
            }
            break;

        case 3:
            if (root == NULL)
            {
                cout<<"\nTree is empty, nothing to delete\n\n"<<endl;
                continue;
            }
            {
                cout << "\nEnter number to delete: \n";

                int del;
                cin >>  del;

                TreapNode *delt = search(root, del);
                (delt == NULL)? cout << "\n" << del << " Not Found\n": cout << "\n" << del << " Deleted\n";


                root = deleteNode(root, del);
                cout << "\nBuilt Tree: \n";
                build(root);
                cout<<endl;
            }
            break;

        case 4:
        {
            main();
        }
        break;

        case 5:
        {

            cout <<"\nExiting."<< endl;
            cout <<"Thank you for using Treap Management System.\n";
            exit(0);
            cout<<endl;
        }
        break;
        default:
            cout << "\nWrong input. Please try again.\nThank you for using Treap Management System.\n";

            char c[1];
            printf("\nDo you want to continue (Y or N)? => ");
            cin >> c;
            if(strcmp(c,"Y")==0)
            {
                return main();
            }
            else
            {
                cout <<"\nExiting."<< endl;
                cout <<"Thank you for using Treap Management System.\n";
                return EXIT_SUCCESS;
            }
        }
    }
}
