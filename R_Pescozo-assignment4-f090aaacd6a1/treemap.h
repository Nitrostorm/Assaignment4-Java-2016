#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;
    
    // TODO your code for KeyValuePair goes here
    KeyValuePair(Key key, Value value){
      k = key;
      v = value;
    }
    
    KeyValuePair(const Key key){
      k = key;
    }
    
    //bool & operator< (KeyValuePair<Key,Value> const& b);
    bool operator<( const KeyValuePair<Key>& lhs, const KeyValuePair<Key>& rhs );
    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // TODO your code for TreeMap goes here:
    KeyValuePair<Key,Value> * find(const Key & k, const Value & v) {
        return &(tree.find(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    
    
};


// do not edit below this line

#endif