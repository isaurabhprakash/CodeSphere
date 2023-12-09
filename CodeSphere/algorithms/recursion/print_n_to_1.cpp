#include "main.h"

void PrintFromNTill1 (int n)
{
    if (n == 0)
        return;
    
    std::cout<<n<<std::endl; // Print n
    PrintFromNTill1 (n-1); // Print from n-1 till 1
}
