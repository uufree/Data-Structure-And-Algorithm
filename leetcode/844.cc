#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool backspaceCompare(string S, string T) {
        int size1 = S.size();
        int size2 = S.size();
        if(size1 < 1 || size1 > 200 || size2 < 0 || size2 > 200)
            return false;
            
        stack<char> stack1;
        stack<char> stack2;
        for(int i=0;i<size1;i++)
        {
            if(S[i] != '#')
                stack1.push(S[i]);
            else
            {
                if(stack1.empty())
                    continue;
                else
                    stack1.pop();
            }
        }
        
        for(int i=0;i<size2;i++)
        {
            if(T[i] != '#')
                stack2.push(T[i]);
            else
            {
                if(stack2.empty())
                    continue;
                else   
                    stack2.pop();
            }
        }
        
        while(!stack1.empty())
        {
            std::cout << stack1.top();
            stack1.pop();
        }
        std::cout << std::endl;
        while(!stack2.empty())
        {
            std::cout << stack2.top();
            stack2.pop();
        }
        std::cout << std::endl;

        if(stack1.size() != stack2.size())
            return false;
        else
        {
            if(stack1.size() == 0)
                return true;

            int size = stack1.size();
            for(int i=0;i<size;i++)
            {
                std::cout << stack1.top() << "    " << stack2.top() << std::endl;
                if(stack1.top() == stack2.top())
                {
                    stack1.pop();
                    stack2.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        return true;
    }

int main(int argc,char** argv)
{
    std::cout << backspaceCompare("xywrrmp","xywrrmu#p") << std::endl;
    return 0;
}
