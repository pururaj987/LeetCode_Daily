// https://leetcode.com/problems/group-anagrams/description/

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Approach - 
// 1. Anagrams are those strings which have same characters with same frequency.
// 2. So , basically we create a map with key as a string and value as a vector of string.
// 3. For every string in original array , we will calculate its sorted version and call it temp and lets call orginal string as str , so we will push str to map where key is temp.
// 4. After that , just loop in map and push the vectors to ans 2d vector.

// TC - O(n * klogk) , n - size of input array , k -- size of each string
// SC - O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string , vector<string>> mp;
        for(auto str: arr) {
            string temp = str;
            sort(temp.begin() , temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};