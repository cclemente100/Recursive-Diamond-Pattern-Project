#include <iostream>
using namespace std;

/*
 * RECURSIVE DIAMOND PATTERN EXPLANATION:
 * 
 * This program uses recursion to print a symmetrical diamond pattern.
 * The diamond has three parts:
 *   1. Top line (all stars)
 *   2. Upper and lower halves (printed recursively)
 *   3. Bottom line (all stars)
 * 
 * The recursive function printDiamondRows() works as follows:
 *   - Base case: When row reaches maxRows, we've reached the middle
 *   - Recursive case: 
 *     a) Print the current row (upper half pattern)
 *     b) Recursively call for the next row (goes deeper into diamond)
 *     c) After returning from recursion, print the mirror row (lower half)
 * 
 * This creates a "sandwich" effect where:
 *   - Going into recursion prints the upper half
 *   - Coming out of recursion prints the lower half (in reverse order)
 * 
 * Pattern structure for middle rows:
 *   [outer stars] [spaces] [inner stars] [spaces] [outer stars]
 *   - Outer stars: decrease from 11 to 1 as we go down
 *   - Inner stars: increase from 1 to 19 (odd numbers)
 *   - Spaces: adjust to maintain total width of 25
 */

// Function to print a row with the diamond pattern
void printRow(int outerStars, int innerStars) {
    // Print left outer stars
    for (int i = 0; i < outerStars; i++) {
        cout << "*";
    }
    
    // Calculate spaces between outer and inner stars
    // Total width is 25, so: outerStars + spaces + innerStars + spaces + outerStars = 25
    // Therefore: totalSpaces = 25 - 2*outerStars - innerStars
    int totalSpaces = 25 - 2 * outerStars - innerStars;
    
    if (innerStars == 0) {
        // Special case: when no inner stars, print all spaces in the middle
        for (int i = 0; i < totalSpaces; i++) {
            cout << " ";
        }
    } else {
        // Normal case: divide spaces on both sides of inner stars
        int spacesPerSide = totalSpaces / 2;
        
        // Print left spaces
        for (int i = 0; i < spacesPerSide; i++) {
            cout << " ";
        }
        
        // Print inner stars
        for (int i = 0; i < innerStars; i++) {
            cout << "*";
        }
        
        // Print right spaces
        for (int i = 0; i < spacesPerSide; i++) {
            cout << " ";
        }
    }
    
    // Print right outer stars
    for (int i = 0; i < outerStars; i++) {
        cout << "*";
    }
    
    cout << endl;
}

// Recursive function to print the diamond rows
void printDiamondRows(int row, int maxRows) {
    // Base case: reached the middle of the diamond
    if (row > maxRows) {
        return;
    }
    
    // Calculate stars for this row
    // For row 1: outer=11, inner=0 (special case - just spaces in middle)
    // For row 2+: outer stars decrease, inner stars increase
    int outerStars = 12 - row;
    int innerStars;
    
    if (row == 1) {
        innerStars = 0;  // First row has no inner stars, just spaces
    } else {
        innerStars = 2 * (row - 1) - 1;  // 1, 3, 5, 7... for rows 2, 3, 4...
    }
    
    // Print upper half row
    printRow(outerStars, innerStars);
    
    // Recursive call to go deeper into the diamond
    printDiamondRows(row + 1, maxRows);
    
    // Print lower half row (mirror of upper half) after recursion returns
    // This happens as we "unwind" from the recursion
    printRow(outerStars, innerStars);
}

int main() {
    // Print top line (all 25 stars)
    for (int i = 0; i < 25; i++) {
        cout << "*";
    }
    cout << endl;
    
    // Print the middle rows recursively (rows 1 through 11)
    // This will print both upper half and lower half due to recursion
    printDiamondRows(1, 11);
    
    // Print bottom line (all 25 stars)
    for (int i = 0; i < 25; i++) {
        cout << "*";
    }
    cout << endl;
    
    return 0;
}
