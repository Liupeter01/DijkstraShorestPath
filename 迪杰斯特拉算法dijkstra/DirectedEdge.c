#include"DirectedEdge.h"

BOOL IsDirectEdgeExist(MGraph G, VertexType x, VertexType y)		  //判断在图G中是否存在有向边<x,y>
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          if (x_pos != -1 && y_pos != -1)
          {
                    return  (
                              (G.Edge[x_pos][y_pos] != 0 &&                          //判断查找元素是否位于对角线
                              G.Edge[x_pos][y_pos] != -1 &&                         //为了避免INT_MAX带来的无符号数解析为-1的问题
                              G.Edge[x_pos][y_pos] != INFINITYSIZE) ? TRUE : FALSE);
          }
          return FALSE;
}

void DisplayDirectNeighbors(MGraph G, VertexType x)         //输出在有向图G与结点x相邻边<x,?>
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //顶点必须存在
          {
                    for (int i = 0; i < G.MaxVertexNum; ++i)
                    {
                              if (G.Edge[x_pos][i] != 0 &&            //判断查找元素是否位于对角线  
                                        G.Edge[x_pos][i] != -1 &&     //避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[x_pos][i] != INFINITYSIZE)
                              {
                                        printf("有向边出边<%c,%c>\n", x, G.Vex[i]);
                              }
                              if (G.Edge[i][x_pos] != 0 &&             //判断查找元素是否位于对角线  
                                        G.Edge[i][x_pos] != -1 &&     //避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[i][x_pos] !=INFINITYSIZE)
                              {
                                        printf("有向边入边<%c,%c>\n", G.Vex[i], x);
                              }
                    }
          } 
}

int CalculateEnVertex(MGraph G, VertexType x)		//计算某一个顶点的入度数量
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)
          {
                    int counter = 0;
                    for (int i = 0; i < G.vexnum; ++i)
                    {
                              if (G.Edge[i][LocateVertex(G, x)] != 0 &&          //判断查找元素是否位于对角线  
                                        G.Edge[i][LocateVertex(G,x)]!=-1 &&       //避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[i][LocateVertex(G, x)] != INFINITYSIZE)      //以列为单位进行遍历
                              {
                                        counter++;
                              }
                    }
                    return counter;
          }
          return -1; //返回0代表该顶点不存在
}

int CalculateOutVertex(MGraph G, VertexType x)			//计算某一个顶点的出度数量
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)
          {
                    int counter = 0;
                    for (int i = 0; i < G.vexnum; ++i)
                    {
                              if (G.Edge[LocateVertex(G, x)][i] != 0 &&         //判断查找元素是否位于对角线  
                                        G.Edge[LocateVertex(G, x)][i] != -1 &&  //避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[LocateVertex(G, x)][i] != INFINITYSIZE)      //以列为单位进行遍历
                              {
                                        counter++;
                              }
                    }
                    return counter;
          }
          return -1; //返回0代表该顶点不存在
}

BOOL	 InsertDirectEdge(MGraph* G, VertexType x, VertexType y)	  //在图G中添加有向无权边<x,y>  ，权值默认为1
{
          return InsertEdge(G, x, y, 1, DIRECTEDGRAPH);
}

BOOL	 InsertDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)	//在图G中添加有向含权边<x,y>，支持修改权值
{
          return InsertEdge(G, x, y, Edge_Value, DIRECTEDGRAPH);
}

BOOL	RemoveDirectEdge(MGraph* G, VertexType x, VertexType y)	  //在有向图G删除有向边<x, y>
{
          return RemoveEdge(G, x, y, ((G->EdgeValue == TRUE) ? INFINITYSIZE : 0), DIRECTEDGRAPH);
}