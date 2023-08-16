//Link: https://leetcode.com/problems/valid-palindrome/

//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
//it reads the same forward and backward. Alphanumeric characters include letters and numbers.

//Given a string s, return true if it is a palindrome, or false otherwise.
// Example:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s) {
        string word;
        for(int i =0; i< s.size(); i++)
            {
            if(s[i] >= 'a' && s[i] <= 'z' || (s[i]>= 'A' && s[i] <= 'Z')){
                word.push_back(tolower(s[i]));
            }
            if(s[i] >='0' && s[i]<='9')word.push_back(s[i]);
        }
        if(word.size() == 0 || word.size() == 1){return true;}
        for(int i =0,j = word.size() -1; i < word.size()/2 && j >= word.size()/2; i++,j--){
           if(word[i] != word[j]) return false;
        }return true;
    }


int main(){
    string element;
    cin>>element;
    cout<<isPalindrom(element);
    return 0;
}


