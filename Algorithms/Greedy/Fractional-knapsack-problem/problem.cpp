#include <iostream>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator for sorting by value/weight ratio (descending)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Step 1: Sort items by ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    // Step 2: Pick items
    for (auto item : items) {
        if (W >= item.weight) {
            // Take full item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take fraction
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10}, {100, 20}, {120, 30}
    };

    int capacity = 50;

    cout << "Maximum value: " << fractionalKnapsack(capacity, items) << endl;

    return 0;
}