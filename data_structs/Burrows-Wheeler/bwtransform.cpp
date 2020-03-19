#include<bits/stdc++.h>
#include"../common/rotate.cpp"
using namespace std;

class bw_transform{
private:
	string compressed;
public:
	
	bw_transform(const string_view& s){
		compressed = this->encode(s);	
	}


	static string encode(const string_view& s){
		int size = s.size();
		vector<string> matrix(size);
		string encoded_string = "";		

		for(int i=0;i<size;i++){
			string cpy(s);

			rotate(cpy,i);
			
			matrix[i] = cpy;
		}

		sort(matrix.begin(),matrix.end());

		for(int i=0;i<size;i++){
			encoded_string.push_back(matrix[i][size-1]);
		}
		
		return encoded_string;
	}

	
};


int main(void){
 	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a = bw_transform::encode("teste");

	cout << a << endl;

	return 0;
}
