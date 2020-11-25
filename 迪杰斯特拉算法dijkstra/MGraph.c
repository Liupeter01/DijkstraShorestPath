#include"MGraph.h"

void InitGraph(MGraph* G)               //图G的初始化
{
          G->MaxVertexNum = Default_Vertices_Size;                    //默认结点的大小
          G->arcnum =  G->vexnum = 0;      //没有结点没有边
          G->EdgeValue = FALSE;
}

void DestroyGraph(MGraph* G)            //图G的销毁
{
          free(G->Vex);
          G->Vex = NULL;
          for (int i = 0; i < G->MaxVertexNum; ++i)
          {
                    free(G->Edge[i]);
          }
          free(G->Edge);
          free(G->Vex);
          G->Edge = NULL;
          G->Vex = NULL;
          G->arcnum = G->vexnum = 0;
}

int LocateVertex(MGraph G, VertexType x)   //在图G中找到顶点下标
{
          int x_pos = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] != 0 && G.Vex[x_pos] == x)
                    {
                              return x_pos;
                    }
          }
          return -1;          //出错
}

void DisplayGraph(MGraph G)             //图G的输出
{
          printf("    ");                 //空格对齐
          for (int i = 0; i < G.vexnum; ++i)                //输出顶点
          {
                    printf("%-4c  ", G.Vex[i]);
          }
          printf("\n");
          for (int i = 0; i < G.vexnum; ++i)                //输出数据
          {
                    printf("%c:  ", G.Vex[i]);
                    for (int j = 0; j < G.vexnum; ++j)
                    {
                              printf("%-4d  ", G.Edge[i][j]);
                    }
                    printf("\n");
          }
          printf("\n");
}

BOOL ExtendGraphSize(MGraph* G,VertexType*arr, int type)                //图G的空间分配以及默认空间扩容函数
{
          G->EdgeValue = ((type == GRAPHWITHVALUE) ? TRUE : FALSE);   //切换图的状态，判断当前是否为带权图
          int GraphSize = (((int)strlen(arr) > G->MaxVertexNum) ? (int)strlen(arr) : G->MaxVertexNum);//图的大小，顶点数多于默认空间数
          G->Vex = (VertexType*)calloc(GraphSize, sizeof(VertexType));
          G->Edge = (EdgeType**)calloc(GraphSize, sizeof(EdgeType*));         //扩容
          assert(G->Vex != NULL && G->Edge != NULL);
          if (G->Vex == NULL || G->Edge == NULL)
          {
                    return FALSE;
          }
          memset(G->Edge, ((type == NORMALGRAPH) ? 0 : INFINITYSIZE), sizeof(EdgeType*) * GraphSize);
          for (int i = 0; i < GraphSize; ++i)
          {
                    G->Edge[i] = (EdgeType*)calloc(GraphSize, sizeof(EdgeType));    //扩容
                    assert(G->Edge[i] != NULL);
                    if (G->Edge[i] == NULL)
                    {
                              return FALSE;
                    }
                    memset(G->Edge[i], ((type == NORMALGRAPH) ? 0 : INFINITYSIZE), sizeof(EdgeType) * GraphSize);  //全部初始化为0
          }
          G->MaxVertexNum = GraphSize;         //扩展最大容量
          if (type != NORMALGRAPH)         //如果该图是一个带权图，则将所有的对角线清空为0
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[i][i] = 0;  //对角线为0
                    }
          }
          return TRUE;
}

void ShowEdgeValue(MGraph G, VertexType x, VertexType y)    //输出图中某条边的权值
{
          int x_pos = LocateVertex(G, x);                   //寻找第一个顶点x在表的位置
          int y_pos = LocateVertex(G, y);                   //寻找第二个顶点y在表的位置

          if (x_pos != -1 && y_pos != -1)                   //两个顶点必须是存在的
          {
                    if (G.Edge[x_pos][y_pos] == 0 ||                  //检测对角线
                              G.Edge[x_pos][y_pos] == -1 ||            //为了避免INT_MAX带来的无符号数解析为-1的问题
                              G.Edge[x_pos][y_pos] == INFINITYSIZE)
                    {
                              printf("边%c%c不存在\n", x, y);
                    }
                    else if (G.Edge[x_pos][y_pos] == 1)
                    {
                              printf("该边使用无权图的默认权值1\n");
                    }
                    else if(G.Edge[x_pos][y_pos] != 0 &&                  //检测对角线
                              G.Edge[x_pos][y_pos] != -1 &&            //为了避免INT_MAX带来的无符号数解析为-1的问题
                              G.Edge[x_pos][y_pos] != INFINITYSIZE)
                    {
                              printf("边%c%c的权值为：%d\n", x, y, G.Edge[x_pos][y_pos]);
                    }
          }
          else
          {
                    printf("顶点不存在\n");
          }
}

