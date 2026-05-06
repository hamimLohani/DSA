#include <iostream>
#include <vector>
using namespace std;

int main() {
    int level, x, y, temp;
    cin >> level;
    vector<bool> cover(level + 1, false);
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> temp;
        cover[temp] = true;
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> temp;
        cover[temp] = true;
    }
    for (int i = 1; i <= level; i++) {
        if (!cover[i]) {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
    
    return 0;
}