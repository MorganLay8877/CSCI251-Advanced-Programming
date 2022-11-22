#ifndef MYTEMP_H
#define MYTEMP_H

using namespace std;

template<typename T>
bool equals (T &e1, T &e2)
{
	return (e1==e2);
         
}

template <typename T>
double scalar_difference(T P1,T P2)
{
    return (P1-P2);
}
template<typename T>
bool ascendingScalar ( const T &a, const T &b)
{
	return  (a.getScalarValue() < b.getScalarValue());
       
}

template<typename T>
bool descendingScalar ( const T &a, const T &b)
{
	return  (a.getScalarValue() < b.getScalarValue());
       
}

template<typename T>
bool ascending ( const T &a, const T &b)
{
	return  (a < b);
       
}

template <class T>
bool descending ( const T &a, const T &b)
{
	return  (a > b);      
}
 

#endif