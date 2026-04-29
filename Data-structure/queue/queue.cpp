#include <iostream>
# include <queue>
using namespace std;

void display(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty.";
        return;
    }
    cout << "Queue elements(front->rear): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
}
int main() {
    queue<int> q;
    int choice;
    while (true)
    {
        cout << "\n\n== Queue Operation ==" << endl;
        cout << "\t1. Enqueue." << endl;
        cout << "\t2. Dequeue." << endl;
        cout << "\t3. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            cout << "Enter element: ";
            cin >> element;
            q.push(element);
            display(q);
            break;
        case 2:
            if (!q.empty())
                q.pop();

            display(q);
            break;
        case 3: 
            return 0;
        
        default:
            break;
        }

    }
    
}