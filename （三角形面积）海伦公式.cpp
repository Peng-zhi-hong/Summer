/*S=√[p(p-a)(p-b)(p-c)] 
　　而公式里的p为半周长： 
　　p=(a+b+c)/2*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    float eadge[3];
    float area;
    struct node * pnext;
} Node;

void compute_area(Node * p);
void list_tail_insert(Node ** pphead, Node ** pptail, Node * p);
void list_print(Node * phead);

int main(){
    Node * phead = NULL, * ptail = NULL;
    int n, i;
    scanf("%d", &n);
    getchar(); // 取出输入缓冲区的回车符
    for(i = 0; i < n; i++){
        Node * pnew = (Node *)calloc(1, sizeof(Node));
        scanf("%f %f %f", &pnew->eadge[0], &pnew->eadge[1], &pnew->eadge[2]);
        compute_area(pnew);
        list_tail_insert(&phead, &ptail, pnew);
    }
    list_print(phead);

    free(phead);
    free(ptail);
    return 0;
}

void compute_area(Node * p){
    float a, b, c;
    float q; //半周长
    a = p->eadge[0];
    b = p->eadge[1];
    c = p->eadge[2];
    if(a + b < c || a + c < b || b + c < a || abs(a - b) > c || abs(a - c) > b || abs(b - c) > a){
        p->area = 0;
    }else{
        q = (a + b + c) / 2;
        p->area = sqrt(q * (q - a) * (q - b) * (q - c));
    }
    return;
}
void list_tail_insert(Node ** pphead, Node ** pptail, Node * p){
    if(* pphead == NULL){
        * pphead = p;
        * pptail = p;
    }else{
 
        (* pptail)->pnext = p;
    }
    return;
}

void list_print(Node * phead){
    while(phead != NULL){
        printf("S=%.2f\n", phead->area);
        phead = phead->pnext;
    }
    return;
}

