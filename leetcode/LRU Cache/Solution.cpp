#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;
struct Node {
    int key;
    int value;
    Node *pre;
    Node *next;
    Node(int x, int y): key(x), value(y), pre(NULL), next(NULL) {}
};
class LRUCache{
private:
	int max;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;
    unordered_map<int, Node *>::iterator it;
public:
    LRUCache(int capacity) {
    	max = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
    	int result = -1;
    	it = map.find(key);
        if(it != map.end()) {
            result = (it->second)->value;
            deleteNode(it->second);
            insertToHead(it->second);
        }
    	return result;
        
    }
    
    void set(int key, int value) {
        it = map.find(key);
        if(it != map.end()) {
            Node *node = it->second;
            node->value = value;
            deleteNode(node);
            insertToHead(node);
        }
        else {
            Node *newItem = new Node(key, value);
            if(map.size() >= max) {
                //cout<<"page out"<<endl;
                Node *victim = tail->pre;
                deleteNode(victim);
                map.erase(victim->key);
            }
            insertToHead(newItem);
            map[key] = newItem;
        }
    }
    void insertToHead(Node *node) {
        Node *next = head->next;
        head->next = node;
        node->pre = head;
        node->next = next;
        next->pre = node;
    }
    void deleteNode(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
};
int main(int argc, char const *argv[])
{
	LRUCache *cache = new LRUCache(1);
	cache->set(2, 1);
    cout<<cache->get(2)<<endl;
    cache->set(3, 2);
    cout<<cache->get(2)<<endl;
    cout<<cache->get(3)<<endl;
	return 0;
}