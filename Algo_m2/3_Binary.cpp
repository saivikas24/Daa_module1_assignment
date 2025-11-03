#include <iostream>
using namespace std;

class BinaryChecker {
public:
    void checkBit(int n, int pos) {
        cout << "Number: " << n << endl;
        cout << "Binary equivalent: ";
        printBinary(n);
        cout << endl;

        // Step 1: Shift bits to right by pos positions
        int shifted = n >> pos;

        // Step 2: Get the last bit using AND operation
        int bit = shifted & 1;

        // Step 3: Print result
        cout << "Bit at position " << pos << " is: " << bit << endl;
        if (bit == 1)
            cout << "True (bit is 1)" << endl;
        else
            cout << "False (bit is 0)" << endl;
    }

private:
    // Helper function to print binary representation
    void printBinary(int n) {
        for (int i = 31; i >= 0; i--) {
            cout << ((n >> i) & 1);
        }
    }
};

int main() {
    BinaryChecker b;

    int num, pos;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter position to check (0 = rightmost bit): ";
    cin >> pos;

    b.checkBit(num, pos);
    return 0;
}
