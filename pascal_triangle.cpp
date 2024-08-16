#include <iostream>

int digits_in_num(int num) {
    if (num < 0) num = -num; // Handle negative numbers
    return num > 0 ? static_cast<int>(std::log10(num)) + 1 : 1;
}

void print_pascal_row(int row, int max_rows, int num_digits)
{
    int element{ 1 };

    // Print initial row Spacing
    for (int s1 = 0; s1 < num_digits * (max_rows - row); s1++) {
        std::cout << " ";
    }
    
    // Elements
    for (int i = 0; i <= row; i++)
    {   
        // not using factorial here
        if (i != 0) {
            element = int(element * (row + 1 - i) / i);
        }

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
    // not using factorial here
    for (int i = 1; i <= levels/2; i++)
    {
        element = int(element * (levels +1 - i) / i);
    }
    return element;
}

void pascal_triangle(int levels)
{
    int max_digits = digits_in_num(max_pascal_triangle(levels)) + 1; // +1 for spacing

    for (int i = 0; i < levels; i++)
    {
        print_pascal_row(i, levels, max_digits);
        std::cout << '\n';
    }
}

int main()
{
    std::cout << "Enter levels to generate: ";
    int levels;
    std::cin >> levels;
    pascal_triangle(levels);
}

