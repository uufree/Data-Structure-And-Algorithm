/*************************************************************************
	> File Name: Graph.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月23日 星期五 01时53分46秒
 ************************************************************************/

#include"Graph.h"

template<typename Tv,typename Te>
void Graph<Tv,Te>::bfs(int s)
{
    reset();
    int clock = 0;int v = s;
    
    do
        if(status(v) == UNDISCOVERED)
            BFS(v,clock);
    while(s != (v = (++v % Graph<Tv,Te>::_n)));
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::BFS(int v,int& clock)
{
    Deque<int> deque;
    status(v) = DISCOVERED;
    deque.push(v);
    
    while(!deque.empty())
    {
        int v = deque.pop();
        dTime(v) = ++clock;
        for(int u = firstNBR(v);u;u = nextNBR(v,u))
            if(status(u) == UNDISCOVERED)
            {
                status(u) = DISCOVERED;
                deque.push(u);
                type(v,u) = TREE;
                parent(u) = v;
            }
            else
                type(v,u) = CROSS;
        status(v) = VISITED;
    }
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::dfs(int s) 
{
    reset();
    int clock = 0;int v = s;

    do
        if(status(v) == UNDISCOVERED)
            DFS(v,clock);
    while(s != (v = (++v % Graph<Tv,Te>::_n)));
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int& clock)
{
    dTime(v) = ++clock;
    status(v) = DISCOVERED;

    for(int u=firstNBR(v);u>-1;u=nextNBR(v))
        switch(status(u))
        {
            case UNDISCOVERED:
                type(v,u) = TREE;
                parent(u) = v;
                DFS(u,clock);
                break;
            case DISCOVERED:
                type(v,u) = BACKWORD;
                break;
            default:
                type(v,u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                break;
        }

    status(v) = VISITED;
    fTime(v) = ++clock;
}

template<typename Tv,typename Te>
Stack<Tv>* Graph<Tv,Te>::tSort(int s)
{
    reset();
    int clock = 0;
    int v = s;
    Stack<Tv>* stack = new Stack<Tv>();
    do
    {
        if(status(s) == UNDISCOVERED)
            if(!TSORT(v,clock,stack))
            {
//其实这块没有必要弹出来吧...可以想成在这块对已经排序的数据做额外的处理        
                while(!stack->empty())
                    stack->pop();
                break;
            }
    }while(s != (v = (++v % Graph<Tv,Te>::_n)));
    return stack;
}

template<typename Tv,typename Te>
bool Graph<Tv,Te>::TSORT(int v,int& clock,Stack<Tv>* stack)
{
    dTime(v) = ++clock;
    status(v) = DISCOVERED;

    for(int u=firstNBR(v);u>-1;v=nextNBR(v,u))
        switch(status(u))
        {
            case UNDISCOVERED:
                parent(u) = v;
                type(v,u) = TREE;
                if(!TSORT(u,clock,stack))
                    return false;
                break;
            case DISCOVERED:
                type(v,u) = BACKWORD;
                break;  
            default:
                type(v,u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
        }
    
    status(v) = VISITED;
    stack->push(vertex(v));
    return true;
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::bcc(int s)
{
    reset();
    int clock = 0;
    int v = s;
    Stack<int> stack;;

    do
        if(status(v) == UNDISCOVERED)
        {
            BCC(v,clock,&stack);
//同拓扑排序的处理一样...就是一个递归搜索,然后对不同的路径做不同的处理   
            stack.pop();
        }
    while(s != (v = (++v % Graph<Tv,Te>::_n)));
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::BCC(int v,int& clock,Stack<int>* stack)
{
    fTime(v) = dTime(v) = ++clock;
    status(v) = DISCOVERED;
    stack->push(v);
    for(int u=firstNBR(v);u>-1;u=nextNBR(v,u))
        switch(status(u))
        {
            case UNDISCOVERED:
                parent(u) = v;
                type(v,u) = TREE;
                BCC(u,clock,stack);
                if(fTime(u) < dTime(v))
                    fTime(u) = std::min(fTime(v),fTime(u));
                else
                {
                    while(v != stack->pop());
                    stack->push(v);
                }
                break;
            case DISCOVERED:
                type(v,u) = BACKWORD;
                break;
            default:
                type(v,u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                break;
        }
    status(v) = VISITED;
}

template<typename Tv,typename Te>
template<typename PU>
void Graph<Tv,Te>::pfs(int s,PU func)
{
    reset();
    int v = s;
    
    do
        if(status(v) == UNDISCOVERED)
            PFS(v,func);
    while(s != (v = (++v % Graph<Tv,Te>::_n)));
}

template<typename Tv,typename Te>
template<typename PU>
void Graph<Tv,Te>::PFS(int s,PU func)
{
    priority(s) = 0;
    status(s) = VISITED;
    parent(s) = -1;

    while(1)
    {
        for(int u=firstNBR(s);u>-1;u=nextNBR(s,u))
            func(this,s,u);

        for(int shortest=65536,w=0;w<Graph<Tv,Te>::_n;w++)
            if(status(w) == UNDISCOVERED)
                if(shortest > priority(w))
                {
                    shortest = priority(w);
                    s = w;
                }
        
        if(status(s) == VISITED)
            break;
        status(s) = VISITED;
        type(parent(s),s) = TREE;
    }
}


























