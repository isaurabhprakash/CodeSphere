/**
 * Solution of the classic knapsack problem using the Top-Down approach
*/
#include<iostream>
#include<vector>

int knapsack (int pCapacity, std::vector<int> pWeights, std::vector<int> pValues, int pNumItems, std::vector<std::vector<int>> t)
{
    // Nothing can be picked if :
    // 1. The bag's capacity is 0 (nothing can be kept in the bag)
    // 2. There's no item (nothing can be picked up)
    if ((pNumItems == 0) || (pCapacity == 0)) {
        
        return 0;
    }
    
    if (t[pCapacity][pNumItems] != -1) {
        
        return t[pCapacity][pNumItems];
    }
    
    if (pWeights[pNumItems-1] > pCapacity) {
        
        // Since weight of the item is greater than the bag capacity,
        // this item itself can not be kept in the bag. Hence, knapsack
        // has to be done for the remaining items
        t[pCapacity][pNumItems] =  knapsack(pCapacity, pWeights, pValues, pNumItems - 1, t);
    } else {
        
        // Since this item can be put in the bag, now there are two choices
        // 1. To keep this item in the bag, and then to do knapsack for rest of the items
        // 2. To not keep this item in the bag, and then to do the knapsack on the rest of the
        // items.
        t[pCapacity][pNumItems] = std::max (pValues[pNumItems-1] + knapsack(pCapacity - pWeights[pNumItems-1], pWeights, pValues , pNumItems - 1, t), knapsack(pCapacity, pWeights, pValues, pNumItems-1, t));
    }
    return t[pCapacity][pNumItems];
}

int main ()
{
    int capacity;
    int numItems;
    int maxValue;
    
    std::cout<<"Enter the capacity of the bag : ";
    std::cin>>capacity;
    
    std::cout<<"\nEnter the number of items : ";
    std::cin>>numItems;
    
    std::vector<std::vector<int>>   t(capacity+1, std::vector<int>(numItems+1, -1));
    
    std::vector<int>    weights(numItems);
    std::vector<int>    values(numItems);
    
    std::cout<<"\nEnter the weights of the items : ";
    for (int i = 0; i < numItems; ++i) {
        std::cin>>weights[i];
    }
    
    std::cout<<"\nEnter the values of the items : ";
    for (int i =0; i < numItems; ++i) {
        std::cin>>values[i];
    }
    
    maxValue = knapsack(capacity, weights, values, numItems, t);
    
    std::cout<<"\nThe maximum value of items in the knapsack is : "<< maxValue<<"\n";
}
