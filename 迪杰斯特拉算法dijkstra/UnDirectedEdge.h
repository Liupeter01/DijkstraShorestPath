///*
//*�ļ�����No_Direct_Edge
//*�ļ���;�����ڴ����Լ����������
/*
*�ļ�����UnDirectedEdge
*�ļ���;�����ڴ����Լ����������
*/
#pragma once
#include"MGraph.h"

BOOL IsUnDirectEdgeExist(MGraph G, VertexType x, VertexType y);		  //�ж���ͼG���Ƿ���������(x,y)
void DisplayUnDirectNeighbors(MGraph G, VertexType x);  //���������ͼG����x���ڱ�(x,?)

//////////////////////////////////////////////////////////ͼ�ı߲�������/////////////////////////////////////////////////////////////////////
BOOL	 InsertUnDirectEdge(MGraph* G, VertexType x, VertexType y);	  //��ͼG�����������Ȩ��(x,y)  ��ȨֵĬ��Ϊ1
BOOL	 InsertUnDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);		//��ͼG���������Ȩ��(x,y)��֧���޸�Ȩֵ
BOOL	RemoveUnDirectEdge(MGraph* G, VertexType x, VertexType y);	  //������ͼGɾ�������(x,y)