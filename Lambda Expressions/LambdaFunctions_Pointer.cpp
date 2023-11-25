 // Lambda Function with Function Pointer: A lambda function that uses a function pointer.
int (*func)(int, int);
func = [](int a, int b) { return a * b; };



// Lambda Function with Member Function Pointer: A lambda function that uses a member function pointer.
struct Rectangle {
    int width, height;
    int area() { return width * height; }
};

Rectangle rect;
auto area = [&rect]() { return rect.area(); };


// Lambda Function with Member Variable Pointer: A lambda function that uses a member variable pointer.
struct Circle {
    int radius;
};

Circle circle;
auto getRadius = [&circle]() { return circle.radius; };
