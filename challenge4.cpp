#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted in increasing order
bool isIncreasing(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false; // Not sorted in increasing order
        }
    }
    return true; // Sorted in increasing order
}

// Function to check if the array is sorted in decreasing order
bool isDecreasing(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            return false; // Not sorted in decreasing order
        }
    }
    return true; // Sorted in decreasing order
}

// Function to check if all elements in the array have a difference <= 3
bool hasSmallDifferences(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) > 3 || abs(a[i] - a[i - 1])<1) {
            return false; // Difference exceeds 3
        }
    }
    return true; // All differences are <=3
}
bool Isuniversal(int a[], int n) {
    if((isIncreasing(a,n) || isDecreasing(a,n)) && hasSmallDifferences(a,n))
    {
        return true;
    }
    return false;
}

int main() {
    int a[10000];
    int subarr[10000];  // Array to store numbers
    int counter = 0; // Counter to increment when conditions check1 and check2 are true

    ifstream file("input2.txt");
    

    string line;
    while (getline(file, line)) {
        int index = 0; // Index to keep track of array size
        stringstream ss(line);
        int num;

        // Extract numbers from the line
        while (ss >> num) {
            a[index++] = num;}
        

        // Check conditions: increasing or decreasing order and small differences is 3 aat max and also the difference between adjacent is atleast 1
       
        if(Isuniversal(a,index))
        {
            counter++;
        }
        else // creating a subarray to remove one digit and checking if its universal
        {// Check if removing one element can make it universal
            bool found = false;
            for (int i = 0; i < index; i++) {
                vector<int> subarr; // Create a subarray
                for (int j = 0; j < index; j++) {
                    if (j != i) {
                        subarr.push_back(a[j]); // Skip the i-th element
                    }
                }
                if (Isuniversal(subarr.data(), subarr.size())) {
                    counter++;
                    found = true;
                    break; // Stop checking further subarrays
               
            }

        }

      

    
}}

    file.close(); // closing the file

   
    cout << counter << endl;

    return 0;

}

// answer : 536