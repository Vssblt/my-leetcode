/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *pointer1 = l1, *pointer2 = l2;

		if (pointer1 == nullptr && pointer2 == nullptr)
			return nullptr;
		
		ListNode *ret = new ListNode;
		ListNode *pointer = ret;
		ListNode *lastPointer = nullptr;
		int n = 0;

		while (1)
		{
			int val1 = 0, val2 = 0;

			if (pointer1 == nullptr && pointer2 == nullptr)
				break;

			pointer1 == nullptr ? val1 = 0 : val1 = pointer1->val;
			pointer2 == nullptr ? val2 = 0 : val2 = pointer2->val;

			pointer->next = new ListNode;
			pointer->next->val = 0;
			pointer->next->next = nullptr;

			pointer->val = (val1 + val2 + n) % 10;
			n = (val1 + val2 + n) / 10;

			lastPointer = pointer;
			pointer = pointer->next;
			if (pointer1 != nullptr)
				pointer1 = pointer1->next;
			if (pointer2 != nullptr)
				pointer2 = pointer2->next;
			
		}
		if (n != 0)
		{
			pointer->val = n;
		} else {
			if (lastPointer != nullptr)
			{
				lastPointer->next = nullptr;
			}
			delete pointer;
		}

		return ret;
	}


};
