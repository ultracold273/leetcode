/**
 * LeetCode Q146 - LRU Cache
 * Design and implement a data structure for Least Recently Used (LRU) 
 * cache. It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if 
 * the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not 
 * already present. 
 * When the cache reached its capacity, it should invalidate the least 
 * recently used item before inserting a new item.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache( 2 ) // capacity;
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 */

/**
 * Hash map plus a linked list implementation
 * Hashmap find at constant time
 * linked list delete, insert and remove all at constant time
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct CacheItemNode{
    int key;
    int val;
    CacheItemNode * prev;
    CacheItemNode * next;
    CacheItemNode(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private: 
    int capacity;
    int size;
    unordered_map<int, CacheItemNode *> hashMap;
    CacheItemNode * head, * tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = tail = NULL;
    }

    int get(int key) {
        if (hashMap.count(key) == 0) return -1;
        else {
            CacheItemNode * cNode = hashMap[key];
            if (tail != cNode) {
                if (cNode->prev != NULL) {
                    cNode->prev->next = cNode->next;
                }else {
                    this->head = cNode->next;
                }
                cNode->next->prev = cNode->prev;
                cNode->prev = tail;
                tail->next = cNode;
                tail = cNode;
                cNode->next = NULL;
            }
            return cNode->val;
        }
    }

    void put(int key, int value) {
        if (hashMap.count(key) != 0) {
            CacheItemNode * cNode = hashMap[key];
            cNode->val = value;
            // Remove the node to the last one
            if (tail != cNode) {
                if (cNode->prev != NULL) {
                    cNode->prev->next = cNode->next;
                }else {
                    this->head = cNode->next;
                }
                cNode->next->prev = cNode->prev;
                cNode->prev = tail;
                tail->next = cNode;
                tail = cNode;
                cNode->next = NULL;
            }
        }else if (size < capacity) {
            CacheItemNode * newNode = new CacheItemNode(key, value);
            if (size == 0) head = tail = newNode;
            else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            hashMap[key] = newNode;
            size++;
        }else{
            // Append the new node
            CacheItemNode * newNode = new CacheItemNode(key, value);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            hashMap[key] = newNode;
            // Delete first node
            CacheItemNode * evictNode = head;
            head = head->next;
            head->prev = NULL;
            hashMap.erase(evictNode->key);
            delete evictNode;
        }
    }
};

