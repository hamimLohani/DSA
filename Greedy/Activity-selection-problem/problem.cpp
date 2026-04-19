#include <iostream>
using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    int n = activities.size();

    // Step 1: Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    // Step 2: Select the first activity
    cout << "Selected activities:\n";
    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";

    // Step 3: Select remaining activities
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << ")\n";
            i = j;
        }
    }
}

int main() {
    vector<Activity> activities = {
        {1, 3}, {2, 4}, {0, 6}, {5, 7},
        {8, 9}, {5, 9}
    };

    activitySelection(activities);

    return 0;
}