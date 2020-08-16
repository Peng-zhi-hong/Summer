/*题目：啤酒每瓶p元，cap个瓶盖或者bottle个空酒瓶可以换一瓶啤酒，当瓶盖或者空酒
瓶不足以换取一瓶瓶酒时可以向商家借若干瓶盖或者空酒瓶，只要能够还
得上，请问给你b元，最多可以喝多少瓶瓶酒？*/
/*思路：假设我们最后最多能够喝到N瓶啤酒，那么瓶数N和给定的钱数M还有瓶酒单价P
，可换瓶酒的盖子数cap和空瓶数bottle存在下面的关系：N=N/cap+N/bottle+M/p.
将上式子化简的：N=M/P*cap*bottle/(cap*bottle-cap-bottle)。*/ 
#include<stdio.h>
int  SumBeer(int m, int p, int cap, int bottle); 
int main() {
        int m , p , cap , bottle ;
        printf("输入钱数，啤酒单价，可换啤酒的瓶盖数和瓶子数：");
        scanf("%d%d%d%d",&m,&p,&cap,&bottle);
        if(m >= p){
        if(cap > 1&&bottle >1){
        int drink_sum = SumBeer(m, p, cap, bottle);
        printf("总共可以喝%d瓶",drink_sum);
    }
        else
        printf("可以无限喝！");
    }
    else
    printf("一瓶酒也买不起，别想喝了。");
	}

int  SumBeer(int m, int p, int cap, int bottle) {
        if (m >= p) {
            return (m / p) * cap * bottle / (cap * bottle - cap - bottle);
            
        } else {

            return 0;
        }
    }
