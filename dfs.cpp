#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

//#define DFS						// DFS (Depth First Search) ���� �켱 Ž��
#define ADJACENT_MATRIX_VERSION_	// ���� ��� ����
//#define REVERSE					// �ݴ�� ��ȸ

#ifdef DFS
// [ ][ ][ ][ ][ ][ ][ ][ ]

struct Vectex
{
	// int data;
};

vector<Vectex> vertices;			// ����
vector<vector<int>> adjacent;		// ���� ���
vector<bool> visited;				// �湮 ���

void CreateGraph()
{
	vertices.reserve(6);
	adjacent = vector<vector<int>>(6);


#ifdef ADJACENT_MATRIX_VERSION_
	// ���� ���
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
	// ���� ����Ʈ
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
	// �湮!
	visited[here] = true;
	cout << "Visited : " << here << endl;

	// ��� ���� ������ ��ȸ�Ѵ�
#ifdef ADJACENT_MATRIX_VERSION_
	// ���� ��� ����
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ������ �湮�Ѵ�
		if (there == false)
			Dfs(there);
	}
#else // ADJACENT_MATRIX_VERSION_
	// ���� ����Ʈ version
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