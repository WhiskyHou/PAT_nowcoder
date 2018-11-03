#include<iostream>
#include<stack>
#include<queue>
#include<iomanip>

using namespace std;

struct Node {
	int address;
	int data;
	int next;
};

int main() {

	int start, n, k;
	cin >> start >> n >> k;

	int data[100000];
	int next[100000];
	for (int i = 0; i < 100000; i++)data[i] = next[i] = -1;

	for (int i = 0; i < n; i++) {
		int address;
		cin >> address;
		cin >> data[address] >> next[address];
	}

	// 按顺序构造节点队列
	int realN = 0;
	int current = start;
	queue<Node> nodes;
	while (current != -1) {
		Node node;
		node.address = current;
		node.data = data[current];
		node.next = next[current];
		nodes.push(node);
		current = next[current];
		realN++;
	}

	// 反转的逻辑和输出
	bool isFirstNode = true;
	int numberOfGroups = realN / k;
	stack<Node>* groups = new stack<Node>[numberOfGroups]();
	for (int i = 0; i < numberOfGroups; i++) {
		for (int j = 0; j < k; j++) {
			Node node = nodes.front();
			nodes.pop();
			groups[i].push(node);
		}

		for (int j = 0; j < k; j++) {
			Node node = groups[i].top();
			groups[i].pop();
			if (isFirstNode) {
				cout << setfill('0') << setw(5) << node.address << " " << node.data << " ";
				isFirstNode = false;
			}
			else {
				cout << setfill('0') << setw(5) << node.address << endl << setfill('0') << setw(5) << node.address << " " << node.data << " ";
			}
		}
	}

	// 剩余的部分按顺序输出
	while (nodes.size() != 0) {
		Node node = nodes.front();
		nodes.pop();
		if (isFirstNode) {
			cout << setfill('0') << setw(5) << node.address << " " << node.data << " ";
			isFirstNode = false;
		}
		else {
			cout << setfill('0') << setw(5) << node.address << endl << setfill('0') << setw(5) << node.address << " " << node.data << " ";
		}
	}

	// 最后一位地址一定是-1
	cout << -1;

	return 0;
}