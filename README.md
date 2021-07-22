# Wait-free simulation for a Lock-free algorithm.

Implementation of a wait-free simulation for a lock-free algorithm as described in the paper - A Practical Wait-Free Simulation for Lock-Free Data Structures. 

# Components of the algorithm
1. Normalized Lock Free Form
2. Wait-free queue
3. Contention Measure
4. Cas Descriptor
5. Wait-Free simulator

# The ABA problem

This section maybe a little convoluted. It is a WIP.

Say, the head of a linked list points to a node A

head -> A (@0x1)

We now want to insert node B.

insert B (@0x2); B.next = 0x1

We do this using a compare_and_swap primitive.

CAS(head, 0x1, 0x2)
    -> Succeed if A is still at the head
    -> fail if A is no longer at the head (maybe due to the insertion from another thread), because B.next would need to be different.

However, there is a possibilty of a problem.

Imagine someone else meanwhile 

insert C (@0x3); C.next = 0x1

CAS(head, 0x1, 0x3)

Now lets imagine someone removes A

remove A

CAS(C.next, 0x1, 0x0)

Now if someone inserts a node D

insert D (@0x1); and D.next = 0x3

C is at the head

CAS(head, 0x3, 0x1)

So the final LL

head -> D -> C -> .

and now ...

insert of B continues.

CAS(head, 0x1, 0x2)
-> this CAS should have failed ideally

head -> B -> A(@0x1) actually D(@0x1) -> C(@0x3)

Even though the last CAS happened to succeed since the values were same, but the thing we are pointing aren't really the same.

This is known as the ABA problem. 

## References
1. [Full length Paper](http://cs.technion.ac.il/~erez/Papers/wf-simulation-full.pdf)
2. [Jon Gjengset's Stream](https://youtube.com/watch?v=Bw8-vvtA-E8&list=TLPQMTMwNzIwMjFtX6aDZ-oy3Q&index=4) 
