#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public: 
        string info;
        Node* leftchild;
        Node* rightchild;

    //contructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //Initializing ROOT to null
    }

    void insert(string element) // Insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //Allocate memory for the new node
        newNode -> info = element; //Assign value the data field of the new data
        newNode -> leftchild = nullptr; //Make the left child of the new node point
        newNode -> rightchild = nullptr; //Make the right child of the new node point

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //Locate the node which be the parent of the node inserted

        if(parent == nullptr) // if the parent is NULL (Tree is empty)
        {
            ROOT = newNode; // Mark the new node as ROOT
            return; // exit
        }

        if (element < parent->info)
        {
            parent->leftchild = newNode;
        }
        else if (element > parent->info)
        {
            parent->rightchild = newNode;
        }
    }


    void search(string element, Node*& parent, Node*& currentNode)
    {
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }
    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr !=NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

      switch (ch)
        {
            case '1':
            {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                obj.insert(word);
                break;
            }
          case '2':
            {
                obj.inorder(obj.ROOT);
                break;
            }
          