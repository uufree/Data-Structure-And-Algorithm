/*************************************************************************
	> File Name: time.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时36分41秒
 ************************************************************************/

#ifndef _TIME_H
#define _TIME_H

#include<sys/time.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

long getTime()
{
    struct timeval val;
    gettimeofday(&val,NULL);
    return val.tv_sec * 1000000 + val.tv_usec;
}

long* getArray()
{
    long* array = new long[100000];
    std::fstream in;
    in.open("/home/uuchen/algorithm/sort/sortdata.dat",std::ios::in | std::ios::binary);
    if(!in.is_open())
        return NULL;
    for(int i=0;i<100000;i++)
        in >> array[i];
    
    in.close();
    return array;
}

long* getBigArray()
{
    long* array = new long[10000000];
    std::fstream in;
    in.open("/home/uuchen/algorithm/sort/BigDataSort.dat",std::ios::in | std::ios::binary);
    if(!in.is_open())
        return NULL;
    for(int i=0;i<10000000;i++)
        in >> array[i];
    
    in.close();
    return array;
}

#endif
