
// 20.1 비쥬얼 스튜디오로 프로파일링 하기
// Debug 모드의 프로파일링(정밀 진단)
// 어떠한 프로그램을 만들 때 중간 중간 프로파일링하는 것은 실력 향상에 많은 도움이 됨
// break pointer를 통해 프로파일링 진행
// heap profile은 계속 켜두는 것이 좋고, cpu profile에 영향을 줄 수도 있다.
//정교한 프로파일링할때는 따로따로 하는 것이 좋음
//memory 프로파일링 
// Diagnostic Tool - Memory Usage - Take Snapshot

//cpu 프로파일링(Debug 모드시 자동으로 뜸(Debug-windows-Show Diagnostic Tool))
// 키는법
// 1. Diagnostic Tool - summary - report CPU Profile
// 2. Diagnostic Tool - CPU Usage - Record CPU Profile
// 빨간색으로 되는 곳만 찾아 들어가서 가장 느린 곳을 찾아 최적화하는 것이 중요

// Release 모드의 프로파일링(주로)
// Debug보단 Release가 실제 사용자가 쓰는 프로그램에 가까우므로 이 방법을 주로 사용
// Debug - performance profiler ... cpu sampling 방법이 가장 좋음

// 20.2 비쥬얼 스튜디오에서 깃헙 사용하기
//view - team explorer
//종류
//1. home
//2. connections manage
//기능
//1.github login
//2.github clone
//3.github ropository creat
//4.Local Git Rpositories - clone된 것들
//5.git changes(home - git changes)
 //commit(그날 coding 한것은 무조건 메모)
 //commit All, commit Alland push, commit Alland sych(push + pull)
//100MB가 넘는 파일은 커맨드창으로 하는 것이 좀더 편함.

 //20.3 Vcpkg 설치 방법
 // 외부 라이브러리 관리
 // https://github.com/Microsoft/vcpkg
 // 설치 방법 - ex. vcpkg.exe install boost:x64-windows
 // vcpkg integrate install - 자금까지 설치한 라이브러리가 vs에서 자동으로 include됨 -> code에서 #incldue<boost/asio.hpp> 하면됨
 // vcpkg search eigen3
 // 설치한 라이브러리 확인 - vcpkg list	

// 20.4 TCP/IP 네트워킹 
 // Boost.asio 라이브러리 이용
//#include <iostream>
//#include <ctime>
//#include <string>
//#include <boost/asio.hpp>
//
//using boost::asio::ip::tcp;
//
//int main()
//{
//	try
//	{
//		boost::asio::io_service io_service;
//
//		tcp::endpoint endpoint(tcp::v4(), 13);
//		tcp::acceptor acceptor(io_service, endpoint);
//
//		std::cout << "Server started" << std::endl;
//
//		for (;;)	// 무한 루프
//		{
//			const std::string message_to_send = "Hello From Server";
//
//			boost::asio::ip::tcp::iostream stream;	// 일반 iostream이 아니라 오버로드된 tcp::iostream
//
//			std::cout << "check 1" << std::endl;	// 네트워킹에서도 cout을 쓸 수 있다.
//
//			boost::system::error_code ec;
//			acceptor.accept(*stream.rdbuf(), ec);	// 클라이언트 접속을 받아들인다.
//
//			std::cout << "check 2" << std::endl;
//
//			if (!ec)	//TODO: How to take care of multiple clients? Multi-threading?
//				std::string line;
//			std::getline(stream, line);
//			std::cout << line << std::endl;
//
//			// send message to client
//			stream << message_to_send;
//			stream << std::endl;
//		}
//	}
//}
//catch (std::exception& e)						// 예외 발생시
//{
//	std::cout << e.what() << std::endl;
//}
//}
//
//
//#include <iostream>
//#include <string>	
//#include <boost/asio.hpp>
//
//using boost::asio::ip::tcp;
//
//int main(int argc, char** argv)
//{
//	try
//	{
//		if (argc != 2)
//		{
//			std::cerr << "Usage : Client <host>\n";
//			return 1;
//		}
//
//		tcp::iostream stream(argv[1], std::to_string(int(13))); // port num = 13
//		if (!stream)
//		{
//			std::cout << "No address. Unable to connect: " << stream.error().message() << std::endl;
//		}
//
//		// send message to server
//		stream << "Hello from client\n";
//
//		// receive message from server
//		std::string line;
//		std::getline(stream, line);
//		std::cout << line << std::endl;
//	}
//	catch (std::exception& e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	return 0;
//}

// 20.5 외부 라이브러리 설치, 프로젝트 템플릿(NanoGUI 사례)
 //내 프로젝트에 include하는법
 //cmake
 //c / c++ - general - Additional Include Directories
 //Linker - Addtional Libray Drectority
 //c / c++ - Preprocessor
 
 // project - export template 한 상태로 새로운 프로젝트 생성하면 자동으로 모두 설정되고 include됨
 // dll 파일은 수동으로 해주어야함.