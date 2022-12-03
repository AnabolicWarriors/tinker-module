#include <string>
#include <utility>

#include <argument/option.h>
#include <args.hxx>

std::pair<bool, option> parser(int argc, char** argv) {
    args::ArgumentParser parser("본 프로그램은 라즈베리파이에서 발생된 시리얼 데이터를 수신받아 VNC 클라이언트를 제어하는 프로그램 입니다.\n", "아래의 옵션을 지정하여 설정을 변경할 수 있습니다.");
    args::HelpFlag help(parser, "help", "넹넹 설정하시죠!", {'h', "help"});
    args::ValueFlag<int> baudrate(parser, "baudrate", "시리얼 통신의 Baudrate를 지정합니다. ", {'b', "baudrate"});
    args::ValueFlag<std::string> com(parser, "com", "시리얼 통신의 Com-Port를 지정합니다. ", {'c', "com"});

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
    std::cout << "Argument Result : \n";
    std::cout << "COM : " << args::get(com) << "\n";
    std::cout << "Baudrate : " << args::get(baudrate) << "\n\n";
    
    return std::make_pair(true, option {
        args::get(com),
        args::get(baudrate),
     });
}