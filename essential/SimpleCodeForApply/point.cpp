#include<iostream>
using namespace std;
//引用计数类，用于存储指向同一对象的指针个数
template<typename E>
class Counter{
private:
    E* ptr;  //对象指针
    int cnt;  //引用计数
    
    template<typename T>
    friend class SmartPtr;

    Counter(E* p){
        ptr = p;
        cnt = 1;
    }
    ~Counter(){
        delete ptr;
    }
};
//智能指针类
template<typename T>
class SmartPtr{
private:
    Counter<T> *ptr_cnt;
public:
    SmartPtr(T* p){
        ptr_cnt = new Counter<T>(p);
    }
    SmartPtr(const SmartPtr& other){
        ptr_cnt = other.ptr_cnt;
        ++ptr_cnt->cnt;
    }
    //复制运算符重载
    SmartPtr& operator=(const SmartPtr& other){
        ptr_cnt = other.ptr_cnt;
        other.ptr_cnt->cnt++;
        ptr_cnt->cnt--;
        if(ptr_cnt->cnt == 0)
            delete ptr_cnt;
        return *this;
    }
    //解引用运算符重载函数
    T& operator*(){
        return *(ptr_cnt->cnt);
    }
    ~SmartPtr(){
        ptr_cnt->cnt--;
        if(ptr_cnt->cnt == 0) 
            delete ptr_cnt;
        else
            cout << "还有" << ptr_cnt->cnt << "个对象指向基础对象" << endl;
    }
};
void test(){
    int *p = new int(42);
    {
        SmartPtr<int> sptr1(p);
        {
            SmartPtr<int> sptr2(sptr1);
            {
                SmartPtr<int> sptr3(sptr1);
            }
        }
    }
    cout << *p << endl;
}
int main(){
    test();
    return 0;
}


// template <typename T>
// class SmartPointer {
// public:
// 	//构造函数
// 	SmartPointer(T* p=0): _ptr(p), _reference_count(new size_t){
// 		if(p)
// 			*_reference_count = 1; 
// 		else
// 			*_reference_count = 0; 
// 	}
// 	//拷贝构造函数
// 	SmartPointer(const SmartPointer& src) {
// 		if(this!=&src) {
// 			_ptr = src._ptr;
// 			_reference_count = src._reference_count;
// 			(*_reference_count)++;
// 		}
// 	}
// 	//重载赋值操作符
// 	SmartPointer& operator=(const SmartPointer& src) {
// 		if(_ptr==src._ptr) {
// 			return *this;
// 		}
// 		releaseCount();
// 		_ptr = src._ptr;
// 		_reference_count = src._reference_count;
// 		(*_reference_count)++;
// 		return *this;
// 	}
 
// 	//重载操作符
// 	T& operator*() {
// 		if(ptr) {
// 			return *_ptr;
// 		}
// 		//throw exception
// 	}
// 	//重载操作符
// 	T* operator->() {
// 		if(ptr) {
// 			return _ptr;
// 		}
// 		//throw exception
// 	}
// 	//析构函数
// 	~SmartPointer() {
// 		if (--(*_reference_count) == 0) {
//             delete _ptr;
//             delete _reference_count;
//         }
// 	}
// private:
// 	T *_ptr;
//         size_t *_reference_count;
//         void releaseCount() {
// 		if(_ptr) {
// 			(*_reference_count)--;
//     			if((*_reference_count)==0) {
//     				delete _ptr;
//     				delete _reference_count;
//     			}
// 		}
//     	}
// };
 
// int main() 
// {
//     SmartPointer<char> cp1(new char('a'));
//     SmartPointer<char> cp2(cp1);
//     SmartPointer<char> cp3;
//     cp3 = cp2;
//     cp3 = cp1;
//     cp3 = cp3;
//     SmartPointer<char> cp4(new char('b'));
//     cp3 = cp4;
// }