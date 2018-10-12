//简单排序(直接选择排序) 不稳定排序
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

void simple_selection_sort(int* list,int lenght)
{
    //后面的比前面选定的数小则交换位置
    int j = 0;
    int k = 0;
    int temp = 0;
    for (int i=0;i<lenght;i++)
    {
        k = i;
        for (j=i+1;j<lenght;j++)
        {
            if (list[j] < list[i])
            {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }

        print_list(list,lenght);
    }
}

int main(int argc, char const *argv[])
{
    int list[] = {7,4,-2,19,13,6};
    int lenght = 6;
    print_list(list,lenght);
    simple_selection_sort(list,lenght);
    return 0;
}
