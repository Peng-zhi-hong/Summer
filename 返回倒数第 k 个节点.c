/*题目：实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。*/

/*思路：设置前后指针都先指向头结点，后指针先移动到第K个结点，那么前后指
针此时相距K个位置。同步后移，当后指针指向链尾时，前指针就自然指向倒数第K个结点 .*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;
      struct ListNode *next;
  };
int main()
{ 
	int k;
	struct ListNode  *p= (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode  *head = p;
	struct ListNode  *t = head;
	p->next = NULL;
for(int i=1;i<10;i++)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = i;
	}
	p->next = NULL;
	p = head; 

printf("输入k:");
scanf("%d",&k);
	while (k--){
		t = t->next;
	}
	while (t){
		t = t->next;
		p = p->next;
	}
printf("倒数第k个 = %d\n",p->val);

	 
	
} 
