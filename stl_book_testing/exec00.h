#pragma once
#include <iostream>
#include <utility>
#include <tuple>

namespace MyLib
{
    double readAndProcessSum(std::istream& s)
    {
        using std::ios;
        double value, sum;

        ios::iostate old_exceptions = s.exceptions();

        s.exceptions(ios::failbit | ios::badbit);
        try
        {
            sum = 0;
            while (s >> value)
            {
                sum += value;
            }
        }
        catch (...)
        {
            if (!s.eof()) 
            {
                s.exceptions(old_exceptions);
                throw;
            }
        }

        s.exceptions(old_exceptions);
        return sum;
    }

    class ignoreLine
    {
    private:
        int num;
    public:
        explicit ignoreLine(int n = 1): num(n) {}
        
        template<typename charT, typename traits>
        friend std::basic_istream<charT, traits>& operator >> (std::basic_istream<charT,traits>& strm, const ignoreLine& ign)
        {
            for (int i = 0; i < ign.num; ++i)
                strm.ignore(std::numeric_limits<std::streamsize>::max(), strm.widen('\n'));
            return strm;
        }
    };

    //template<typename T1, typename T2>
    //std::ostream& operator << (std::ostream& strm, const std::pair<T1,T2>& p)
    //{
    //    return strm << "[]";
    //}

    //class Foo
    //{
    //public:
    //    Foo(std::tuple<int,float>) 
    //    {
    //        cout << "foo:tuple" << endl;
    //    }

    //    template <typename... Args>
    //    Foo(Args... args) 
    //    {
    //        cout << "foo:args" << endl;
    //    }
    //};
}

int exec01()
{
    int a,b;

    //std::cin >> a;
    //std::cin >> b;

    //std::cout << "a: " << a << " b: " << b << std::endl;

    while (std::cin >> a >> b)
    {
        std::cout << "a: " << a << " b: " << b << std::endl;
    }

	return 0;
}

int exec02()
{
    std::bitset<10> flags(7);
    std::cout << flags;

    std::complex<float> c(3.1f, 7.4f);
    std::cout << c;

    std::string s;
    std::cin >> s;
    std::cout << s;

    char buffer[81];
    std::cin >> std::setw(81) >> buffer;
    std::cout << buffer;

    return 0;
}

int exec03()
{
    char* cstring = "hello";

    std::cout << static_cast<void*>(cstring) << std::endl;

    //int x;
    //std::cin >> x;
    std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
    std::cin.setstate(std::ios::failbit);
    
    std::cout << std::cin.fail() << std::endl;

    //std::cout << cin.rdstate() << std::endl;

    return 0;
}

int exec04()
{
    using namespace std;
    double sum;
    try
    {
        sum = MyLib::readAndProcessSum(cin);
    }
    catch (const ios::failure& error)
    {
        cerr << "I/O Exception: " << error.what() << endl;
        return EXIT_FAILURE;
    }
    catch (const exception& error)
    {
        cerr << "Standard Exception: " << error.what() << endl;
        return EXIT_FAILURE;
    }
    catch (...)
    {
        cerr << "Unknown exception" << endl;
        return EXIT_FAILURE;
    }

    cout << "sum: " << sum << endl;

    return 0;
}

int exec05()
{
    using namespace std;
    //char c1[5];
    //cin.get(c1, 5);
    //cout << c1 << endl;
    //cout << (cin.rdstate() & ios::failbit) << endl;

    char c2[80], c3[80];
    cin.get(c2, 5);
    cin.getline(c3, 5, 'y');

    cout << c2 << endl;
    cout << c3 << endl;
    cout << (cin.rdstate() & ios::failbit) << endl;

    return 0;
}

int exec06()
{
    using namespace std;
    using namespace MyLib;

    cout << setw(6) << setfill('_') << "he" << endl;

    endl(cout);
    endl(cout);
    endl(cout);

    cin >> ignoreLine(5);

    return 0;
}

int exec07()
{
    using namespace std;
    using namespace MyLib;
    pair<int,int> p;
    p = make_pair(5, 4);

    //cout << p << endl;

    cout << std::tuple_size<pair<int,int>>::value << endl;
    std::tuple_element<0, pair<int,int>>::type x;


    return 0;
}

int exec08()
{
    //using namespace std;
    //using namespace MyLib;

    //tuple<int,float> t(1, 2.2);
    //pair<int,Foo> p1(42, t);

    //pair<int,Foo> p2(piecewise_construct, make_tuple(42), t);

    int i = 0;
    auto p = std::make_pair(std::ref(i), std::ref(i));
    p.first++;
    p.second++;
    std::cout << i << std::endl;

    return 0;o
}

int exec09()
{


    return 0;
}
