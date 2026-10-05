class LFUCache {
public:

    class Node {
    public:
        int key;
        int val;
        int freq;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            freq = 1;
        }
    };

    int cap;
    int minFreq;

    unordered_map<int, Node*> mpp;

    unordered_map<int, list<Node*>> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void increaseFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq].remove(node);
        if(freqList[oldFreq].empty()) {

            if(minFreq == oldFreq) {
                minFreq++;
            }

            freqList.erase(oldFreq);
        }
        node->freq++;
        freqList[node->freq].push_front(node);
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];
        increaseFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if(cap == 0) {
            return;
        }
        if(mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            node->val = value;
            increaseFreq(node);

            return;
        }
        if(mpp.size() == cap) {
            auto& list = freqList[minFreq];
            Node* lru = list.back();

            mpp.erase(lru->key);

            list.pop_back();

            delete lru;

            if(list.empty()) {
                freqList.erase(minFreq);
            }
        }
        Node* newNode = new Node(key, value);

        mpp[key] = newNode;
        freqList[1].push_front(newNode);

        minFreq = 1;
    }
};