#include <iostream>
#include <regex>
using namespace std;
std::string file_extension(const std::string &path) {
                 std::smatch m;
                 auto pat = std::regex("\\.([a-zA-Z0-9]+)$");
                 if (std::regex_search(path, m, pat)) { return m[1].str();  }
                 return std::string();                                                
             
}

int main()
{
    string str = "home/ys/project/http_download/abc.txt";
    cout << file_extension(str)<<endl;
    return 0;
}

