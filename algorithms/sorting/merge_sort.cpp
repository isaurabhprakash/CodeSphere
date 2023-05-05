#include <iostream>
#include <vector>

std::vector<int> Merge(std::vector<int> pLeftSubArray, std::vector<int> pRightSubArray)
{
    int                 left_arr_idx   = 0;
    int                 right_arr_idx  = 0;
    int                 merged_arr_idx = 0;
    std::vector<int>    merged_arr;

    while (left_arr_idx < pLeftSubArray.size() && right_arr_idx < pRightSubArray.size()) {

        if (pLeftSubArray[left_arr_idx] < pRightSubArray[right_arr_idx]) {

            merged_arr.push_back(pLeftSubArray[left_arr_idx]);
            ++left_arr_idx;
        } else {

            merged_arr.push_back(pRightSubArray[left_arr_idx]);
            ++right_arr_idx;
        }
    }

    if (left_arr_idx < pLeftSubArray.size()) {

        for (int idx = left_arr_idx; idx < pLeftSubArray.size(); ++idx) {

            merged_arr.push_back(pLeftSubArray[idx]);
        }
    } else {

        for (int idx = right_arr_idx; idx < pRightSubArray.size(); ++idx) {

            merged_arr.push_back(pRightSubArray[idx]);
        }
    }

    return merged_arr;
}

std::vector<int> MergeSort(std::vector<int> pArray, int pLeft, int pRight)
{
    int mid;
    std::vector<int> left_sub_arr;
    std::vector<int> right_sub_arr;

    if (pArray.size() == 1) {

        return pArray;
    }

    mid = pLeft + ((pRight - pLeft) / 2);

    for (int i = pLeft; i <= mid; ++i) {

        left_sub_arr.push_back(pArray[i]);
    }

    for (int i = mid + 1; i <= pRight; ++i) {

        right_sub_arr.push_back(pArray[i]);
    }

    left_sub_arr  = MergeSort(left_sub_arr, 0, left_sub_arr.size() - 1);
    right_sub_arr = MergeSort(right_sub_arr, 0, right_sub_arr.size() - 1);

    return Merge(left_sub_arr, right_sub_arr);
}

int main()
{
    int                 size_of_arr;
    std::vector<int>    arr;
    std::vector<int>    sorted_arr;

    std::cout << "Enter the size of the arrary : ";
    std::cin >> size_of_arr;

    std::cout << "Enter the elements of the arrary : ";
    for (int idx = 0; idx < size_of_arr; ++idx) {

            int ele;

        std::cin >> ele;
        arr.push_back(ele);
    }

    sorted_arr = MergeSort(arr, 0, arr.size() - 1);

    std::cout << "The sorted array is : ";
    for (auto ele : sorted_arr) {
        std::cout << ele << " ";
    }
}