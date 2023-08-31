#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"dijkstra.h"                              //迪杰斯特拉dijkstra算法

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          Pair pair[] =
          {
                    {'A','B',1}, {'A','D',3}, {'A','C',3}, 
                    {'B','D',1}, {'B','E',4}, 
                    {'C','D',2}, {'C','F',7}, 
                    {'D','E',2}, {'D','F',6}, 
                    {'E','F',3}
          };                 //带权边

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
            InsertUnDirectEdgeValue(&Graph, pair[i].VexOne, pair[i].VexTwo, pair[i].distance);
          }
          DisplayGraph(Graph);          //图的输出
          DijkstraShortestPath(Graph, 'A');
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}