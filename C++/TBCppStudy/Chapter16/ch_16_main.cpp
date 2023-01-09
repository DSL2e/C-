#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

int main(void)
{
	// list�� ��ü������ sort�� reverse�� ����. container���� ã�ƾ���.
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(),3);
	container.insert(itr, 128);

	for (auto& e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	for (auto& e : container) cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());
	for (auto& e : container) cout << e << " ";
	cout << endl;

	return 0;
}

// 16.1 Standard Template Libraries(STL)�� Containers �Ұ�
 // STL
 // ������� - 1.�˰��� 2. �����̳� 3. Functions 4. iterators 
 // cppreference.com
 // container
/*
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>

using namespace std;

void sequence_containers()
{
	// #include<vector>
	{
		vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		for (auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	// #include<deque>
	{
		deque<int> deq;
		for (int i = 0 ;i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (auto& e : deq)
			cout << e << " ";
		cout << endl;
	}
}

void associative_containers()
{
	// #include<set>
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// multiset : duplication is allowed
	{
		std::multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto& e : str_set)
			cout << e << " ";
		cout << endl;
	}
	// #include<map> map : key/value
	{
		std::map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;

		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}

	// multimap : dulicated keys
	{
		std::multimap<char, int> map;
		map.insert(std::pair<char, int>('a', 10));
		map.insert(std::pair<char, int>('b', 10));
		map.insert(std::pair<char, int>('c', 10));
		map.insert(std::pair<char, int>('a', 100));

		cout << map.count('a') << endl;

		for (auto& e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}

}

void container_adapters()
{
	// #include<stack>
	{
		cout << "Stack" << endl;

		std::stack<int> stack;
		stack.push(1); // push adds a copy
		stack.emplace(2); // emplace constructs a new object
		stack.emplace(3);
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}
	//  #include<queue>
	{
		cout << "queue" << endl;
		std::queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;
	}

	// Prioity queue(Heap)
	{
		cout << "Priority queue" << endl;

		std::priority_queue<int> heap;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			heap.push(n);

		for (int i = 0; i < 10; ++i)
		{
			cout << heap.top() << endl;
			heap.pop();
		}
	}
}

int main(void)
{
	//sequence_containers();

	//associative_containers();

	//container_adapters();
	return 0;
}
*/
 
 
// 16.2 STL �ݺ���(Iterators) �Ұ� 
/*
int main(void)
{
	// 	list, set, map(make_pair) �� ��� ����
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//vector<int>::iterator
	vector<int>::const_iterator itr;
	itr = container.begin();

	while (itr != container.end())
	{
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	return 0;
}
*/

// 16.3 STL �˰��� �Ұ�
 // ���� ���� �����Ƿ� �ϸ鼭 �ʿ��� ���� �ִ��� ã��
/*
using namespace std;

int main(void)
{
	// list�� ��ü������ sort�� reverse�� ����. container���� ã�ƾ���.
	vector<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(),3);
	container.insert(itr, 128);

	for (auto& e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	for (auto& e : container) cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());
	for (auto& e : container) cout << e << " ";
	cout << endl;

	return 0;
}
*/