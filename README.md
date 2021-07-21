# Wait-free simulation for a Lock-free algorithm.

Implementation of a wait-free simulation for a lock-free algorithm as described in the paper - A Practical Wait-Free Simulation for Lock-Free Data Structures

# Example of a Linked-list insertion

Say, the head of a linked list points to a node A

head -> A (@0x1)

We now want to insert node B.

insert B (@0x2); B.next = 0x1

We do this using a compare_and_swap primitive.

CAS(head, 0x1, 0x2)
    -> Succeed if A is still at the head
    -> fail if A is no longer at the head (maybe due to the insertion from another thread)

## References
1. [Full length Paper](http://cs.technion.ac.il/~erez/Papers/wf-simulation-full.pdf)
2. [Jon Gjengset's Stream](https://youtube.com/watch?v=Bw8-vvtA-E8&list=TLPQMTMwNzIwMjFtX6aDZ-oy3Q&index=4) 
