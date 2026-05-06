#include <iostream>
using namespace std;

int main() {
    int n, faces = 0;
    cin >> n;
    string shaps;
    for (int i = 0; i < n; i++) {
        cin >> shaps;
        if (shaps == "Tetrahedron") faces += 4;
        if (shaps == "Cube") faces += 6;
        if (shaps == "Octahedron") faces += 8;
        if (shaps == "Dodecahedron") faces += 12;
        if (shaps == "Icosahedron") faces += 20;
    }
    cout << faces << endl;
    return 0;
}