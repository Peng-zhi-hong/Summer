/*��Ŀ��ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��*/

/*˼·������ǰ��ָ�붼��ָ��ͷ��㣬��ָ�����ƶ�����K����㣬��ôǰ��ָ
���ʱ���K��λ�á�ͬ�����ƣ�����ָ��ָ����βʱ��ǰָ�����Ȼָ������K����� .*/

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

printf("����k:");
scanf("%d",&k);
	while (k--){
		t = t->next;
	}
	while (t){
		t = t->next;
		p = p->next;
	}
printf("������k�� = %d\n",p->val);

	 
	
} 
