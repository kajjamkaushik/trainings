#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base prototype class
class Shape {
protected:
    int X;
    int Y;
    std::string color;

public:
    // Regular constructor
    Shape() : X(0), Y(0), color("") {
    }

    // Prototype constructor
    Shape(const Shape& source) : X(source.X), Y(source.Y), color(source.color) {
    }

    // Virtual destructor
    virtual ~Shape() {}

    // The clone operation - pure virtual method
    virtual std::unique_ptr<Shape> clone() const = 0;

    // Getters and setters
    void setX(int x) { X = x; }
    int getX() const { return X; }

    void setY(int y) { Y = y; }
    int getY() const { return Y; }

    void setColor(const std::string& c) { color = c; }
    std::string getColor() const { return color; }

    // For demonstration purposes
    virtual void printInfo() const {
        std::cout << "Shape at position (" << X << ", " << Y << ") with color " << color << std::endl;
    }
};

// Concrete prototype - Rectangle
class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    // Regular constructor
    Rectangle() : Shape(), width(0), height(0) {
    }

    // Prototype constructor
    Rectangle(const Rectangle& source) : Shape(source), width(source.width), height(source.height) {
    }

    // Clone implementation
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    // Getters and setters
    void setWidth(int w) { width = w; }
    int getWidth() const { return width; }

    void setHeight(int h) { height = h; }
    int getHeight() const { return height; }

    // Override printInfo for Rectangle
    void printInfo() const override {
        Shape::printInfo();
        std::cout << "Rectangle with width: " << width << ", height: " << height << std::endl;
    }
};

// Concrete prototype - Circle
class Circle : public Shape {
private:
    int radius;

public:
    // Regular constructor
    Circle() : Shape(), radius(0) {
    }

    // Prototype constructor
    Circle(const Circle& source) : Shape(source), radius(source.radius) {
    }

    // Clone implementation
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    // Getters and setters
    void setRadius(int r) { radius = r; }
    int getRadius() const { return radius; }

    // Override printInfo for Circle
    void printInfo() const override {
        Shape::printInfo();
        std::cout << "Circle with radius: " << radius << std::endl;
    }
};

// Application class
class Application {
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    // Constructor with initialization
    Application() {
        // Create and configure a circle
        auto circle = std::make_unique<Circle>();
        circle->setX(10);
        circle->setY(10);
        circle->setRadius(20);
        circle->setColor("Red");

        // Add the circle to shapes
        shapes.push_back(std::move(circle));

        // Clone the circle and add it to shapes
        auto anotherCircle = dynamic_cast<Circle*>(shapes[0].get())->clone();
        shapes.push_back(std::move(anotherCircle));

        // Create and configure a rectangle
        auto rectangle = std::make_unique<Rectangle>();
        rectangle->setX(5);
        rectangle->setY(5);
        rectangle->setWidth(10);
        rectangle->setHeight(20);
        rectangle->setColor("Blue");

        // Add the rectangle to shapes
        shapes.push_back(std::move(rectangle));
    }

    // Business logic method
    void businessLogic() {
        std::cout << "Original shapes:" << std::endl;
        for (const auto& shape : shapes) {
            shape->printInfo();
        }

        std::cout << "\nCreating copies using prototype pattern:" << std::endl;

        // Create copies of all shapes
        std::vector<std::unique_ptr<Shape>> shapesCopy;
        for (const auto& shape : shapes) {
            shapesCopy.push_back(shape->clone());
        }

        // Print the copies
        for (const auto& shape : shapesCopy) {
            shape->printInfo();
        }
    }
};

int main() {
    Application app;
    app.businessLogic();
    return 0;
}
//output:
//Original shapes :
//Shape at position(10, 10) with color Red
//Circle with radius : 20
//Shape at position(10, 10) with color Red
//Circle with radius : 20
//Shape at position(5, 5) with color Blue
//Rectangle with width : 10, height : 20
//
//Creating copies using prototype pattern :
//Shape at position(10, 10) with color Red
//Circle with radius : 20
//Shape at position(10, 10) with color Red
//Circle with radius : 20
//Shape at position(5, 5) with color Blue
//Rectangle with width : 10, height : 20
