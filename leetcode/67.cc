/*************************************************************************
	> File Name: 67.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月15日 星期二 16时15分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>

std::string addBinary(std::string a,std::string b)
{
    std::string result;
    std::stack<char> stack;
    int alen = a.length();
    int blen = b.length();
    int maxlen = std::max(alen,blen);
    
    int ch = 0;
    int ach = 0;
    int bch = 0;
    char p;
    for(int i=1;i<maxlen+1;i++)
    {
        if(alen-i >= 0)
            ach = a[alen-i] - '0';
        if(blen-i >= 0)
            bch = b[blen-i] - '0';
        
        std::cout << ach << " + " << bch << std::endl;

        int temp = ach + bch + ch;
        if(temp == 0)
        {
            p = '0';
            ch = 0;
        }
        else if(temp == 1)
        {
            p = '1';
            ch = 0;
        }
        else if(temp == 2)
        {
            p = '0';
            ch = 1;
        }
        else if(temp == 3)
        {
            p = '1';
            ch = 1;
        }
        stack.push(p);
        ach = 0;
        bch = 0;
    }
    
    if(ch != 0)
        stack.push('1');
    
    while(!stack.empty())
    {
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}

int main(int argc,char** argv)
{
    std::string a = "100";
    std::string b = "110010";
    std::string res = addBinary(a,b);
    std::cout << res << std::endl;

    return 0;
}

