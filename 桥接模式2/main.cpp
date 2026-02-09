#include <iostream>
#include <string>
#include <memory>

// Implementor: Color Interface
class Color {
public:
    virtual ~Color() = default;
    virtual std::string fill() const = 0;
};

// ConcreteImplementor: Red
class Red : public Color {
public:
    std::string fill() const override {
        return "Red";
    }
};

// ConcreteImplementor: Blue
class Blue : public Color {
public:
    std::string fill() const override {
        return "Blue";
    }
};

// Abstraction: Shape
class Shape {
protected:
    std::shared_ptr<Color> color; // Bridge to the Implementor

public:
    Shape(std::shared_ptr<Color> c) : color(c) {}
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// RefinedAbstraction: Circle
class Circle : public Shape {
public:
    Circle(std::shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        std::cout << "Drawing a " << color->fill() << " Circle." << std::endl;
    }
};

// RefinedAbstraction: Square
class Square : public Shape {
public:
    Square(std::shared_ptr<Color> c) : Shape(c) {}
    void draw() const override {
        std::cout << "Drawing a " << color->fill() << " Square." << std::endl;
    }
};

int main() {
    // Create implementations (Colors)
    auto red = std::make_shared<Red>();
    auto blue = std::make_shared<Blue>();

    // Create abstractions (Shapes) bridged with implementations
    std::shared_ptr<Shape> redCircle = std::make_shared<Circle>(red);
    std::shared_ptr<Shape> blueSquare = std::make_shared<Square>(blue);
    
    // Demonstrate usage
    redCircle->draw();
    blueSquare->draw();

    // Adding more combinations to show flexibility
    std::shared_ptr<Shape> blueCircle = std::make_shared<Circle>(blue);
    std::shared_ptr<Shape> redSquare = std::make_shared<Square>(red);
    
    blueCircle->draw();
    redSquare->draw();

    return 0;
}
