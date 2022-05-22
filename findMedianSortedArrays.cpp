#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//暴力法
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it) {
            nums1.push_back(*it);
        }

        sort(nums1.begin(), nums1.end(), [](const int& a, const int& b) {return a < b; });

        //if (nums1.size() == 0) return 0;   提示：1 <= m + n <= 2000

        int mid = (nums1.size()-1) / 2;
        if (nums1.size() % 2 == 1) {
            return nums1[mid];
        }
        else {
           return (nums1[mid] + nums1[mid+1]) / 2.0;
        }

    }
};


//出队标记
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();

        size_t mid = (m + n - 1) / 2;    //中间数坐标, 1 <= m + n <= 2000
        int mid1 = 0, mid2 = 0;    //标记出队

        for (size_t i = 0; i <= mid; ++i) {
            if (nums1.size() >= 1 && nums2.size() >= 1) {
                if (nums1[0] < nums2[0]) {
                    mid1 = nums1[0];
                    nums1.erase(nums1.begin());
                }
                else
                {
                    mid1 = nums2[0];
                    nums2.erase(nums2.begin());
                }
            }
            else if (nums1.size() >= 1 && nums2.size() == 0) {          //一个已经为空
                mid1 = nums1[0];
                nums1.erase(nums1.begin());
            }
            else if (nums2.size() >= 1 && nums1.size() == 0) {
                mid1 = nums2[0];
                nums2.erase(nums2.begin());
            }
        }

        if ((m + n) % 2 == 1) {
            return mid1;
        }
        else {   //求均值
            if (nums1.size() >= 1 && nums2.size() >= 1) {
                if (nums1[0] < nums2[0]) {
                    mid2 = nums1[0];
                    nums1.erase(nums1.begin());
                }
                else
                {
                    mid2 = nums2[0];
                    nums2.erase(nums2.begin());
                }
            }
            else if (nums1.size() >= 1 && nums2.size() == 0) {                //一个已经为空
                mid2 = nums1[0];
                nums1.erase(nums1.begin());
            }
            else if (nums2.size() >= 1 && nums1.size() == 0) {
                mid2 = nums2[0];
                nums2.erase(nums2.begin());
            }

            return (mid1 + mid2) / 2.0;
        }

    }
};


int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,5,6};
    double midNum = 0;

    //Solution1 s1;
    //double midNum_s1 = s1.findMedianSortedArrays(nums1, nums2);

    Solution2 s2;
    midNum = s2.findMedianSortedArrays(nums1, nums2);

    cout <<endl<< "****************" << endl;
    //cout << "midNum: " << midNum<< endl;
    cout << "midNum: " << midNum << endl;
    system("pause");
    return 0;
}