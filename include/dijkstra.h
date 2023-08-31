#pragma once
#include"MGraph.h"

void InitDijkstraArray(MGraph G, BOOL** visit, int** path, unsigned int** dist, VertexType StartPoint); //初始化迪杰斯特拉算法所需要的数组辅助结构
void DestroyDijkstraArray(BOOL* visit, int* path,unsigned int* dist);			//销毁迪杰斯特拉算法的结构
BOOL JudgeArray(MGraph G, BOOL* visit);		//判断顶点是否被全部的访问
void DijkstraShortestPath(MGraph G, VertexType V);	//dijkstra最短路径算法的主程序，需要传递起始的顶点