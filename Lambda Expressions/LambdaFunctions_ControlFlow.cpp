// Lambda Function with Generic Parameter: A lambda function that checks if a number is even.
auto isEven = [](auto num) { return num % 2 == 0; };




// Lambda Function with Conditional Statement: A lambda function that returns the maximum of two numbers.
auto max = [](int a, int b) { return a > b ? a : b; };




// Lambda Function with Loop: A lambda function that calculates the sum of an array.
int arr[] = {1, 2, 3, 4, 5};
auto sum = [&arr]() {
    int total = 0;
    for(int i = 0; i < 5; i++) {
        total += arr[i];
    }
    return total;
};



// Lambda Function with Recursion: A lambda function that calculates the factorial of a number.
auto factorial = [](auto f, int n) -> int {
    if(n == 0) return 1;
    else return n * f(f, n - 1);
};




// Lambda Function with Exception Handling: A lambda function that handles division by zero.
auto divide = [](int a, int b) {
    if(b == 0) throw std::invalid_argument("Division by zero");
    return a / b;
};

  
