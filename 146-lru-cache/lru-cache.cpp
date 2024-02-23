class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node* next;
        Node* prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    int cap=0;
    unordered_map<int,Node*> mp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(Node* temp){
        Node* temp2=head->next;
        temp->next=temp2;
        temp->prev=head;
        head->next=temp;
        temp2->prev=temp;
    }

    void del(Node* temp){
        Node* tempnext=temp->next;
        Node* tempprev=temp->prev;
        tempprev->next=tempnext;
        tempnext->prev=tempprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            del(temp);
            add(temp);
            
            mp[key]=head->next;
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            del(mp[key]);
            mp.erase(key);
        }
        if(cap==mp.size()){
            mp.erase(tail->prev->key);
            del(tail->prev);
        }
        Node* temp=new Node(key,value);
        add(temp);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */