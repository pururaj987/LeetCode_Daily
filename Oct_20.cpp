// https://leetcode.com/problems/integer-to-roman/description/

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.

class Solution {
public:
    string intToRoman(int num) {
        string arr[4][10] = {{"" , "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX"} , 
                             {"" , "X" , "XX" , "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC"} , 
                             {"" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM"} , 
                             {"" , "M" , "MM" , "MMM"}};

        int count = 0;
        string res = "";
        int n = num;
        while(n) {
            int number = n % 10;
            res = (arr[count][number]) + res;
            count ++;
            n /= 10;
        }
        return res;
    }
};