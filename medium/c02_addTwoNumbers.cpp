
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int data) : val(data), next(nullptr) {}

}ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* result = new ListNode(-1);
	ListNode* cur = result;
	int sum = 0;
	int added = 0;
	int val1 = 0;
	int val2 = 0;
	while (l1 || l2) {
		val1 = (l1 == nullptr) ? 0 : l1->val;
		val2 = (l2 == nullptr) ? 0 : l2->val;
		sum = (val1 + val2 + added);
		added = sum / 10;
		cur->next = new ListNode(sum  % 10);
		cur = cur->next;
		if (l1 != nullptr) l1 = l1->next;
		if (l2 != nullptr) l2 = l2->next;
	}
	if (added != 0)
		cur->next = new ListNode(1);
	return result->next;
}

void PrintListNode(ListNode* l)
{
	ListNode* cur = l;
	while (cur != nullptr) {
		cout << cur->val<< " ";
		cur = cur->next;
	}
}

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	PrintListNode(l1);
	cout << endl;

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	PrintListNode(l2);
	cout << endl;
	
	ListNode * result = addTwoNumbers(l1, l2);
	PrintListNode(result);
	cout << endl;
    return 0;
}