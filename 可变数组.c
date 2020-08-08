#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int *array;
	int size;
}Array;
const int BLOCK_SIZE = 10;
Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
void array_inflate(Array *a,int more_size);

Array array_create(int init_size)
{
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int)*init_size);
	return a; 
}

void array_free(Array *a)
{
	free(a->array);
	a->size = 0;
	a->array = NULL;
}

//·â×° 
int array_size(const Array *a)
{
	return a->size; 
}

int *array_at(Array *a,int index)
{
	if(index >= a->size)
	array_inflate(a, ((index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size));
	return &(a->array[index]);
}

void array_inflate(Array *a,int more_size)
{
int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
int i;
memcpy(p,a->array,a->size*sizeof(int));
//for(i = 0 ;i < a->size;i++ )
//{
//	p[i] = a->array[i];
//}
free(a->array);
a->array = p;
a->size += more_size;
}
void print(Array *a,int count)
{
	int j; 
	for( j = 0;j < count;j++)
	printf("%d ",a->array[j]);
}

int main()
{
	Array a = array_create(5);
	printf("%d\n",array_size(&a));
	*array_at(&a,0) = 1; 
	printf("%d\n",*array_at(&a,0));
	int num;
	int count = 0;
	while(num != -1){
		scanf("%d",&num);
		if(num != -1)
		*array_at(&a,count++) = num;

	}	
	print(&a,count);
	array_free(&a);
	
	return 0;
}

