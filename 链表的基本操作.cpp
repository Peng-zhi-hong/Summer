#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
	
	int value;
	struct _node *next;
	
 } Node;
 
typedef struct _list{

 	Node *head;
 	Node *tail;
 	
 }List;
 
void menu();
int search(List *plist,int number);
void deleted(List *plist,int number);
void clear(List *plist);
void print(List *plist);
void add(List *plist,int number);

int main(int argc,char const *argv[])
 {
	 	List list;
	 	list.head = list.tail = NULL;
	 	int choice;
	 	char ch;
	 	
		while(1)
		{
		 	menu();
		 	printf("�����룺");
		 	scanf("%d",&choice);
		 	switch(choice)
		 	{  
		 		case 1:	
				    int number;
				 	do{
				 		scanf("%d",&number);
				 		if(number != -1)
				 		{
				 			add(&list,number);
						 }
					 }while(number != -1);
					 if(number == -1)
					 {
					 printf("�����ɹ�����������������˵�������");
						getchar();
						getchar();}
					 break;
				case 2:
					printf("������ҵ����ݣ�");
				   scanf("%d",&number);
				   int isfound;
				   isfound = search(&list,number);
				   getchar();
				if(isfound){ 
					   printf("�����ݴ���");
					   printf("�Ƿ�Ҫɾ����[y/n]");
					   scanf("%c",&ch);
					   if(ch == 'y' || ch == 'Y'){
					   		if(list.head == NULL)
							 	 {
							 	    printf("���Ǹ���������������������˵�������");
							        getchar();
							        getchar();
							 	
								  }
							else{
	
							   	 deleted(&list,number);
							   	 printf("ɾ���ɹ�,��������������˵���������");
							   	 getchar();
		                         getchar();  }
					   }
					} 
				else{

					    printf("�����ݲ�����,��������������˵���������");
					    getchar();
                        getchar();}
					    break;
				case 3:
						if((list.head == NULL)||(list.head->next == NULL))
						 	 {
						 	    printf("���Ǹ���������������������˵�������");
						        getchar();
						        getchar();
						 	
							  }
				    	else
					       print(&list);
					   break;
					   
				case 4:
					clear(&list);
				            break;
				default:
					 return 0;
			 }	
			 system("cls") ;
		 }
				 return 0;
		 }
 //�˵� 
 void menu()
 {
 	printf("1, �������     2����������������Ƿ����,�����ڿ�ѡ��ɾ��\n");
 	printf("3����ʾ�������� 4�� �����������\n");
 	printf("other:�˳�"); 
 }
 
 //������� 
 void add(List *plist,int number){
 
		 Node *p = (Node*)malloc(sizeof(Node));
		 			p->value = number;
		 			p->next = NULL;
		 		plist->tail = plist->head;
		// 			while(last->next){
		// 				last = last->next;
		//			 }
		 if(plist->tail)
		 {
		 		while(plist->tail->next){
		 			plist->tail = plist->tail->next;
					 }	
					 plist->tail->next = p;					 
		 }
		 else
		 {
		 	plist->head = p;
		 
		 }
}
//���������Ƿ���� 
int search(List *plist,int number){
	     Node *p;
	     int isFound = 0;
	     for( p = plist->head; p ;p = p->next)
		 {
		 if(p->value == number)
		 {
		 	isFound = 1;
		 return isFound;
		 	} 
		 	
		 }
		 return isFound;
}
//ɾ������ 
void deleted(List *plist,int number){
		 Node *q,*p;
		 for(q = NULL,p=plist->head;p;q=p,p=p->next){
		 	if(p->value == number){
			 if(q){
		 	    q->next = p->next;
			 }else{
			 	plist->head = p->next;
			 }	
		    free(p);
		 	break;
			 }
			}
}
//����������� 
void clear(List *plist){
        Node *p;
		Node *q;
		q = NULL;
		for(p = plist->head; p ; p=q)
		{
			q = p->next;
			free(p);
			}
		
			printf("��ճɹ�����������������˵���������");
			getchar();
            getchar();
            
		

}
//��ʾ��������	
void print(List *plist)
{
      
    Node *p;
	for( p = plist->head; p ;p = p->next)
		 {
		 	printf("%d\t",p->value);
		 }
		 printf("\n");
		 printf("��������������˵�������"); 
		 getchar();
         getchar();

}
