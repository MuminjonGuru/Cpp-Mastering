// Lambda Function with Function Object: A lambda function that uses a function object.
struct Multiply {
    int operator()(int a, int b) const { return a * b; }
};

Multiply multiply;



// Lambda Function with Default Arguments: A lambda function that uses default arguments.
auto add = [](int a, int b = 0) { return a + b; };


// Lambda Function with Variadic Templates: A lambda function that uses variadic templates.
auto sum = [](auto... args) { return (args + ...); };
