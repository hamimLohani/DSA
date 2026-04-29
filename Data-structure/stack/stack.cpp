#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> st) {
    if (st.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack Elements (top->bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
}
int main() {
    stack<int> st;
    while (true)
    {
        cout << "\n\n== Stack Operation ==" << endl;
        cout << "\t1. Push." << endl;
        cout << "\t2. Pop." << endl;
        cout << "\t3. Exit." << endl;

        int choice;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "\nEnter element for push: ";
            cin >> element;
            st.push(element);
            display(st);
            break;
        case 2:
            if (!st.empty())
                st.pop();
                
            display(st);
            break;
        case 3:
            return 0;
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
}