#include<iostream>
using namespace std;
template <typename T>
class List{
public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std::count) const;
private:
    ListItem<T>* _end;
    ListItem<T>* _front;
    long _size;
};
template <typename T>
class ListItem{
public:
    T value() const {return _value};
    ListItem* next const {return _next;}
private:
    T _value;
    ListItem* _next;
};

template<class Item>
struct ListIter{
    Item* ptr;
    ListItem(Item* p = 0) : ptr(p) {}
    //不必实现拷贝构造 因为编译器提供的缺省行为已经足够  operator= 同理
    Item& operator*() const {return *ptr;}
    Item* operator->() const {return ptr;}
    ListIter& operator++() {ptr = ptr->next(); return *this;}
    ListIter operator++() {ListIter tep = *this; ++*this; return tep;}
    bool operator==(const ListIter& i) const {return ptr == i.ptr;}
    bool operator!=(const ListIter& i) const {return ptr != i.ptr;}
};
template <typename T>
bool operator!=(const ListItem<T>&, T n) {return item.value() != n;}

//将list和find() 藉由ListIter粘合起来
int main(){
    List<int> mylist;
    for(int i = 0; i < 5; ++i){
        mylist.insert_front(i);
        mylist.insert_end(i + 2);
    }
    mylist.display();
    ListIter<ListItem<int>> begin(mylist.front());
    ListIter<ListItem<int>> end;
    ListIter<ListItem<int>> iter;

    iter = find(begin, end, 3);
    if(iter == end)
        cout << "not found" << endl;
    else 
        cout << "found." << iter->value() << endl; 
    return 0;
}