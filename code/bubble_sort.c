//冒泡算法
//O(n^2)
#include <stdio.h>

void print_list(int* list,int lenght)
{
    for (int i=0;i<lenght;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void bubble_sort(int* list,int lenght)
{
    print_list(list,lenght);
    int i=0,j=0;
    int temp = 0;
    int flag = 0;
    for (i=0;i<lenght;i++)
    {
        flag = 1;
        //把最大的数冒泡到最后面 i代表已经冒泡了的个数
        for (j=0;j<lenght-i-1;j++)
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
        print_list(list,lenght);
    }
}

int main(int argc, char const *argv[])
{
    int list[] = {23,38,22,45,23,67,31,15,41};
    int lenght = 10;
    bubble_sort(list,lenght);
    return 0;
}
