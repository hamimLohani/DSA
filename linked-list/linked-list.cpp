#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;
};

Node *head = nullptr;

bool isEmpty() {
    if (head == nullptr) {
        cout << "The Linked list is empty.\n";
        return true;
    }
    return false;
}

void insertAtEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) 
        temp = temp->next;
    
    temp->next = newNode;
    cout << value << " insert at the end.\n";
}

void insertAtBeginning(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " insert at the beginnign.\n";
}

void insert(int pos, int value) {
    if (pos < 0) {
        cout << "Invalid index.\n";
        return;
    }
    Node *newNode = new Node;
    newNode->data = value;
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        cout << value << " insert at " << pos << endl;
        return;
    }
    int i = 0;
    Node *temp = head;
    while (temp != nullptr && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == nullptr) {
        cout << "Invalid index.\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << value << " insert at " << pos << endl;
}

int search(int value) {
    if (isEmpty()) return -1;

    Node *temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) 
            return pos;
        
        pos++;
        temp = temp->next;
    }
    cout << value << " not found.\n";
    return -1;
}

void deleteValue(int value) {
    if (isEmpty()) return;

    if (head->data == value) {
        Node *del = head;
        head = head->next;
        delete del;
        cout << value << " deleted.\n";
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value) 
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << value << " not found.\n";
        return;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
    cout << value << " deleted.\n";
}

void display() {
    if (isEmpty()) return;

    Node *temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n=== Linked List Operation ===\n";
        cout << "\t1. Insert at beginnig.\n";
        cout << "\t2. Insert at end.\n";
        cout << "\t3. Insert at index.\n";
        cout << "\t4. Delete by value.\n";
        cout << "\t5. Search.\n";
        cout << "\t6. Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            insertAtBeginning(value);
            display();
            break;
        case 2:
            cout << "Enter element: ";
            cin >> value;
            insertAtEnd(value);
            display();
            break;
        case 3:
            cout << "Enter element: ";
            cin >> value;
            int i;
            cout << "Enter index: ";
            cin >> i;
            insert(i, value);
            display();
            break;
        case 4:
            cout << "Enter element: ";
            cin >> value;
            deleteValue(value);
            display();
            break;
        case 5:
            cout << "Enter element: ";
            cin >> value;
            search(value);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}