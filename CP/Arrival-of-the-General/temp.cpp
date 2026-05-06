#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, temp, max = INT_MIN, min = INT_MAX, moves = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec[i] = temp;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
    }
    int max_index;
    for (int i = 0; i < n; i++)
        if (max == vec[i]) {
            max_index = i;
            break;
        }
    while (max_index > 0) {
        swap(vec[max_index], vec[max_index - 1]);
        max_index--;
        moves++;
    }
    int min_index;
    for (int i = n - 1; i >= 0; i--)
        if (min == vec[i]) {
            min_index = i;
            break;
        }
    while (min_index < n - 1) {
        swap(vec[min_index], vec[min_index + 1]);
        min_index++;
        moves++; 
    }
    cout << moves << endl;
    return 0;
}