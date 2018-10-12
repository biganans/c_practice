//冒泡算法 稳定排序
//O(n^2)
#include <stdio.h>

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void bubble_sort(int* list,int length)
{
    print_list(list,length);
    int i=0,j=0;
    int temp = 0;
    int flag = 0;
    for (i=0;i<length;i++)
    {
        flag = 1;
        //把最大的数冒泡到最后面 i代表已经冒泡了的个数
        for (j=0;j<length-i-1;j++)
        {
            if (list[j+1] < list[j])
            {
                flag = 0;
                //change
                temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
        //说明当前已经是排序完毕
        if (1 == flag)
        {
            break;
        }
        print_list(list,length);
    }
}

int main(int argc, char const *argv[])
{
    int list[] = {23,38,22,45,23,67,31,15,41};
    int length = 10;
    bubble_sort(list,length);
    return 0;
}
