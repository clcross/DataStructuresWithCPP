#ifndef SLL_H
#define SLL_H

class SLLNode {
    private:
        int mVal;
        SLLNode *mNext;
    public:
        int get_val() { return mVal; }
        void set_val(int val) { mVal = val; }
        SLLNode* get_next() { return mNext; }
        void set_next(SLLNode *next) { mNext = next; }
        SLLNode(int val, SLLNode *next) {
            set_val(val);
            set_next(next);
        }
};

class SLL {
    private:
        SLLNode *mHead;
        SLLNode *mTail;
    public:
        SLL();
        ~SLL();
        void push_back(const int val);
        void push_front(const int val);
        bool contains(const int val);
        bool remove (const int val);
        void print();
};

#endif
