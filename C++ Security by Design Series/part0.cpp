#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void unsafeFunction() {
    char buffer[10];
    strcpy(buffer, "This is way too long for the buffer");
}

void vectorBasedFunction() {
    vector<int> safeArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Adding more elements is safe
    safeArray.push_back(11);
    safeArray.push_back(12);

    for (int elem : safeArray) {
        cout << elem << " ";
    }
    cout << endl;
}

void saferFunction() {
    char buffer[10];
    const char* longString = "This string is too long for the buffer";

    strncpy(buffer, longString, sizeof(buffer) - 1); // Copy with boundary
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null termination

    cout << "Buffer contains: " << buffer <<endl;
}

void stringBasedFunction() {
    string safeString = "This can be a very long string without overflow risks";
    cout << "Safe string contains: " << safeString << endl;
}

void vectorBasedFunction() {
    vector<int> safeArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Adding more elements is safe
    safeArray.push_back(11);
    safeArray.push_back(12);

    for (int elem : safeArray) {
       cout << elem << " ";
    }
    cout << endl;
}

int main() {
         


    cout << "CMPLITD" << endl;
    return 0;
}
