#include <iostream>

#define PI 3.14

double area(double radius)
{
    return PI * (radius * radius);
}

void print_pascal_row(int row)
{
    int element{ 1 };
    double fraction{ 1.0 };
    std::cout << element << " ";

    for (int i = 1; i <= row; i++)
    {
        fraction = static_cast<double>(row + 1 - i) / i;
        element = int(element * fraction);
        std::cout << element << " ";
    }
}

void pascal_triangle(int levels)
{
    for (int i = 0; i < levels; i++)
    {
        print_pascal_row(i);
        std::cout << '\n';
    }
}

int main()
{
    //std::cout << "Enter Radius: ";
    //int radius;
    //std::cin >> radius;
    //std::cout << "Araea: " << area(radius);
    pascal_triangle(8);
}

