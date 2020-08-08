#include<stdio.h>
struct point{
	int x;
	int y;
};
struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main()
{
	struct point y = {0,0};
//	getStruct(&y);
//	output(y);
	//µÈ¼ÛÓÚoutput(*getStruct (&y));
	struct point *p = getStruct(&y);

//	print(getStruct(&y));
*p =(struct point){3,4};
	 printf("%d",p->x);
//		print(getStruct(&y));
		}
struct point* getStruct(struct point *p)
{
	scanf("%d",&p->y);

	return p;
}
void output(struct point p)
{
	printf("%d%d\n",p.x,p.y);
}
void print(const struct point *p)
{
	printf("%d%d\n",p->x,p->y);
}

