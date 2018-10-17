## c_practice
练习基本的c算法

## 主要内部排序方法的性能

| 方法 | 平均时间 | 最坏时间 | 附加空间 | 稳定性 | 算法简单描述 |
| ------ | ------ | ------ | ------ | ------ | ------ |
| 直接插入 | O(n^2) | O(n^2) | O(1) | 稳定 | 从i后依次选择数与i-1倒叙进行对比，如果i位置数大则i位置后移。(往前插入的时候有折半插入方法，实质都一样只是查找插入位置快了一点，但是移动的位置是一样的) |
| shell(希尔)排序 | O(n^1.3) |   | O(1) | 不稳定 | 缩小增量排序过程，先取l=(len+1)/2两两对比:即位置0和位置l对比、1和l+1对比；然后继续取(l+1)/2位置增量进行对比，直到增量为0为止。 |
| 直接选择(简单选择) | O(n^2) | O(n^2) | O(1) | 不稳定 | 两层循环，只要后面的数比当前数小就进行位置交换。 |
| 堆排序 | O(nlog2(n)) | O(nlog2(n)) | O(1) | 不稳定 | 1：建立堆；2：将堆顶记录和最后一个记录交换位置，则前n-1个记录是无序的，而最后一个记录是有序的；3：堆顶记录被交换后，前n-1个记录不再是堆，需将前n-1个待排序记录重新组织成为一个堆，然后将堆顶数据和倒数第二个记录交换位置，即将整个序列中次小关键字值的记录调整（排除）出无序区；4：重复上述步骤，直到记录排好序为止。 |
| 冒泡排序 | O(n^2) | O(n^2) | O(1) | 稳定 | 最多有0...length次对比，每次从1..length-i选出最大的数,如果当前没有比默认第一个位置的数大，则排序完毕。 |
| 快速排序 | O(nlog2(n)) | O(n^2) | O(nlog2(n)) | 不稳定 | 先确定参照数，默认选0位置，1：从右选出比参照数小的j位置赋值为参照数，记录数变成j位置的数；2：从左边选出比参照数大的位置k把参照数记录为k位置的数并赋值为参照数；重复1、2步骤，直到左右位置重合，则该位置为最后的参照数位置。对于最后的位置再次分为左右区间，再依次对左右重复上述步骤，直到分界出来的左右相等为止，意思就是左右两边都找不到满足1、2条件的情况，算法结束。 |
| 归并排序 | O(nlog2(n)) | O(nlog2(n)) | O(n) | 稳定 | 开始归并的时候，每个记录是长度1的有序子序列，对这些序列进行逐趟归并，每次归并后有序的子序列长度扩大一倍；当子序列的长度大于等于整个序列时，此时整个记录为有序的。即2->4->8->2n子序列归并排序 |
| 基数排序 | O(d(n+r)) | O(d(n+r)) | O(n+r) | 稳定 | 依次对每个进位数进行排序：个位->十位->百位->... 最后得到的序列即为有序数组。其中，d 为位数，r 为基数，n 为原数组个数。 |

## 字符串匹配    
BF（Brute Force，暴力检索）O(m*n)、RK（Robin-Karp，哈希检索）O(m*n)、KMP（教科书上最常见算法）O(m+n)、BM（Boyer Moore）O(m*n)~O(n)、SundayO(m*n)~O(n)等
