# Implemntations 
- Bit-Vector
- Linked-List
- Array
- CursorBased
- Partially Ordered Tree (P.O.T)

# Characteristics of POT
- Binary tree
    - a tree has a left or right child or both left and right
- Balanced tree
    - height is minimum for the # of nodes
-At lowest level where leaves may be missing we require that all MISSING LEAVES ARE TO THE RIGHT OF ALL LEAVES PRESENT in te lowest level
- POT Property
    - the priority of the parent is less than or equal to the priority of the children

# Steps in inserting
- place new element x at the lowest level to the right of the leaves present  OR
    - next level if current level is full
- while (x is not root && POT not satisfied){
    SWAP(parent, x)
}
# DeleteMin
- min = root node
- replace root with the element x found at the lowest level far right
- While ((X is not leaf) and NOT POT){
    SChild = smaller child of parent X;
    SWAP(parent, X);
}
- return min;

# Exercise
- Given index of parent find formula of the index of Left child and right child
    - LC = 2 * parentndx + 1;
    - RC = 2 * parentndx + 2;
- Given index of child (either left or right) find formula of parent
    - parentIndex = (childndx - 1) / 2 

## Notes
### Partially Ordered Trees (POT)
- Parent node shall be higher order than its children
    - ordering of nodes in the 

### Heap property
- MinHeap
- MaxHeap
- highest priority shall be the root and rest of its childrenshall be lsss than or equal priority of root

### BINARY SEARCH TREE
- left child has to be lesser than: Right child has to be greater than its parent node
- in BST, parent node 

## HEAP
- katong array nga elements is stored nga lC = 2 * parentidx + 1 chuchu 
- naay max ug min heap or diri tong max min hepa

## POT 
- katong parent node is higher order    than its children