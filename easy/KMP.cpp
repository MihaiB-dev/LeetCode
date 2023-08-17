//Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
//or -1 if needle is not part of haystack.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())return -1;
        
        //We will use KMP for this problem
        //Time complexity : O(haystack.size() + needle.size())
        //Memory complexity: O(needle.size())
        
        //Create the table for needle
        //Index: -1 0 1 2 3 4 5 6 7 8 9
        //Example : a b c d a b e a b f
        //         -1-1-1-1 0 1-1 0 1-1
        
        vector<short> table(needle.size(), -1); 
        short i = 0; //index for the beginning
        short j = 1; //index for each letter
        while(j != needle.size()){
            if(needle[j] == needle[i]){
                i++;
                table[j] = i - 1;
                j++;
            }
            else {
                if(i == 0){
                    j++;
                }else{
                    i = table[i-1] + 1;
                }   
            } 
        }
        
        j = -1;
        for(i = 0; i < haystack.size(); i++){
            if(needle[j+1] == haystack[i]){
                j++;
            }
            else
            {   
                while(true){
                    if(j == -1)break;
                    
                    j = table[j];
                    if(needle[j+1] == haystack[i]){j++; break;}
                }
            }
            if(j == needle.size() - 1)return i - j;
        }
        
    return -1;   
    }
};

int main(){

    Solution solution;

    string a = "aabaaabaaac";
    string b = "aabaaac";
    cout << solution.strStr(a,b);

    return 0;
}
