#include"MGraph.h"

void InitGraph(MGraph* G)               //ͼG�ĳ�ʼ��
{
          G->MaxVertexNum = Default_Vertices_Size;                    //Ĭ�Ͻ��Ĵ�С
          G->arcnum =  G->vexnum = 0;      //û�н��û�б�
          G->EdgeValue = FALSE;
}

void DestroyGraph(MGraph* G)            //ͼG������
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

int LocateVertex(MGraph G, VertexType x)   //��ͼG���ҵ������±�
{
          int x_pos = 0;
          for (x_pos; x_pos < G.MaxVertexNum; ++x_pos)
          {
                    if (G.Vex[x_pos] != 0 && G.Vex[x_pos] == x)
                    {
                              return x_pos;
                    }
          }
          return -1;          //����
}

void DisplayGraph(MGraph G)             //ͼG�����
{
          printf("    ");                 //�ո����
          for (int i = 0; i < G.vexnum; ++i)                //�������
          {
                    printf("%-4c  ", G.Vex[i]);
          }
          printf("\n");
          for (int i = 0; i < G.vexnum; ++i)                //�������
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

BOOL ExtendGraphSize(MGraph* G,VertexType*arr, int type)                //ͼG�Ŀռ�����Լ�Ĭ�Ͽռ����ݺ���
{
          G->EdgeValue = ((type == GRAPHWITHVALUE) ? TRUE : FALSE);   //�л�ͼ��״̬���жϵ�ǰ�Ƿ�Ϊ��Ȩͼ
          int GraphSize = (((int)strlen(arr) > G->MaxVertexNum) ? (int)strlen(arr) : G->MaxVertexNum);//ͼ�Ĵ�С������������Ĭ�Ͽռ���
          G->Vex = (VertexType*)calloc(GraphSize, sizeof(VertexType));
          G->Edge = (EdgeType**)calloc(GraphSize, sizeof(EdgeType*));         //����
          assert(G->Vex != NULL && G->Edge != NULL);
          if (G->Vex == NULL || G->Edge == NULL)
          {
                    return FALSE;
          }
          memset(G->Edge, ((type == NORMALGRAPH) ? 0 : INFINITYSIZE), sizeof(EdgeType*) * GraphSize);
          for (int i = 0; i < GraphSize; ++i)
          {
                    G->Edge[i] = (EdgeType*)calloc(GraphSize, sizeof(EdgeType));    //����
                    assert(G->Edge[i] != NULL);
                    if (G->Edge[i] == NULL)
                    {
                              return FALSE;
                    }
                    memset(G->Edge[i], ((type == NORMALGRAPH) ? 0 : INFINITYSIZE), sizeof(EdgeType) * GraphSize);  //ȫ����ʼ��Ϊ0
          }
          G->MaxVertexNum = GraphSize;         //��չ�������
          if (type != NORMALGRAPH)         //�����ͼ��һ����Ȩͼ�������еĶԽ������Ϊ0
          {
                    for (int i = 0; i < G->MaxVertexNum; ++i)
                    {
                              G->Edge[i][i] = 0;  //�Խ���Ϊ0
                    }
          }
          return TRUE;
}

void ShowEdgeValue(MGraph G, VertexType x, VertexType y)    //���ͼ��ĳ���ߵ�Ȩֵ
{
          int x_pos = LocateVertex(G, x);                   //Ѱ�ҵ�һ������x�ڱ��λ��
          int y_pos = LocateVertex(G, y);                   //Ѱ�ҵڶ�������y�ڱ��λ��

          if (x_pos != -1 && y_pos != -1)                   //������������Ǵ��ڵ�
          {
                    if (G.Edge[x_pos][y_pos] == 0 ||                  //���Խ���
                              G.Edge[x_pos][y_pos] == -1 ||            //Ϊ�˱���INT_MAX�������޷���������Ϊ-1������
                              G.Edge[x_pos][y_pos] == INFINITYSIZE)
                    {
                              printf("��%c%c������\n", x, y);
                    }
                    else if (G.Edge[x_pos][y_pos] == 1)
                    {
                              printf("�ñ�ʹ����Ȩͼ��Ĭ��Ȩֵ1\n");
                    }
                    else if(G.Edge[x_pos][y_pos] != 0 &&                  //���Խ���
                              G.Edge[x_pos][y_pos] != -1 &&            //Ϊ�˱���INT_MAX�������޷���������Ϊ-1������
                              G.Edge[x_pos][y_pos] != INFINITYSIZE)
                    {
                              printf("��%c%c��ȨֵΪ��%d\n", x, y, G.Edge[x_pos][y_pos]);
                    }
          }
          else
          {
                    printf("���㲻����\n");
          }
}

BOOL InsertEdge(MGraph* G, VertexType x, VertexType y, int Edge_Value, int Type)
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);     //x��y��λ��
          if (x_pos != -1 && y_pos != -1)                   //��������������
          {
                    if (Type == DIRECTEDGRAPH)     //����ͼ
                    {
                              G->Edge[x_pos][y_pos] = Edge_Value;
                    }
                    else if (Type == UNDIRECTEDGRAPH)       //����ͼ
                    {
                              G->Edge[x_pos][y_pos] = G->Edge[y_pos][x_pos] = Edge_Value;
                    }
                    G->arcnum++;        //��������
                    return TRUE;
          }
          return FALSE;       //����ʧ��
}