BOOL InsertEdge(MGraph* G, VertexType x, VertexType y, int Edge_Value, int Type)
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);     //x和y的位置
          if (x_pos != -1 && y_pos != -1)                   //两个顶点必须存在
          {
                    if (Type == DIRECTEDGRAPH)     //有向图
                    {
                              G->Edge[x_pos][y_pos] = Edge_Value;
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //无向图
                    {
                              G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = Edge_Value;
                    }
                    G->arcnum++;        //边数自增
                    return TRUE;
          }
          return FALSE;       //插入失败
}

BOOL RemoveEdge(MGraph* G, VertexType x, VertexType y, int Value, int Type)      //在图G中删除边
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);     //x和y的位置
          if (x_pos != -1 && y_pos != -1)                   //两个顶点必须存在
          {
                    if (x_pos != y_pos)           //当前两个图操作的为对角线
                    {
                              if (Type == DIRECTEDGRAPH)     //有向图
                              {
                                        G->Edge[x_pos][y_pos] = Value;          //0或非连通状态
                              }
                              else if (Type == UNDIRECTEDGRAPH)       //无向图
                              {
                                        G->Edge[x_pos][y_pos] = Value;  //0或非连通状态
                                        G->Edge[y_pos][x_pos] = Value; //0或非连通状态
                              }
                              G->arcnum--;        //边数自增
                              return TRUE;
                    }
          }
          return FALSE;       //插入失败
}

BOOL InsertVertex(MGraph* G, VertexType x)      //在图G中插入结点x
{
          if (G->vexnum >= G->MaxVertexNum)       //结点空间满了
          {
                    return FALSE;
          }
          else
          {
                    G->Vex[G->vexnum++] = x;      //新增加一个结点且结点数自增
                    return TRUE;
          }
}

void CreateBatchVertex(MGraph* G, VertexType* arr, int type)          //在图G中批量插入顶点
{
          if (ExtendGraphSize(G, arr, type))   //判断插入的顶点是否需要扩容
          {
                    for (VertexType* p = arr; *p != '\0'; ++p)
                    {
                              if (!InsertVertex(G, *p))
                              {
                                        printf("顶点%c --- 插入失败\n", *p);
                              }
                    }
          }
}

//在图G中删除结点x，该函数包含顶点的有向边和无向边的处理
BOOL RemoveVertex(MGraph* G, VertexType x)
{
          int x_pos = LocateVertex(*G, x);        //寻找顶点下标
          if (x_pos != -1)    //顶点必须存在
          {
                    G->Vex[x_pos] = 0;
                    for (int i = 0; i < G->MaxVertexNum; ++i)   //将该顶点的所有的边删除
                    {
                              G->Edge[x_pos][i] = 0; //行清空删除所有的出边
                              G->Edge[i][x_pos] = 0;//列清空删除所有的入边                    
                    }
                    G->vexnum--;        //结点数-1
                    return TRUE;
          }
          return FALSE;
}


/*在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1*/
int FindFirstNeighbor(MGraph G, VertexType x)              //在图中寻找某一个顶点x的第一个邻接顶点y
{
          int x_pos = LocateVertex(G, x);
          int flag = 0;       //判断是否找到
          int TheFirst = 0;
          if (x_pos != -1)                   //顶点必须存在
          {
                    for (TheFirst = 0; TheFirst < G.MaxVertexNum; ++TheFirst)
                    {
                              if (G.Edge[x_pos][TheFirst] != 0 &&               //判断查找元素是否位于对角线
                                        G.Edge[x_pos][TheFirst] != -1 &&         //为了避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[x_pos][TheFirst] != INFINITYSIZE) 
                              {
                                        flag = 1;
                                        break;
                              }
                    }
          }
          return ((!flag) ? -1 : TheFirst);  //没有找到或返回对应结点下标
}

/*在图G中顶点X的第一个邻接点，返回除了顶点y以外的下一个顶点号，若y是x的最后一个邻接点，则返回-1*/
int FindNextNeighbor(MGraph G, VertexType x, VertexType y)          //在图中寻找某一个顶点x的除了顶点y以外的，第二个邻接顶点
{
          int x_pos = LocateVertex(G, x);     //用于保存x的位置
          int y_pos = LocateVertex(G, y);     //用于保存y的位置
          int flag = 0;       //判断是否找到
          int TheNext = 0;
          if (x_pos != -1 && y_pos != -1)                   //顶点必须存在
          {
                    for (TheNext = y_pos + 1; TheNext < G.MaxVertexNum; ++TheNext)
                    {
                              if (G.Edge[x_pos][TheNext] != 0 &&               //判断查找元素是否位于对角线
                                        G.Edge[x_pos][TheNext] !=-1 &&        //为了避免INT_MAX带来的无符号数解析为-1的问题
                                        G.Edge[x_pos][TheNext] != INFINITYSIZE) //不是自身且必须连通
                              {
                                        flag = 1;
                                        break;
                              }
                    }
          }
          return ((!flag) ? -1 : TheNext);  //没有找到或返回对应结点下标
}