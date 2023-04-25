class SmallestInfiniteSet {
    set<int> S;
public:

    SmallestInfiniteSet() {
        for (int i=1; i<=1000; i++)
            S.insert(i);
    }

    int popSmallest() {
        int x = *S.begin();
        S.erase(S.begin());
        return x;
    }

    void addBack(int num) {
        S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */