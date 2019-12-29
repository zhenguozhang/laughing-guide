#pragma once
#include"Global_variables.h"
#include"Graph_DG.h"
using namespace std;

void delete_edge(Graph_DG &graph);
void add_edge(Graph_DG &graph);
void delete_point(Graph_DG &graph);
void add_point(Graph_DG &graph);
void delete_point(Graph_DG &graph) {
	cout << "请输入您想减少的路由号" << endl;

	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头

	int number, vexnum, edge;

	vexnum=graph.vexnum;
	edge = graph.edge;
	cin >> number;
	int ios = 0;
	for(;ios<vexnum;ios++) { if (route_number[ios] == number) break; }
	int *route_number1;
	route_number1 = new int[vexnum-1];
	for (int i = 0; i < ios; i++) route_number1[i] = route_number[i];
	for (int i = ios; i < vexnum-1; i++) route_number1[i] = route_number[i+1];

	route_number = new int[vexnum -1];
	for (int i = 0; i < vexnum -1; i++) route_number[i] = route_number1[i];
	Graph_DG graph1(vexnum - 1, edge);
	graph.createGraph(ios,graph1);




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
	cout << "请输入您想增加的路由号" << endl;

	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头

	int number, vexnum, edge;

	vexnum = graph.vexnum;
	edge = graph.edge;
	cin >> number;
	int *route_number1;
	route_number1 = new int[vexnum + 1];
	for (int i = 0; i < vexnum; i++) route_number1[i] =route_number[i];
	route_number1[vexnum] = number;

	route_number = new int[vexnum + 1];
	for (int i = 0; i < vexnum+1; i++) route_number[i] = route_number1[i];

	Graph_DG graph1(vexnum + 1, edge);
	//graph1.createGraph(1000);
	for (int i = 0; i < vexnum; i++) {
		for (int k = 0; k < vexnum; k++) {
			graph1.arc[i][k] = graph.arc[i][k];
		}
	}
	for (int i = 0; i < vexnum ; i++) {
		graph.dis[i] = graph1.dis[i];
	}




	graph.vexnum = graph1.vexnum;
	graph.edge = graph1.edge;
	graph.arc = new int*[vexnum +1];
	graph.dis = new Dis[vexnum + 1];
	for (int i = 0; i < vexnum + 1; i++) {
		graph.arc[i] = new int[vexnum + 1];
		for (int k = 0; k < vexnum + 1; k++) {
			graph.arc[i][k] = graph1.arc[i][k];
		}
	}
	for (int i = 0; i < vexnum + 1; i++) {
		graph.dis[i] = graph1.dis[i];
	}

}
void delete_edge(Graph_DG &graph) {
	cout << "请输入想删除的边(格式 v1 v2  e)" << endl;
	int v1 = 0, v2 = 0, v3 = 0;
	cin >> v1 >> v2 >> v3;
	int i = 0;
	int m = 0;
	for (; i < graph.vexnum; i++) { if (route_number[i] == v1) break; }
	for (; m < graph.vexnum; i++) { if (route_number[i] == v2) break; }
	graph.arc[i][m] = INT_MAX;
	graph.arc[m][i] = INT_MAX;

}
void add_edge(Graph_DG &graph) {
	cout << "请输入想增加的边(格式 v1 v2  e)" << endl;
	int v1 = 0, v2 = 0, v3 = 0;
	cin >> v1 >> v2 >> v3;
	int i = 0;
	int m = 0;
	for (; i < graph.vexnum; i++) { if (route_number[i] == v1) break; }
	for (; m < graph.vexnum; m++) { if (route_number[m] == v2) break; }
	graph.arc[i][m] = v3;
	graph.arc[m][i] = v3;
}

