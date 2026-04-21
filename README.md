[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/CfQsebdN)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=23666342&assignment_repo_type=AssignmentRepo)
# Bubble/Selection/Insertion Sorts

## Directions

You are going to implement the three exchange-based sorting algorithms as discussed in lecture. This program relies on the `Dictionary` ADT being implemented by using an array-based list as the underlying data structure. The sorting algorithms need to be implemented in the `ArrayList` class template. A working `main` function is already provided. Use this to test your various sorting algorithms.

## Notes

- Assume these sorting algorithms are only performing an ascending sort
- Since we are implementing these algorithms within `ArrayList`, all data are stored in `buffer`
    + This is a typical array, so you can use the `[]` subscript operator on it directly
- There is a `swap` method available for you to use within `ArrayList`
    + It takes two arguments, which are the two indices you want to swap in `buffer`
- Each sorting algorithm needs to keep track of how many key comparisons are being performed and the number of swaps it needed
    + There are already attributes for this (`numComps` and `numSwaps`, respectively)
    + Make sure that you're incrementing them as the algorithm proceeds

## Sample Run

If you managed to implement these algorithms correctly, you should be able to match the following sample runs exactly. You are suggested to try other scenarios as well (best case, worst case, etc.).

### Bubble Sort

```text
Welcome to my dictionary program!
Here are your options:
        1. Find
        2. Insert
        3. Remove
        4. Sort
        5. Size
        6. Clear
        7. Print
        8. Quit
Enter your option: 4
What kind of sort algorithm should be used?
        1. Bubble sort
        2. Selection sort
        3. Insertion sort
1
Number of key comparisons: 28
Number of swaps: 15
Enter your option: 7
--------------------------------------------------------------------------------
   0 | banana                    | a fruit that many like, or a phone
   1 | cactus                    | a pointy plant
   2 | dog                       | a domesticated fluff ball
   3 | graph                     | an awesome data structure!
   4 | haskell                   | fantastic programming language, go learn it
   5 | igloo                     | a cool house
   6 | phoenix                   | a bird on fire
   7 | quack                     | said Mr. Duck
--------------------------------------------------------------------------------
Enter your option: 8
```

### Selection Sort

```text
Welcome to my dictionary program!
Here are your options:
        1. Find
        2. Insert
        3. Remove
        4. Sort
        5. Size
        6. Clear
        7. Print
        8. Quit
Enter your option: 4
What kind of sort algorithm should be used?
        1. Bubble sort
        2. Selection sort
        3. Insertion sort
2
Number of key comparisons: 28
Number of swaps: 5
Enter your option: 8
```

### Insertion Sort

```text
Welcome to my dictionary program!
Here are your options:
        1. Find
        2. Insert
        3. Remove
        4. Sort
        5. Size
        6. Clear
        7. Print
        8. Quit
Enter your option: 4
What kind of sort algorithm should be used?
        1. Bubble sort
        2. Selection sort
        3. Insertion sort
3
Number of key comparisons: 20
Number of swaps: 15
Enter your option: 8
```
