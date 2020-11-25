#pragma once
#include"MGraph.h"

void InitDijkstraArray(MGraph G, BOOL** visit, int** path, unsigned int** dist, VertexType StartPoint); //��ʼ���Ͻ�˹�����㷨����Ҫ�����鸨���ṹ
void DestroyDijkstraArray(BOOL* visit, int* path,unsigned int* dist);			//���ٵϽ�˹�����㷨�Ľṹ
BOOL JudgeArray(MGraph G, BOOL* visit);		//�ж϶����Ƿ�ȫ���ķ���
void DijkstraShortestPath(MGraph G, VertexType V);	//dijkstra���·���㷨����������Ҫ������ʼ�Ķ���