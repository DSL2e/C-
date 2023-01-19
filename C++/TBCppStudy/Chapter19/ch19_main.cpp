#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class Cost
{
private:
	int A;
	int B;
	int C;
	int sum = 0;

public:
	Cost()
	{
		A = 0;
		B = 0;
		C = 0;
	}

	Cost(int* cost)
	{
		A = cost[0];
		B = cost[1];
		C = cost[2];
	}

	enum Discount
	{
		One = 1,
		Two = 2,
		Three = 3
	};

	int getA() { return A; }
	int getB() { return B; }
	int getC() { return C; }
	int Sum(int PartSum) { return sum += PartSum; }
	const int& getSum() { return sum; }
};

int main(void)
{
	int temp;
	int cost[3];

	cin >> cost[0] >> cost[1] >> cost[2];

	Cost MyCost(cost);

	int intersection_time[101] = { 0, };
	int time[2] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		cin >> time[0] >> time[1];
		for (int start = time[0]; start < time[1]; ++start)
			intersection_time[start]++;
	}
	for (int i = 1; i < 100; ++i)
	{
		if (intersection_time[i] == 0) continue;

		switch (intersection_time[i])
		{
		case MyCost.One:
			MyCost.Sum(MyCost.getA());
			break;
		case MyCost.Two:
			MyCost.Sum(MyCost.getB() * 2);
			break;
		case MyCost.Three:
			MyCost.Sum(MyCost.getC() * 3);
			break;
		}
	}

	cout << MyCost.getSum() << endl;

	return 0;
}
//Ch19. ��� c++�ʼ� ��ҵ�

//19.1 ���� �Լ��� std::function
 // lambda - �͸��Լ�
  // ex. func = [](const int& i) -> void { cout << "Hello, World" << endl; } (1234);
  // lambda-introduce([&], [=], [this]) - scope ���� ���� ��� ���� ����� �� �ְ� ��.
 // std::function - function pointer�� ü��ȭ ������ ��
  // ex. function<return type(parameter)> func;
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void goodbye(const string& s)
{
	cout << "Goodbye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "Hello " << s << endl;
	}
};

int main(void)
{
	// lambda-introducer
	// lambda-parameter
	// lambda-return-type-clause
	// compound-statement
	auto func = [](const int& i) -> void { cout << "Hello, World" << endl; };

	func(123);

	// lambda-introduce([&], [=], [this]) - scope ���� ���� ��� ���� ����� �� �ְ� ��.
	{
		string name = "Jack Jack";
		[&]() {std::cout << name << endl; } ();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	// #include<algorithm> (��ȣ�ϴ� ���)
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	// bind�� func�� parameter ���� - parameter�� �Է¾��ص� ��.
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	// std::placeholders
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f(string("World"));

		auto f2 = std::bind(&goodbye, std::placeholders::_1);

		f2(string("World"));


	}
		return 0;
}
*/

// 19.2 �Լ����� ���� ���� ���� �� ��ȯ�ϱ� (c++ 17)
 // 1.Ʃ��(#inclde <tuple>)
/*
//tuple<int, int> my_func()
auto my_func()
{
	// return tuple<int, int>(123,456);
	return tuple(123, 456, 789);

}

int main(void)
{
	//auto result = my_func();
	//cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;

	auto [a, b, c] = my_func();

	cout << a << b << c << endl;

	return 0;
}
*/

// 19.3 std::thread�� ��Ƽ�������� ����
/*
#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>

using namespace std;
mutex mtx;

int main(void)
{
	//{
	//	const int num_pro = std::thread::hardware_concurrency();

	//	cout << std::this_thread::get_id() << endl;

	//	vector<std::thread> my_threads;
	//	my_threads.resize(num_pro);

	//	for (auto& e : my_threads)
	//		e = std::thread([]() {
	//		cout << std::this_thread::get_id() << endl;
	//		while (true) {} });

	//	for (auto& e : my_threads)
	//		e.join();
	//}

	// one thread
	if(false)
	{
		auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			}
		};

		work_func("JackJack");
		work_func("Dash");
	}

	// multi threads
	{

		auto work_func = [](const string& name)
		{
			for (int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				mtx.lock();
				cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
				mtx.unlock();
			}
		};

		std::thread t1 = std::thread(work_func, "JackJack");
		std::thread t2 = std::thread(work_func, "Dash");

		t1.join();
		t2.join();
	}

	return 0;
}
*/

