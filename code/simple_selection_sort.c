//简单排序(直接选择排序) 不稳定排序
//T(n) = O(n^2) S(n)=O(1)
#include <stdio.h>

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void simple_selection_sort(int* list,int length)
{
    //后面的比前面选定的数小则交换位置
    int j = 0;
    int k = 0;
    int temp = 0;
    for (int i=0;i<length;i++)
    {
        k = i;
        for (j=i+1;j<length;j++)
        {
            if (list[j] < list[i])
            {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }

        print_list(list,length);
    }
}

int main(int argc, char const *argv[])
{
    int list[] = {7,4,-2,19,13,6};
    int length = 6;
    print_list(list,length);
    simple_selection_sort(list,lenght);
    return 0;
}
