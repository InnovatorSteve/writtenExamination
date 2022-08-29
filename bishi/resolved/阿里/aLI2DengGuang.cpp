#include<iostream>
#include<vector>
using namespace std;

//int* 动态数组  + 前缀和
int prefixSumCalculateScore(int** matrix, int m, int n){
    //建立行前缀和
    vector<vector<int>> prefixSumRow(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for( int j = 0; j < n; ++j){
            if(j == 0) prefixSumRow[i][j] = matrix[i][j];
            else prefixSumRow[i][j] = prefixSumRow[i][j - 1] + matrix[i][j];
        }
    }
    // 建立列前缀和
    vector<vector<int>> prefixSumCol(m, vector<int>(n));
    for(int j = 0; j < n; ++j){
        for( int i = 0; i < m; ++i){
            if(i == 0) prefixSumCol[i][j] = matrix[i][j];
            else prefixSumCol[i][j] = prefixSumCol[i - 1][j] + matrix[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                if(prefixSumRow[i][j] > 0) ++cnt;
                if(prefixSumRow[i][n - 1] - prefixSumRow[i][j] > 0) ++cnt;
                if(prefixSumCol[i][j] > 0) ++cnt;
                if(prefixSumCol[m - 1][j] - prefixSumCol[i][j] > 0) ++cnt;
            }
        }
    }
    return cnt;
}
int main(){
    int m, n;
    cin >> m >> n;
    //c 建立动态二位数组 申请 释放
    int **matrix = (int **)calloc(m, sizeof(int*));
    for(int i = 0; i < m; ++i)
        matrix[i] = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    cout << prefixSumCalculateScore(matrix, m, n);
    //释放 
    for(int i = 0; i < m; ++i)
        free(matrix[i]);
    free(matrix);
    return 0;
}
//vector + 遍历
// int calculateScore(vector<vector<int>>& matrix, int m, int n){
//     int cnt = 0;
//     for(int i = 0; i < m; ++i){
//         for(int j = 0; j < n; ++j){
//             if(!matrix[i][j]){
//                 int num = 0;
//                 while(i - (++num) >= 0){
//                     if(matrix[i - num][j]){
//                         ++cnt; break;
//                     }
//                 }
//                 num = 0;
//                 while(i + (++num) < m){
//                     if(matrix[i + num][j]){
//                         ++cnt; break;
//                     }
//                 }
//                 num = 0;
//                 while(j - (++num) >= 0){
//                     if(matrix[i][j - num]){
//                         ++cnt; break;
//                     }
//                 }
//                 num = 0;
//                 while(j + (++num) < n){
//                     if(matrix[i][j + num]){
//                         ++cnt; break;
//                     }
//                 }
//             }
//         }
//     }
//     return cnt;

// }
// int main(){
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> matrix(m, vector<int>(n));
//     for(int i = 0; i < m; ++i){
//         for(int j = 0; j < n; ++j){
//             int num;
//             cin >> num;
//             matrix[i][j] = num;
//         }
//     }
//     cout << calculateScore(matrix, m, n) << endl;
//     return 0;
// }