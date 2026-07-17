#include<iostream>
#include<cmath>
using namespace std;

struct Stadium{
    double x, y, r;
};

Stadium s[3];

double var(double x, double y) {
    double ratio[3];
    double sum =0;
    for (int i = 0; i < 3; ++i){
        ratio[i] = sqrt((x - s[i].x) * (x - s[i].x) + (y - s[i].y) * (y - s[i].y)) / s[i].r;
        sum += ratio[i];
    }
    double mean = sum / 3.0;
    double var = 0;
    for (int i = 0; i < 3; ++i) {
        double deviation = ratio[i] - mean;
        var += deviation * deviation;
    }
    return var/3.0;
}

int main(){

    double totalx = 0, totaly = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> s[i].x >> s[i].y >> s[i].r;
        totalx += s[i].x;
        totaly += s[i].y;
    }

    double cur_x = totalx / 3.0;
    double cur_y = totaly / 3.0;
    double cur_var = var(cur_x, cur_y);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    double step = 1.0;

    while(step > 1e-10){
        bool improved = false;
        
        for (int i = 0; i < 4; ++i) {
            double next_x = cur_x + dx[i] * step;
            double next_y = cur_y + dy[i] * step;
            double next_var = var(next_x, next_y);

            if (next_var < cur_var) {
                cur_var = next_var;
                cur_x = next_x;
                cur_y = next_y;
                improved = true;
            }
        }

        if (!improved) {
            step /= 2.0;
        }
    }

    if (cur_var < 1e-6){
        printf("%.5f %.5f\n", cur_x, cur_y);
    }

    return 0;
}