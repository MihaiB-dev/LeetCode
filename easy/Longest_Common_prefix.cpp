// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string final = strs[0];
        
        //for each word
        for(short i = 1; i < strs.size(); i++)
        {   bool ok = false;
            
            //verify if there is a suffix to try
            if(final.size() == 0)return final;
         
            //for each letter from the word
            for(short j = 0; j < strs[i].size(); j++){
                if(strs[i][j] != final[j]){
                    ok = true;
                    
                    //pop from the suffix till remains the common one
                    for(short contor = final.size() - j; contor > 0; contor --)final.pop_back();    
                }
            }
            //if the curreent word is a smaller part of the "final", it becomes the new suffix.
            if(strs[i].size() < final.size() && ok == 0)final = strs[i];
        }
        
        return final;
    }
};

int main(){
    vector<string> strs("flower","flow","flight");
    Solution solution;
    cout << solution.longestCommonPrefix(strs);
    return 0;
}