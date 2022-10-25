// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// A string is represented by an array if the array elements concatenated in order forms the string.

// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "" , s2 = "";
        for(auto str: word1)
            s1 += str;
        for(auto str: word2)
            s2 += str;
        return s1 == s2;
    }
};


// Approach 2 - Keep 4 pointers
// TC - O(N)
// SC - O(1)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // keep track of current chars in string
        int i = 0 , j = 0;
        // keep track of current string
        int st1 = 0 , st2 = 0;
        while(st1 < word1.size() && st2 < word2.size()) {
            int curr_len_first = word1[st1].size();
            int curr_len_second = word2[st2].size();
            while(i < curr_len_first && j < curr_len_second) {
                // if currrent characters don't match
                if(word1[st1][i] != word2[st2][j]) {
                    return false;
                }
                i++ , j++;
            }
            // if first string is smaller , move to next string in first array and reset i to 0
            if(i == curr_len_first) {
                i = 0;
                st1 ++;
            }
            // do same thing with j as well
            if(j == curr_len_second) {
                j = 0;
                st2 ++;
            }
        }
        return (st1 == word1.size() && st2 == word2.size());
    }
};