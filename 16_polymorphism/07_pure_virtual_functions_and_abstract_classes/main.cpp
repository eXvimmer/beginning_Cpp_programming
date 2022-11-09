// NOTE: in order for a class to be an abstract base class, it must contain at
// lease one pure virtual function.
// pure virtual function example : virtual void function() = 0;
// All derived classes must override pure virtual methods or they'll also be
// abstract.

#include <iostream>
#include <vector>

class Shape { // abstract base class
private:
  // attributes common to all shapes
public:
  virtual void draw() = 0;   // pure virtual function
  virtual void rotate() = 0; // pure virtual function
  virtual ~Shape() {}
};

// an abstract class, because pure virtual functions are not overridden
class OpenShape : public Shape {
public:
  virtual ~OpenShape() {}
};

class ClosedShape : public Shape { // abstract class
public:
  virtual ~ClosedShape() {}
};

class Line : public OpenShape { // concrete class
public:
  virtual void draw() override { std::cout << "Drawing a line\n"; }
  virtual void rotate() override { std::cout << "Rotating a line\n"; }
  virtual ~Line() {}
};

class Circle : public ClosedShape {
public:
  virtual void draw() override { std::cout << "Drawing a circle\n"; }
  virtual void rotate() override { std::cout << "Rotating a circle"; }
  virtual ~Circle() {}
};

class Square : public ClosedShape {
public:
  virtual void draw() override { std::cout << "Drawing a square\n"; }
  virtual void rotate() override { std::cout << "Rotating a square\n"; }
  virtual ~Square() {}
};

void refresh_screen(const std::vector<Shape *> &shapes) {
  std::cout << "Refreshing\n";
  for (const auto p : shapes) {
    p->draw();
  }
}

int main() {
  /* Shape s;  // ERROR */
  /* Shape *p{}; // ERROR */

  /* Line l; */
  /* l.draw(); */
  /* l.rotate(); */

  /* Shape *ptr{new Circle()}; // totally valid, because Circle is a Shape */
  /* ptr->draw(); */
  /* ptr->rotate(); */
  /* delete ptr; */

  Shape *s1{new Circle()};
  Shape *s2{new Line()};
  Shape *s3{new Square()};

  std::vector<Shape *> shapes{s1, s2, s3};

  refresh_screen(shapes);

  delete s1;
  delete s2;
  delete s3;

  return 0;
}
