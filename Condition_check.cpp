#include<bits/stdc++.h>
using namespace std;

const int MAX = 9;

struct BanCo {
	int n;
	int a[MAX][MAX];
	
	int X_thuan[MAX][MAX];
	int X_nguoc[MAX][MAX];
	int X_hang[MAX][MAX];
	int X_cot[MAX][MAX];
	
	int O_thuan[MAX][MAX];
	int O_nguoc[MAX][MAX];
	int O_hang[MAX][MAX];
	int O_cot[MAX][MAX];
	
	int maxX;
	int maxO;
}banco;

void khoitao(){
	
	memset(banco.a, -1, sizeof(banco.a));
	
}

void in(int mat[][MAX], int n){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void setHang(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 2;

	for(int i = 0; i < n; i ++){
		int cnt = 0;
		for(int j = 0; j < n; j ++){
			if(mat[i][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][j] = cnt;
			Max = max(Max, cnt);
		}
	} 
}

void setCot(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 2;

	for(int j = 0; j < n; j ++){
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(mat[i][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][j] = cnt;
			Max = max(Max, cnt);
		}
	}
}

void setThuan(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 2;
	

	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = 0; j < n - i; j ++){
			if(mat[k][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[k][j] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i < n - j; i++){
			if(mat[i][k] == value)
				cnt++;
			else 
				cnt = 0;
			res[i][k] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
}

void setNguoc(int mat[][MAX], int res[][MAX], int n, char C, int &Max){
	int value = (C == 'X') ? 1 : 2;
	
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = n - 1; j >= i; j --){
			if(mat[k][j] == value)
				cnt++;
			else 
				cnt = 0;
			res[k][j] = cnt;
			Max = max(Max, cnt);
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i <= n - j; i++){
			if(mat[i][k] == value)
				cnt ++;
			else
				cnt = 0;
			res[i][k] = cnt;
			k--;
		}
	}
}

int main(){
	ifstream file; file.open("Case.txt");
	
	file >> banco.n;
	
	khoitao();  
	
	for(int i = 0; i < banco.n; i ++)
		for(int j = 0; j < banco.n; j ++){
			char ch;
			file >> ch;
			if(ch == '-')	banco.a[i][j] = 0;
			else if(ch == 'X') banco.a[i][j] = 1;
			else if(ch == 'O') banco.a[i][j] = 2;
		}
			
	file.close();
			
	cout << "Ban co:\n";
	in(banco.a, banco.n);
	
	cout << "--------------------\n";
	
	setHang(banco.a, banco.X_hang, banco.n, 'X', banco.maxX);
	setHang(banco.a, banco.O_hang, banco.n, 'O', banco.maxO);
	cout << "Hang X:\n";
	in(banco.X_hang, banco.n);
	cout << "Hang O:\n";
	in(banco.O_hang, banco.n);
	
	cout << "--------------------\n";
	
	setCot(banco.a, banco.X_cot, banco.n, 'X', banco.maxX);
	setCot(banco.a, banco.O_cot, banco.n, 'O', banco.maxO);
	cout << "Cot X:\n";
	in(banco.X_cot, banco.n);
	cout << "Cot O:\n";
	in(banco.O_cot, banco.n);
	
	cout << "---------------------\n";
	
	setThuan(banco.a, banco.X_thuan, banco.n, 'X', banco.maxX);
	setThuan(banco.a, banco.O_thuan, banco.n, 'O', banco.maxO);
	cout << "Thuan X:\n";
	in(banco.X_thuan, banco.n);
	cout << "Thuan O:\n";
	in(banco.O_thuan, banco.n);
	
	cout << "---------------------\n";
	
	setNguoc(banco.a, banco.X_nguoc, banco.n, 'X', banco.maxX);
	setNguoc(banco.a, banco.O_nguoc, banco.n, 'O', banco.maxO);
	cout << "Nguoc X:\n";
	in(banco.X_nguoc, banco.n);
	cout << "Nguoc O:\n";
	in(banco.O_nguoc, banco.n);
	
	cout << "---------------------\n";
	
	cout << "X: " << banco.maxX << " O: " << banco.maxO;
}
