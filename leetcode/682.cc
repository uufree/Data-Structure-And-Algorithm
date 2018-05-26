#include<vector>
#include<string>
#include<stack>
#include<iostream>

using namespace std;

int calPoints(vector<string>& ops) {
        stack<int> stack;
        int sum = 0;
        int size = ops.size();
        string iter;
        for(int i=0;i<size;++i)
        {
            iter = ops[i];
            

            if(iter == "C")
            {
                int x = stack.top();
                stack.pop();
                sum -= x;
            }
            else if(iter == "D")
            {
                int x = 2*stack.top();
                sum += x;
                stack.push(x);
            }
            else if(iter == "+")
            {
                int x = stack.top();
                stack.pop();
                int xx = stack.top();
                stack.pop();
                int xxx = x+xx;
                sum += xxx;
                stack.push(xx);
                stack.push(x);
                stack.push(xxx);
                break;
            }
            else
            {
                int x = stoi(iter);
                stack.push(x);
                sum += x;
            }
        }
        return sum;
    }

int main(int argc,char** argv)
{
    vector<string> vec = {"5","-2","4","C","D","9","+","+"};
    cout << calPoints(vec) << endl;
    return 0;
}
