⚙️ How a Priority Queue Works (using a Heap)
🧩 1. Insertion (Enqueue)

When you insert a new element:
- Place it at the last index (the next open spot in the heap).
- Then “bubble up” or “heapify up”:
- If it violates the heap property (e.g., child > parent in a Max Heap),
swap it with its parent.
    
Keep doing this until the property is satisfied.
🧠 Think of it as the new element climbing up to its correct “priority” spot.


🗑️ 2. Deletion (Dequeue)
When removing the top priority element (the root):

1. Swap the root with the last element.
2. Remove the last element (which was the root).
3. Then “bubble down” or “heapify down”:
- Compare the new root with its children.
- In a Max Heap, if a child is larger,wb swap with the larger child.
- Continue until no violations remain.
🧠 Think of it as the root “sinking down” until it’s correctly placed.