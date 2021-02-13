Difficulty: 1900. Time: 5hours.

In fact I wasn't sure whether I've used this much time. The thing is that I didn't focus entirely on this one. The problem is very interesing. 

From the official editorial, I noticed that they describe the solution in a better way. What I did was essentially the same
as what they do, of course, otherwise I would have not got AC. However my idea was messy, and I am sure if I am not learning
new stuff, next time in the contest I would still use that long time.

## My idea: 

It is kind of clear that we need to sort the items. Then I care whether an array has a tail (len > 1). If it doesn't have a tail,
it means that it has nothing else to move out of the array, causing no decrease. If it does have a tail, then it must cause some
decrease. 

Then I made it into 4 cases: 0, 1, 2, and 3 tails respectively. If it has 0 tails, then it is simple, just max + mid - min.
If it has 3 tails,  this is also trivial, because it means, at least we need to cause decreases twice. Note that we should treat
the sum of all tail elements as a single sum. 

Now the 1 and 2 tails are trickier. For 1 tail, it means that whatever we do, the array with the tail must have all its elements
contribute the same sign, i.e., the tail and its head must go together. Either as positive numbers in the result or as a negative
part in the result. Why? Because the tail must go out to one of the other two singletons, say we have {a,b}, {c}, {d}, and it
goes to {a}, {c-b}, {d}. Then next time either we move {a} out, to get a minus a somewhere, or we do {a + b - c}. In any case,
a and b have the same sign in the final sum. Hence when we only have 1 tail, we find that array, sum the head and the tail, then treat it as a
0 tail case by doing max + mid - min. 

For 2 tails, it means that we have 5 numbers, 3 heads and 2 tails. What to do in this case? This time it is not clear what to do with these
5 parts. My own method is stopping me from thinking in a clear way. First I choose the smallest 2 numbers from these 5 numbers and give them
two negative signs. WA. Second I realized that we can actually all move to the single head to only cause 1 decrease, but I made a mistake to compare
the single head and the sum of the other two heads, which is also WA. The right answer is to first find the single head, then compare it with the
sum of the two smallest values in the other 4 values. Why? Because our method is either to cause only one decrease to that single head,
or we find two values (either head, or tail) in the other 4 values because we have to make 5 values to 1 value, which means, we need to make two
of them operated on another two (since we are not using the single head, and we cannot make the two values in the same set operate on each other),
therefore our target is to find the two smallest values in these 4.

So in this most complicated case, we need to compare the single head and the two smallest values in the other two arrays. Then find the final result.

---

## What the official idea is better than mine and what is the defect of my method?

They clearly spot the operations into a tree structure. From the tree structure, we can actually see how the elements
from different bags would restrict each other. Then by doing so, they find the target that they want to minimize.

However, in my case, it actually took me a few hours to prove my case analysis is correct especially for 1/2 tails.
Also I found them out by using the test cases from the online judge, this is not good for a contest. For the 2 tails,
it is very tricky to see how to deal with them. 

Note that essentially the official website does the same thing as mine, especially for the last tedious discussion on two tails.
In their argument, they do not even have to worry about this argument. Because they prove a more abstract and essential idea:
on the odd layers, they either 1. pick all nodes from a set or 2. two smallest values from different sets. 

How this idea corresponds to my 2-tail case: if we use 1 single head -- we take all elements from that array, their case 1; 
if we use 2 smallest values among the other 4, if they are in the same array, we are taking all elements from that array 
essentially because a tail is equal to the sum of all the rest values, their case 1.
If they are not in the same array, for sure we are picking those two non-singleton heads, then it is their case 2.

---

## Official tutorial:
Model the problem as a rooted tree (graph). There are 𝑛_1 + 𝑛_2 + 𝑛_3 nodes, corresponding to the elements from the three bags. Edges between two nodes represent an operation on the two elements and it can be seen that an edge can exist only between nodes of elements from different sets. A directed edge from 𝑏 to 𝑎 means that 𝑏 is removed and 𝑎 is replaced to 𝑎−𝑏. All edges are directed towards the root.

In the given rooted tree, operations are applied bottom up, that is, an operation is applied on a leaf node and its parent, and the leaf node is removed. The process is continued until only the root node is remaining.

It is easy to see that the value of the element at the end of all operations is the sum of elements at even depth minus the sum of elements at odd depth (depth is 0 indexed).

Claim: The constructed rooted tree is valid, if the elements at odd depth are

1. are from at least two different bags, or

2. contain all elements from one bag.

Proof:

Consider a rooted tree with all elements at odd depth from exactly one bag (say 𝑋) which doesn't fulfil criteria 2. No remaining elements from bag 𝑋 can be connected to the nodes at odd depth, making it impossible to construct a tree. This implies that 1 must hold.

However, if criteria 2 holds, no elements from bag 𝑋 remain to be connected, and thus the tree can be constructed.

Hence proved.

Now, we have to minimise either of the two cases, which is the solution to the problem.

For the first case, we can choose the two smallest numbers such that they both appear in different bags to be at odd depth.

For the second case, we can choose all numbers from the bag where the sum of the numbers is minimum to be at odd depth.



