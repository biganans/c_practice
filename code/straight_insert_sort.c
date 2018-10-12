//直接插入算法
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

void straight_insert_sort(int* list,int lenght)
{
    print_list(list,lenght);
    int i=0,j=0;
    int k = 0;
    int tmp = 0;
    for (i=1;i<lenght;i++)
    {
        tmp = list[i];
        j=i-1;
        //直接进行位置交换
        while(list[j] > tmp && j >= 0)
        {
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = tmp;
        print_list(list,lenght);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {7,4,-2,19,13,42,6,20};
    int lenght = 8;
    straight_insert_sort(a,lenght);
    return 0;
}
