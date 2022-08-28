#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;


int main(){
    vector<pair<int,int>> point;
    for(int i = 0; i < 4; ++i){
        int a, b;
        cin >> a >> b;
        point.emplace_back(make_pair(a, b));
    }
    double diBian = sqrt(abs(point[0].first - point[2].first) * abs(point[0].first - point[2].first) + 
                 abs(point[0].second - point[2].second) * abs(point[0].second - point[2].second));
    double area1 = abs((point[0].second - point[2].second) * point[1].first + 
                       (point[2].first - point[0].first) * point[1].second + 
                       point[0].first * point[2].second - point[0].second * point[2].first) / 
                       sqrt((point[0].second - point[2].second) * point[0].second-point[2].second) + 
                       (point[0].first - point[2].first) * (point[0].first-point[2].first) 
                       * diBian / 2;
    double area2 = abs((point[0].second-point[2].second) * point[3].first + (point[2].first-point[0].first) * point[3].second+point[0].first * point[2].second-point[0].second * point[2].first)/sqrt((point[0].second-point[2].second) * point[0].second-point[2].second) + (point[0].first-point[2].first) * (point[0].first-point[2].first) * diBian / 2;
    double ans = area1 + area2;
    cout << 2  << endl;

}


int i, j;
        int area = 0;
        for (i = 0; i < objects.size(); i++)
        {
            j = (i + 1) % objects.size();
            area += objects.get(i).getX() * objects.get(j).getY();
            area -= objects.get(i).getY() * objects.get(j).getX();
        }
        area /= 2;
        System.out.println(Math.abs(area));
    }
