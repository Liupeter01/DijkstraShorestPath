#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"dijkstra.h"                              //�Ͻ�˹����dijkstra�㷨

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          Pair pair[] =
          {
                    {'A','B',10}, {'A','D',30}, {'A','E',100}, {'B','C',50},
                    {'C','E',10},  {'D','C',20},  {'D','E',60}
          };                 //��Ȩ��

          for (int i = 0; i < sizeof(pair)/sizeof(Pair); ++i)
          {
                    InsertDirectEdgeValue(&Graph, pair[i].VexOne, pair[i].VexTwo, pair[i].distance);
          }

          DisplayGraph(Graph);          //ͼ�����

          DijkstraShortestPath(Graph, 'A');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}