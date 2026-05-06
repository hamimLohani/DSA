#include <iostream>
#include <set>
using namespace std;

int main() {
    string letters;
    set<char> st;

    getline(cin, letters);

    for (int i = 0; i < letters.size(); i++) {
        if (letters.at(i) <= 'z' && letters.at(i) >= 'a') 
            st.insert(letters.at(i));
    }
    cout << st.size() << endl;
    return 0;
}