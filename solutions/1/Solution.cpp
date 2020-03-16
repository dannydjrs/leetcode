#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;

        int i;
        int length = nums.size();

        for (i = 0; i < length; i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m.find(target - nums[i])->second, i};
            }

            m[nums[i]] = i;
        }

        return {0,0};
    }
};