BOOL RemoveEdge(MGraph* G, VertexType x, VertexType y, int Value, int Type)      //��ͼG��ɾ����
{
          int x_pos = LocateVertex(*G, x);
          int y_pos = LocateVertex(*G, y);     //x��y��λ��
          if (x_pos != -1 && y_pos != -1)                   //��������������
          {
                    if (x_pos != y_pos)           //��ǰ����ͼ������Ϊ�Խ���
                    {
                              if (Type == DIRECTEDGRAPH)     //����ͼ
                              {
                                        G->Edge[x_pos][y_pos] = Value;          //0�����ͨ״̬
                              }
                              else if (Type == UNDIRECTEDGRAPH)       //����ͼ
                              {
                                        G->Edge[x_pos][y_pos] = Value;  //0�����ͨ״̬
                                        G->Edge[y_pos][x_pos] = Value; //0�����ͨ״̬
                              }
                              G->arcnum--;        //��������
                              return TRUE;
                    }
          }
          return FALSE;       //����ʧ��
}

BOOL InsertVertex(MGraph* G, VertexType x)      //��ͼG�в�����x
{
          if (G->vexnum >= G->MaxVertexNum)       //���ռ�����
          {
                    return FALSE;
          }
          else
          {
                    G->Vex[G->vexnum++] = x;      //������һ������ҽ��������
                    return TRUE;
          }
}

void CreateBatchVertex(MGraph* G, VertexType* arr, int type)          //��ͼG���������붥��
{
          if (ExtendGraphSize(G, arr, type))   //�жϲ���Ķ����Ƿ���Ҫ����
          {
                    for (VertexType* p = arr; *p != '\0'; ++p)
                    {
                              if (!InsertVertex(G, *p))
                              {
                                        printf("����%c --- ����ʧ��\n", *p);
                              }
                    }
          }
}

//��ͼG��ɾ�����x���ú����������������ߺ�����ߵĴ���
BOOL RemoveVertex(MGraph* G, VertexType x)
{
          int x_pos = LocateVertex(*G, x);        //Ѱ�Ҷ����±�
          if (x_pos != -1)    //����������
          {
                    G->Vex[x_pos] = 0;
                    for (int i = 0; i < G->MaxVertexNum; ++i)   //���ö�������еı�ɾ��
                    {
                              G->Edge[x_pos][i] = 0; //�����ɾ�����еĳ���
                              G->Edge[i][x_pos] = 0;//�����ɾ�����е����                    
                    }
                    G->vexnum--;        //�����-1
                    return TRUE;
          }
          return FALSE;
}


/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬�����򷵻ض���ţ���û���򷵻�-1*/
int FindFirstNeighbor(MGraph G, VertexType x)              //��ͼ��Ѱ��ĳһ������x�ĵ�һ���ڽӶ���y
{
          int x_pos = LocateVertex(G, x);
          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheFirst = 0;
          if (x_pos != -1)                   //����������
          {
                    for (TheFirst = 0; TheFirst < G.MaxVertexNum; ++TheFirst)
                    {
                              if (G.Edge[x_pos][TheFirst] != 0 &&               //�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                                        G.Edge[x_pos][TheFirst] != -1 &&         //Ϊ�˱���INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[x_pos][TheFirst] != INFINITYSIZE) 
                              {
                                        flag = 1;
                                        break;
                              }
                    }
          }
          return ((!flag) ? -1 : TheFirst);  //û���ҵ��򷵻ض�Ӧ����±�
}

/*��ͼG�ж���X�ĵ�һ���ڽӵ㣬���س��˶���y�������һ������ţ���y��x�����һ���ڽӵ㣬�򷵻�-1*/
int FindNextNeighbor(MGraph G, VertexType x, VertexType y)          //��ͼ��Ѱ��ĳһ������x�ĳ��˶���y����ģ��ڶ����ڽӶ���
{
          int x_pos = LocateVertex(G, x);     //���ڱ���x��λ��
          int y_pos = LocateVertex(G, y);     //���ڱ���y��λ��
          int flag = 0;       //�ж��Ƿ��ҵ�
          int TheNext = 0;
          if (x_pos != -1 && y_pos != -1)                   //����������
          {
                    for (TheNext = y_pos + 1; TheNext < G.MaxVertexNum; ++TheNext)
                    {
                              if (G.Edge[x_pos][TheNext] != 0 &&               //�жϲ���Ԫ���Ƿ�λ�ڶԽ���
                                        G.Edge[x_pos][TheNext] !=-1 &&        //Ϊ�˱���INT_MAX�������޷���������Ϊ-1������
                                        G.Edge[x_pos][TheNext] != INFINITYSIZE) //���������ұ�����ͨ
                              {
                                        flag = 1;
                                        break;
                              }
                    }
          }
          return ((!flag) ? -1 : TheNext);  //û���ҵ��򷵻ض�Ӧ����±�
}