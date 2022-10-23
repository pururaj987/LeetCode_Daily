// https://leetcode.com/problems/set-mismatch/description/

// You have a set of integers s, which originally contains all the numbers from 1 to n. 
// Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Input: nums = [1,2,2,4]
// Output: [2,3]

// Input: nums = [1,1]
// Output: [1,2]

// Approach - 1 -- Using Set
// TC - O(N)
// SC - O(N)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        int repeated = 0;
        int missing = 0;
        for(auto num : nums) {
            if(st.count(num) > 0) {
                repeated = num;
            } else {
                st.insert(num);
            }
        }
        int count = 1;
        for(auto num : st) {
            if(num !=  count) {
                missing = count;
                break;
            } else {
                count ++;
            }
        }
        if(missing == 0) {
            missing = *(st.end()) + 1;
        }
        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }
};

// Approach - 2 -- Without set
// TC - O(NLogN)
// SC - O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        int repeated = 0;
        int missing = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() - 1 ; ++i) {
            if(nums[i] == nums[i+1]) {
                repeated = nums[i];
            }
        }
        int count = 1;
        for(int i = 0 ; i < nums.size();) {
            if(nums[i] != count) {
                missing = count;
                break;
            }
            if(nums[i] == nums[i+1]) {
                i += 2;
            } else {
                i ++;
            }
            count ++;
        }
        if(missing == 0) {
            if(repeated == 1)
                missing = 2;
            else
                missing = nums[nums.size() - 1] + 1;
        }
        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }
};