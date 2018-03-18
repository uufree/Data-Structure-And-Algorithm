/*************************************************************************
	> File Name: queen.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 17时12分24秒
 ************************************************************************/

#include<iostream>
#include"stack.h"

struct Queen
{
    int _x,_y;
    Queen(){};
    Queen(int x_,int y_) : _x(x_),_y(y_){};
    
    bool operator==(Queen const& lhs){return _x == lhs._x || _y == lhs._y || _x+_y == lhs._x+lhs._y || _x-_y == lhs._x-lhs._y;};
    bool operator!=(Queen const& lhs){return !(*this == lhs);};
};

void getPlace(Stack<Queen>& stack,int N)
{
    Queen pos(0,0);

    while(pos._x < N)
    {
        if(pos._y >= N)
        {
            pos = stack.pop();
            pos._y++;
        }
        else
        {
            while(stack.find(pos) >= 0 & pos._y < N)
                pos._y++;
            
            if(pos._y < N)
            {
                stack.push(pos);
                pos._x++;
                pos._y = 0;
            }
        }

    }
}

int main(int argc,char** argv)
{
    Stack<Queen> stack;
    getPlace(stack,4);
    
    while(!stack.empty())
    {
        Queen temp = stack.pop();
        std::cout << "X: " << temp._x << "        " << "Y: " << temp._y << std::endl;
    }

    return 0;
}
