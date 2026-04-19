#ifndef ARRAY_LIST_DICTIONARY_HPP
#define ARRAY_LIST_DICTIONARY_HPP

#include "Dictionary.hpp"
#include "ArrayList.hpp"
#include <iomanip>

template <typename Key, typename Val>
class ArrayListDictionary : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }

            bool operator<(Record& rightObj) const { return this->k < rightObj.k; }
            bool operator<=(Record& rightObj) const { return this->k <= rightObj.k; }
            bool operator>(Record& rightObj) const { return this->k > rightObj.k; }
            bool operator>=(Record& rightObj) const { return this->k >= rightObj.k; }
            bool operator==(Record& rightObj) const { return this->k == rightObj.k; }
            bool operator!=(Record& rightObj) const { return this->k != rightObj.k; }
        };

        // the underlying array-based list
        ArrayList<Record>* list;

        // copy the state of the argument dictionary to `this`
        void copy(const ArrayListDictionary<Key, Val>&);

    public:
        // constructor with the maximum size as the argument
        ArrayListDictionary(int = 100);

        // copy constructor
        ArrayListDictionary(const ArrayListDictionary<Key, Val>&);

        // overloaded assignment operator
        ArrayListDictionary<Key, Val>& operator=(const ArrayListDictionary<Key, Val>&);

        // destructor
        virtual ~ArrayListDictionary();

        // remove all records in the dictionary, resetting to the initial state
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // return the number of key comparisons made by the sorting algorithm
        virtual unsigned getNumComps() const;

        // return the number of swaps made by the sorting algorithm
        virtual unsigned getNumSwaps() const;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;

        // sort the records in the dictionary using the algorithm (argument 1)
        //      1 --> bubble sort
        //      2 --> selection sort
        //      3 --> insertion sort
        virtual void sort(int);

        // overloaded stream insertion operator to make printing easier
        template <typename T, typename U>
        friend ostream& operator<<(ostream&, const ArrayListDictionary<T,U>&);
};

#include "ArrayListDictionary.tpp"
#endif
