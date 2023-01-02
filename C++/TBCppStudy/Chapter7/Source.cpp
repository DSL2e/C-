#include<iostream>
#include<cmath>
#include<vector>
#include<array>
#include<tuple>
#include<functional>
#include<cassert>
#include<string>
#include<cstdarg>
using namespace std;

double findAverage(int count, ...)
{
	double sum = 0;
	va_list list;

	va_start(list, count);

	// typeµµ ¹Ì¸® Á¤ÇØµÖ¾ßÇÔ.
	for (int arg = 0; arg < count; arg++)
	{
		sum += va_arg(list, int);
	}
	va_end(list);

	return sum / count;
}

int main(int argc, char* argv[])
{
	array<int, 5> my_array{ 1,2,3,4,5 };

	cout << findAverage(5, my_array) << endl;
}

//°ª¿¡ ÀÇÇÑ ÀÎ¼ö Àü´Ş(Call by value)
 /* °ª¸¸ Àü´ŞÇÏ´Â °Í -> ¸ŞÀÎ°ú ÇÔ¼ö¿¡¼­ÀÇ ÁÖ¼Ò°¡ ´Ù¸§
	void doSomething(int y)
	{
		cout << "In func " << y << " " << &y <<endl;
	}
	int main(void)
	{
		int x{6};

		cout << "In main " << x << " " << &y << endl;
	
		doSomething(x); // x : argument (=actual parameters)
		doSomething(x+1);

		return 0;
	}
 */

// Âü¼Ò¿¡ ÀÇÇÑ ÀÎ¼ö Àü´Ş(Call by Reference)
 // ¼±È£ÇÏ´Â ¹æ¹ı. ´ÜÁ¡?? ¸®ÅÍ·² »ó¼ö¸¦ ³Ö¾úÀ» ¶§ ¿À·ù -> const int &x (but, ¾È¿¡¼­ ¼öÁ¤ ºÒ°¡´É)
 // 
 /* º¯¼ö ÀÚÃ¼¸¦ ³Ñ±â´Â ¹æ½Ä -> ¸ŞÀÎ°ú ÇÔ¼ö¿¡¼­ÀÇ ÁÖ¼Ò°¡ °°À½
	void addOne(int &y)
	{
		cout << "In func " << y << " " << &y << endl;
		y = y + 1;
	}

	int main(void)
	{
		int x{5};

		cout << "In main " << x << " " << &x << endl;
		addOne(x);
		cout << "In main " << x << " " << &x << endl;
		return 0;
	}
 */
/* Æ÷ÀÎÅÍ 
	void addOne(int* &y)
	{
		(*y)++;
		cout << "In func " << *y << " " << &y << endl;
	}

	int main(void)
	{
		int x{ 5 };
		int* ptr;

		ptr = &x;

		cout << "In main " << *ptr << " " << &ptr << endl;
		addOne(ptr);
		cout << "In main " << *ptr << " " << &ptr << endl;
		return 0;
	}
*/
/* ¹è¿­
	void foo(vector<int> &arr)
	{
		for (auto &n : arr)
			n++;
	}
	int main(void)
	{
		vector<int> arr{ 1,2,3,4 };
		for (const int& n : arr)
			cout << n << " ";
		cout << endl;
		foo(arr);
		for (const int& n : arr)
			cout << n << " ";
		cout << endl;
		return 0;
	}
*/

// ÁÖ¼Ò¿¡ ÀÇÇÑ ÀÎ¼ö Àü´Ş(Call by Address)

// ´Ù¾çÇÑ ¹İÈ¯ °ªÀ» (°ª, ÂüÁ¶, ÁÖ¼Ò, ±¸Á¶Ã¼, Æ©ÇÃ)
 // 1. °ªÀ» ¹Ş´Â´Ù -> º¹»çÇØ¼­ µé¾î°¡¹Ç·Î ¼Óµµ°¡ µå¸²

 // 2. ÁÖ¼Ò¸¦ ¸®ÅÏ -> ÇÔ¼ö¿¡¼± ¿µ¿ªÀ» ³Ñ¾î°¡¸é »ç¶óÁö¹Ç·Î Á¤¸» À§Çè

 // 3. ·¹ÆÛ·±½º¸¦ ¸®ÅÏ -> ¸Ş¸ğ¸® °ø°£Àº ¾ÈÀüÇÏ°Ô Àâ¾ÆµÎ°í ·¹ÆÛ·±½º¸¸ º¸³» ÀÛ¾÷

 // 4. ¿©·¯ °³¸¦ ¸®ÅÏ
	/* 1. ±¸Á¶Ã¼
		S getStrct()
		{
			S my_s{ 1,2,3,4 };
			return my_s;
		}

		int main(void)
		{
			S my_s = getStrct();
			cout << my_s.a << endl;
		}
	*/

	/*	2. Æ©ÇÃ
		std::tuple<int, double> getTuple()
		{
			int a = 10;
			int d = 3.14;
			return std::make_tuple(a, d);
		}

		int main(void)
		{
			std::tuple<int, double> my_tp = getTuple();
			cout << std::get<0>(my_tp) << endl; // a
			cout << std::get<1>(my_tp) << endl; // d

			// c++ 17
			auto [a, d] = getTuple();
			cout << a << endl;
			cout << d << endl;
			return 0;
		}
	*/

