// Dynamic memory allocation (new and delete)
#include <iostream>

int main() {
    int* ptr = new int;
    *ptr = 10;

    std::cout << "Value of ptr: " << *ptr << std::endl;

    delete ptr;

    return 0;
}


// Pointers to pointers
#include <iostream>

int main() {
    int var = 10;
    int* ptr = &var;
    int** ptrToPtr = &ptr;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Value of var using pointer: " << *ptr << std::endl;
    std::cout << "Value of var using pointer to pointer: " << **ptrToPtr << std::endl;

    return 0;
}



// Pointers and multidimensional arrays
#include <iostream>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr)[3] = arr;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "Value of arr[" << i << "][" << j << "]: " << *(*(ptr + i) + j) << std::endl;
        }
    }

    return 0;
}


// Pointers and strings
#include <iostream>

int main() {
    char str[] = "Hello, World!";
    char* ptr = str;

    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value of str using pointer: " << ptr << std::endl;

    return 0;
}
