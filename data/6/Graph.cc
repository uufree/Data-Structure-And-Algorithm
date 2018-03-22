/*************************************************************************
	> File Name: Graph.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月23日 星期五 01时53分46秒
 ************************************************************************/

#include"Graph.h"

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
    
    private:
        Vector<Vectex<Tv> > V;
        Vector<Vector<Edge<Te>*>> E;  
};

