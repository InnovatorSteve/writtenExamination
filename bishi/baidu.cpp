#include<iostream>
#include<vector>
using namespace std;

void enlargeK(vector<vector<int>>& source, int k){
    int n = source.size();
    vector<vector<int>> dst(n * k, vector<int>(n * k));
    for(int i = 0; i < n * k; ++i){
        for(int j = 0; j < n * k; ++j){
            dst[i][j] = source[i / k][j / k],
            cout << dst[i][j] << " ";
            }
        cout << endl;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> source(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> source[i][j];
    }
    enlargeK(source, k);
    return 0;
}