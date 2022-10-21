// https://leetcode.com/problems/contains-duplicate-ii/description/

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Input: nums = [1,2,3,1], k = 3
// Output: true

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// Approach:
// 1. Loop through the array and if the index of current number is not in the map , store it there.
// 2. If index is already there , check if the difference of i and stored index in map is <= k. If it is , then return true;
// 3. Else update the stored index with i.
// 4. Its because if (Ex - if difference of 0 and 3 is not less than 2 , then definitely the difference of 0 and 4 i.e. a number greater than 3 will not be less than 2).
// 5. This is why we remove the previous index stored and update it with current index.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            } else if(abs(mp[nums[i]] - i) <= k) {
                return true;
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    } 
};