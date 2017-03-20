//#include<iostream>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode * next;
//	ListNode(int x) : val(x), next(NULL) {};
//};
//class Solution
//{
//public:
//	ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
//	{
//		ListNode list(0);
//		while (l1)
//		{
//			int val = l1->val + l2->val;
//			ListNode li(val);
//			li.next = list.next;
//			list.next = &li;
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		return list.next;
//	}
//};
//
//int main()
//{
//	ListNode node0(0);
//	ListNode node1(1);
//	ListNode node2(2);
//	node0.next = &node1;
//	node1.next = &node2;
//	//----------------------
//	ListNode node3(3);
//	ListNode node4(4);
//	ListNode node5(5);
//	node3.next = &node4;
//	node4.next = &node5;
//	Solution solution;
//	ListNode * result = solution.addTwoNumbers(&node0, &node3);
//}