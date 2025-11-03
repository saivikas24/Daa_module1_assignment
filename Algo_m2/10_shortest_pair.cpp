#include <iostream>
#include <cmath>  // for sqrt and pow
#include <limits> // for numeric_limits
using namespace std;

// Class representing a point in 2D space
class Point {
public:
    float x, y;
    Point(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};

// Class to find the closest pair using brute force
class ClosestPairFinder {
private:
    float distance(Point p1, Point p2) {
        // Formula: sqrt((x2 - x1)^2 + (y2 - y1)^2)
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }

public:
    void findClosest(Point points[], int n) {
        float minDist = numeric_limits<float>::max();
        Point p1, p2;

        // Compare every pair of points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float dist = distance(points[i], points[j]);

                if (dist < minDist) {
                    minDist = dist;
                    p1 = points[i];
                    p2 = points[j];
                }
            }
        }

        cout << "\nClosest points are: (" << p1.x << ", " << p1.y << ") and ("
             << p2.x << ", " << p2.y << ")\n";
        cout << "Minimum Distance = " << minDist << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    Point points[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates of point " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }

    ClosestPairFinder finder;
    finder.findClosest(points, n);

    return 0;
}
