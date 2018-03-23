/*************************************************************************
	> File Name: Graph.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月23日 星期五 01时53分39秒
 ************************************************************************/

#ifndef _GRAPH_H
#define _GRAPH_H

#include"../2/vector.h"
#include"../4/stack.h"
#include"../4/deque.h"
#define INT_MAX 65536

typedef enum {UNDISCOVERED,DISCOVERED,VISITED} PointStatus;//点状态
typedef enum {UNDETERMINED,TREE,CROSS,FORWARD,BACKWORD} LineType;//边在遍历树中所属的类型

//定点类型,边类型
template<typename Tv,typename Te>
class Graph
{
    private:
        void reset()
        {
            for(int i = 0;i < _n;i++)
            {
                status(i) = UNDISCOVERED;
                dTime(i) = fTime(i) = -1;
                parent(i) = -1; priority(i) = INT_MAX;
                for(int j = 0;j < _n;j++)
                    if(exists(i,j))
                        type(i,j) = UNDETERMINED;
            }
        }
        void BFS(int,int&);//广度优先算法
        void DFS(int,int&);//深度优先算法
        void BCC(int,int&,Stack<int>&);//(连通域)基于DFS的双连通分量分解算法
        bool TSort(int,int&,Stack<Tv>*);//(连通域)基于DFS的拓扑排序算法
        template<typename PU> void PFS(int,PU);//(连通域)优先级搜索框架
    public:
    //顶点
        int _n;//顶点总数
        virtual int insert(Tv const&) = 0;//插入顶点,返回编号
        virtual Tv remove(int) = 0;//删除顶点及其关连边,返回该定点的信息
        virtual Tv& vertex(int) = 0;//返回顶点V的数据
        virtual int inDegree(int) = 0;//返回顶点V的出度
        virtual int outDegree(int) = 0;//返回顶点V的入度
        virtual int firstNBR(int) = 0;//顶点V的首个临接顶点
        virtual int nextNBR(int,int) = 0;//顶点V的下一个临接顶点
        virtual PointStatus& status(int) = 0;//返回顶点V的状态
        virtual int& dTime(int) = 0;//顶点V的时间标签dTime
        virtual int& fTime(int) = 0;//顶点V的时间标签fTime
        virtual int& parent(int) = 0;//顶点V在遍历树中的parent
        virtual int& priority(int) = 0;//顶点V在遍历树中的优先级

    //边
        int _e;//边总数
        virtual bool exists(int,int) = 0;//边(v,u)是否存在
        virtual void insert(Te const& elem,int,int,int) = 0;//在顶点V和U中插入权重为W的边e
        virtual Te remove(int,int) = 0;//删除顶点V和U之间的边E,并返回E的信息
        virtual LineType& type(int,int) = 0;//返回边E的状态
        virtual Te& edge(int,int) = 0;//返回边(v,u)的数据
        virtual int& weight(int,int) = 0;//返回边(v,u)的权重
    
    //算法
        void bfs(int);//广度优先搜索
        void dfs(int);//深度有限搜索
        void bcc(int);//基于DFS的双连通域的分解算法
        Stack<Tv>* tSort(int);//基于DFS的拓扑排序算法    
        void prim(int);//最小支撑树Prim算法
        void dijkstra(int);//最短路径 dijkstra算法
        template<typename PU> void pfs(int, PU);//优先搜索框架
};

template<typename Tv>
struct Vectex//顶点对象
{
    Tv _data;
    int _inDegree,_outDegree;
    PointStatus _status;
    int _dTime,_fTime;
    int _parent;
    int _priority;

    Vectex(Tv const& data = (Tv)0) :
        _data(data),_inDegree(0),_outDegree(0),_status(UNDISCOVERED),
        _dTime(-1),_fTime(-1),_parent(-1),_priority(INT_MAX)
    {};
};

template<typename Te>
struct Edge
{
    Te _data;
    int _weight;
    LineType _type;
    Edge(Te const& data,int weight) :
        _data(data),_weight(weight),_type(UNDETERMINED)
    {};
};

template<typename Tv,typename Te>
class GraphMatrix : public Graph<Tv,Te>
{
    public:
        GraphMatrix(){Graph<Tv,Te>::_n = Graph<Tv,Te>::_e = 0;}
        ~GraphMatrix()
        {
            for(int i=0;i<Graph<Tv,Te>::_n;i++)
                for(int j=0;j<Graph<Tv,Te>::_n;j++)
                    delete E[i][j];
        }
        
        //点操作    
        Tv& vertex(int i) override {return V[i];}; 
        int inDegree(int i) override {return V[i]._inDegree;};
        int outDegree(int i) override {return V[i]._outDegree;};
        int firstNBR(int i) override {return nextNBR(i,Graph<Tv,Te>::_n);};
        int nextNBR(int i,int j) override//在临接表中很好描述
        {
            while((j > -1) && (!exists(i,--j)));
            return j;
        };
        PointStatus& status(int i) override {return V[i]._status;}; 
        int& dTime(int i) override {return V[i]._dTime;}; 
        int& fTime(int i) override {return V[i]._fTime;};
        int& parent(int i) override {return V[i]._parent;};
        int& priority(int i) override {return V[i]._priority;};
        
        int insert(Tv const& data) override
        {
            for(int i=0;i<Graph<Tv,Te>::_n;i++)
                E[i].insert(NULL);
            Graph<Tv,Te>::_n++;
            E.insert(Vector<Edge<Te>*>(Graph<Tv,Te>::_n,Graph<Tv,Te>::_n,(Edge<Te>*)NULL));
            return V.insert(Vectex<Tv>(data));
        }
        
        Te remove(int i) override
        {
            for(int j=0;j<Graph<Tv,Te>::_n;j++)
                if(exists(i,j))
                {
                    delete E[i][j];//删除所有出边
                    --V[j]._outDegree;
                }
            E.remove(i);
            Graph<Tv,Te>::_n--;
            Tv data = V[i]._data;
            V.remove(i);

            for(int j=0;j<Graph<Tv,Te>::_n;j++)
                if(Edge<Te>* edge = E[j].remove(i))
                {
                    delete edge;
                    V[j]._inDegree--;
                }
            return data;
        }
        
        //边操作     
        bool exists(int i,int j) override {return i>=0 & i<Graph<Tv,Te>::_n & j>=0 & j<Graph<Tv,Te>::_n & E[i][j]!=NULL;}
        LineType& tyep(int i,int j) override {return E[i][j]->_type;};
        Te& edge(int i,int j) override {return E[i][j]->_data;};
        int& weight(int i,int j) override {return E[i][j]->_weight;};
        
        void insert(Te const& elem,int w,int i,int j) override
        {
            if(exists(i,j))
                return;
            E[i][j] = new Edge<Te>(elem,w);
            Graph<Tv,Te>::_e++;
            V[i]._outDegree++;
            V[j]._inDegree++;
        }
        
        Te remove(int i,int j) override
        {
            Te data = E[i][j]->_data;
            delete E[i][j];
            E[i][j] = NULL;
            Graph<Tv,Te>::_e--;
            V[i]._outDegree--;V[j]._inDegree--;
            return data;
        };

    private:
        Vector<Vectex<Tv> > V;
        Vector<Vector<Edge<Te>*>> E;  
};



#endif
