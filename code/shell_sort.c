//希尔排序 不稳定排序
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

//d为排序的间距，依次变小
void shell_pass(int* list,int lenght,int d)
{
    int k = 0;
    int temp = 0;
    //需要排序的次数
    for (int i=d;i<lenght;i++)
    {
        temp = list[i];
        k = i-d;
        if (list[k] > temp)
        {
            list[i] = list[k];
            list[k] = temp;
        }
    }
}

void shell_sort(int* list,int lenght)
{
    print_list(list,lenght);
    int d = lenght/2;
    while(d >=1)
    {
        shell_pass(list,lenght,d);
        d = d/2;
        print_list(list,lenght);
    }

}

int main(int argc, char const *argv[])
{
    int a[] = {9,13,8,2,5,13,7,1,15,11};
    int lenght = 10;
    shell_sort(a,lenght);
    return 0;
}
