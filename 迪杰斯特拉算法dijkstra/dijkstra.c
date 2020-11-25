#include"dijkstra.h"

void InitDijkstraArray(MGraph G, BOOL** visit, int** path, unsigned int** dist, VertexType StartPoint)  //��ʼ���Ͻ�˹�����㷨����Ҫ�����鸨���ṹ
{
		  *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
		  *path = (int*)malloc(sizeof(int) * G.vexnum);
		  *dist = (unsigned int*)malloc(sizeof(unsigned int) * G.vexnum);
		  assert(*visit != NULL || *dist != NULL);
		  memset(*path, -1, sizeof(int) * G.vexnum);		//·����¼�����ʼ��Ϊ-1
		  memset(*dist, 0, sizeof(unsigned int) * G.vexnum);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*dist)[i] = G.Edge[LocateVertex(G, StartPoint)][i];
					(*visit)[i] = FALSE;
					if (G.Edge[LocateVertex(G, StartPoint)][i] != 0 &&	  //���ڶԽ�����
							  G.Edge[LocateVertex(G, StartPoint)][i] != -1		//���������
							  )			 //���������ͨ�ģ����ʼ��Ϊ0
					{
							  (*path)[i] = LocateVertex(G, StartPoint);
					}
					else
					{
							  (*path)[i] = -1;
					}
		  }
		  (*visit)[LocateVertex(G, StartPoint)] = TRUE;		//��ʼ�Ķ����Ѿ�������
}

void DestroyDijkstraArray(BOOL* visit, int *path,unsigned int* dist)			//���ٵϽ�˹�����㷨�Ľṹ
{
		  free(visit);
		  free(path);
		  free(dist);
}

BOOL JudgeArray(MGraph G, BOOL* visit)			//�ж϶����Ƿ�ȫ���ķ���
{
		  BOOL flag = TRUE;
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (!visit[i])				  //visit�����״̬��Ӧ��ΪTRUE
					{
							  flag = FALSE;
					}
		  }
		  return flag;
}

void DijkstraShortestPath(MGraph G, VertexType V)//�㷨����������Ҫ������ʼ�Ķ���
{
		  BOOL* visit = NULL;
		  int* path = NULL;
		  unsigned int* dist = NULL;
		  InitDijkstraArray(G, &visit, &path, &dist, V);			//��ʼ��

		  int EndPos = -1;			  //��¼��������
		  while (!JudgeArray(G, visit))
		  {
					unsigned int ShorestEdge = INFINITYSIZE;
					for (int i = 0; i < G.vexnum; ++i)
					{
							  if (!visit[i] && ShorestEdge > dist[i]) //�ö���û�б�����
							  {
										ShorestEdge = dist[i];//ѡ������
										EndPos = i;
							  }
					}
					visit[EndPos] = TRUE;		  //���ý�������
					for (int i = 0; i < G.vexnum; ++i)
					{
							  if (!visit[i])		//�ö���û�б�����
							  {
										if (
												  G.Edge[EndPos][i] != 0 &&			  //���ڶԽ���
												  G.Edge[EndPos][i] != -1 &&	  //���Ƿ���ͨ
												  G.Edge[EndPos][i] != INFINITYSIZE &&
												  dist[EndPos] + G.Edge[EndPos][i] < dist[i]		  //����������·������С��ԭʼ·��
												  )
										{
												  dist[i] = dist[EndPos] + G.Edge[EndPos][i];
												  path[i] = EndPos;	  //����ֹ���ָ�����
										}
							  }
					}
		  }
		  DestroyDijkstraArray(visit, path, dist);
}