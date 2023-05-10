#include<iostream>
#include<vector>

void swap (std::vector<int> & pArray, int pFirstIdx, int pSecondIdx)
{
        int first_ele;
 
    first_ele          = pArray[pFirstIdx];
    pArray[pFirstIdx]  = pArray[pSecondIdx];
    pArray[pSecondIdx] = first_ele;
 }

int Partition (std::vector<int> & pArray, int pLeft, int pRight)
{
        int pivot;
        int l_idx;
        int r_idx;
    
    // Choose th pivot element
    pivot = pLeft;
    
    l_idx = pLeft;
    r_idx = pRight;
    
    while (true) { // or just '>'
        
        while (pArray[l_idx] <= pArray[pivot]) {
            
            ++l_idx;
        }
        
        while (pArray[r_idx] > pArray[pivot]) {
            
            --r_idx;
        }
        
        if (l_idx > r_idx) {
            
            break;
            
        } else {
            
            swap (pArray, l_idx, r_idx);
        }
    }
    
    swap (pArray, pivot, r_idx);
    
    return r_idx;
}

void QuickSort (std::vector<int> & pArray, int pLeft, int pRight)
{
        int sorted_ele_idx;

    if (pRight <= pLeft) {
        return;
    }
    
    sorted_ele_idx = Partition (pArray, pLeft, pRight);
    
    /**
        Now all the elements before sorted_ele_idx index are less than element element
        at sorted_ele_idx index, and all the elements after sorted_ele_idx index are greater
        than element at sorted_ele_idx index. Basically, the Pivot is at it's place.
        Recursively, sort the two unsortd arrays using QuickSort
     */
    QuickSort(pArray, 0, sorted_ele_idx - 1);
    QuickSort(pArray, sorted_ele_idx + 1, pRight);
}

int main ()
{
        int                 size_of_arr;
        std::vector<int>    arr;
    
    std::cout << "Enter the size of the arrary : ";
    std::cin >> size_of_arr;
    
    std::cout << "Enter the elements of the arrary : ";
    for (int idx = 0; idx < size_of_arr; ++idx) {
    
            int ele;
        std::cin >> ele;
        arr.push_back(ele);
    }
    
    QuickSort (arr, 0, arr.size() - 1);
    
    std::cout << "The sorted array is :";
    for (const auto ele:arr){
        std::cout<<ele<<" ";
    }
    
    std::cout << "\n";
}