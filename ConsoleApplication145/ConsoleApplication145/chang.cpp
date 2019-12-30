#include "pch.h"
#include "chang.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

void delete_point(Graph_DG &graph) {
	cout << "请输入您想减少的路由号" << endl;
	cout << "zhaozepeng" << endl;
	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头

	int number, vexnum, edge;

	vexnum = graph.vexnum;
	edge = graph.edge;
	cin >> number;
	int ios = 0;
	int flag = 1;
	for (; ios < vexnum; ios++) {
		if (route_number[ios] == number) {
			flag = 0; break;
		}
	}
	if (flag == 1) { cout << "找不到这个路由器，请检查后重新输入" << endl; return; }
	int *route_number1;
	route_number1 = new int[vexnum - 1];
	for (int i = 0; i < ios; i++) route_number1[i] = route_number[i];
	for (int i = ios; i < vexnum - 1; i++) route_number1[i] = route_number[i + 1];

	route_number = new int[vexnum - 1];
	for (int i = 0; i < vexnum - 1; i++) route_number[i] = route_number1[i];
	Graph_DG graph1(vexnum - 1, edge);
	graph.createGraph(ios, graph1);




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
	cout << "删除成功！" << endl;

}
void add_point(Graph_DG &graph) {
	cout << "请输入您想增加的路由号" << endl;

	fin.clear();//必须先调用这个，清除flag
	fin.seekg(0);//才能用这个设定到文件开头
	int number, vexnum, edge;
	cin >> number;
	vexnum = graph.vexnum;
	edge = graph.edge;
	for (int i = 0; i < vexnum; i++) {
		if (route_number[i] == number) {
			cout << "该路由器号已经存在，请重新输入"; return;
		}
	}


	int *route_number1;
	route_number1 = new int[vexnum + 1];
	for (int i = 0; i < vexnum; i++) route_number1[i] = route_number[i];
	route_number1[vexnum] = number;

	route_number = new int[vexnum + 1];
	for (int i = 0; i < vexnum + 1; i++) route_number[i] = route_number1[i];

	Graph_DG graph1(vexnum + 1, edge);
	//graph1.createGraph(1000);
	for (int i = 0; i < vexnum; i++) {
		for (int k = 0; k < vexnum; k++) {
			graph1.arc[i][k] = graph.arc[i][k];
		}
	}
	for (int i = 0; i < vexnum; i++) {
		graph.dis[i] = graph1.dis[i];
	}




	graph.vexnum = graph1.vexnum;
	graph.edge = graph1.edge;
	graph.arc = new int*[vexnum + 1];
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
	cout << "增加成功！" << endl;
}
void delete_edge(Graph_DG &graph) {
	cout << "请输入想删除的边(格式 v1 v2  )" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	int i = 0;
	int m = 0;
	int flag = 0;
	for (; i < graph.vexnum; i++) { if (route_number[i] == v1) { flag++; break; } }
	for (; m < graph.vexnum; m++) { if (route_number[m] == v2) { flag++; break; } }
	if (flag != 2 || graph.arc[i][m] == INT_MAX) { cout << "找不到您想要的点，请确认后重新输入" << endl << endl; return; }
	graph.arc[i][m] = INT_MAX;
	graph.arc[m][i] = INT_MAX;
	cout << "删除成功" << endl;
}
void add_edge(Graph_DG &graph) {
	cout << "请输入想增加的边(格式 v1 v2  e)" << endl;
	int v1 = 0, v2 = 0, v3 = 0;
	cin >> v1 >> v2 >> v3;
	int i = 0;
	int m = 0;
	int flag = 0;
	for (; i < graph.vexnum; i++) { if (route_number[i] == v1) { flag++; break; } }
	for (; m < graph.vexnum; m++) { if (route_number[m] == v2) { flag++; break; } }
	if (flag != 2) { cout << "找不到您想要的点，请确认后重新输入" << endl << endl; return; }
	graph.arc[i][m] = v3;
	graph.arc[m][i] = v3;
	cout << "增加成功" << endl;
}
