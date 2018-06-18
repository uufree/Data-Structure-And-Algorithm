
#include<iostream>
#include<vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 0)
            return false;
        
        int size = flowerbed.size();
        for(int i=0;i<size;i++)
        {
            if(flowerbed[i] == 1)
                continue;
            else
            {
                if(i == 0)
                {
                    if(flowerbed[i+1] == 0)
                    {
                        --n;
                        flowerbed[i] = 1;
                        if(n)
                            continue;
                        else
                            return true;
                    }
                    else
                        continue;
                }
                else if(i > 0 && i < size-1)
                {
                    if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
                    {
                        --n;
                        flowerbed[i] = 1;
                        if(n)
                            continue;
                        else
                            return true;
                    }
                    else
                        continue;
                } 
                else if(i == size-1)
                {
                    if(flowerbed[i-1] == 0)
                    {
                        --n;
                        flowerbed[i] = 1;
                        if(n)
                            continue;
                        else
                            return true;
                    }
                    else
                        continue;
                }
            }
        }
        
        if(n == 0)
            return true;
        else
            return false;
    }

int main(int argc,char** argv)
{
    vector<int> vec{1,0,0,0,0,1};
    
    std::cout << canPlaceFlowers(vec,2) << std::endl;
}
