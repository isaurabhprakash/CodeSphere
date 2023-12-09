#include "main.h"

int main(int argc, const char * argv[]) {
            
    std::vector<int>    arr;
    
    arr.push_back(99);
    arr.push_back(43);
    arr.push_back(-12);
    arr.push_back(901);
    arr.push_back(-1782);
    arr.push_back(18);
    
    sortArrayRecursively (arr);
    
    for (auto num : arr) {
        
        std::cout<<num <<" ";
    }
    return 0;
}
