#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

		vector<ListNode*> groupHeads;
		ListNode* tmpGroupHead = nullptr;
		{
			int flag = 1;
			auto curr = head;
			tmpGroupHead = head;
			while (curr->next != nullptr) {
				curr = curr->next;
				++flag;
				if (flag == k) {
					groupHeads.push_back(tmpGroupHead);
					flag = 0;
					tmpGroupHead = curr->next;
				}
			}
		}

		for (auto it = groupHeads.rbegin(); it != groupHeads.rend(); ++it) {
			auto pre = *it, curr = pre->next;
			pre->next = tmpGroupHead;

			int flag = 1;
			while (flag < k)
			{
				auto tmp = curr->next;
				curr->next = pre;
				pre = curr;
				curr = tmp;
				++flag;
			}
			tmpGroupHead = pre;
		}

		return tmpGroupHead;
	}
};