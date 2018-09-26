//segment tree test
//first input the length of the sequence
//input the region left & right and output the min

#include<bits/stdc++.h>

using namespace std;

void build(int input[], int tree[], int left, int right, int pos){

	if(left == right){// if find the lowest child return the value

		tree[pos] = input[left];
		return ;
	}
	int mid = (left + right) / 2;

	build(input, tree, left, mid, 2*pos);//build left child
	build(input, tree, mid+1, right, 2*pos + 1);//build right child

	tree[pos] = min(tree[2*pos], tree[2*pos+1]);
}

int range_min(int tree[], int r_left, int r_right, int left, int right, int pos){

	if(r_left <= left && r_right >= right)// if total overlap
		return tree[pos];
	if(r_left > right || r_right < left)// none overlap
		return 1000000;
	else{// search the child

		int mid = (left + right) / 2;
		return min(range_min(tree, r_left, r_right, left, mid, 2*pos), range_min(tree, r_left, r_right, mid+1, right, 2*pos+1)); 
	}
}

void print(int tree[]){

	for(int i = 1 ; i <= 7 ; i++){

		printf("%d ", tree[i]);
	}
}

int main(void){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	int len;

	scanf("%d", &len);

	int input[len+1];

	for(int i = 1 ; i <= len ; i++)
		scanf("%d", &input[i]);

	int tree[4*len];
	memset(tree, 0, sizeof(tree));

	build(input, tree, 1, len, 1);
	print(tree);
	putchar('\n');

	int left, right;

	while(~scanf("%d %d", &left, &right))
		printf("min: %d\n", range_min(tree, left, right, 1, len, 1));

	return 0;
}