#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // integers and bool
    int integerVar = 123;
    bool trueVar = true, falseVar = false;
        // Printing using cout or printf
    cout << integerVar << endl;
    cout << trueVar << " " << falseVar << endl;
    printf("%d\n", integerVar);
    printf("%d %d\n", trueVar, falseVar);
    
    // floats
    float singlePVar = 1.1234567890123456789;
    double doublePVar = 1.1234567890123456789;
    printf("%20.16f\n", singlePVar);
    printf("%20.16f\n", doublePVar);

    // Strings
    char str[11] = "Hello, C++";
    printf("%s\n", str);

    string dynamicStr = "Hello, C++";
    printf("Initial string: \t%s\n", dynamicStr.c_str());
    dynamicStr = "Hello, World!!!!!!!!!!";
    printf("After modification: \t%s\n", dynamicStr.c_str());

    return 0;
}
