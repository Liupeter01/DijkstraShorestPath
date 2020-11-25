#include"DirectedEdge.h"

BOOL IsDirectEdgeExist(MGraph G, VertexType x, VertexType y)		  //�ж���ͼG���Ƿ���������<x,y>
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          if (x_pos != -1 && y_pos != -1)
          {
                    return  (
                              (G.Edge[x_pos][y_pos] != 0 &&                          //�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                              G.Edge[x_pos][y_pos] != -1 &&                         //Ϊ�˱���INT_MAX�������޷���������Ϊ-1������
                              G.Edge[x_pos][y_pos] != INFINITYSIZE) ? TRUE : FALSE);
          }
          return FALSE;
}

void DisplayDirectNeighbors(MGraph G, VertexType x)         //���������ͼG����x���ڱ�<x,?>
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //����������
          {
                    for (int i = 0; i < G.MaxVertexNum; ++i)
                    {
                              if (G.Edge[x_pos][i] != 0 &&            //�жϲ���Ԫ���Ƿ�λ�ڶԽ���  
                                        G.Edge[x_pos][i] != -1 &&     //����INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[x_pos][i] != INFINITYSIZE)
                              {
                                        printf("����߳���<%c,%c>\n", x, G.Vex[i]);
                              }
                              if (G.Edge[i][x_pos] != 0 &&             //�жϲ���Ԫ���Ƿ�λ�ڶԽ���  
                                        G.Edge[i][x_pos] != -1 &&     //����INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[i][x_pos] !=INFINITYSIZE)
                              {
                                        printf("��������<%c,%c>\n", G.Vex[i], x);
                              }
                    }
          } 
}

int CalculateEnVertex(MGraph G, VertexType x)		//����ĳһ��������������
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)
          {
                    int counter = 0;
                    for (int i = 0; i < G.vexnum; ++i)
                    {
                              if (G.Edge[i][LocateVertex(G, x)] != 0 &&          //�жϲ���Ԫ���Ƿ�λ�ڶԽ���  
                                        G.Edge[i][LocateVertex(G,x)]!=-1 &&       //����INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[i][LocateVertex(G, x)] != INFINITYSIZE)      //����Ϊ��λ���б���
                              {
                                        counter++;
                              }
                    }
                    return counter;
          }
          return -1; //����0����ö��㲻����
}

int CalculateOutVertex(MGraph G, VertexType x)			//����ĳһ������ĳ�������
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)
          {
                    int counter = 0;
                    for (int i = 0; i < G.vexnum; ++i)
                    {
                              if (G.Edge[LocateVertex(G, x)][i] != 0 &&         //�жϲ���Ԫ���Ƿ�λ�ڶԽ���  
                                        G.Edge[LocateVertex(G, x)][i] != -1 &&  //����INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[LocateVertex(G, x)][i] != INFINITYSIZE)      //����Ϊ��λ���б���
                              {
                                        counter++;
                              }
                    }
                    return counter;
          }
          return -1; //����0����ö��㲻����
}

BOOL	 InsertDirectEdge(MGraph* G, VertexType x, VertexType y)	  //��ͼG�����������Ȩ��<x,y>  ��ȨֵĬ��Ϊ1
{
          return InsertEdge(G, x, y, 1, DIRECTEDGRAPH);
}

BOOL	 InsertDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)	//��ͼG���������Ȩ��<x,y>��֧���޸�Ȩֵ
{
          return InsertEdge(G, x, y, Edge_Value, DIRECTEDGRAPH);
}

BOOL	RemoveDirectEdge(MGraph* G, VertexType x, VertexType y)	  //������ͼGɾ�������<x, y>
{
          return RemoveEdge(G, x, y, ((G->EdgeValue == TRUE) ? INFINITYSIZE : 0), DIRECTEDGRAPH);
}