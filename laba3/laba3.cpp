#include <iostream>
#include <cmath>
using namespace std;
class Vector2D {
protected:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    double length() const {
        return std::sqrt(x * x + y * y);
    }
    virtual void print() const {
        cout << "Vector2D: (" << x << ", " << y << "), Length: " << length() << endl;
    }
};
class Vector3D : public Vector2D {
private:
    double z;

public:
    Vector3D(double x = 0, double y = 0, double z = 0) : Vector2D(x, y), z(z) {}

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    void print() const override {
        cout << "Vector3D: (" << x << ", " << y << ", " << z << "), Length: " << length() << endl;
    }
};
int main() {
    Vector2D* vec2D = new Vector2D(3, 4);
    vec2D->print(); // Вызов функции print() через указатель на базовый класс

    Vector2D* vec3D = new Vector3D(3, 4, 5);
    vec3D->print(); // Вызов функции print() через указатель на базовый класс, но объект производного класса

    return 0;
}