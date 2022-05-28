
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr && list2 == nullptr)
			return list1;
		else if (list1 == nullptr)
			return list2;
		else if (list2 == nullptr)
			return list1;

		ListNode* p1, * p2, * head, * pre;
		if (list1->val > list2->val) {
			p1 = list1;
			p2 = list2->next;
			head = list2;
			pre = head;
		}
		else {
			p1 = list1->next;
			p2 = list2;
			head = list1;
			pre = head;
		}

		while (p1 != nullptr && p2 != nullptr)
			if (p1->val > p2->val) {
				pre->next = p2;
				p2 = p2->next;

			}
			else {
				pre->next = p1;
				p1 = p1->next;
			}

		pre->next = p2 == nullptr ? p1 : p2;

		return head;
	}
};