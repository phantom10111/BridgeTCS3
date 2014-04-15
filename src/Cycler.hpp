#ifndef CYCLER_HPP
#define CYCLER_HPP

#include <array>

template<class T, int N>
class Cycler{
private:
	int i;
	std::array<T, N> data;
public:
	Cycler(std::array<T, N>);
	T& next();
	void rotateTo(int);
	int getIndex();
	T& getAt(int);
};

template<class T, int N>
Cycler<T, N>::Cycler(std::array<T, N> data) : data(data)
{
	i = 0;
}

template<class T, int N>
T& Cycler<T, N>::next()
{
	T& res = data[i];
	++i;
	if(i == data.size())
		i = 0;
	return res;
}

template<class T, int N>
T& Cycler<T, N>::getAt(int i)
{
	return data[i];
}

template<class T, int N>
void Cycler<T, N>::rotateTo(int j){
	i = j;
}

template<class T, int N>
int Cycler<T, N>::getIndex(){
	return i;
}

#endif
