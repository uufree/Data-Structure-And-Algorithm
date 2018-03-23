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






























