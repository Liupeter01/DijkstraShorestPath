#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

/*数据类型设定*/
#define VertexType char
#define EdgeType int

/*非连通设定*/
#define INFINITYSIZE INT_MAX    //不连通

/*图的类型设定*/
#define DIRECTEDGRAPH 0x33    //有向图
#define UNDIRECTEDGRAPH 0x44  //无向图

/*图是否含有权*/
#define GRAPHWITHVALUE 0x55    //有权图
#define NORMALGRAPH 0x66  //无权图

/*边的默认大小设定*/
#define Default_Vertices_Size 10        //默认的大小

/*边的构造结构体*/
typedef struct Pair           
{
          VertexType VexOne;  //顶点名称
          VertexType VexTwo;  //顶点名称
          int distance;                 //权
}Pair;

/*邻接矩阵数据结构*/
typedef struct MGraph                      //邻接矩阵数据结构
{
          VertexType *Vex;                    //结点名称
          EdgeType **Edge;                  //边
          int vexnum;                             //当前结点的数量
          int arcnum;                              //当前边的数量
          int MaxVertexNum;                //最大的顶点数量
          BOOLEAN EdgeValue;   
          //图如果有权重，则开启非连通设定
          //图如果无权重，则使用0作为非连通
}MGraph;

//////////////////////////////////////////////////////////图的基本操作函数/////////////////////////////////////////////////////////////////////
void InitGraph(MGraph* G);                 //图G的初始化
void DestroyGraph(MGraph* G);          //图G的销毁
void DisplayGraph(MGraph G);            //图G的输出

BOOL ExtendGraphSize(MGraph* G, VertexType* arr, int type);         //图G的空间分配以及默认空间扩容函数
int LocateVertex(MGraph G, VertexType x);                  //在图G中找到顶点下标
void ShowEdgeValue(MGraph G, VertexType x, VertexType y);            //输出图中某条边的权值

//////////////////////////////////////////////////////////图的边操作函数/////////////////////////////////////////////////////////////////////
/*需要传递图，以及边的两个顶点，边的权(默认为1)，图的类型*/
BOOL InsertEdge(MGraph* G, VertexType x, VertexType y, int Edge_Value, int Type);         //在图中插入边

/*需要传递图，以及边的两个顶点，删除后边的值(可以为0也可以是INFINITYSIZE)，图的类型*/
BOOL RemoveEdge(MGraph* G, VertexType x, VertexType y, int Value, int Type);      //在图G中删除边

//////////////////////////////////////////////////////////图的结点操作函数/////////////////////////////////////////////////////////////////////
BOOL InsertVertex(MGraph* G, VertexType x);        //在图G中插入结点x
void CreateBatchVertex(MGraph* G, VertexType* arr,int type);                   //在图G中批量插入顶点
BOOL RemoveVertex(MGraph* G, VertexType x);                  //在图G中删除结点x

//////////////////////////////////////////////////////////图的邻接顶点操作函数/////////////////////////////////////////////////////////////////////
/*在图G中顶点X的第一个邻接点，若有则返回顶点号，若没有则返回-1*/
int FindFirstNeighbor(MGraph G, VertexType x);              //在图中寻找某一个顶点x的第一个邻接顶点y

/*在图G中顶点X的第一个邻接点，返回除了顶点y以外的下一个顶点号，若y是x的最后一个邻接点，则返回-1*/
int FindNextNeighbor(MGraph G, VertexType x, VertexType y);           //在图中寻找某一个顶点x的除了顶点y以外的，第二个邻接顶点