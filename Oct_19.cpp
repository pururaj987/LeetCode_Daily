// https://leetcode.com/problems/top-k-frequent-words/description/

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;
        for(auto word : words) {
            mp[word] ++;
        }
        vector<pair<string,int>> v;
        for(auto it : mp) {
            v.push_back(it);
        }
        sort(v.begin() , v.end() , [](const pair<string,int> &a , const pair<string,int> &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        });
        vector<string> ans;
        for(auto it : v) {
            k--;
            ans.push_back(it.first);
            if(k == 0) {
                break;
            }
        }
        return ans;
    }
};