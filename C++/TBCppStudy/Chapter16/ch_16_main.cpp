#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

int main(void)
{
	// list는 자체적으로 sort와 reverse가 있음. container에서 찾아야함.
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

// 16.1 Standard Template Libraries(STL)와 Containers 소개
 // STL
 // 구성요소 - 1.알고리즘 2. 컨테이너 3. Functions 4. iterators 
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
 
 
// 16.2 STL 반복자(Iterators) 소개 
/*
int main(void)
{
	// 	list, set, map(make_pair) 다 사용 가능
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

// 16.3 STL 알고리즘 소개
 // 많은 양이 있으므로 하면서 필요한 것이 있는지 찾기
/*
using namespace std;

int main(void)
{
	// list는 자체적으로 sort와 reverse가 있음. container에서 찾아야함.
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