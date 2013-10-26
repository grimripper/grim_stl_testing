#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    std::ofstream f("output.bin", ios::out | ios::binary);
    f << "hello" << endl;
    f.write(
    f.close();
    
    std::ifstream f2("output.bin", ios::in | ios::binary);
    cout << f2.rdbuf();
}
