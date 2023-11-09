#include <string>
#include <utility>

#include <argument/option.h>
#include <args.hxx>

std::pair<bool, option> parser(int argc, char** argv) {
    args::ArgumentParser parser("본 프로그램은 라즈베리파이에서 발생된 시리얼 데이터를 수신받아 VNC 클라이언트를 제어하는 프로그램 입니다.\n", "아래의 옵션을 지정하여 설정을 변경할 수 있습니다.");
    args::HelpFlag help(parser, "help", "넹넹 설정하시죠!", {'h', "help"});

    args::ValueFlag<int> baudrate(parser, "baudrate", "시리얼 통신의 Baudrate를 지정합니다. ", {'b', "baudrate"});
    args::ValueFlag<std::string> com(parser, "com", "시리얼 통신의 Com-Port를 지정합니다. ", {'c', "com"});
    
    args::ValueFlag<std::string> vnc_ip(parser, "vnc_ip", "서버의 아이피 주소를 입력해 주세요.", {'v', "vnc_ip"});
    args::ValueFlag<std::string> api_ip(parser, "api_ip", "서버의 아이피 주소를 입력해 주세요.", {'l', "api_ip"});
    
    args::ValueFlag<int> vnc_port(parser, "vnc_port", "VNC 서버의 포트를 입력해 주세요.", {'p', "port"});
    args::ValueFlag<int> api_port(parser, "api_port", "API 서버의 포트를 입력해 주세요.", {'a', "api_port"});
    
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return std::make_pair(false, option{});
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!baudrate) { 
        std::cerr << "baudrate 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!com) {
        std::cerr << "com 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!vnc_ip) {
        std::cerr << "vnc ip 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!api_ip) {
        std::cerr << "api ip 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!vnc_port) {
        std::cerr << "vnc_port 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }
    if (!api_port) {
        std::cerr << "api_port 값이 설정이 되지 않았습니다.";
        std::cerr << parser;
        return std::make_pair(false, option{});
    }

    std::cout << "Argument Result : \n";
    std::cout << "COM : " << args::get(com) << "\n";
    std::cout << "Baudrate : " << args::get(baudrate) << "\n\n";
    std::cout << "API IP : " << args::get(api_ip) << "\n\n";
    std::cout << "API Port : " << args::get(api_port) << "\n\n";
    std::cout << "VNC IP : " << args::get(vnc_ip) << "\n\n";
    std::cout << "VNC Port : " << args::get(vnc_port) << "\n\n";
    
    return std::make_pair(true, option {
        args::get(com),
        args::get(baudrate),
        args::get(vnc_ip),
        args::get(api_ip),
        args::get(vnc_port),
        args::get(api_port),
     });
}