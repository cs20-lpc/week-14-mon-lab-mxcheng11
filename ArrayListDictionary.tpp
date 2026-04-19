template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(int i)
: list(new ArrayList<Record>(i)) { }

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::ArrayListDictionary(const ArrayListDictionary<Key, Val>& copyObj) {
    copy(copyObj);
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>& ArrayListDictionary<Key, Val>::operator=(const ArrayListDictionary<Key, Val>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename Key, typename Val>
ArrayListDictionary<Key, Val>::~ArrayListDictionary() {
    delete list;
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::copy(const ArrayListDictionary<Key, Val>& copyObj) {
    list = new ArrayList<Record>(*copyObj.list);
}

template <typename Key, typename Val>
Val ArrayListDictionary<Key, Val>::find(const Key& target) const {
    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == target) {
            return list->getElement(i).v;
        }
    }

    throw string("find: error, unsuccessful search, target key not found");
}

template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::getNumComps() const {
    return list->getNumComps();
}

template <typename Key, typename Val>
unsigned ArrayListDictionary<Key, Val>::getNumSwaps() const {
    return list->getNumSwaps();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::remove(const Key& k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        throw string("remove: error, unable to find record with matching key to remove");
    }
}

template <typename Key, typename Val>
int ArrayListDictionary<Key, Val>::size() const {
    return list->getLength();
}

template <typename Key, typename Val>
void ArrayListDictionary<Key, Val>::sort(int algo) {
    list->sort(algo);
}

template <typename Key, typename Val>
ostream& operator<<(ostream& outStream, const ArrayListDictionary<Key, Val>& myObj) {
    const char FILL       = '-';
    const int  WIDTH      = 80;
    const int  SLOT_WIDTH = 4;
    const int  KEY_WIDTH  = 25;

    typename ArrayListDictionary<Key, Val>::Record r;

    if (myObj.size() == 0) {
        outStream << "Dictionary is empty!\n";
    }
    else {
        outStream << setfill(FILL) << setw(WIDTH) << "" << endl << setfill(' ');

        for (int i = 0; i < myObj.list->getLength(); i++) {
            r = myObj.list->getElement(i);
            outStream << right << setw(SLOT_WIDTH) << i << " | "
                      << left << setw(KEY_WIDTH)
                      << r.k << " | " << r.v << endl;
        }

        outStream << setfill(FILL) << setw(WIDTH) << "" << endl;
    }

    return outStream;
}
