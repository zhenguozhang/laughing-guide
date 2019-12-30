#include"pch.h"
#include"Graph_DG.h"
#include"Global_variables.h"
#include"chang.h"
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
void show() {
	
}

int main() {
	fin.open("testt.txt", ios::in);
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
		int m = 0;
		int flag = 1;
		cin >> choice;
		if (choice == 1)  add_point(graph);
		if (choice == 2) { delete_point(graph); }
		if (choice == 3)
		{
			cout << "请输入您想查看的路由器号" << endl;

			cin >> rou_num;
			for (; m < graph.vexnum; m++) {
				if (route_number[m] == rou_num) { flag = 0; break; }
			}
				if (flag == 0) {
					rou_num = m + 1;
					graph.Dijkstra(rou_num);
					graph.print_route(rou_num);
					//graph.print_path(rou_num);
				}
				else { cout << "该路由器号不存在，请重新输入" << endl; }
			
		}
		if (choice == 4)  add_edge(graph);
		if (choice == 5) delete_edge(graph);
		if (choice == 6)   exit(0);
		if (choice == 7)   graph.print();

		//graph.print();
		

	}
	return 0;
}


	