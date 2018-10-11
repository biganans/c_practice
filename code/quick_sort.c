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

//先确定一个数然后两边找，左边找比数小的index，右边找比数大的index，然后交叉记录直到左右index重合，起到一个分界的作用
int quick_ome_pass(int* list,int lenght,int low,int high)
{
    int temp = list[low];
    int i=low;
    int j = high;
    if (low > high)
    {
        return 0;
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

    return i;

}

//递归
void recursive_sort(int* list,int lenght,int low,int high)
{
    int k = 0;
    if (low < high)
    {
        k = quick_ome_pass(list,lenght,low,high);
        //分别递归当前分割线的左右两边继续排序
        recursive_sort(list,lenght,low,k-1);
        recursive_sort(list,lenght,k+1,high);
    }
}

//使用栈来做非递归算法
#define MAX_STACK 300
void quick_sort(int* list,int lenght)
{
    int stack[MAX_STACK] = {0};
    int top = 0;
    int low = 0;
    int high = lenght-1;
    int k = 0;

    do
    {
        while (low < high)
        {
            k = quick_ome_pass(list,lenght,low,high);
            //记录当次的分界点
            stack[top++] = high;
            stack[top++] = k+1;
            //第二个子序，这里相当于只执行了一边的排序，另外一边则直接记录下分界点
            high = k-1;
        }
        //再执行记录下来的其他分段
        if (top != 0)
        {
            low = stack[top--];
            high = stack[top--];
        }
    }
    while (low < high && top!=0);

}

int main(int argc, char const *argv[])
{
    int list[] = {29,38,22,45,23,67,31};
    int lenght = 7;
    print_list(list,lenght);

    // recursive_sort(list,lenght,0,lenght-1);
    quick_sort(list,lenght);
    return 0;
}
