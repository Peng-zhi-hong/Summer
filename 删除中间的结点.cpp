/*题目：实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。*/
 
/*思路：由于无法访问前驱节点，我们应将下一节点的值赋予当前节点，然后删除下一节点。*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
  };

void deleteNode(struct ListNode* node) {
    struct ListNode* temp = node->next;
   node->val = node->next->val;
    node->next = node->next->next;
    free(temp);
}
int main()
{
	int val;
	struct ListNode  *p= (struct ListNode*)malloc(sizeof(struct ListNode)+1);
	struct ListNode  *head = p;
	p->next = NULL;
	for(int i=1;i<10;i++)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = i;
	}
	p->next = NULL;
	p= head;
	scanf("%d",&val);
	p = head;
	for(p = head -> next;p!=NULL;p = p -> next){
		if(p->val == val)
		deleteNode(p);
		
	}

	 	for(p = head -> next;p!=NULL;p = p -> next)
	
	  printf("\n%d\n",p->val);
	
	 
} 
