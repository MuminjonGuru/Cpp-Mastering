// #include <iostream>

// int calculateArea(int width, int height) {
//     return width * height; // Potential for overflow
// }

// int main() {
//     int width = 300000;
//     int height = 300000;
//     int area = calculateArea(width, height);
//     std::cout << "Area: " << area << std::endl;
//     return 0;
// }




// #include <cstdint>
// #include <iostream>

// int64_t calculateArea(int64_t width, int64_t height) {
//     return width * height; // Reduced risk of overflow
// }

// int main() {
//     int64_t width = 300000;
//     int64_t height = 300000;
//     int64_t area = calculateArea(width, height);
//     std::cout << "Area: " << area << std::endl;
//     return 0;
// }




#include <iostream>
#include <limits>

bool willMultiplyOverflow(int a, int b) {
    if (a > 0 && b > 0 && a > (std::numeric_limits<int>::max() / b)) {
        return true;
    }
    // Additional checks for negative numbers can be added here
    return false;
}

int safeMultiply(int a, int b) {
    if (willMultiplyOverflow(a, b)) {
        std::cerr << "Error: Operation would cause overflow." << std::endl;
        return 0; // or handle error appropriately-
    }
    return a * b;
}

int main() {
    int a = 300000;
    int b = 300000;
    int product = safeMultiply(a, b);
    std::cout << "Product: " << product << std::endl;
    return 0;
}