// 18.4 ���̽� �����, std::atomic, std::scoped_lock
/*
#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>
#include<atomic>

using namespace std;
mutex mtx;


int main(void)
{
	int shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(1));

			// �߰��� text-switch �Ͼ�� �ʵ��� �������. - 1.atomic�� ���������� 2. mutex lock

			//std::lock_guard lock(mtx);
			std::scoped_lock lock(mtx); // c++17, if scope end, unlock
			shared_memory++;
			//shared_memory.fetch_add(1);
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "Afer" << endl;
	cout << shared_memory << endl;

	return 0;
}
*/

// 18.5 �۾� ��� �񵿱� ���α׷���(async, future, promise)
 // thread ������� �۾� vs task ������ �۾�
 // thread�� wait�� join�� �ʿ�, async�� get�� wait�� ����
/*
#include<iostream>
#include<future>
#include<thread>

using namespace std;
mutex mtx;


int main(void)
{

	// multi-threading (�����带 ����)
	 // �������� ��Ƽ������ ������� scope�� �а� ��Ƽ� ������ ����
	 // �ֱٿ� thread�� �� �� �ִ� ������ ����ϱ⵵ ��
	{
		int result;
		std::thread t([&] {result = 1 + 2; });
		t.join(); // �����尡 �۾��� ��ĥ �� ���� ��޸�.
		cout << result << endl;
	}

	// task-based parallelim(���� ��ȣ�ϴ� ���)
	 // � �۾��� �� ���ΰ��� ����. -> �۾� �Ϸᰡ ���� �������� �𸥴�.
	{
		// std::future<int> fut = ..
		auto fut = std::async ([] {return 1 + 2; });
		cout << fut.get() << endl; // �۾��� ��ġ�� ���� �� ���� ��ٸ�
	}

	// future and promise
	{
		std::promise<int> prom; // future�� ���� �� �ִ� ����
		auto fut = prom.get_future();

		// promise�� ������ parameter�� �־����
		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2); 
			}, std::move(prom));

		cout << fut.get() << endl;
		t.join();
	}

	// async, thread�� ����? -> thread�� main�� ���������� ������ ���� �߻� / async�� ������.
	// async�� �޾��ִ� future�� ������ �׳� ���������� ó����
	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
		});
		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async2 end" << endl;
		});

		auto f1 = std::thread([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});
		auto f2 = std::thread([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;
	}
	return 0;
}
*/

// 18.6 ��Ƽ������ ���� (���� ���� ���)
/*
#include <iostream>
#include <chrono>
#include <mutex>
#include <utility>
#include <vector>
#include <atomic>
#include <numeric>		// std::inner_product
#include <random>
#include <execution>	// parallel execution
#include <future>
#include <thread>

using namespace std;

mutex mtx; // ���� thread�� ������ �� �ִ� scope�� �־ ��

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned int start, const unsigned int end, unsigned long long& sum)
{
	for (unsigned int i = start; i < end; ++i)
	{
		sum += (v0[i] * v1[i]);
	}
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned int start, const unsigned int end, unsigned long long& sum)
{
	//cout << "Thread Start" << endl;
	for (unsigned int i = start; i < end; ++i)
	{
		std::scoped_lock lock(mtx);
		sum += (v0[i] * v1[i]);
	}
	//cout << "Thread End" << endl;
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned int start, const unsigned int end, atomic<unsigned long long>& sum)
{
	for (unsigned int i = start; i < end; ++i)
	{
		sum += (v0[i] * v1[i]);
	}
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned int start, const unsigned int end)
{
	int sum = 0;
	for (unsigned int i = start; i < end; ++i)
		sum += (v0[i] * v1[i]);
	return sum;
}
int main()
{
	const long long n_data = 100'000'000;
	const unsigned int numThread = 4;

	// initialize vectors
	vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	// random number create
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	cout << "���� - std::inner_product" << endl;
	{
		const auto sta = std::chrono::steady_clock::now();		// �ð� ���� ����

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	cout << "���� 1�� - Naive\n"; // race condition �߻�
	{
		const auto sta = std::chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::thread> threads;
		threads.resize(numThread);

		const unsigned int numPerThread = n_data / numThread; // �յ� �й�
		for (unsigned int t = 0; t < numThread; ++t)
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
				t * numPerThread, (t + 1) * numPerThread, std::ref(sum));

		for (unsigned int t = 0; t < numThread; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	cout << "���� 2�� - Lockguard\n"; // ���� 1�� ���� ���� (��ü lock�ɸ� ���ü��� �ȵǰ� overhead�� Ŀ��)
	{
		const auto sta = std::chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::thread> threads;
		threads.resize(numThread);

		const unsigned int numPerThread = n_data / numThread;
		for (unsigned int t = 0; t < numThread; ++t)
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t * numPerThread, (t + 1) * numPerThread, std::ref(sum));

		for (unsigned int t = 0; t < numThread; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	cout << "���� 3�� - Atomic\n"; // ������ ������ ����� ���� ����
	{
		const auto sta = std::chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<std::thread> threads;
		threads.resize(numThread);

		const unsigned int numPerThread = n_data / numThread;
		for (unsigned int t = 0; t < numThread; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * numPerThread, (t + 1) * numPerThread, std::ref(sum));
		for (unsigned int t = 0; t < numThread; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	// 1-3�� �� ������ ���� ��� �־��ָ鼭 ���� �ϴ� ��� -> ���� ���� ����.
	// 4~�� ���������� ����Ͽ��� �������� �κ� ���� ���ϴ� ��� -> ���ü� ������ ����� �ʿ䰡 ����.

	cout << "���� 4�� - Future\n";
	{
		const auto sta = std::chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures;
		futures.resize(numThread);

		const unsigned int numPerThread = n_data / numThread;
		for (unsigned int t = 0; t < numThread; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * numPerThread, (t + 1) * numPerThread);
		for (unsigned int t = 0; t < numThread; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;

	}

	cout << "���� 5�� - promise\n";
	{
		const auto sta = std::chrono::steady_clock::now();

		vector<std::promise<int>> prom;
		vector<std::future<int>> future;
		vector<std::thread> threads;

		prom.resize(numThread);
		future.resize(numThread);
		threads.resize(numThread);

		unsigned long long sum(0);
		unsigned numPerThread = n_data / numThread;

		for (unsigned i = 0; i < numThread; ++i)
		{
			future[i] = prom[i].get_future();

			threads[i] = std::thread([&](std::promise<int>&& prom)
				{
					unsigned long long sub_sum(0);
					for (unsigned int start = i * numPerThread; start < (i+1) * numPerThread; ++start)
						sub_sum += (v0[start] * v1[start]);
					prom.set_value(sub_sum);

				}, std::move(prom[i]));
		}

		for (unsigned int t = 0; t < numThread; ++t)
		{
			threads[t].join();
			sum += future[t].get();
		}

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	cout << "���� 6�� - std::transform_reduce\n";
	{
		const auto sta = std::chrono::steady_clock::now();
		// std::execution::seq -> ����������
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}
}
*/

