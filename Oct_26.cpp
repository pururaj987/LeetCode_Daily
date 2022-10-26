// https://leetcode.com/problems/continuous-subarray-sum/

// Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

// Approach - 
// 1. In this question , we will use a property of remainder.
// 2. We will maintain the sum upto every index i.e prefix sum and take the remainder when that sum is divided by k and store it in map along with index.
//    Ex - 23 % 6 = 5 and (23 + 6) % 6 = 5 and (23 + 6 + 6) % 6 = 5
//    This means that remainder of two sums will be same only when k or a multiple of k is added to themm.
// 3. For every sum , we will check if remainder is already present and if it is we take the difference of indexes to check if it is >= 2.
// 4. If difference is >= 2 , we return true else we check for further indexes.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int , int> mp;
        mp[0] = -1;
        for(int i = 0 ; i < nums.size() ; ++i) {
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end()) {
                // if sizr of subarray is >= 2
                if(i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};