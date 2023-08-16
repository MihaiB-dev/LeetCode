//Link: https://leetcode.com/problems/roman-to-integer/

//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

#include <iostream>
#include <string>
using namespace std;
class Romans {
short transform(char l){
        if(l == 'I')return 1;
        
        if(l =='V')return 5;
        
        if(l == 'X')return 10;
        
        if(l == 'L')return 50;
        
        if(l == 'C')return 100;
        
        if(l == 'D')return 500;
        
        return 1000;
    }
public:
int romanToInt(string s) {
    short number = 0,i;
    if(s.size() == 1){return transform(s[0]);} //when we have a single symbol
    
    for(i = 0; i < s.size() - 1; i++){
        if((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
            ||(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
            ||(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')))
        {number += transform(s[i+1])- transform(s[i]); i++;}
        else {number += transform(s[i]);}
    
    }
    //we went till the s.size() - 2 in the for, we verify in the end if the last symbol was written or not.
    if(i == s.size() - 1)number += transform(s[s.size() - 1]);
    return number;
}
}


int main(){
    string roman;
    cin>>roman;

    Romans solution;

    cout<<solution.romanToInt(roman);
    return 0;
}
