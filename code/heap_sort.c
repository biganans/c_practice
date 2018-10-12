//堆排序 不稳定排序
// T(n)=O(nlog2(n)) S(n) = O(1)

#include <stdio.h>

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

//向下过滤
void down(int* list,int index,int end)
{
    int tindex = index;
    int hole = 0;
    int temp = 0;
    while(1)
    {
        hole = 2*tindex + 1;
        if (hole > end)
        {
            break;
        }
        if (hole + 1 <= end && list[hole] < list[hole+1])
        {
            hole ++;
        }
        if (list[tindex] > list[hole])
        {
            break;
        }
        temp = list[tindex];
        list[tindex] = list[hole];
        list[hole] = temp;

        tindex = hole;
    }
}

void heap_sort(int* list,int length)
{
    int temp = 0;
    for(int i=length/2;i>=0;i--)
    {
        down(list,i,length-1);
        print_list(list,length);
    }
    for (int i=0;i<length;i++)
    {
        temp = list[0];
        list[0] = list[length-1-i];
        list[length-1-i] = temp;

        down(list,0,length-2-i);
        print_list(list,length);
    }

}

/* 初始化的堆数据
                    27
            15              19
        18      28      34      65
    49      25 37
*/
int main(int argc, char const *argv[])
{
     //           0  1  2  3  4  5  6  7  8  9
    int list[] = {27,15,19,18,28,34,65,49,25,37};
    int length = 10;
    print_list(list,length);
    heap_sort(list,length);
    return 0;
}

//看图解容易理解，写代码一片迷糊 TOT 借鉴于网上
