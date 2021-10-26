#ifndef disjointset_h
#define disjointset_h
#include <vector>

/* Note to self
rank init to 1 [Default]
rank -> set's max depth.
*/

template <class type>
class disjoint_set
{
public:
    disjoint_set(__int32 n = 0) : _groupCount(n), _setcount(std::vector(_groupCount, 1)) { createDisjointSet(); }
    void union_set(type, type);
    type find_parent(type);
    inline bool is_valid(type &) const;
    bool detect_cycle(type &, type &);

private:
    __int32 _groupCount;
    std::vector<type> _parent;
    std::vector<type> _rank;
    std::vector<type> _setcount;
    inline void createDisjointSet();
};

template <class type>
void disjoint_set<type>::createDisjointSet()
{
    _parent = std::vector<type>(_groupCount);
    _rank = std::vector<type>(_groupCount, 1);
    for (type i = 0; i < _groupCount; i++)
        _parent[i] = i;
}
#endif