#ifndef disjointset_h
#define disjointset_h
#include <vector>

template <class T>
class disjointset
{
public:
    disjointset(__int32 n = 0) : _groupCount(n) { createDisjointSet(); }

private:
    __int32 _groupCount;
    std::vector<T> _parent;
    std::vector<T> _rank;
    inline void createDisjointSet();
};

void disjointset::createDisjointSet()
{
    // create a group.
}

#endif