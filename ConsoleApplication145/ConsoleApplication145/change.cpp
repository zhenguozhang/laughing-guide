#include"pch.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

void delete_point(Graph_DG &graph) {
	cout << "请输入您想减少的路由号" << endl;

	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头

	int number, vexnum, edge;

	fin >> vexnum >> edge;
	cin >> number;
	route_number = new int[vexnum];
	for (int i = 0; i < number - 1; i++) route_number[i] = i + 1;
	for (int i = number - 1; i < vexnum; i++) route_number[i] = i + 2;
	Graph_DG graph1(vexnum - 1, edge);
	graph1.createGraph(number);
	graph.vexnum = graph1.vexnum;
	graph.edge = graph1.edge;
	graph.arc = new int*[vexnum - 1];
	graph.dis = new Dis[vexnum - 1];
	for (int i = 0; i < vexnum - 1; i++) {
		graph.arc[i] = new int[vexnum - 1];
		for (int k = 0; k < vexnum - 1; k++) {
			graph.arc[i][k] = graph1.arc[i][k];
		}
	}
	for (int i = 0; i < vexnum - 1; i++) {
		graph.dis[i] = graph1.dis[i];
	}

}
void add_point(Graph_DG &graph) {
	cout << "请输入您想增加的路由个数" << endl;

	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头

	int number, vexnum, edge;

	fin >> vexnum >> edge;
	cin >> number;
	route_number = new int[vexnum + number];
	for (int i = 0; i < vexnum + number; i++) route_number[i] = i + 1;
	Graph_DG graph1(vexnum + number, edge);
	graph1.createGraph(number);
	graph.vexnum = graph1.vexnum;
	graph.edge = graph1.edge;
	graph.arc = new int*[vexnum + number];
	graph.dis = new Dis[vexnum + number];
	for (int i = 0; i < vexnum + number; i++) {
		graph.arc[i] = new int[vexnum + number];
		for (int k = 0; k < vexnum + number; k++) {
			graph.arc[i][k] = graph1.arc[i][k];
		}
	}
	for (int i = 0; i < vexnum + number; i++) {
		graph.dis[i] = graph1.dis[i];
	}

}
void delete_edge(Graph_DG &graph) {
	cout << "请输入想删除的边(格式 v1 v2  e)" << endl;
	int v1 = 0, v2 = 0, v3 = 0;
	cin >> v1 >> v2 >> v3;
	graph.arc[v1 - 1][v2 - 1] = INT_MAX;
	graph.arc[v2 - 1][v1 - 1] = INT_MAX;

}
void add_edge(Graph_DG &graph) {
	cout << "请输入想增加的边(格式 v1 v2  e)" << endl;
	int v1 = 0, v2 = 0, v3 = 0;
	cin >> v1 >> v2 >> v3;
	graph.arc[v1 - 1][v2 - 1] = v3;
	graph.arc[v2 - 1][v1 - 1] = v3;
}

