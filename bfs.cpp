#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

#define	BFS							//	BFS (Breadth First Search) �ʺ� �켱 Ž��
#define ADJACENT_MATRIX_VERSION_	// 	���� ��� ����

#ifdef BFS
// [ ][ ][ ][ ][ ][ ][ ][ ]

struct Vectex
{
	// int data;
};

vector<Vectex> vertices;			// ����
vector<vector<int>> adjacent;		// ���� ���
vector<bool> discovered;			// �߰� ����

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
	vector<int> parent(6, -1);		// ������ ���� �߰� �Ǿ�����?
	vector<int> distance(6, -1);	// ���������� �󸶳� ������ �ִ���?

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
		//���� ��� ����
		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0)
				continue;
#else // ADJACENT_MATRIX_VERSION_
		// ���� ����Ʈ ����
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
