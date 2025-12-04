// Source: https://www.hackerrank.com/challenges/operator-overloading/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
public:
   vector<vector<int>> a;
   Matrix operator+(Matrix& m1) {
      Matrix m2; 
      for(int i = 0; i < m1.a.size(); i++) {
         vector<int> intermediate;
         for(int j = 0; j < m1.a[i].size(); j++) {
            intermediate.push_back(m1.a[i][j] + this->a[i][j]);
         }
         m2.a.push_back(intermediate);
      }

      return m2;
   }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
