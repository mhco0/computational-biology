#include<bits/stdc++.h>

template<class T>
void rotate_left(T& data,const size_t pivot){
	std::reverse(data.begin(),data.begin()+pivot);
	std::reverse(data.begin()+pivot,data.end());
	std::reverse(data.begin(),data.end());
}

template<class T>
void rotate_right(T& data, const size_t pivot){
	rotate_left(data,data.size()-pivot);
}

template<class T>
void rotate(T& data,const size_t pivot,bool right = false){
	if(right){
		rotate_right(data,pivot);
	}else{
		rotate_left(data,pivot);
	}
}
