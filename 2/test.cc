/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 20时11分24秒
 ************************************************************************/

#include<iostream>
//#include"vector.h"
#include"bitmap.h"

int main(int argc,char** argv)
{
//    int array[10] = {9,8,7,6,9,4,9,2,7,0};
//    int array2[10] = {0,1,2,3,4,5,6,7,8,9};
//    Vector<int> vec(array,10);
//    Vector<int> vec2(array2,10);

//    std::cout << vec.size() << std::endl;
//    std::cout << vec.empty() << std::endl;
//    std::cout << vec.find(12) << std::endl;
//    std::cout << vec2.search(5) << std::endl; 
//    std::cout << vec[0] << std::endl;
//    vec = vec2;    
//    vec.remove(2,5);
//    vec.insert(11);
//    vec.mergeSort(0,9);
//    vec2.unsort(0,5); 
//    vec2.uniquify(); 
//    vec2.show();
    
//    std::cout << vec2.search(8) << std::endl;
    
    
    Bitmap map(16);
    map.set(4);
    std::cout << map.get(3) << std::endl;
    return 0;
}
