#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main()
{
    ordered_set s;

    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(11);
    s.insert(13);

    cout << "Segundo primo: " << *s.find_by_order(1) << '\n';
    cout << 11 << "  ́e o " << s.order_of_key(11) + 1 << "ºprimo\n";

    return 0;
}

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

int main()
{
    ordered_multiset s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    // s = 1 2 2 3 3 3
    for (auto x : s)
        cout << x << ' ';
    cout << '\n';

    s.erase(s.find_by_order(s.order_of_key(3)));

    // s = 1 2 2 3 3
    for (auto x : s)
        cout << x << ' ';
    cout << '\n';

    return 0;
}