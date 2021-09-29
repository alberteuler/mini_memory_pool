#pragma once
class RadixTree__
{
public:
	bool isEnd;
	RadixTree__* zero;
	RadixTree__* one;
	void insert(int num);
	void delect(int num);
	RadixTree__* search(int num);
	RadixTree__():isEnd(false), zero(nullptr), one(nullptr){}
	~RadixTree__() = default;
private:
};

