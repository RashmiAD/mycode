// Using Doubly Linked List and Map with key as int and value as iterator to doubly linked list
class FirstUnique {
public:
    list<int> dl;
    unordered_map<int, list<int>::iterator> mp;
    
    FirstUnique(vector<int>& nums) {
        for(int &x : nums)
            add(x);
    }
    
    int showFirstUnique() {
        if(!dl.empty())
            return dl.front();
        else
            return -1;
    }
    
    void add(int value) {
        auto itr = mp.find(value);
        if(itr == mp.end()) {
            dl.push_back(value);
            list<int>::iterator dl_it = dl.end();
            dl_it--;
            mp[value] = dl_it;
        }
        else {
            auto l_it = mp[value];
            if(l_it != dl.end()) {
                mp[value] = dl.end();
                dl.erase(l_it);
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
