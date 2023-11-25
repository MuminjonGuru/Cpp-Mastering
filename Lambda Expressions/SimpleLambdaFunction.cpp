auto add = [](int a, int b) { return a + b; };

// Lambda Function with Capture by Value: A lambda function that multiplies a number by a factor.
int factor = 5;
auto multiply = [factor](int a) { return a * factor; };


// Lambda Function with Capture by Reference: A lambda function that increments a number.
int num = 5;
auto increment = [&num]() { num++; };


// Lambda Function with Return Type: A lambda function that returns a string.
auto greet = []() -> std::string { return "Hello, World!"; };
