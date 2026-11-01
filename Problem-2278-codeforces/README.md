G. 0s and 1s
time limit per test2 seconds
memory limit per test256 megabytes
A tree is an undirected connected graph with no cycles.

You are given a tree with n
 nodes, rooted at node 1
. Each node i
 (1≤i≤n
) has a binary state, initially equal to xi
 (xi∈{0,1}
) and a target binary state yi
 (yi∈{0,1}
) associated with it.

You wish to make the state of every node equal to its target state. To do so, you are allowed to inject energy pulses into the root node. Each time a pulse is injected, it propagates through the tree according to the following procedure:

If the current state of the node is 0
, its state becomes 1
, and the pulse stops at this node.

Otherwise, if the current state of the node is 1
, its state becomes 0
, and the node sends one pulse to each of its children. If it has no children, then the pulse disappears. Every pulse sent to a child follows the same propagation rules.
Determine whether it is possible to make the state of every node equal to its target state. If it is possible, also find the minimum number of energy pulses needed to achieve this goal. Since this number can be very large, report the answer modulo 998244353
.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of each test case follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of nodes in the tree.

The next n−1
 lines each contain two integers u
 and v
 (1≤u,v≤n
, u≠v
), denoting an undirected edge between nodes u
 and v
. It is guaranteed that the given edges form a tree.

The next line contains a binary string x
 of length n
, where xi
 (1≤i≤n
, xi∈{0,1}
) represents the initial state of node i
.

The next line contains a binary string y
 of length n
, where yi
 (1≤i≤n
, yi∈{0,1}
) represents the target state of node i
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, if it is impossible to make the state of every node equal to its target state, output −1
. Otherwise, print the minimum number of energy pulses needed modulo 998244353
.

Example
InputCopy
5
1
0
0
1
0
1
3
1 2
1 3
000
011
3
1 2
1 3
000
010
3
1 2
2 3
000
001
OutputCopy
0
1
2
-1
4
Note
In the first test case, the initial state is already equal to the target state. Therefore, no energy pulse is required, and the answer is 0
.

In the second test case, the tree contains only the root. Initially, its state is x1=0
.

After one pulse is injected into the root, its state becomes 1=y1
, and the pulse stops. Therefore, the answer is 1
.

For the third test case, 2
 pulses are needed. The following image shows the propagation of both pulses through the tree.

Propagation of the two pulses. Pulse 1
 yields states 100
, and Pulse 2
 propagates to achieve the target 011
<!-- . -->