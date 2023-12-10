#include "main.h"

void insertTop (std::stack<int> & s, int top)
{
    if (s.empty ()) {
        
        s.push(top);
        return;
    }
    
    int  curTop = s.top ();
    s.pop ();
    
    insertTop(s, top);
    
    s.push(curTop);
}

void sortStackRecursively (std::stack<int>  & s)
{
    if (s.size () == 1)
        return;
    
    int top = s.top ();
    s.pop ();
    
    sortStackRecursively (s); // reverse all elements of stack other than the top
    
    insertTop (s, top); // insert the top element at the first position
}
