// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.

// Approach - 
// 1. Since we need to check all the subsequences , we can use recursion and for every string , if it contains unique characters we can either select it or not
//    and if it has repeated characters , we will not select it.
// 2. To check for uniqueness , we will concatenate curr string and arr[i].
// 3. For uniqueness checking - 
//    3.a - Take an integer checker and set it to 0.
//    3.b - Since the integer is of 32 bits and we only need to check for 26 characters , we will convert char in string to integer and set its bit in checker to 1.
//    3.c - For every char , convert to char and check if (checker && (1 >> val) > 0) - if it is true , then char is repeated otherwise set bit to 1 by doing (checker |= (1 >> val)).

class Solution {
public:
    int solve(int i , int n , vector<string> &arr, string curr) {
        if(i >= n) {
            return curr.size();
        }
        string temp = arr[i] + curr;
        int checker = 0;
        for(auto c : temp) {
            int val = c - 'a';
            if((checker & (1 << val)) > 0) {
                return solve(i+1 , n , arr , curr);
            }
            checker |= (1 << val);
        }
        return max(solve(i+1 , n , arr , temp) , solve(i+1 , n , arr , curr));
    }
    int maxLength(vector<string>& arr) {
        string curr = "";
        int i = 0;
        return solve(i , arr.size() , arr , curr);
    }
};