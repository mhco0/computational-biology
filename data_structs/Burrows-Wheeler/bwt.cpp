#pragma once
#include<vector>
#include<string>
#include<utility>
#include<iostream>
#include"../common/rotate.cpp"

class bwt{
private:
	static int inverse(const std::vector<int>& v,const int &index,int callback){
		return (!callback) ? index : v[inverse(v,index,callback-1)];
	};
public:
	
	bwt(){	
	}

	~bwt(){
	}

	static std::pair<std::string,int> encode(const std::string_view& s){
		int size = s.size();
		std::vector<std::pair<std::string,int>> matrix(size);
		std::string encoded_string = "";
		int index = -1;		

		for(int i=0;i<size;i++){
				std::string cpy(s);

			rotate(cpy,i);		
	
			matrix[i] = {cpy,i};
		}

		std::sort(matrix.begin(),matrix.end());

		for(int i=0;i<size;i++){
			encoded_string.push_back(matrix[i].first[size-1]);
			if(matrix[i].second == 0){
				// the index for the string without rotations
				index = i;
			}
		}
		
		return {encoded_string,index};
	}

	static std::string decode(const std::pair<std::string,int> &encoded){
		std::vector<std::pair<char,int>> sorted_string(encoded.first.size());
		std::vector<int> translate(encoded.first.size());
		std::string decoded_string(encoded.first.size(),' ');
		int index = encoded.second;

		for(int i=0;i<sorted_string.size();i++){
			sorted_string[i] = {encoded.first[i],i};
		}

		std::sort(sorted_string.begin(),sorted_string.end());

		for(int i=0;i<sorted_string.size();i++){
			translate[sorted_string[i].second] = i;
		}

		for(int i=0;i<decoded_string.size();i++){
			decoded_string[decoded_string.size()-1-i] = encoded.first[inverse(translate,index,i)];
		}

		return decoded_string;
	}
};


int main(void){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	auto a = bwt::encode("teste");

	std::cout <<"("<< a.first << "," << a.second << ")" << std::endl;
	std::cout << "translated: " << std::endl << bwt::decode(a) << std::endl;

	return 0;
}
