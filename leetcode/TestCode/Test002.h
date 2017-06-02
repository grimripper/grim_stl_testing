#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* l1_curr = l1, *l2_curr = l2, *l3_head = NULL, *l3_curr = NULL;
		while (l1_curr || l2_curr || carry)
		{
			int sum = carry;
			if (l1_curr)
			{
				sum += l1_curr->val;
				l1_curr = l1_curr->next;
			}
			if (l2_curr)
			{
				sum += l2_curr->val;
				l2_curr = l2_curr->next;
			}

			ListNode* new_node = new ListNode(sum % 10);
			carry = sum / 10;

			if (l3_curr)
			{
				l3_curr->next = new_node;
				l3_curr = l3_curr->next;
			}
			else
			{
				l3_curr = new_node;
				l3_head = l3_curr;
			}
		}

		return l3_head;
	}
};

class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode preHead{ 0 };
		int carry = 0;
		ListNode* l1_curr = l1, *l2_curr = l2, *l3_curr = &preHead;
		while (l1_curr || l2_curr || carry)
		{
			int a = l1_curr ? l1_curr->val : 0;
			int b = l2_curr ? l2_curr->val : 0;
			int sum = carry + a + b;

			l3_curr->next = new ListNode(sum % 10);
			l3_curr = l3_curr->next;

			carry = sum / 10;
			l1_curr = l1_curr ? l1_curr->next : NULL;
			l2_curr = l2_curr ? l2_curr->next : NULL;
		}

		return preHead.next;
	}
};

void run()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* l3 = Solution2().addTwoNumbers(l1, l2);
	cout << l3->val << l3->next->val << l3->next->next->val << endl;
}
