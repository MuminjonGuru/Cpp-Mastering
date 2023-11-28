// understanding pointers
#include <iostream>

int main() {
    int var = 10;
    int* ptr = &var;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;

    return 0;
}


// pointer arithmetic
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    for(int i = 0; i < 5; i++) {
        std::cout << "Value of arr[" << i << "]: " << *(ptr + i) << std::endl;
    }

    return 0;
}


// Dereferencing pointers
#include <iostream>

int main() {
    int var = 10;
    int* ptr = &var;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Value of var using pointer: " << *ptr << std::endl;

    return 0;
}



// Null pointers
#include <iostream>

int main() {
    int* ptr = nullptr;

    if(ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    } else {
        std::cout << "ptr is not null" << std::endl;
    }

    return 0;
}



// Pointers and arrays
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    for(int i = 0; i < 5; i++) {
        std::cout << "Value of arr[" << i << "]: " << ptr[i] << std::endl;
    }

    return 0;
}



// Pointers and functions
#include <iostream>

void changeValue(int* ptr) {
    *ptr = 20;
}

int main() {
    int var = 10;

    std::cout << "Before changeValue: " << var << std::endl;
    changeValue(&var);
    std::cout << "After changeValue: " << var << std::endl;

    return 0;
}
