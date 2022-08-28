#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        for(int j = 0; j < m; ++j){
            mat[i][j] = str[j];
        }
    }
    for(int i = 0; i < q; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 - 1; j < x2; ++j){
            for(int k = y1 - 1;  k < y2; ++k){
                if(mat[j][k] >= 'a' && mat[j][k] <= 'z'){
                    mat[j][k] = (char)mat[j][k] - 32;
                }else{
                    mat[j][k] = (char)mat[j][k] + 32;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}