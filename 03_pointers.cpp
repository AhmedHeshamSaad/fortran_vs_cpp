#include <iostream>
#include <iomanip>

int main() {
    int myArray[10];

    // Initialize the array with values 1 through 10
    for(int i = 0; i < 10; ++i) {
        myArray[i] = i + 1;
    }

    // Print the original array
    std::cout << "Original array: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << std::setw(2) << myArray[i] << " ";
    }
    std::cout << "\n";

    // Pointer to a subsection of the array
    int* ptr = &myArray[4]; // Point to the 5th element (index 4)

    // Print the slice before modification
    std::cout << "Slice before mod: ";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(2) << ptr[i] << " ";
    }
    std::cout << "\n";

    // Modify the slice through the pointer
    for(int i = 0; i < 3; ++i) {
        ptr[i] *= 2; // Double each element in the slice
    }

    // Print the slice after modification
    std::cout << "Slice after mod:  ";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(2) << ptr[i] << " ";
    }
    std::cout << "\n";

    // Show the effect on the original array
    std::cout << "Modified array:   ";
    for(int i = 0; i < 10; ++i) {
        std::cout << std::setw(2) << myArray[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
