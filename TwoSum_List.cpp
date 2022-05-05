#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>
#include<complex>
#include<unordered_map>
#include<vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> result;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0, base = 0, num = 0;

        if ((l1 != NULL) && (l2 != NULL)) {       //初始化头结点
            num = (*l1).val + (*l2).val;
            carry = num / 10;
            base = num % 10;

            tail = new ListNode(base);
            head = tail;

            l1 = l1->next;
            l2 = l2->next;
        }


        while ((l1 != NULL) && (l2 != NULL)) {             
            num   = (*l1).val + (*l2).val + carry;  //加上进位
            carry = num / 10;
            base  = num % 10;

            tail->next  = new ListNode(base);
            tail = tail->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        //处理不等长部分
        while(l1) {
            num = (*l1).val + carry;
            carry = num / 10;
            base = num % 10;

            tail->next = new ListNode(base);
            tail = tail->next;

            l1 = l1->next;
        }

        while (l2) {
            num = (*l2).val + carry;
            carry = num / 10;
            base = num % 10;

            tail->next = new ListNode(base);
            tail = tail->next;

            l2 = l2->next;
        }

        if (carry) {   //处理最后进位
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return head;

    }
};
int main()
{
    Solution s;
    ListNode* head;

    //l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
    //    [8, 9, 9, 9, 0, 0, 0, 1]
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(9);

    ListNode* t1 = l1;
    ListNode* t2 = l2;

    for (int i = 0; i < 6; ++i) {
        t1->next = new ListNode(9);
        t1 = t1->next;
    }

    for (int i = 0; i < 3; ++i) {
        t2->next = new ListNode(9);
        t2 = t2->next;
    }

    head = l1;

    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;

    head = l2;

    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]"<<endl;

    head = s.addTwoNumbers(l1, l2);

    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "]"<<endl;

    system("pause");
    return 0;
}