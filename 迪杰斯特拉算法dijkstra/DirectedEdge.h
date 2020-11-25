/*
*�ļ�����DirectedEdge
*�ļ���;�����ڴ����Լ����������
*/
#pragma once
#include"MGraph.h"

BOOL IsDirectEdgeExist(MGraph G, VertexType x, VertexType y);		  //�ж���ͼG���Ƿ���������<x,y>
void DisplayDirectNeighbors(MGraph G, VertexType x);  //���������ͼG����x���ڱ�<x,?>

//////////////////////////////////////////////////////////ͼ�Ľ���������/////////////////////////////////////////////////////////////////////
int CalculateEnVertex(MGraph G, VertexType x);			//����ĳһ��������������
int CalculateOutVertex(MGraph G, VertexType x);			//����ĳһ������ĳ�������

//////////////////////////////////////////////////////////ͼ�ı߲�������/////////////////////////////////////////////////////////////////////
BOOL	 InsertDirectEdge(MGraph* G, VertexType x, VertexType y);	  //��ͼG�����������Ȩ��<x,y>  ��ȨֵĬ��Ϊ1
BOOL	 InsertDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value);		//��ͼG���������Ȩ��<x,y>��֧���޸�Ȩֵ
BOOL	RemoveDirectEdge(MGraph* G, VertexType x, VertexType y);	  //������ͼGɾ�������<x, y>