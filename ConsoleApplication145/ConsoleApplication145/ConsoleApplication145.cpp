#include"pch.h"
#include"Graph_DG.h"
#include"Global_variables.h"
#include"change.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;



//检验输入边数和顶点数的值是否有效，可以自己推算为啥：
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}

int main() {
	fin.open("test.txt", ios::in);
	if (!fin)
	{
		cout << "Fail to open the file!" << endl;
		exit(0);
	}
	int vexnum; int edge;
	fin >> vexnum >> edge;
	route_number = new int[vexnum];
	for (int i = 0; i < vexnum; i++) route_number[i] = i + 1;


	while (!check(vexnum, edge)) {
		cout << "输入的数值不合法，请重新输入" << endl;
		cin >> vexnum >> edge;
	}
	Graph_DG graph(vexnum, edge);
	graph.createGraph();

	while (1) {
		cout << "请选择您想选择的项目" << endl;
		cout << "1.增加点      2删除点        3.显示路由表" << endl;
		cout << "4.增加边      5删除边        6.退出" << endl;
		cout << "7.显示矩阵表" << endl;
		int choice;
		int rou_num;
		cin >> choice;
		if (choice == 1)  add_point(graph);
		if (choice == 2) { delete_point(graph); cout << graph.arc[2][3] << endl; }
		if (choice == 3)
		{
			cout << "请输入您想查看的路由器号" << endl;
			
			cin >> rou_num;
			graph.Dijkstra(rou_num);
			graph.print_route(rou_num);
			//graph.print_path(rou_num);
		}
		if (choice == 4)  add_edge(graph);
		if (choice == 5) delete_edge(graph);
		if (choice == 6)   exit(0);
		if (choice == 7)   graph.print();

		//graph.print();
		

	}
	return 0;
}




