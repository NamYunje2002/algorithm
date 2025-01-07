#include <iostream>

class Rectangle {
public:
    Rectangle(int width, int height) : width(width), height(height) {};

    int get_width() const {
        return width;
    }

    int get_height() const {
        return height;
    }

    void set_width(int width) {
        if (0 < width && width < 1001) {
            this->width = width;
        }
    }

    void set_height(int height) {
        if (0 < height && height < 2001) {
            this->height = height;
        }
    }

    int area() const {
        return width * height;
    }

    int perimeter() const {
        return 2 * width + 2 * height;
    }

    bool is_square() {
        return width == height;
    }

private:
    int width;
    int height;
};