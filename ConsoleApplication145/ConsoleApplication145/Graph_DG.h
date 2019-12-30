#pragma once
#include<string>
#include<vector>
#include"Global_variables.h"
using namespace std;
struct Dis {
	vector<int> path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		vector<int>path;
	}
};

class Graph_DG {
public:
	int vexnum;   //ͼ�Ķ������
	int edge;     //ͼ�ı���
	int **arc;   //�ڽӾ���
	Dis * dis;   //��¼�����������·������Ϣ
public:
	//���캯��

	Graph_DG(int vexnum, int edge);

	//��������
	~Graph_DG();
	// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
	//�����1��ʼ���
	bool check_edge_value(int start, int end, int weight);
	//����ͼ
	void createGraph();
	void createGraph(int n, Graph_DG & graph1);
	//��ӡ�ڽӾ���
	void print();
	//�����·��
	void Dijkstra(int begin);
	//��ӡ���·��
	void print_path(int);
	void print_route(int);
};
