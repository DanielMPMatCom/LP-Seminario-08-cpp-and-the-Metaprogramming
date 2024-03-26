#include <iostream>

// A Point class that can be instantiated at compile time
class Point {
public:
    constexpr Point(int x, int y) : m_x(x), m_y(y) {}

    constexpr int getX() const { return m_x; }
    constexpr int getY() const { return m_y; }

private:
    int m_x;
    int m_y;
};

// An instance of a Point object that is created at compile time
constexpr Point p1(5, 10);
// Another instance of a Point object that is created at compile time
constexpr Point p2(5, 20);


// Get the midpoint between two points
constexpr Point midPoint(const Point& p1, const Point& p2)
{
    return Point((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
}

// Midpoint between p1 and p2 is calculated at compile time
constexpr Point p = midPoint(p1, p2);


int main() {
    
    std::cout << "Point 1 coordinates: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point 2 coordinates: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "Midpoint coordinates: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    return 0;
}