class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
vector<int> result;
        unordered_map<int, int> hashtable;

        for (size_t i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];

            if (hashtable.find(num) != hashtable.end()) {
                result.push_back(hashtable[num]);
                result.push_back(i);
                break;
            }

            hashtable[nums[i]] = i;  //if判断后，再添加至hashtable
        }

        return result;
    }
};