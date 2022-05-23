
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		auto prev = head, current = head -> next;
		head->next = nullptr;
		while (current != nullptr)
		{
			auto tmp = current->next;
			current->next = prev;
			prev = current;
			current = tmp;
		}

		return prev;
	}
};