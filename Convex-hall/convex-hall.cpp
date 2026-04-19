#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    vector<Point> hull;

    if (n < 3) return hull;

    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) ||
            (points[i].y == ymin &&
             points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    swap(points[0], points[minIndex]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1 &&
               orientation(hull[hull.size() - 2],
                           hull[hull.size() - 1],
                           points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << "\nConvex Hull points:\n";
    for (auto p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}