//基数排序 稳定排序

#include <stdio.h>
#include <string.h>

#define RADIX 10 //基数0,1,2,3,4,5,6,7,8,9

int radixList[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

int get_number_length(int number)
{
    char temp[64];
    sprintf(temp,"%d",number);
    return strlen(temp);
}

//得到基数位置上的数值
int get_number(int number,int pos)
{
    int temp = radixList[pos];
    return (number/temp)%10;
}

//递归
int* sort(int* list,int length,int digit,int max_digit)
{
    if (digit > max_digit)
    {
        return list;
    }
    //进行基数装桶，记录每个基位的数
    int count[RADIX] = {0};
    int temp = 0;
    //统计将数组中的数字分配到桶中后，各个桶中的数字个数
    for (int i=0;i<length;i++)
    {
        temp = get_number(list[i],digit);
        count[temp]++;
    }
    //  0   1   2   3   4   5   6   7   8   9
    //  0   0   1   1   2   0   0   1   1   0
    //将各个桶中的数字个数，转化成各个桶中最后一个数字的下标索引
    //这一步比较神奇，需要好好理一理
    for (int i=1;i<RADIX;i++)
    {
        count[i] = count[i] + count[i-1];
    }
    int bucket[length] = {0};
    //  0   1   2   3   4   5   6   7   8   9
    //  0   0   1   2   4   4   4   5   6   6
    for (int i=length-1;i>=0;i--)
    {
        int d = get_number(list[i],digit);
        bucket[count[d] - 1] = list[i];
        count[d] --;
    }
    print_list(list,length);
    return sort(bucket,length,digit+1,max_digit);
}

void radix_sort(int* list,int length)
{
    //寻找最大位数
    int max_digit = 0;
    for (int i=0;i<length;i++)
    {
        int digit = get_number_length(list[i]);
        if (digit > max_digit)
        {
            max_digit = digit;
        }
    }
    printf("max_digit:%d\n",max_digit);
    int* result = sort(list,length,0,max_digit);
}

int main(int argc, char const *argv[])
{
    int list[] = {2314,5428,373,222,17,54};
    int length = 6;
    print_list(list,length);
    radix_sort(list,length);
    return 0;
}
