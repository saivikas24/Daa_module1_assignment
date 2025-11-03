#include <iostream>
#include <math.h>   // for pow() function
using namespace std;

// Class to solve Knapsack problem using all possible combinations
class Knapsack {
private:
    int n;                 // number of items
    int capacity;          // maximum weight bag can hold
    int weight[10];        // weights of items
    int value[10];         // values of items

public:
    // Function to take input from user
    void getInput() {
        cout << "Enter number of items: ";
        cin >> n;

        cout << "Enter capacity of the knapsack: ";
        cin >> capacity;

        cout << "Enter weights of all items:\n";
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
        }

        cout << "Enter values of all items:\n";
        for (int i = 0; i < n; i++) {
            cin >> value[i];
        }
    }

    // Function to find the best combination
    void findBest() {
        int totalComb = pow(2, n);   // total number of combinations (2^n)
        int maxValue = 0;            // to store best value
        int bestMask = 0;            // to remember which items are taken

        // Try all possible combinations using binary representation
        for (int mask = 0; mask < totalComb; mask++) {
            int totalWeight = 0;
            int totalValue = 0;

            // Check each bit to know which item is included
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {   // if bit is set, take that item
                    totalWeight += weight[i];
                    totalValue += value[i];
                }
            }

            // Check if weight within limit and better value found
            if (totalWeight <= capacity && totalValue > maxValue) {
                maxValue = totalValue;
                bestMask = mask;
            }
        }

        // Print the result
        cout << "\nMaximum value that can be carried: " << maxValue << endl;
        cout << "Items included: ";
        for (int i = 0; i < n; i++) {
            if (bestMask & (1 << i))
                cout << "Item" << i + 1 << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Knapsack bag;
    bag.getInput();
    bag.findBest();
    return 0;
}
