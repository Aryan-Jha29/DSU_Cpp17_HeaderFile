# Disjoint-Set-Union-Header

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/powered-by-coffee.svg)](https://forthebadge.com) [![forthebadge](https://forthebadge.com/images/badges/uses-brains.svg)](https://forthebadge.com)


Implementation of **Disjoint Set Union Header File(.hpp)** from scratch using object oriented design approach.

## How to use?
* **disjoint_set.hpp** file must be present in the **present working directory** or its path must be set in the environment variable for the IDE.
* Compatible C++ versions: **C++11, C++14, C++17, C++20**

---
## Key Functionalities

* To create a **DSU**(Disjoint Set Union) with **N groups**.
* To merge two set with given `node_ids`.
    * Implemented **Union-By-Rank** to perform optimsed merger of nodes.
* To find the `parent_node` for a given input node.
    * Implemented **Path Compression** to optimise the method.
* To perform validation of nodes with the given `node_id`.
* To detect existence of a cycle by utilising the **find_parent** method.
*  To obtain the total count of disjoint sets in **O(1)**
*  To obtain the size of the set to which a given node belongs in **O(1)**

---
## Sample C++ template:

```c++
    #include <bits/stdc++.h>
    #include "disjoint_set.hpp"

    using namespace std;
    int main()
    {
        int N;
        cin>>N;
        disjoint_set<int> ds(N);
        // code goes here
    }      
```
---

## Methods
**disjoint_set<datatype>:: method()**

* **bool is_valid(`datatype &`)**
* **datatype find_parent(`datatype`)**
* **void union_set(`datatype`, `datatype`)**
* **bool detect_cycle(`datatype &`, `datatype &`)**
* **datatype get_dsu_count()**
* **datatype get_set_count(`datatype`)**
  

---

## CopyRight & License
**[MIT LICENSE](https://github.com/Aryan-Jha29/Disjoint-Set-Union-Header/blob/main/LICENSE "View")**

### Authors

* **[Akash Chouhan](https://github.com/akashchouhan16  "View Profile")**
* **[Aryan Jha](https://github.com/aryan-Jha29  "View Profile")**






