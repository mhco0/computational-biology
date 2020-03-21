#include<bits/stdc++.h>
#include"../common/rotate.cpp"
using namespace std;

class bwt{
private:
	static int inverse(const vector<int>& v,const int &index,int callback){
		return (!callback) ? index : v[inverse(v,index,callback-1)];
	};
public:
	
	bwt(){	
	}

	~bwt(){
	}

	static pair<string,int> encode(const string_view& s){
		int size = s.size();
		vector<pair<string,int>> matrix(size);
		string encoded_string = "";
		int index = -1;		

		for(int i=0;i<size;i++){
			string cpy(s);

			rotate(cpy,i);		
	
			matrix[i] = {cpy,i};
		}

		sort(matrix.begin(),matrix.end());

		for(int i=0;i<size;i++){
			encoded_string.push_back(matrix[i].first[size-1]);
			if(matrix[i].second == 0){
				// the index for the string without rotations
				index = i;
			}
		}
		
		return {encoded_string,index};
	}

	static string decode(const pair<string,int> &encoded){
		vector<pair<char,int>> sorted_string(encoded.first.size());
		vector<int> translate(encoded.first.size());
		string decoded_string(encoded.first.size(),' ');
		int index = encoded.second;

		for(int i=0;i<sorted_string.size();i++){
			sorted_string[i] = {encoded.first[i],i};
		}

		sort(sorted_string.begin(),sorted_string.end());

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
 	ios::sync_with_stdio(0);
	cin.tie(0);
	
	auto a = bwt::encode("teste");

	cout <<"("<< a.first << "," << a.second << ")" << endl;
	cout << "translated: " << endl << bwt::decode(a) << endl;

	return 0;
}
