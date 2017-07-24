#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define INT_SIZE 32
using namespace std;
typedef long long ll;
const int siz = 1e6 + 1;
struct node {
	int value;     // Only used in leaf nodes
	node *arr[2];
};
map <int, node*> roots;
node *newNode() {
	node *temp = new node;
	temp -> value = 0;
	temp -> arr[0] = temp -> arr[1] = NULL;
	return temp;
}
void insertr(int n, int val) {
	node *temp = newNode();
	roots[n] = temp;
	for(int i = INT_SIZE - 1; i >= 0; i--) {
		bool a = val & (1 << i);
		if(temp -> arr[a] == NULL)
			temp -> arr[a] = newNode();
		else if(temp -> arr[a] != NULL) {
			node *temp1 = temp -> arr[a];
			node *new1 = newNode();
			new1 = temp1;
			temp -> arr[a] = new1;
		}
		temp = temp -> arr[a];
	}
	temp -> value = val;
}
void insert(int n,int p, int val) {
	node *root = roots[p];
	node *temp = newNode();
	temp -> value = root -> value;
	temp -> arr[0] = root -> arr[0];
	temp -> arr[1] = root -> arr[1];
	roots[n] = temp;
	for(int i = INT_SIZE - 1; i >= 0; i--) {
		bool a = val & (1 << i);
		if(temp -> arr[a] == NULL) {
			temp -> arr[a] = newNode();
			//node *temp1 = temp;
		}
		else if(temp -> arr[a] != NULL) {
			node *temp1 = temp -> arr[a];
			node *new1 = newNode();
			new1 -> value = temp1 -> value;
			new1 -> arr[0] = temp1 -> arr[0];
			new1 -> arr[1] = temp1 -> arr[1];
			temp -> arr[a] = new1;
		}
		temp = temp -> arr[a];
	}
	temp -> value = val;
}
int query1(int v, int k) {
	node *temp = roots[v];
	for(int i = INT_SIZE - 1; i >= 0; i--) {
		bool a = k & (1 << i);
		if(temp -> arr[1 - a] != NULL)
			temp = temp -> arr[1 - a];
		else if(temp -> arr[a] != NULL)
			temp = temp -> arr[a];
	}
	return k ^ (temp -> value); 
}
int query2(int v, int k) {
	node *temp = roots[v];
	for(int i = INT_SIZE - 1; i >= 0; i--) {
		bool a = k & (1 << i);
		if(temp -> arr[a] != NULL)
			temp = temp -> arr[a];
		else if(temp -> arr[1 - a] != NULL)
			temp = temp -> arr[1 - a];
	}
	return k ^ (temp -> value);
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int r, key;
	scanf("%d%d", &r, &key);
	insertr(r, key);
	int u, v, k;
	for(int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &u, &v, &k);
		insert(u, v, k);
	}
	int last_ans = 0;
	while(q--) {
		int t;
		scanf("%d", &t);
		t ^= last_ans;
		//cout <<"T: " << t << endl;
		if(t == 0) {
			scanf("%d%d%d", &v, &u, &k);
			u ^= last_ans;
			v ^= last_ans;
			k ^= last_ans;
			insert(u, v, k);
		}
		else {
			scanf("%d%d", &v, &k);
			v ^= last_ans;
			k ^= last_ans;
			int min_ans, max_ans;
			min_ans = query2(v, k);
			max_ans = query1(v, k);
			printf("%d %d\n", min_ans, max_ans);
			last_ans = min_ans ^ max_ans;
		}
	}
	return 0;
}