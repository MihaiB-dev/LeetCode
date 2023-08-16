//Link : https://leetcode.com/problems/majority-element/

// Given an array nums of size n, return the majority element.

//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

//Example:
//Input: nums = [3,2,3]
//Output: 3

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = nums[0], counter = 1;
        if(nums.size() == 1){return number;}
        
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] == number){counter ++;}
            else {counter --;}
            
            if(counter == -1){number = nums[i]; counter = 1;}
        }
        return number;
    }
};

int main(){
    Solution solution ;
    vector<int> elements(1,1,1,3,3,3,3);
    cout << solution.majorityElement(elements);
    return 0;
}