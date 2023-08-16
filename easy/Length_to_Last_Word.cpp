//Link: https://leetcode.com/problems/length-of-last-word/

// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        short i = s.size() - 1, length = 0;
        
        //if it's not a letter, we rase spaces
        while(s[i] == ' '){i--;}
        
        //we will stop when we will see space or we finish the s;
        while(i != -1 && s[i] != ' '){
            length ++;
            i --;
        }
        return length;
        
    }
};
int main(){
    Solution solution;
    string s;
    cin >> s;
    cout << solution.lengthOfLastWord(s);
    return 0;
}