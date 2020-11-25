#include"UnDirectedEdge.h"

BOOL  IsUnDirectEdgeExist(MGraph G, VertexType x, VertexType y)		   //�ж���ͼG���Ƿ���������(x,y)
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          if (x_pos != -1 && y_pos != -1)
          {
                    return  (
                              (         G.Edge[x_pos][y_pos] != 0 &&           //�������(x,y)�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                                        G.Edge[x_pos][y_pos] != -1 &&              //Ϊ�˱���(x,y) INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[x_pos][y_pos] != INFINITYSIZE &&
                                        G.Edge[y_pos][x_pos] != 0 &&              //�������(y,x)�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                                        G.Edge[y_pos][x_pos] != -1 &&               //Ϊ�˱���(y,x) INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[y_pos][x_pos] != INFINITYSIZE) ? TRUE : FALSE);
          }
          return FALSE;
}

void DisplayUnDirectNeighbors(MGraph G, VertexType x) //���������ͼG����x���ڱ�(x,?)
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //����������
          {
                    for (int i = 0; i < G.MaxVertexNum; ++i)
                    {
                              if (G.Edge[x_pos][i] != 0 &&   //�������(x,y)�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                                        G.Edge[x_pos][i] != -1 &&       //Ϊ�˱���(y,x) INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[x_pos][i] != INFINITYSIZE)
                              {
                                        printf("�����(%c,%c)\n", x, G.Vex[i]);
                              }
                    }
          }
}

BOOL	 InsertUnDirectEdge(MGraph* G, VertexType x, VertexType y)	  //��ͼG�����������Ȩ��(x,y)  ��ȨֵĬ��Ϊ1
{
          return InsertEdge(G, x, y, 1, UNDIRECTEDGRAPH);
}

BOOL	 InsertUnDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)	//��ͼG���������Ȩ��(x,y)��֧���޸�Ȩֵ
{
          return InsertEdge(G, x, y, Edge_Value, UNDIRECTEDGRAPH);
}

BOOL	RemoveUnDirectEdge(MGraph* G, VertexType x, VertexType y)  //������ͼGɾ�������(x,y)
{
          return RemoveEdge(G, x, y, ((G->EdgeValue == TRUE) ? INFINITYSIZE : 0), UNDIRECTEDGRAPH);
}