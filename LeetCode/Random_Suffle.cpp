// Shuffle a set of numbers without duplicates. 

class Solution {
public:
    
    vector<int> nums;
    Solution(vector<int>& nums) {
        this-> nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> sa = nums;
        random_shuffle(sa.begin(), sa.end());
        return sa;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */