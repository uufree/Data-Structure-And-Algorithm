/*************************************************************************
	> File Name: 14.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月11日 星期五 05时43分40秒
 ************************************************************************/

#include<iostream>
#include<bitset>

////////////////////////////////////////////
//46-01
int accmulateTimesCore(char* array)
{
    if(*(array+1) == '\0')
        return 1;
    
    if(*array < '3')
    {
        if(*(array+1) < '6')
            return accmulateTimesCore(array+1) + accmulateTimesCore(array+2);
        else if(*(array+1) > '5')
            return accmulateTimesCore(array+1);
    }
    else
        return accmulateTimesCore(array+1);
    return 0;
}

void accmulateTimes(char* array,int length)
{
    if(array == NULL || length <= 0)
        return;
    std::cout <<  accmulateTimesCore(array) << std::endl;
}

////////////////////////////////////////////////
//48
void getLongestStr(const char* str,int length)
{
    if(str == NULL || length <= 0)
        return;
    
    int* set = new int[26];
    for(int i=0;i<26;i++)
        set[i] = -1;

    int currentLength = 0;
    int maxLength = 0;
    for(int i=0;i<length;i++)
    {
        int index = set[str[i] - 'a'];  //获取当前字符上次出现的位置
        if(index < 0)      //如果这个字符上次没有出现，递增长度
            ++currentLength;
        else        //如果这个字符出现过
        {
            if(currentLength > maxLength)   //判断当前长度与历史长度的比较    
                maxLength = currentLength;
            currentLength = i - index;      //修改当前长度为：本次出现与上次出现的差值
        }
        set[str[i] - 'a'] = i;      //重新记录本次的出现位置
    }
    
    delete [] set;
    std::cout << maxLength << std::endl;
}

//////////////////////////////////////////////////////
//49
int Min(int pos1,int pos2,int pos3)
{
    int min = (pos1 < pos2) ? pos1 : pos2;
    min = (min < pos3) ? min : pos3;
    return min;
}

void getUglyNumber(int index)
{
    int* array = new int[index];
    array[0] = 1;
    int nextIndex = 1;
    int* pos1 = array;
    int* pos2 = array;
    int* pos3 = array;

    while(nextIndex < index)
    {
        int min = Min(*pos1 * 2,*pos2 * 3, *pos3 * 5);
        array[nextIndex] = min;

        while(*pos1 * 2 <= array[nextIndex])
            ++pos1;
        while(*pos2 * 3 <= array[nextIndex])
            ++pos2;
        while(*pos3 * 5 <= array[nextIndex])
            ++pos3;

        ++nextIndex;
    }
    
    int ugly = array[index-1];
    std::cout << ugly << std::endl;

    delete [] array;
}

int main(int argc,char** argv)
{
    getUglyNumber(1500);
    return 0;
}
