#include <iostream>


#include<vector>
#include<deque>
#include<list>
#include<set> // set and multiset
#include<map> // map and multimap
#include<unordered_set>//unordered set/multiset
#include<unordered_map>//unordered map/multimap
#include<iterator>
#include<algorithm>
#include<numeric> // some numeric algorithm
#include<functional>
using namespace std;

void myVector(){

    /* Vector */
    std::vector<int> vec; // vec.size() == 0
    vec.push_back(6);
    vec.push_back(9);
    vec.push_back(1); // vec = {4,1,8};vec.size() == 3

    // Vector specific operations:
    std::cout << vec[2] << endl;        // 1 (no range check)
    std::cout << vec.at(2) << endl;  // 1 (throw range_error exception of out of range)

    /* 这里有三种方法遍历
     * 第一种方法是常用的
     * 第二种的话，比第一种更加快速，也是公认的方法。这里不光是vector，list也可以
     * 第三种是C++11新方法，不过为什么这里不给用？？？
     */

    for(int i; i < vec.size(); i++){std::cout << vec[i] << " ";}
    for(std::vector<int>::iterator itr = vec.begin();   itr!=vec.end();  ++itr)
        std::cout << *itr << " ";
     for(int it: vec){std::cout << it << " ";}

    // Vector is a dynamically allocated contiguous array in memory
    // 这意味着vector就跟一般的数组一样，地址是连续的。
    int* p = &vec[0];

    // common member function of all containers
    // vec:{6,9,1}
    if (vec.empty()){ std::cout << "Not possible.\n";}

    cout << vec.size(); //3

    std::vector<int> vec2(vec); // copy constructor, vec2:{6,9,1}
    vec.clear(); // remove all items in vec; vec.size() == 0
    vec2.swap(vec); // vec2 becomes empty, and vec has 3 items.

    // Note:No penalty of abstraction, very efficient.
}

void myDeque(){
    int arrayToDeq[]={2,3,4}; // 不能直接deq={...},会报错
    std::deque<int> deq(arrayToDeq,arrayToDeq+3);
    deq.push_front(1);
    deq.push_back(5);

    // Deque has similar interface with vector
    cout << deq[1]; // 2
    /* Properties:
    * 1. fast insert/remove at the beginning and the end;
    * 2. slow insert/remove in the middle: 0(n)
    * 3. slow search: 0 (n)
    */
}
void myList(){
    list<int> myList = {5,2,9};
    myList.push_back(6);
    myList.push_front(1);

    list<int >::iterator itr = find(myList.begin(), myList.end(), 2);//itr->2
    myList.insert(itr, 8); // O(1), faster than vector & deque
    itr++; // itr -> 9
    myList.erase(itr);

}
void myArray(){
    ;
}
int main() {
//    myVector();
//    myDeque();
//    myList();
    myArray();

    getchar();
    return 0;
}
