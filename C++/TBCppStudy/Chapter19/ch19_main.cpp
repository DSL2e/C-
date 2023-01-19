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
//Ch19. 모던 c++필수 요소들

//19.1 람다 함수와 std::function
 // lambda - 익명함수
  // ex. func = [](const int& i) -> void { cout << "Hello, World" << endl; } (1234);
  // lambda-introduce([&], [=], [this]) - scope 범위 내에 모든 것을 사용할 수 있게 함.
 // std::function - function pointer를 체계화 시켜준 것
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

	// lambda-introduce([&], [=], [this]) - scope 범위 내에 모든 것을 사용할 수 있게 함.
	{
		string name = "Jack Jack";
		[&]() {std::cout << name << endl; } ();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) {cout << val << endl; };
	// #include<algorithm> (선호하는 방식)
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []() -> int { return 1; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	// bind로 func과 parameter 묶기 - parameter를 입력안해도 됨.
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

// 19.2 함수에서 여러 개의 리턴 값 반환하기 (c++ 17)
 // 1.튜플(#inclde <tuple>)
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

// 19.3 std::thread와 멀티쓰레딩의 기초
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

// 18.4 레이스 컨디션, std::atomic, std::scoped_lock
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

			// 중간에 text-switch 일어나지 않도록 묶어야함. - 1.atomic의 증감연산자 2. mutex lock

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

// 18.5 작업 기반 비동기 프로그래밍(async, future, promise)
 // thread 기반으로 작업 vs task 단위로 작업
 // thread는 wait인 join이 필요, async는 get이 wait의 역할
/*
#include<iostream>
#include<future>
#include<thread>

using namespace std;
mutex mtx;


int main(void)
{

	// multi-threading (쓰레드를 관리)
	 // 전통적인 멀티쓰레딩 방식으로 scope를 넓게 잡아서 변수를 공유
	 // 최근엔 thread만 쓸 수 있는 변수를 사용하기도 함
	{
		int result;
		std::thread t([&] {result = 1 + 2; });
		t.join(); // 쓰레드가 작업을 마칠 떄 까지 기달림.
		cout << result << endl;
	}

	// task-based parallelim(좀더 선호하는 방식)
	 // 어떤 작업을 할 것인가를 기준. -> 작업 완료가 언제 들어올지를 모른다.
	{
		// std::future<int> fut = ..
		auto fut = std::async ([] {return 1 + 2; });
		cout << fut.get() << endl; // 작업을 마치고 끝날 때 까지 기다림
	}

	// future and promise
	{
		std::promise<int> prom; // future를 받을 수 있는 변수
		auto fut = prom.get_future();

		// promise를 무조건 parameter로 넣어야함
		auto t = std::thread([](std::promise<int>&& prom)
			{
				prom.set_value(1 + 2); 
			}, std::move(prom));

		cout << fut.get() << endl;
		t.join();
	}

	// async, thread의 차이? -> thread는 main이 끝나기전에 끝나면 오류 발생 / async는 괜찮음.
	// async를 받아주는 future이 없으면 그냥 순차적으로 처리됨
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

// 18.6 멀티쓰레딩 예제 (벡터 내적 계산)
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

mutex mtx; // 여러 thread가 접근할 수 있는 scope에 넣어도 됨

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

	cout << "정답 - std::inner_product" << endl;
	{
		const auto sta = std::chrono::steady_clock::now();		// 시간 측정 시작

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}

	cout << "실험 1번 - Naive\n"; // race condition 발생
	{
		const auto sta = std::chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::thread> threads;
		threads.resize(numThread);

		const unsigned int numPerThread = n_data / numThread; // 균등 분배
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

	cout << "실험 2번 - Lockguard\n"; // 실험 1에 비해 느림 (전체 lock걸면 동시성이 안되고 overhead만 커짐)
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

	cout << "실험 3번 - Atomic\n"; // 여전히 최적의 결과에 비해 느림
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

	// 1-3은 한 변수에 값을 계속 넣어주면서 갱신 하는 방식 -> 값을 리턴 못함.
	// 4~은 로컬적으로 계산하여서 리턴해준 부분 값을 더하는 방식 -> 동시성 문제를 고려할 필요가 없음.

	cout << "실험 4번 - Future\n";
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

	cout << "실험 5번 - promise\n";
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

	cout << "실험 6번 - std::transform_reduce\n";
	{
		const auto sta = std::chrono::steady_clock::now();
		// std::execution::seq -> 순차적으로
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);
		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
		cout << "time = " << dur.count() << endl;
		cout << "result = " << sum << endl;
		cout << endl;
	}
}
*/

// 19.7 완벽한 전달과 std::forward
 //  copy constructor과 move constructor는 효율성 차지가 심함 -> R-value와 L-value의 구별이 필요함
 // std::forward
  // 역할: L-value와 R-value를 구별해주기 위해 사용
 // R-value ref로 받아도 해당 ref는 변수이기때문에 move를 해줘야 move constructor이 실행됨.
/* ex1) std::forward 문법 설명

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

	// template화 될때는 L-value, R-value인지 구별 못함.
	func_wrapper(s);
	func_wrapper(MyStruct());

	func(s);
	func(MyStruct());

	return 0;
}
*/

// r-value와 l-value가 다르게 작동하는 예제(move constructor 과 copy constructor)
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
		// 초기화 함수를 따로 두는 것이 편리함.
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
	CustomVector new_vec(std::move(vec)); // R-value ref여도 move를 명시해줘야 move constructor이 실행됨
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

// 19.8 자료형 추론(auto와 decltype)
 // reference: http://thbecker.net/articles/auto_and_decltype/section_01.html
 // atuo: 자료형을 자동으로 추론해줌
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

	// 성질1. auto는 가장 기본적인 자료형만 추론 해준다.
	void ex2()
	{
		int x = int();

		auto auto_x = x;

		const int& crx = x;

		auto auto_crx1 = crx; // int auto_crx1

		const auto& auto_crx2 = crx; // const나 &를 쓰고 싶다면 다음과 같은 방식으로 사용

		volatile int vx = 1024; // volatie은 값이 자주 바뀌므로 최적화할 때 빼달라는 것

		auto avx = vx;

		volatile auto vavx = vx;
	}

	// template도 다른 추가적인 것들은 제거 해주고 기본 자료형만 추론됨
	template<class T>
	void func_ex3(T arg) //void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int& crx = 123;

		func_ex3(crx);
	}

	// auto 성질2. reference로 가져올 때는 const 인식함.
	void ex4()
	{
		const int c = 0;
		auto & rc = c; //
		// rc = 123; // error
	}

	// 성질3. l-value, r-value에 맞게 수정해줌
	void ex5()
	{
		int i = 42;
		auto&& ri_1 = i; // l-value
		auto&& ri_2 = 42; // r-value

	}

	// 성질4. pointer를 받을 때는 주소를 가져오므로 모든 성질을 다 가져와야함.
	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;
		// *p2 = 50; // error
	}

	// 성질6. T와S의 자료형이 다를 때 결과 값의 자료형 추론
	// decltype: 결과 값의 자료형을 추론하여 리턴받아 typedef으로 정의하는 것
	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)
	{
		auto prod1 = lhs * rhs;

		typedef decltype(lhs* rhs) product_type;
		product_type prod2 = lhs * rhs;

		// decltype(lhs * rhs) prod3 = lhs * rhs;
	}

	// decltype 활용 1. 람다함수의 리턴타입
	template<typename T, typename S>
	//decltype(lhs* rhs) func_ex8(T lhs, S rhs) -> 불가능 -> decltype(lhs* rhs) lhs, rhs가 정의 안되었음.
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

	// decltype성질2: 변수가 선언된 그대로 가져옴
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
		typedef decltype(p->m_x)	m_x_type; // int -> 'declared' type를 가져온다

		// ()가 추가되면 l-value renference로 가져온다.
		typedef decltype((x))		x_type2;
		typedef decltype((cx))		cx_type2;
		typedef decltype((crx))		crx_type2;
		typedef decltype((p->m_x))	m_x_type2; // const int &로 가져온다.
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
		decltype(vect[1]) sencond_element = vect[1]; // int& -> [] operator는 reference를 리턴해준다.
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

		typedef decltype(cx* cy) prod_cxcy_type; // int -> return is prvalue(결과값은 R-value)
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type; // (같은 타입일때)return is L-value. & is added.
		auto c = d1 < d2 ? d1 : d2; // double

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; // promotion of x to double
		auto d = x < d2 ? x : d2; // double

		// auto d = std::min(x,dbl); // error - 같은 데이터 타입에만 작동
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
		cout << &lambda << " " << &lambda2 << endl; // 주소가 다름.
		cout << &lambda << " " << &lambda3 << endl; // 주소가 같음.
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