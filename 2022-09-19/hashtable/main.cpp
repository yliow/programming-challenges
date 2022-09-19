/*
  std::unordered_map
  std::unordered_set

  Hashtable
  Runtime: average O(1), worse O(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

template < typename T >
std::ostream & operator<<(std::ostream & cout, const std::unordered_set< T > & X)
{
    std::string delim = "";
    cout << '{';
    for (auto & x: X)
    {
        cout << delim << x;
        delim = ", ";
    }
    cout << '}';
    return cout;
}

template < typename S, typename T >
std::ostream & operator<<(std::ostream & cout, const std::unordered_map< S, T > & X)
{
    std::string delim = "";
    cout << '{';
    for (auto & x: X)
    {
        cout << delim << x.first << ':' << x.second;
        delim = ", ";
    }
    cout << '}';
    return cout;
}

int main()
{
    std::unordered_set< int > X;
    std::cout << X << '\n';

    for (auto x: std::vector< int >{1, 3, 5, 3})
    {
        if (X.find(x) == X.end())
        {
            std::cout << x << " not found ... add ...";
            X.insert(x);
            std::cout << X << " ... ";
            if (X.find(x) != X.end())
            {
                std::cout << x << " found\n";
            }
        }
        else
        {
            std::cout << x << " found\n";
        }
    }
    X.erase(3);
    std::cout << X << '\n';
    X.clear();
    std::cout << X << '\n';

    std::cout << "unordered map\n";
    
    std::unordered_map< int, int > h;
    std::cout << h << '\n';
    for (auto & key: std::vector< int >{1, 3, 5})
    {
        if (h.find(key) == h.end())
        {
            std::cout << key << " not found ... add ... ";
            h[key] = 2 * key;
            std::cout << h << " ... ";
            if (h.find(key) != h.end())
            {
                std::cout << "found ...";
                std::cout << h << '\n';
            }
        }
        else
        {
            std::cout << key << " found\n";
        }
    }
    h.erase(3);
    std::cout << h << '\n';
    h.clear();
    std::cout << h << '\n';

    return 0;
}