// ¾È¶óÀÎ ÇÔ¼ö
 // cout << (5 > 6 ? 6 : 5) << endl; Ã³·³ ÄÄÆÄÀÏ ´Ü°è¿¡¼­ ¸¸µé¾î¼­ ºü¸£°Ô Ã³¸®ÇÏ°Ô µÊ. 
 // ÄÄÆÄÀÏ·¯ÇÑÅ× ÇØ´Ş¶ó°í ¿äÃ»ÇÏ´Â °ÍÀÌ°í ÄÄÆÄÀÏ·¯°¡ inline¸¦ Àû¿ëÇÒ Áö °áÁ¤
/*
	inline int min(int x, int y)
	{
		return ((x > y) ? y : x);
	}

	int main(void)
	{
		cout << min(5, 6) << endl;
		cout << min(3, 2) << endl;
	}
*/

// ÇÔ¼ö ¿À¹ö·Îµù
 // µ¿ÀÏÇÑ ÇÔ¼ö¸¦ ¿©·¯°³ ¸¸µå´Â °Í
 // µé¾î¿À´Â ¸Å°³º¯¼ö°¡ ´Ù¸¥µ¥ ÇÔ¼ö ±â´ÉÀÌ ºñ½ÁÇÒ ¶§ ÁÖ·Î »ç¿ë 
 // ÄÄÆÄÀÏ ÇÒ ¶§, °¡Àå ¸Â´Â ¾î¶² ÇÔ¼ö¸¦ ¼±ÅÃÇÒ Áö °áÁ¤ (return type·Î´Â ±¸º° x. argument¿Í parameter·Î ±¸ºĞ)
 /*
	int add(int x, int y)
	{
		return x + y;
	}

	double add(double x, double y)
	{
		return x + y;
	}

	int main(void)
	{
		add(1, 2);
		add(3.0, 4.0);
		return 0;
	}
 */

// ¸Å°³º¯¼öÀÇ ±âº»°ª
 // ¸Å°³º¯¼öÀÇ ±âº»°ªÀ» ÅëÇØ argument ÀÔ·ÂÀ» »ı·«ÇÏ´Â ¹æ¹ı
 // ÁÖ·Î header¿¡¸¸ ±âº» ¼³Á¤À» ÇØÁÜ. (µÑ´Ù´Â x)
 /*
	void print(int x = 10, int y =20, int z = 30)
	{
		cout << x << " " << y << " " << z << endl;
	}

	int main(void)
	{
		print(100);
		print(100, 200);
		print(100, 200, 300);
	}
 */

// ÇÔ¼ö Æ÷ÀÎÅÍ
 // ÇÔ¼öµµ Æ÷ÀÎÅÍ·Î ÁÖ¼Ò¸¦ °¡Áö°í ÀÖ°í ÇØ´ç ³»¿ëÀ» Ã³¸®ÇÏ´Â °Í
 /*
	int func()
	{
		return 5;
	}

	int goo()
	{
		return 10;
	}
	int main(void)
	{
		int(*fcnptr)() = func;
		cout << fcnptr() << endl;

		fcnptr = goo;
		cout << fcnptr() << endl;

		// functional »ç¿ë
		std::function<bool(const int&)> fcnptr;

		return 0;
	}
 */

//std::vector¸¦ ½ºÅÃÃ³·³ »ç¿ëÇÏ±â
 // ³»ºÎ¿¡ new¿Í delete¸¦ Àû°Ô È£ÃâÇÏµµ·Ï ÇÏ´Â °ÍÀÌ Áß¿ä
 /*

	std::vector<int> v{ 1,2,3 };
	std::vector<int> stack;

	v.resize(2);

	// size: ¸î°³¸¦ »ç¿ë , capacity: °¡Áö°í ÀÖ´Â ¸Ş¸ğ¸®

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl; // 2 ,3À¸·Î Ãâ·ÂµÊ

	// v.reserve(number) - ¸Ş¸ğ¸® °ø°£ ¹Ì¸® È®º¸ >> capacity¸¦ ÁÙÀÌ°í ´Ã¸± ÇÊ¿ä°¡ ¾ø¾î¼­ È¿À²ÀÌ ÁÁÀ½(°ø°£ ³²ºñ°¡ ÀÖÀ» ¼öµµ)
	stack.push_back(3);
	stack.push_back(5);
	stack.push_back(7);
	stack.pop_back();
	stack.pop_back();
	stack.pop_back();
 */

