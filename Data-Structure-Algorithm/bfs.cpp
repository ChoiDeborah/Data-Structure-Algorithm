#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#define	BFS							//	BFS (Breadth First Search) 너비 우선 탐색
#define ADJACENT_MATRIX_VERSION_	// 	인접 행렬 버전

#ifdef BFS
// [ ][ ][ ][ ][ ][ ][ ][ ]

struct Vectex
{
	// int data;
};

vector<Vectex> vertices;			// 정점
vector<vector<int>> adjacent;		// 인접 목록
vector<bool> discovered;			// 발견 여부

void CreateGraph()
{
	vertices.reserve(6);
	adjacent = vector<vector<int>>(6);

#ifdef ADJACENT_MATRIX_VERSION_
	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 },
	};
#else // ADJACENT_MATRIX_VERSION_
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
#endif // ADJACENT_MATRIX_VERSION_
}

void Bfs(int here)
{
	vector<int> parent(6, -1);		// 누구에 의해 발견 되었는지?
	vector<int> distance(6, -1);	// 시작점에서 얼마나 떨어져 있는지?

	queue<int> q;
	q.push(here);
	discovered[here] = true;

	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited : " << here << endl;

#ifdef ADJACENT_MATRIX_VERSION_
		//인접 행렬 버전
		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;
#else // ADJACENT_MATRIX_VERSION_
		// 인접 리스트 버전
		for (int there : adjacent[here])
		{
#endif // ADJACENT_MATRIX_VERSION_
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);

	Bfs(0);
}

#endif // BFS
