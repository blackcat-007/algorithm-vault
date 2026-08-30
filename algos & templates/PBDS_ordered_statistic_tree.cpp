#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_set =
    tree<T,
         null_type,
         less<T>,
         rb_tree_tag,
         tree_order_statistics_node_update>;

//usage
ordered_set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
//kth smallest element (0-indexed)
*s.find_by_order(k);
//NUMBER OF ELEMENTS STRICTLY LESS THAN x
s.order_of_key(x);