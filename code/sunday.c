/**
    Sunday算法是Daniel M.Sunday于1990年提出的字符串模式匹配。相对比较KMP和BM
　　算法而言，简单了许多。
　　　　原理与BM算法相仿，有点像其删减版，所以其时间复杂度和BM算法差不多，平均性能的
　　时间复杂度也为O(n)，最差情况的时间复杂度为O(n * m)，但是要容易理解。
*/

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

#define MAXSIZE 256

void get_move_length(char* tList,int tLength,int* moveList)
{
    //默认list中的任何字符均不出现在targetList中，那么每次移动的距离为targetList的长度 + 1
    for (int i = 0; i < MAXSIZE; ++i)
    {
        moveList[i] = tLength;
    }
    //查找能够出现在targetList中的字符，若一个字符出现多次，选择最右位置的字符，所以targetList的下标遍历从0开始
    for (int i = 0; tList[i]; ++i)
    {
        moveList[tList[i]] = tLength - i;
    }
    print_list(moveList,MAXSIZE);
}

/**
    匹配原理：从前往后匹配，如果遇到不匹配情况判断母串S参与匹配的最后一位的下一位字符
　　，如果该字符出现在模板串T中，选择最右出现的位置进 行对齐；否则直接跳过该匹配区域。
*/
void sunday(char* list,int length,char* tList,int tLength)
{
    int moveList[MAXSIZE] = {0};
    get_move_length(tList,tLength,moveList);

    int i = 0;
    int j = 0;
    int pos = -1;
    while(i < length)
    {
        j = 0;
        for(;j<tLength && i+j < length && list[i+j] == tList[j];++j)
            ;
        if (j >= tLength)
        {
            pos = i;
            break;
        }
        if (i+tLength >length)
        {
            pos = -1;
            break;
        }
        printf("i:%d\n",i);
        i += moveList[list[i+tLength]];
    }

    if (pos == -1)
    {
        printf("%s in %s is tan90\n", tList,list);
    }
    else
    {
        printf("%s in %s pos is %d \n",tList,list,pos);
    }
}

int main(int argc, char const *argv[])
{
    char list[] = "CDDSSABCABSKSDNLABCCS";
    char targetList[] = "ABCABS";
    int length = strlen(targetList);
    sunday(list,strlen(list),targetList,length);
    return 0;
}
