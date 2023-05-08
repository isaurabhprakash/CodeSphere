#include<iostream>
#include<vector>
#include<string>

#define MAX_CHAR_LIMIT  255

void CountSort(std::string & pString)
{
        std::vector<char>    count_arr(MAX_CHAR_LIMIT);

    for (auto ch : pString) {

        count_arr[ch]++;
    }

    pString.clear();

    for (int ch = 0; ch < MAX_CHAR_LIMIT; ++ch) {

        for (int ch_count = 0; ch_count < count_arr[ch]; ++ch_count) {

            pString.push_back(ch);
        }
    }
}

int main()
{
        std::string str;
        
    std::cout << "Enter the string to be sorted : ";
    std::cin >> str;

    CountSort(str);
    
    std::cout << "The sorted string is :" << str;
}