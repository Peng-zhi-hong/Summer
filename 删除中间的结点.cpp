/*��Ŀ��ʵ��һ���㷨��ɾ�����������м��ĳ���ڵ㣨�����ǵ�һ�������һ���ڵ㣩���ٶ���ֻ�ܷ��ʸýڵ㡣*/
 
/*˼·�������޷�����ǰ���ڵ㣬����Ӧ����һ�ڵ��ֵ���赱ǰ�ڵ㣬Ȼ��ɾ����һ�ڵ㡣*/
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
