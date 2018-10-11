//快速排序
#include <stdio.h>

void print_list(int* list,int lenght)
{
    for (int i=0;i<lenght;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

void quick_ome_pass(int* list,int lenght,int low,int high)
{
    int temp = list[low];
    int i=low;
    int j = high;
    if (low > high)
    {
        return;
    }

    while (i != j)
    {
        //从右边找到比temp小的
        while(i<j && list[j] > temp)
        {
            j--;
        }
        //把左边的值赋值成比temp小的那个数
        if (i<j)
        {
            list[i] = list[j];
        }
        //从左边找比temp大的
        while(i<j && list[i] < temp)
        {
            i++;
        }
        if (i<j)
        {
            //把右边的值赋值比temp大的数
            list[j] = list[i];
        }
    }
    //最后把temp的值放位置
    list[i] = temp;

    print_list(list,lenght);

    //分别递归当前分割线的左右两边继续排序
    quick_ome_pass(list,lenght,low,i-1);
    quick_ome_pass(list,lenght,i+1,high);

}

void quick_sort(int* list,int lenght)
{
    print_list(list,lenght);
    //先确定一个数然后两边找，左边找比数小的index，右边找比数大的index，然后交叉记录直到左右index重合，起到一个分界的作用
    quick_ome_pass(list,lenght,0,lenght-1);
}

int main(int argc, char const *argv[])
{
    int list[] = {29,38,22,45,23,67,31};
    int lenght = 7;
    quick_sort(list,lenght);
    return 0;
}
