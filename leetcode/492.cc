#include<iostream>
#include<vector>

using namespace std;

vector<int> constructRectangle(int area) {
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=1;i<=area;++i)
        {
            if(!temp.empty())
                temp.clear();
            
            if(area % i == 0)
            {
                temp.push_back(i);
                temp.push_back(area / i);
            }
            res.push_back(temp);
            std::cout << temp[0] << "    " << temp[1] << std::endl;
        }

        std::cout << res.size() << std::endl;
        
        int pos;
        int min = area;
        int size = res.size();
        for(int i=0;i<size;i++)
        {
            if(res[i][0] < res[i][1])
                continue;
            if(res[i][1] - res[i][0] < min)
            {
                min = res[i][1] - res[i][0];
                pos = i;
            }
        }
        
        temp = res[pos];
        return temp;
    }

int main()
{
    vector<int> temp = constructRectangle(4);
    std::cout << temp[0] << std::endl;
    std::cout << temp[1] << std::endl;

    return 0;
}
