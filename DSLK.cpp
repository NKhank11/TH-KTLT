#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node *makeNode(int x){
	node *newNode = new node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void display(node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int SZ(node *head){
	int ans = 0;
	while(head != NULL){
		ans++;
		head = head->next;
	}
	return ans;
}
void themDau(node *&head, int x){
	node *newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}
void themCuoi(node *&head, int x){
	node *newNode = makeNode(x);
	node *temp = head;
	if(temp == NULL){
		head = newNode;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
void themGiua(node *&head, int x, int k){
	node *newNode = makeNode(x);
	if(k < 1 || k > SZ(head) + 1){
		return;
	}
	if(k == 1){
		themDau(head, x);
		return;
	}
	node *temp = head;
	for(int i = 1; i <= k - 2; i ++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
void xoaDau(node *&head){
	if(head == NULL) return;
	node *nodeXoa = head;
	head = head->next;
	delete nodeXoa;
}
void xoaCuoi(node *&head){
	if(head == NULL) return;
	node *temp = head;
	if(temp->next == NULL){
		head = NULL;
		delete temp;
		return;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	node *nodeXoa = temp->next;
	temp->next = NULL;
	delete nodeXoa;
}
void xoaGiua(node *&head, int k){
	if(k < 1 || k > SZ(head) + 1) return;
	node *temp = head;
	if(k == 1){
		xoaDau(head);
		return;
	}
	for(int i = 1; i <= k - 2; i++){
		temp = temp->next;
	}
	node *knode = temp->next;
	temp->next = knode->next;
	delete knode;
}
int main(){
	node *head = NULL;
	while(true){
		cout << "-----------------------\n";
		cout << "1. Them dau\n";
		cout << "2. Them cuoi\n";
		cout << "3. Them giua\n";
		cout << "4. Xoa dau\n";
		cout << "5. Xoa cuoi\n";
		cout << "6. Xoa giua\n";
		cout << "7. Duyet\n";
		cout << "0. Thoat\n";
		cout << "-----------------------\n";
		int a;
		cout << "Nhap lua chon: ";
		cin >> a;
		if(a == 1){
			cout << "Nhap gia tri can them: ";
			int x;
			cin >> x;
			themDau(head, x);
		}
		else if(a == 2){
			cout << "Nhap gia tri can them: ";
			int x;
			cin >> x;
			themCuoi(head, x);
		}
		else if(a == 3){
			int x, k;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			cout << "Nhap vi tri can them: ";
			cin >> k;
			themGiua(head, x, k);
		}
		else if(a == 4){
			xoaDau(head);
		}
		else if(a == 5){
			xoaCuoi(head);
		}
		else if(a == 6){
			int k;
			cout << "Nhap vi tri can xoa: ";
			cin >> k;
			xoaGiua(head, k);
		}
		else if(a == 7){
			display(head);
		}
		else if(a == 0) break;
	}
	return 0;
}