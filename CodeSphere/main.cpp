#include "main.h"

int main(int argc, const char * argv[]) {
            
    std::stack<int> s;
    
    s.push (1);
    s.push (2);
    s.push (3);
    s.push (4);
    s.push (5);
    s.push (6);

    sortStackRecursively (s);
    
    while (!s.empty ()) {
        
        std::cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
