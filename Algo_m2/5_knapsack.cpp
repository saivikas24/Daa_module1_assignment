#include <iostream>
#include <algorithm>  // for sort
using namespace std;

// Class to represent an item
class Item {
public:
    float value, weight;

    // Constructor
    Item(float v, float w) {
        value = v;
        weight = w;
    }
};

// Function to compare two items based on value/weight ratio
bool compare(Item a, Item b) {
    float r1 = a.value / a.weight;
    float r2 = b.value / b.weight;
    return r1 > r2;  // Sort in descending order
}

float fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items by ratio (value/weight)
    sort(items, items + n, compare);

    float totalValue = 0.0; // Total value in knapsack
    int currentWeight = 0;  // Current weight of knapsack

    // Loop through each item
    for (int i = 0; i < n; i++) {
        // If item can fit fully
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        // If item cannot fit fully, take fraction
        else {
            int remain = capacity - currentWeight;
            totalValue += items[i].value * ((float)remain / items[i].weight);
            break;  // Bag is full
        }
    }

    return totalValue;
}

int main() {
    int n = 3; // Number of items
    int capacity = 50; // Maximum bag weight

    // Create items (value, weight)
    Item items[] = { {60, 10}, {100, 20}, {120, 30} };

    float maxValue = fractionalKnapsack(capacity, items, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
