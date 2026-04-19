#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the list
        int maxSize;

        // copy the state of the argument list to `this`
        void copy(const ArrayList<T>&);

        // swap the elements at the given positions
        void swap(int, int);

        // different sort algorithms to sort the elements in the list
        void bubbleSort();
        void selectionSort();
        void insertionSort();

        // counter to keep track of the number of key comparisons and swaps
        static unsigned numComps, numSwaps;

    public:
        // constructor with the maximum size as the argument
        ArrayList(int = 100);

        // copy constructor
        ArrayList(const ArrayList<T>&);

        // overloaded assignment operator
        ArrayList<T>& operator=(const ArrayList<T>&);

        // destructor
        virtual ~ArrayList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // return the maximum size of the list
        int getMaxSize() const;

        // return the number of key comparisons made by the sorting algorithm
        static unsigned getNumComps();

        // return the number of swaps made by the sorting algorithm
        static unsigned getNumSwaps();

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // determine if the list currently full
        bool isFull() const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // sort the elements in the list using the algorithm (argument 1)
        //      1 --> bubble sort
        //      2 --> selection sort
        //      3 --> insertion sort
        virtual void sort(int);

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const ArrayList<U>&);
};

#include "ArrayList.tpp"
#endif