// 19.7 �Ϻ��� ���ް� std::forward
 //  copy constructor�� move constructor�� ȿ���� ������ ���� -> R-value�� L-value�� ������ �ʿ���
 // std::forward
  // ����: L-value�� R-value�� �������ֱ� ���� ���
 // R-value ref�� �޾Ƶ� �ش� ref�� �����̱⶧���� move�� ����� move constructor�� �����.
/* ex1) std::forward ���� ����

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

//void func(MyStruct s)
//{
//	cout << "Pass by R-ref" << endl;
//}

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
}

int main()
{
	MyStruct s;

	// templateȭ �ɶ��� L-value, R-value���� ���� ����.
	func_wrapper(s);
	func_wrapper(MyStruct());

	func(s);
	func(MyStruct());

	return 0;
}
*/

// r-value�� l-value�� �ٸ��� �۵��ϴ� ����(move constructor �� copy constructor)
/*
#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;
		// �ʱ�ȭ �Լ��� ���� �δ� ���� ����.
		init(_n_data, _init);
	}

	CustomVector(CustomVector & l_input)
	{
		cout << "Copy Constructor" << endl;
		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}


	CustomVector(CustomVector&& r_input)
	{
		cout << "Move Constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void doSomething(CustomVector& vec)
{
	cout << "Pass by L-ref" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-ref" << endl;
	CustomVector new_vec(std::move(vec)); // R-value ref���� move�� �������� move constructor�� �����
}

template<typename T>
void doSomethingTemplate(T&& vec)
{
	doSomething(std::forward<T>(vec));
}

int main()
{
	CustomVector my_vec(10, 1024);


	//CustomVector temp(my_vec);
	//CustomVector temp(std::move(my_vec));

	doSomething(my_vec);
	doSomething(CustomVector(10,8));

	return 0;
}
*/

// 19.8 �ڷ��� �߷�(auto�� decltype)
 // reference: http://thbecker.net/articles/auto_and_decltype/section_01.html
 // atuo: �ڷ����� �ڵ����� �߷�����
