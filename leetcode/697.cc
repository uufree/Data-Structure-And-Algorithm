#include<iostream>
#include<vector>

int findShortestSubArray(std::vector<int>& nums) {
    int* map = new int[50000]{0};
    int number = 0;
    int size = 0;
    for(auto iter=nums.begin();iter!=nums.end();++iter)
        ++map[*iter];
    for(int i=0;i<50000;i++) {
        if(map[i] > size) {
            number = i;
            size = map[i];
        }
    } 
    std::vector<int> numbers;
    std::vector<int> sizes;
    for(int i=0;i<50000;i++) {
        if(map[i] == size) {
            numbers.push_back(i);
            sizes.push_back(size);
        }
    }
    delete [] map;
    
    int minRes = 50000;
    int res = 0;
    for(size_t i=0;i<numbers.size();i++) {
        number = numbers[i];
        size = sizes[i];
        for(auto iter=nums.begin();iter!=nums.end();++iter) {
            if(*iter != number) 
                continue;
            else {
                for(auto niter=iter;niter!=nums.end();++niter) {
                    ++res;
                    if(*niter == number)
                        --size;
                    if(size == 0)
                        break;
                }
            }

            if(res > 0)
                break;
        }
        if(res < minRes) {
            minRes = res;
            res = 0;
        }
    }
    return minRes;
}

int main(int argc,char** argv)
{
    std::vector<int> vec{1,2,2,3,1,4,2};
    std::cout << findShortestSubArray(vec) << std::endl;
    return 0;
}
