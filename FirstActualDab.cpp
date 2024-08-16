#include <iostream>

#define PI 3.14

double area(double radius)
{
    return PI * (radius * radius);
}

int digits_in_num(int num) {
    /*Return the number of digits in the number*/
    // Handle Negative numbers
    if (num < 0) {
        num *= -1;
    }
    int digits = 1;
    while (num / 10 != 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

void print_pascal_row(int row, int max_rows, int num_digits)
{
    int element{ 1 };
    double fraction{ 1.0 };

    // Print Spacing
    for (int s1 = 0; s1 < num_digits * (max_rows - row); s1++) {
        std::cout << " ";
    }

    for (int i = 0; i <= row; i++)
    {   
        // not using factorial here
        if (i != 0) {
            fraction = (double) (row + 1 - i) / i;
        }
        element = int(element * fraction);

        std::cout << element;

        // Print Spacing
        // multiplied by 2 for symmerty
        int req_spacing = num_digits * 2 - digits_in_num(element);
        for (int s2 = 0; s2 < req_spacing; s2++) {
            std::cout << " ";
        }

    }
}

int max_pascal_triangle(int levels) {
    int element{ 1 };
    double fraction{ 1.0 };
    levels--;
    for (int i = 0; i <= levels/2; i++)
    {
        // not using factorial here
        if (i != 0) {
            fraction = (double)(levels + 1 - i) / i;
        }
        element = int(element * fraction);
    }
    return element;
}

void pascal_triangle(int levels)
{
    // this should be one greater than the digits of the max value in the triangle for spacing
    int max_digits = digits_in_num(max_pascal_triangle(levels)) + 1;

    for (int i = 0; i < levels; i++)
    {
        print_pascal_row(i, levels, max_digits);
        std::cout << '\n';
    }
}

int main()
{
    //std::cout << "Enter Radius: ";
    //int radius;
    //std::cin >> radius;
    //std::cout << "Araea: " << area(radius);
    pascal_triangle(11);
    //std::cout << "MAX: " << max_pascal_triangle(15);
}