/*
class Examples
{
public:
	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;


		for (auto itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr : vect)
			cout << itr;
	}

	// ����1. auto�� ���� �⺻���� �ڷ����� �߷� ���ش�.
	void ex2()
	{
		int x = int();

		auto auto_x = x;

		const int& crx = x;

		auto auto_crx1 = crx; // int auto_crx1

		const auto& auto_crx2 = crx; // const�� &�� ���� �ʹٸ� ������ ���� ������� ���

		volatile int vx = 1024; // volatie�� ���� ���� �ٲ�Ƿ� ����ȭ�� �� ���޶�� ��

		auto avx = vx;

		volatile auto vavx = vx;
	}

	// template�� �ٸ� �߰����� �͵��� ���� ���ְ� �⺻ �ڷ����� �߷е�
	template<class T>
	void func_ex3(T arg) //void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int& crx = 123;

		func_ex3(crx);
	}

	// auto ����2. reference�� ������ ���� const �ν���.
	void ex4()
	{
		const int c = 0;
		auto & rc = c; //
		// rc = 123; // error
	}

	// ����3. l-value, r-value�� �°� ��������
	void ex5()
	{
		int i = 42;
		auto&& ri_1 = i; // l-value
		auto&& ri_2 = 42; // r-value

	}

	// ����4. pointer�� ���� ���� �ּҸ� �������Ƿ� ��� ������ �� �����;���.
	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;
		// *p2 = 50; // error
	}

	// ����6. T��S�� �ڷ����� �ٸ� �� ��� ���� �ڷ��� �߷�
	// decltype: ��� ���� �ڷ����� �߷��Ͽ� ���Ϲ޾� typedef���� �����ϴ� ��
	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		auto prod1 = lhs * rhs;

		typedef decltype(lhs* rhs) product_type;
		product_type prod2 = lhs * rhs;

		// decltype(lhs * rhs) prod3 = lhs * rhs;
	}

	// decltype Ȱ�� 1. �����Լ��� ����Ÿ��
	template<typename T, typename S>
	//decltype(lhs* rhs) func_ex8(T lhs, S rhs) -> �Ұ��� -> decltype(lhs* rhs) lhs, rhs�� ���� �ȵǾ���.
	auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
	{
		return lhs * rhs;
	}

	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 345);
	}

	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	// decltype����2: ������ ����� �״�� ������
	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();

		auto a = x; //int
		auto b = cx; //int
		auto c = crx; //int
		auto d = p; //const S*
		auto e = p->m_x; // int

		typedef decltype(x)			x_type;
		typedef decltype(cx)		cx_type;
		typedef decltype(crx)		crx_type;
		typedef decltype(p->m_x)	m_x_type; // int -> 'declared' type�� �����´�

		// ()�� �߰��Ǹ� l-value renference�� �����´�.
		typedef decltype((x))		x_type2;
		typedef decltype((cx))		cx_type2;
		typedef decltype((crx))		crx_type2;
		typedef decltype((p->m_x))	m_x_type2; // const int &�� �����´�.
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42, 43 };

		auto a = foo(); // S
		typedef decltype(foo()) foo_type;// const s

		auto b = foobar(); // int
		typedef decltype(foobar()) foobar_type; // const s

		auto itr = vect.begin(); // int
		typedef decltype(vect.begin()) iterator_type; // int

		auto first_element = vect[0]; // int
		decltype(vect[1]) sencond_element = vect[1]; // int& -> [] operator�� reference�� �������ش�.
	}


	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;
		auto a = x * y;

		typedef decltype(cx* cy) prod_cxcy_type; // int -> return is prvalue(������� R-value)
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type; // (���� Ÿ���϶�)return is L-value. & is added.
		auto c = d1 < d2 ? d1 : d2; // double

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promotion of x to double
		auto d = x < d2 ? x : d2; // double

		// auto d = std::min(x,dbl); // error - ���� ������ Ÿ�Կ��� �۵�
	}

	template<typename T, typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	template<typename T, typename S>
	auto fpmin(T x, S y) ->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double  d = 45.1;
		auto a = std::min(static_cast<double>(i), d);

		int& j = i;

		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1; // &double
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2; // double
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type2; // double
	}

	void ex13()
	{
		std::vector<int> vect;
		typedef decltype(vect[0]) integer;
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer; // nested type
	}

	void ex15()
	{
		auto lambda = []() { return 42; };
		decltype(lambda) lambda2(lambda);
		decltype((lambda)) lambda3(lambda);

		cout << "Lambda functioms" << endl;
		cout << &lambda << " " << &lambda2 << endl; // �ּҰ� �ٸ�.
		cout << &lambda << " " << &lambda3 << endl; // �ּҰ� ����.
	}
	// generic lambda
	void ex16()
	{
		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << lambda(4.5, 2.2) << endl;
	}
};
int main()
{


	return 0;
*/