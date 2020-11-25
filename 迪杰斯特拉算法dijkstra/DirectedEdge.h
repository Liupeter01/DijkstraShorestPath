/*
*文件名：DirectedEdge
*文件用途：用于处理以及操作有向边
*/
#pragma once
#include"MGraph.h"

BOOL IsDirectEdgeExist(MGraph G, VertexType x, VertexType y);		  //判断在图G中是否存在有向边<x,y>
void DisplayDirectNeighbors(MGraph G, VertexType x);  //输出在有向图G与结点x相邻边<x,?>

//////////////////////////////////////////////////////////图的结点操作函数/////////////////////////////////////////////////////////////////////
int CalculateEnVertex(MGraph G, VertexType x);			//计算某一个顶点的入度数量
int CalculateOutVertex(MGraph G, VertexType x);			//计算某一个顶点的出度数量

//////////////////////////////////////////////////////////图的边操作函数/////////////////////////////////////////////////////////////////////
BOOL	 InsertDirectEdge(MGraph* G, VertexType x, VertexType y);	  //在图G中添加有向无权边<x,y>  ，权值默认为1
BOOL	 InsertDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);		//在图G中添加有向含权边<x,y>，支持修改权值
BOOL	RemoveDirectEdge(MGraph* G, VertexType x, VertexType y);	  //在有向图G删除有向边<x, y>