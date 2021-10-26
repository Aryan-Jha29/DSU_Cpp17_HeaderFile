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

template <class type>
bool disjoint_set<type>::detect_cycle(type &node_id1, type &node_id2)
{
    return (find_parent(node_id1) == find_parent(node_id2));
}

/*  
 1 2 3 4 5 -> 5
 Union(12) [12, 3,4,5] -> 4
 union(34) [12, 34, 5] -> 3
 Union(12,34) [1234, 5] -> 2

*/
/*Implementation of find_parent using Path Compression*/
template <class type>
type disjoint_set<type>::find_parent(type node_id)
{
    // need isValid
    if (node_id == _parent[node_id])
        return node_id;

    return _parent[node_id] = find_parent(_parent[node_id]);
}

#endif