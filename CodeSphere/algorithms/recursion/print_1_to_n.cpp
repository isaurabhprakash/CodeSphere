#include <iostream>

void printTillN (int n) 
{
    if (n == 0) {
        
        return;
    }
    
    printTillN (n-1);  // Print till n-1
    std::cout << n << std::endl; // Print n
}