// Àç±ÍÀû ÇÔ¼ö È£Ãâ

// ¹æ¾îÀû ÇÁ·Î±×·¡¹ÖÀÇ °³³ä
 // syntax error
 // semantic errors(ÇÁ·Î±×·¡¸Ó°¡ ½Å°æ½á¾ßÇÏ´Â ºÎºĞ)	
 // violated assumption
 /* Runtime ¿À·ù -> ¸Ş¸ğ¸® ¾ï¼¼½º°¡ °¡´ÉÇÑ ¹üÀ§¸¦ ÁöÁ¤ÇØÁØ´Ù.
   string hello = "Hello, my name is Jack jack"
   int ix;
   cin >> ix; // 1004 ÀÔ·Â
   cout << hello[ix] << endl;
 */

// ´Ü¾ğÇÏ±â assert #include<cassert>
 // ÄÄÆÄÀÏ·¯ÀÇ µµ¿òÀ» ¹Ş´Â °Í
 /*
	void printValue(const array<int, 5> &my_array, const int &ix)
	{
		// Debug mode¿¡¼­¸¸ ½ÇÇà
		// Runtime error°¡ ¹ß»ıÇÏ±ä ÇÏÁö¸¸, ¾îµğ¼­ ¿À·ù°¡ ¹ß»ıÇß´ÂÁö ¾Ë ¼ö ÀÖÀ½.
		assert(ix >= 0);
		assert(ix <= my_array.size() - 1);
	}

	int main(void)
	{

		array<int, 5> my_array{ 1,2,3,4,5 };
		printValue(my_array, 100);

		// static_assert(º¯¼ö+Á¶°Ç, "¹®±¸") - ÄÄÆÄÀÏ ½Ã, ¿À·ù¸¦ ¹ß»ı
	}
 */

// ¸í·ÉÁÙ ÀÎ¼ö
	/*
	int main(int argc, char* argv[])
	{
		for (int count = 0; count < argc; ++count)
		{
			std::string argv_single = argv[count];

			if (count == 1)
			{
				int input_number = std::stoi(argv_single);
				cout << input_number << endl;
			}
			cout << argv_single << endl;
		}
	}
	*/

// »ı·«ºÎÈ£ Ellipsis (#include<cstdarg>)
 // °¹¼ö°¡ ¸Â¾Æ¾ßÇÏ°í va_arg¿¡¼­ type¸¦ ¹Ì¸® Á¤ÀÇÇØ¾ßÇÔ 
 // ¸Å°³º¯¼öÀÇ °¹¼ö°¡ Á¤ÇÏÁö¾Ê°í »ç¿ë
 /*
	double findAverage(int count, ...)
	{
		double sum = 0;
		va_list list;

		va_start(list, count);

		// typeµµ ¹Ì¸® Á¤ÇØµÖ¾ßÇÔ.
		for (int arg = 0; arg < count ; arg++)
			sum += va_arg(list, int);

		va_end(list);

		return sum / count;
	}

	int main(int argc, char* argv[])
	{
		cout << findAverage(1, 1, 2, 3, "Hello", "c") << endl;
		cout << findAverage(3, 1, 2, 3) << endl;
		cout << findAverage(5, 1, 2, 3, 4 ,5) << endl;
		cout << findAverage(10, 1, 2, 3, 4, 5) << endl; // °¹¼ö°¡ Àß¸øµÇ¾î ¿À·ù
	}
 */

// tip
// Âü¼Ò¿¡ ÀÇÇÑ ÀÎ¼ö Àü´Ş(Call by Reference)
  // ÀÔ·Â °ªÀº const·Î ¾Õ¿¡, Ãâ·Â °ªÀº µÚ¿¡ Àû´Â´Ù. ex. void getSinCos(const double degrees, double &sin_out, double &cos_out) 
  // °è»ê ÇÏ´Â °ªÀº const¸¦ ¾²´Â ½À°ü + È£­ŒÇÒ ¶§ ¸¶´Ù ÇÏ¿ë ÇÏ´Â °ÍÀº staticÀ¸·Î Àç»ç¿ë ex. static const double pi = 3.141592;
  // ÀÔ·Â °ªÀº const int &x·Î °ÅÀÇ ¹«Á¶°Ç »ç¿ë (why? ¸®ÅÍ·² »ó¼öµµ ¹ŞÀ» ¼ö ÀÖ°í ¸Ş¸ğ¸® °ø°£ Àı¾à °¡´É)
  // typedef int* pint; -> ÀÌ·±¹æ½ÄÀ¸·Î ÁÖ·Î º¯°æÇØ¼­ »ç¿ë