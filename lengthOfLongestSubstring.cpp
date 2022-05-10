class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {   //容错
            return 0;
        }

        unordered_map<char, int> hashtable;
        int maxLen = 0, curLen = 0, startIndex = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            if (hashtable.find(s[i]) == hashtable.end()) {
                ++curLen;                         //扩充长度
                hashtable[s[i]] = i;
            }
            else {
                if (curLen > maxLen)    maxLen = curLen;
                startIndex = max(startIndex, hashtable[s[i]]);    //滑动窗口无重复 hashtable[s[i]  缩减两个重复字符之间距离，窗口内已有其它有重复字符(如： abba)则基于上一次startIndex缩减
                
                curLen = i - startIndex;         //缩减长度

                hashtable[s[i]] = i;
            }
        }

        if (curLen > maxLen) maxLen = curLen;

        return maxLen;
    }
};