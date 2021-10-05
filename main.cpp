#include <iostream>
#include "threadpool.hpp"

#define MAX_THREADS 32

ThreadPool __TP(MAX_THREADS);

using namespace std;
int main () {
    auto square = [](const uint64_t x) {
        return x*x;
    };

    const uint64_t num_nodes = 32;
    vector<future <uint64_t>> futures;

    //二叉树的前序遍历
    typedef function<void(uint64_t) > traverse_t;
    //这是一个数列化的二叉树
    traverse_t traverse = [&](uint64_t node) {
        if(node < num_nodes) {
            auto future = __TP.enqueue(square, node);
            futures.emplace_back(move(future));

            traverse(node * 2 + 1);//左孩子
            traverse(node * 2 + 2);//又孩子
        }
    };

    traverse(0);

    for(auto &future : futures){
        cout<<future.get() <<endl;
    }
    
}