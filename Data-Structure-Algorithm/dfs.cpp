#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

//#define DFS						// DFS (Depth First Search) 깊이 우선 탐색
#define ADJACENT_MATRIX_VERSION_	// 인접 행렬 버전
//#define REVERSE					// 반대로 순회

#ifdef DFS
// [ ][ ][ ][ ][ ][ ][ ][ ]

struct Vectex
{
	// int data;
};

vector<Vectex> vertices;			// 정점
vector<vector<int>> adjacent;		// 인접 목록
vector<bool> visited;				// 방문 목록

void CreateGraph()
{
	vertices.reserve(6);
	adjacent = vector<vector<int>>(6);


#ifdef ADJACENT_MATRIX_VERSION_
	// 인접 행렬
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
	// 인접 리스트
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
#endif // ADJACENT_MATRIX_VERSION_
}

//DFS

//Dfs(0)
//- Dfs(1)
//-- Dfs(2)
//-- Dfs(3)
//--- Dfs(4)

void Dfs(int here)
{
	// 방문!
	visited[here] = true;
	cout << "Visited : " << here << endl;

	// 모든 인접 정점을 순회한다
#ifdef ADJACENT_MATRIX_VERSION_
	// 인접 행렬 버전
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳이 있으면 방문한다
		if (there == false)
			Dfs(there);
	}
#else // ADJACENT_MATRIX_VERSION_
	// 인접 리스트 version
	for (int i = 0; i < adjacent[here].size(); ++i)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}
#endif // ADJACENT_MATRIX_VERSION_
	}

void DfsAll()
{
	visited = vector<bool>(6, false);

#ifdef REVERSE
	for (int i = 5; i >= 0; i--)
#else // REVERSE
	for (int i = 0; i < 6; i++)
#endif // REVERSE
	{
		if (visited[i] == false)
			Dfs(i);
	}
}

int main()
{
	CreateGraph();

	//visited = vector<bool>(6, false);
	//Dfs(0);

	DfsAll();
}
#endif // DFS