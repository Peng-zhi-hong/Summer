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
		 	printf("请输入：");
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
					 printf("建立成功，按任意键返回主菜单。。。");
						getchar();
						getchar();}
					 break;
				case 2:
					printf("输入查找的数据：");
				   scanf("%d",&number);
				   int isfound;
				   isfound = search(&list,number);
				   getchar();
				if(isfound){ 
					   printf("该数据存在");
					   printf("是否要删除：[y/n]");
					   scanf("%c",&ch);
					   if(ch == 'y' || ch == 'Y'){
					   		if(list.head == NULL)
							 	 {
							 	    printf("这是个空链表，按任意键返回主菜单。。。");
							        getchar();
							        getchar();
							 	
								  }
							else{
	
							   	 deleted(&list,number);
							   	 printf("删除成功,按任意键返回主菜单。。。。");
							   	 getchar();
		                         getchar();  }
					   }
					} 
				else{

					    printf("该数据不存在,按任意键返回主菜单。。。。");
					    getchar();
                        getchar();}
					    break;
				case 3:
						if((list.head == NULL)||(list.head->next == NULL))
						 	 {
						 	    printf("这是个空链表，按任意键返回主菜单。。。");
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
 //菜单 
 void menu()
 {
 	printf("1, 添加数据     2，查找输入的数据是否存在,若存在可选择删除\n");
 	printf("3，显示所有数据 4， 清空所有数据\n");
 	printf("other:退出"); 
 }
 
 //添加数据 
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
//查找数据是否存在 
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
//删除数据 
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
//清空所有数据 
void clear(List *plist){
        Node *p;
		Node *q;
		q = NULL;
		for(p = plist->head; p ; p=q)
		{
			q = p->next;
			free(p);
			}
		
			printf("清空成功，按任意键返回主菜单。。。。");
			getchar();
            getchar();
            
		

}
//显示所有数据	
void print(List *plist)
{
      
    Node *p;
	for( p = plist->head; p ;p = p->next)
		 {
		 	printf("%d\t",p->value);
		 }
		 printf("\n");
		 printf("按任意键返回主菜单。。。"); 
		 getchar();
         getchar();

}
