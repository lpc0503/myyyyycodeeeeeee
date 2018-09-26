//BKDRHASH
//test
#include<bits/stdc++.h>

using namespace std;

unsigned int BKDRHash(string str){

	unsigned int seed = 131;
	unsigned int hash = 0;
	int len = str.size();

	for(int i = 0 ; i < len ; i++)
		hash = hash * seed + str[i];

	return(hash & 0x7fffffff) % 10000;
}

int main(){

	string str;
	cin >> str;

	cout << BKDRHash(str);

	return 0;
}