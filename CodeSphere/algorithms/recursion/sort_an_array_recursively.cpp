#include "main.h"

void insertElementAtCorrectPos (std::vector<int> & pArray, int pElement)
{
    if (pArray.size () == 0 || pElement > pArray[pArray.size () -1]) {
        
        // Either there are no elements in the array or the element can be inserted at the
        // last position itself
        pArray.push_back(pElement);
        return;
    }
    
    int last_element = pArray.back ();
    
    pArray.pop_back();
    
    insertElementAtCorrectPos(pArray, pElement);
    
    pArray.push_back(last_element);
}

void sortArrayRecursively (std::vector<int> & pArray)
{
    if (pArray.size () == 1) { // Base Conditon
        
        return;
    }
    
    int lastEle = pArray.back();
    
    pArray.pop_back();
    
    // Sort the entire array other than the last element
    sortArrayRecursively(pArray);
    
    // Insert the last element at the correct position in the sorted array
    insertElementAtCorrectPos (pArray, lastEle);
}
