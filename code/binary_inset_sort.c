//折半插入排序
#include <stdio.h>

void print_list(int* list,int lenght)
{
    for (int i=0;i<lenght;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}


void binary_inset_sort(int* list,int lenght)
{
    print_list(list,lenght);
    int i=0,j=0,low=0,high=0,mid=0;
    int temp = 0;
    for (i=1;i<lenght;i++)
    {
        //low和hight都是记录i以前的最高最低点，只是方便找到插入的位置
        low = 0;
        high = i-1;
        temp = list[i];
        while(low <= high)
        {
            mid = (high+low)/2;
            if (list[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j=i-1;j>=high+1;j--)
        {
            list[j+1] = list[j];
        }
        list[high+1] = temp;

        print_list(list,lenght);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {30,13,70,85,39,42,6,20};
    int lenght = 8;
    binary_inset_sort(a,lenght);
    return 0;
}
