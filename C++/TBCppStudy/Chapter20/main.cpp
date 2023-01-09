
// 20.1 ����� ��Ʃ����� �������ϸ� �ϱ�
// Debug ����� �������ϸ�(���� ����)
// ��� ���α׷��� ���� �� �߰� �߰� �������ϸ��ϴ� ���� �Ƿ� ��� ���� ������ ��
// break pointer�� ���� �������ϸ� ����
// heap profile�� ��� �ѵδ� ���� ����, cpu profile�� ������ �� ���� �ִ�.
//������ �������ϸ��Ҷ��� ���ε��� �ϴ� ���� ����
//memory �������ϸ� 
// Diagnostic Tool - Memory Usage - Take Snapshot

//cpu �������ϸ�(Debug ���� �ڵ����� ��(Debug-windows-Show Diagnostic Tool))
// Ű�¹�
// 1. Diagnostic Tool - summary - report CPU Profile
// 2. Diagnostic Tool - CPU Usage - Record CPU Profile
// ���������� �Ǵ� ���� ã�� ���� ���� ���� ���� ã�� ����ȭ�ϴ� ���� �߿�

// Release ����� �������ϸ�(�ַ�)
// Debug���� Release�� ���� ����ڰ� ���� ���α׷��� �����Ƿ� �� ����� �ַ� ���
// Debug - performance profiler ... cpu sampling ����� ���� ����

// 20.2 ����� ��Ʃ������� ���� ����ϱ�
//view - team explorer
//����
//1. home
//2. connections manage
//���
//1.github login
//2.github clone
//3.github ropository creat
//4.Local Git Rpositories - clone�� �͵�
//5.git changes(home - git changes)
 //commit(�׳� coding �Ѱ��� ������ �޸�)
 //commit All, commit Alland push, commit Alland sych(push + pull)
//100MB�� �Ѵ� ������ Ŀ�ǵ�â���� �ϴ� ���� ���� ����.

 //20.3 Vcpkg ��ġ ���
 // �ܺ� ���̺귯�� ����
 // https://github.com/Microsoft/vcpkg
 // ��ġ ��� - ex. vcpkg.exe install boost:x64-windows
 // vcpkg integrate install - �ڱݱ��� ��ġ�� ���̺귯���� vs���� �ڵ����� include�� -> code���� #incldue<boost/asio.hpp> �ϸ��
 // vcpkg search eigen3
 // ��ġ�� ���̺귯�� Ȯ�� - vcpkg list	

// 20.4 TCP/IP ��Ʈ��ŷ 
 // Boost.asio ���̺귯�� �̿�
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
//		for (;;)	// ���� ����
//		{
//			const std::string message_to_send = "Hello From Server";
//
//			boost::asio::ip::tcp::iostream stream;	// �Ϲ� iostream�� �ƴ϶� �����ε�� tcp::iostream
//
//			std::cout << "check 1" << std::endl;	// ��Ʈ��ŷ������ cout�� �� �� �ִ�.
//
//			boost::system::error_code ec;
//			acceptor.accept(*stream.rdbuf(), ec);	// Ŭ���̾�Ʈ ������ �޾Ƶ��δ�.
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
//catch (std::exception& e)						// ���� �߻���
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

// 20.5 �ܺ� ���̺귯�� ��ġ, ������Ʈ ���ø�(NanoGUI ���)
 //�� ������Ʈ�� include�ϴ¹�
 //cmake
 //c / c++ - general - Additional Include Directories
 //Linker - Addtional Libray Drectority
 //c / c++ - Preprocessor
 
 // project - export template �� ���·� ���ο� ������Ʈ �����ϸ� �ڵ����� ��� �����ǰ� include��
 // dll ������ �������� ���־����.