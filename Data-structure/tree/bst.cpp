#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *root = nullptr;

Node *createNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->right = nullptr;
    newNode->left = nullptr;
    return newNode;
}
void insert(int value) {
    Node *newNode = new Node;
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node *temp = root;
    Node *parent = nullptr;
    while (temp != nullptr) {
        parent = temp;
        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else {
            delete newNode;
            return;
        }
    }
    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}
void search(int value) {
    Node *temp = root;
    while (temp != nullptr) {
        if (value == temp->data) {
            cout << value << " found.\n";
            return;
        }
        if (value < temp->data)
            temp = temp->left;
        else 
            temp = temp->right;
    }
    cout << value << " not found.\n";
}


int main() {
    int choice, value;
    while (true) {
        cout << "\n==== Tree Operation ====\n";
        cout << "\t1. Insertion.\n";
        cout << "\t2. Search.\n";
        cout << "\t3. Delete.\n";
        cout << "\t4. Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> value;
                search(value);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
}