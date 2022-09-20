#include <iostream>
#include <vector>

template < typename T >
std::ostream & operator<<(std::ostream & cout, const std::vector< T > & v)
{
    std::string delim = "";
    cout << '[';
    for (auto & x: v)
    {
        cout << delim << x;
        delim = ", ";
    }
    cout << ']';
    return cout;
}

int main()
{
    std::vector< int > v{1,2,3};
    std::cout << v << '\n';
    v.push_back(42);
    std::cout << v << '\n';

    std::vector< int >::iterator p = v.begin();
    ++p;
    v.erase(p);
    std::cout << v << '\n';
    std::cout << *p << '\n';
    v.insert(p, 999);
    std::cout << v << '\n';

    v.clear();
    std::cout << v << '\n';
    
    return 0;
}
