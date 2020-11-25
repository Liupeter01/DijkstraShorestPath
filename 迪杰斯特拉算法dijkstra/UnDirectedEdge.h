///*
//*文件名：No_Direct_Edge
//*文件用途：用于处理以及操作无向边
/*
*文件名：UnDirectedEdge
*文件用途：用于处理以及操作无向边
*/
#pragma once
#include"MGraph.h"

BOOL IsUnDirectEdgeExist(MGraph G, VertexType x, VertexType y);		  //判断在图G中是否存在无向边(x,y)
void DisplayUnDirectNeighbors(MGraph G, VertexType x);  //输出在有向图G与结点x相邻边(x,?)

//////////////////////////////////////////////////////////图的边操作函数/////////////////////////////////////////////////////////////////////
BOOL	 InsertUnDirectEdge(MGraph* G, VertexType x, VertexType y);	  //在图G中添加无向无权边(x,y)  ，权值默认为1
BOOL	 InsertUnDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);		//在图G中添加无向含权边(x,y)，支持修改权值
BOOL	RemoveUnDirectEdge(MGraph* G, VertexType x, VertexType y);	  //在有向图G删除无向边(x,y)