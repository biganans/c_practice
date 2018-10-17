//KMP算法
//求需要匹配的字符串(m长度)的左右两方向最长相等串，再向左偏移1得到next数组，回溯数组，保证主串的位置不变只改变比较串(n长度)的位置，是的算法达到O(m+n)
#include <stdio.h>
#include <string.h>

void print_list(int* list,int length)
{
    for (int i=0;i<length;i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
}

//求next数组
// ABCABS
void getNext(char* list,int length,int *next)
{
    if (length <= 0)
    {
        printf("length error ");
        return;
    }
    next[0] = -1;
    int j = 1;
    int k = -1;
    while(j<length-1)
    {
        if (k == -1 || list[j] == list[k])
        {
            // next[++j] = ++k;
            //当两个字符串相等时需要跳过
            //TIPS:这个算是在KMP上的原始算法的一点优化
            if(list[++j] == list[++k])
            {
                next[j] = next[k];
            }
            else
            {
                next[j] = k;
            }
        }
        else
        {
            //不相等的时候需要回溯
            k = next[k];
        }
    }
}


void kmp_sort(char* list,int length,char* findList,int flength,int* next)
{
    printf("str:%s len:%d str:%s len:%d\n",list,length,findList,flength);
    int i=0,j=0;
    while(i<length && j<flength)
    {
        // 需要注意-1的回溯，-1就是意味着跳过i重新从j=0开始
        if (j == -1 || list[i] == findList[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }
    printf("i:%d j:%d \n", i,j);
    if (j == flength)
    {
        printf("find str %s in %s, the position is %d\n", findList,list,i-j);
    }
    else
    {
        printf("%s has no str: %s\n", list,findList);
    }
}


int main(int argc, char const *argv[])
{
    char list[] = "CDDSSABCABSKSDNLABCCS";
    char comList[] = "ABCABS";
    int length = strlen(comList);
    int next[length] = {0};
    getNext(comList,length,next);
    printf("%s \n",comList);
    print_list(next,length);
    kmp_sort(list,strlen(list),comList,length,next);
    return 0;
}
