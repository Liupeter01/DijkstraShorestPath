#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"dijkstra.h"                              //迪杰斯特拉dijkstra算法

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          Pair pair[] =
          {
                    {'A','B',10}, {'A','D',30}, {'A','E',100}, {'B','C',50},
                    {'C','E',10},  {'D','C',20},  {'D','E',60}
          };                 //带权边

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
                    InsertDirectEdgeValue(&Graph, pair[i].VexOne, pair[i].VexTwo, pair[i].distance);
          }

          DisplayGraph(Graph);          //图的输出

          DijkstraShortestPath(Graph, 'A');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}