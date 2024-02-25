class MedianFinder {
public:
    multiset<int> balancedBST;
    multiset<int>::iterator mid;

    MedianFinder() {
    }
    
    void addNum(int num) {
        // O(2logN) 

        // O(logN)
        balancedBST.insert(num);
        if(balancedBST.size() == 1) 
        {
            mid = balancedBST.begin();
            print();
            cout << distance(balancedBST.begin(), mid) << " " << *mid << endl;
            return;
        }

        // O(logN)
        if(num >= *mid) // since set.begin() moves, divide the cases.
        {   // 1) inserted to right subtree
            if(balancedBST.size() % 2 == 1) mid++;
        }
        else
        {   // 2) inserted to left subtree
            if(balancedBST.size() % 2 == 0) mid--;
        }
       
    }
    
    double findMedian() {
        // O(1)
        int size = balancedBST.size();
        auto it = mid;
        if(size % 2 == 0) return (*it++ + *it) / 2.0;
        else return *it;
    }

    void print()
    {
        cout << "print : ";
        for(auto n : balancedBST)
        {
            cout << n << " ";
        }
        cout << endl;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */