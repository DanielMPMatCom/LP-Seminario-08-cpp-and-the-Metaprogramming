#include <iostream>

//Clase Point que puede ser instanciada en tiempo de compilación
class Point {
public:
    constexpr Point(int x, int y) : m_x(x), m_y(y) {}

    constexpr int getX() const { return m_x; }
    constexpr int getY() const { return m_y; }

private:
    int m_x;
    int m_y;
};

//Instancia de Point que puede ser creada en tiempo de compilación
constexpr Point p1(5, 10);
//Otra instancia de Point que es creada en tiempo de compilación
constexpr Point p2(5, 20);


// Obtener el punto medio entre dos puntos
constexpr Point midPoint(const Point& p1, const Point& p2)
{
    return Point((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
}

// El punto medio entre p1 y p2 es calculado en tiempo de compilación
constexpr Point p = midPoint(p1, p2);


int main() {
    
    std::cout << "Point 1 coordinates: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point 2 coordinates: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "Midpoint coordinates: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    return 0;
}