//归并排序 稳定排序
//T(n) = O(nlog2(n))
//S(n) = O(n)
//有两种方式：从上往下 从下往上 归并

#include <stdio.h>

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

//合并数组
void merge(int* list,int start,int len,int end)
{
    //记录排序后的数组，然后再赋值给原始数组
    int temp[len] = {0};
    int rend = start+len;
    if (rend > end)
    {
        //有可能数据不足
        rend = end;
    }
    int mid = start+len/2;
    int i=start,j=mid;
    int k = 0; //临时数组的下标

    while(i < mid && j < rend)
    {
        if (list[i] > list[j])
        {
            //存后面的数
            temp[k] = list[j];
            j ++;
            k ++;
        }
        else
        {
            //存前面的数
            temp[k] = list[i];
            i ++;
            k ++;
        }
    }
    //前面剩余的数存进来
    while (i < mid)
    {
        temp[k] = list[i];
        k++;
        i++;
    }
    //后面剩余的数存进来
    while (j < rend)
    {
        temp[k] = list[j];
        k ++;
        j ++;
    }
    k = 0;
    for (i=start;i<rend;i++)
    {
        list[i] = temp[k];
        k ++;
    }

}

void merge_pass(int* list,int len,int end)
{
    //和剩余的单个元素组合
    int k = 0; //记录第几段
    while (k*len < end)
    {
        merge(list,k*len,len,end);
        k ++;
    }

}

void merge_sort(int* list,int length)
{
    //从上往下归并 2->4->8->...
    for (int len=1;len<length;)
    {
        len *= 2;
        merge_pass(list,len,length);
        print_list(list,length);
    }

}

int main(int argc, char const *argv[])
{
    int list[] = {23,38,22,45,23,67,31,15,41};
    int length = 9;
    print_list(list,length);
    merge_sort(list,length);

    return 0;
}
