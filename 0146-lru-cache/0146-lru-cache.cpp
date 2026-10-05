class LRUCache {
public:
    int cap;
    class Node{
        public:
            int key;
            int val;
            Node*prev;
            Node*next;
            Node(int _key,int _val){
                key=_key;
                val=_val;
            }
    };
    Node*head;
    Node*tail;
    unordered_map<int,Node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node*node){
        Node*delprev=node->prev;
        Node*delnext=node->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    void insertNode(Node*node){
        Node*temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node*node=mpp[key];
        int res=node->val;
        deleteNode(node);
        insertNode(node);
        return res;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*node=mpp[key];
            deleteNode(node);
            node->val=value;
            insertNode(node);
            return;
        }else{
            if(mpp.size()==cap){
                Node*node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node*newNode=new Node(key,value);
            mpp[key]=newNode;
            insertNode(newNode);
        }
    }
};
