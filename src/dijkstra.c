#include"dijkstra.h"

void InitDijkstraArray(MGraph G, BOOL** visit, int** path, unsigned int** dist, VertexType StartPoint)  //初始化迪杰斯特拉算法所需要的数组辅助结构
{
		  *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
		  *path = (int*)malloc(sizeof(int) * G.vexnum);
		  *dist = (unsigned int*)malloc(sizeof(unsigned int) * G.vexnum);
		  assert(*visit != NULL || *dist != NULL);
		  memset(*path, -1, sizeof(int) * G.vexnum);		//路径记录数组初始化为-1
		  memset(*dist, 0, sizeof(unsigned int) * G.vexnum);
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					(*dist)[i] = G.Edge[LocateVertex(G, StartPoint)][i];
					(*visit)[i] = FALSE;
					if (G.Edge[LocateVertex(G, StartPoint)][i] != 0 &&	  //不在对角线上
							  G.Edge[LocateVertex(G, StartPoint)][i] != -1		//不是无穷大
							  )			 //如果边是连通的，则初始化为0
					{
							  (*path)[i] = LocateVertex(G, StartPoint);
					}
					else
					{
							  (*path)[i] = -1;
					}
		  }
		  (*visit)[LocateVertex(G, StartPoint)] = TRUE;		//起始的顶点已经被访问
}

void DestroyDijkstraArray(BOOL* visit, int *path,unsigned int* dist)			//销毁迪杰斯特拉算法的结构
{
		  free(visit);
		  free(path);
		  free(dist);
}

BOOL JudgeArray(MGraph G, BOOL* visit)			//判断顶点是否被全部的访问
{
		  BOOL flag = TRUE;
		  for (int i = 0; i < G.vexnum; ++i)
		  {
					if (!visit[i])				  //visit数组的状态都应该为TRUE
					{
							  flag = FALSE;
					}
		  }
		  return flag;
}

void recursive(VertexType *arr,int *path, int prev,int next)
{
	if(prev == -1){
		return;
	}
	recursive(arr,path,path[prev],prev);
	printf("%c->%c ",arr[prev],arr[next]);
}

void DisplayShorestPath(MGraph G,VertexType *arr,VertexType startpos,int *path)
{
	printf("\n--------------display the shortest path route--------------------\n");
	for(int i = 0 ; i < G.vexnum; ++i){	//
		if(i != LocateVertex(G,startpos)){
			int next = i;
			int prev = path[next];

			recursive(arr,path,path[prev],prev);
			printf("%c->%c\n",arr[prev],arr[next]);
		}
	}

}

void DisplayShortestDistance(MGraph G,VertexType *arr,VertexType startpos,unsigned int *distance)
{
	printf("\n--------------display the shortest path distance--------------------\n");
	printf("%s","startpos->destination_pos:distance\n");
	for(int i = 0 ; i < G.vexnum; ++i){	//
		if(i!=LocateVertex(G, startpos) && distance[i]!=INFINITYSIZE){
			printf("%c->%c:%u\n",startpos,arr[i],distance[i]);
		}
	}
}

void DijkstraShortestPath(MGraph G, VertexType *arr,VertexType V)//算法的主程序，需要传递起始的顶点
{
		  BOOL* visit = NULL;
		  int* path = NULL;
		  unsigned int* dist = NULL;
		  InitDijkstraArray(G, &visit, &path, &dist, V);			//初始化
		  while (!JudgeArray(G, visit))
		  {
					int EndPos = -1;			  //记录结束顶点
					unsigned int ShorestEdge = INFINITYSIZE;
					for (int i = 0; i < G.vexnum; ++i)
					{
							  if (!visit[i] && ShorestEdge > dist[i]) //该顶点没有被访问
							  {
										ShorestEdge = dist[i];//选择排序
										EndPos = i;
							  }
					}
					visit[EndPos] = TRUE;		  //设置结束顶点
					for (int i = 0; i < G.vexnum; ++i)
					{
							  if (!visit[i])		//该顶点没有被访问
							  {
										if (
												  G.Edge[EndPos][i] != 0 &&			  //不在对角线
												  G.Edge[EndPos][i] != -1 &&	  //不是非连通
												  G.Edge[EndPos][i] != INFINITYSIZE &&
												  dist[EndPos] + G.Edge[EndPos][i] < dist[i]		  //满足其他的路径长度小于原始路径
												  )
										{
												  dist[i] = dist[EndPos] + G.Edge[EndPos][i];
												  path[i] = EndPos;	  //将终止结点指向起点
										}
							  }
					}
		  }

		DisplayShortestDistance(G,arr,V,dist);
		DisplayShorestPath(G,arr,V,path);

		DestroyDijkstraArray(visit, path, dist);
}