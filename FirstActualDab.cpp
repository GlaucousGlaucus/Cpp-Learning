#include <iostream>

#define PI 3.14

double area(double radius)
{
	return PI * (radius * radius);
}

int main() {
	std::cout << "Enter Radius: ";
	double radius;
	std::cin >> radius;
	std::cout << "Area: " << area(radius);
}

