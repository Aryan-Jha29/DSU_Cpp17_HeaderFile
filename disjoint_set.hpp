#ifndef disjointset_h
#define disjointset_h
#include <iostream>
#include <vector>

static const auto optimize = []() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

template <class type>
class disjoint_set
{
public:
    disjoint_set(type n = 0) : _groupCount(n), _setcount(std::vector<type>(_groupCount, 1))
    {
        createDisjointSet();
    }
    void union_set(type, type);
    type find_parent(type);
    bool is_valid(type &) const;
    bool detect_cycle(type &, type &);
    type get_dsu_count() { return _groupCount; }
    type get_set_count(type node_id)
    {
        return (is_valid(node_id)) ? _setcount[node_id] : -1;
    };

private:
    type _groupCount;
    std::vector<type> _parent;
    std::vector<type> _rank;
    std::vector<type> _setcount;
    void createDisjointSet();
    type find_parent_util(type);
};

template <class type>
inline void disjoint_set<type>::createDisjointSet()
{
    _parent = std::vector<type>(_groupCount);
    _rank = std::vector<type>(_groupCount, 1);
    for (type i = 0; i < _groupCount; i++)
        _parent[i] = i;
}

/*To check if node used is valid and belongs to the dsu or no.*/
template <class type>
inline bool disjoint_set<type>::is_valid(type &node_id) const
{
    return (node_id >= 0 and node_id < _parent.size());
}

/*To detect cycle for 2 nodes with respective node ids.*/
template <class type>
bool disjoint_set<type>::detect_cycle(type &node_id1, type &node_id2)
{
    return (find_parent(node_id1) == find_parent(node_id2));
}

/*Implementation of find_parent using Path Compression.*/
template <class type>
type disjoint_set<type>::find_parent(type node_id)
{
    return (is_valid(node_id)) ? find_parent_util(node_id) : -1;
}
template <class type>
type disjoint_set<type>::find_parent_util(type node_id)
{
    if (node_id == _parent[node_id])
        return node_id;

    return _parent[node_id] = find_parent_util(_parent[node_id]);
}

/*Implementation of UNION of two sets using Union-By Rank.*/
template <class type>
void disjoint_set<type>::union_set(type node_id1, type node_id2)
{
    if ((not is_valid(node_id1)) or (not is_valid(node_id2)))
    {
        std::cerr << "[*]Node Invalid" << std::endl;
        return;
    }

    type group_id1 = find_parent(node_id1);
    type group_id2 = find_parent(node_id2);
    bool flag = false;
    if (not detect_cycle(node_id1, node_id2))
    {
        _groupCount -= 1;
        flag = true;
        if (_rank[group_id1] < _rank[group_id2])
        {
            _parent[group_id1] = group_id2;
            _setcount[group_id2] += _setcount[group_id1];
        }
        else if (_rank[group_id1] > _rank[group_id2])
        {
            _parent[group_id2] = group_id1;
            _setcount[group_id1] += _setcount[group_id2];
        }
        else
        {
            _parent[group_id2] = group_id1;
            _setcount[group_id1] += _setcount[group_id2];
            _rank[group_id1] += 1;
        }
    }

    if (not flag)
    {
        std::cerr << "[*]Invalid Operation -> cycle detected(" << node_id1 << "," << node_id2 << ")";
        std::cout << std::endl;
    }
    return;
}
#endif
