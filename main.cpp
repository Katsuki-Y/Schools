//
//  main.cpp
//  Xcode_test
//
//  Created by Y Katsuki on 2021/06/07.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <fstream>
#include <random>
using namespace std;

int SIZE = 10;

double f(double *n) {
    double a = 0;
    for(int i = 0; i < SIZE ;i++){
        a += n[i] * n[i];
    }
    a = pow(a, 0.5);
    if(a < 1){
        return 1;
    }else{
        return 0;
    }
}
/*double Tripzoid_Method(double a, double b,int n) {
    double t = (b - a) / n;
    double S = 0;
    for (double i = a; i < b; i += t) {
        S += (t / 6.0) * (func(a) + func(a + t) + 4 * func(a + (t / 2.0)));
    }
    return S;
}
double Simpson_Method(double a, double b, int n) {
    double t = (b - a) / n;
    double S = 0;
    double x1 = 0;
    double x2 = 0;
    double x3 = 0;
    
    for(double i = 0; i <= n-2; i+=2){
        x1 = a + i * t;
        x2 = x1 + t;
        x3 = x1 + 2.0 * t;
        S += t/3.0 * (func(x1) + 4.0*func(x2) + func(x3));
    }
    return S;
}
 */


int main() {
    double num = pow(10, 8);
    double n[SIZE];
    double a = 0;
    double b = 1;
    double sum = 0;
    double genmitu = 0;
    srand((unsigned int)time(0));
    for(double i = 0; i < num; i++){
        for(int i = 0; i < SIZE; i++){
            n[i] = (double)rand() / RAND_MAX;
        }
        sum += f(n);
    }
    cout << sum << endl;;
    sum = sum / num;
    cout << sum << endl;
    //genmitu = 8.0 * M_PI / 6.0 / 4.0 * 2;
    //genmitu = 2 * 24 * pow(4 * M_PI, 4) / 362880 / pow(2, 9);
    genmitu = pow(M_PI, 5) / 120　/ pow(2, 10);
    cout << genmitu << endl;
    cout << fabs(sum - genmitu) << endl;
    
    
    /*double n = 0;
    double a = -1;
    double b = 1;
    double ans[2][12];
    
    
    
    for(int j = 0;j < 12;j++){
        n = pow(2, j + 1);
        ans[0][j] = Simpson_Method(a, b, n);
        ans[1][j] = fabs(M_PI - ans[0][j]);
    }
    cout << "atai" << endl;
    for(int i = 0; i < 12; i++){
        printf("%l15.15f \n", ans[0][i]);
    }
    cout << "gosa" << endl;
    for(int i = 0; i < 12; i++){
        printf("%l15.15f \n", ans[1][i]);
    }*/
   

    
    /*double space = 0.005;
    double max_x = 2;
    double max_y = 1;
    double size_x = max_x/space;
    double size_y = max_y/space;
    double ave = 0;
    double S = 0;
    double S_1 = 0;
    double sa = 0;
    
    vector <vector<double>> S_tempe(size_y-1, vector<double>(size_x-1));
    vector <vector<double>> tempe(size_y, vector<double>(size_x));
    vector <vector<double>> copy_tempe(size_y, vector<double>(size_x));
    
    for(double i = 0;i<size_x;i++){
        tempe[0][i] = 1;
        tempe[size_y-1][i] = -1;
        copy_tempe[0][i] = 1;
        copy_tempe[size_y-1][i] = -1;

    }
    for(double i = 1;i<size_y;i++){
        tempe[i][0] = -1;
        tempe[i][size_x-1] = -1;
        copy_tempe[i][0] = -1;
        copy_tempe[i][size_x-1] = -1;
    }
    
    for(double j = 0;j<size_y;j++){
        for(double i = 0;i<size_x;i++){
            cout << tempe[j][i];
        }
        cout << endl;
    }//
    //ここからガウス
    for(int count = 0;count < MAX;count++){
        for(double j = 1; j < size_y-1;j++){
            for(double i = 1; i < size_x-1;i++){
                tempe[j][i] = (tempe[j][i-1] + tempe[j+1][i] + tempe[j-1][i] +tempe[j][i+1])/4.0;
                ave += tempe[j][i];
            }
        }
        ave = ave / ((size_y-1) * (size_x-1));
        for(double j = 1; j < size_y-1;j++){
            for(double i = 1; i < size_x-1;i++){
                S += (tempe[j][i] - ave) * (tempe[j][i] - ave);
            }
        }
        S = S / ((size_y-1) * (size_x-1));
        S = pow(S, 1.0/2);
        sa= S - S_1;
        S_1 = S;
        if(sa < 10e-12){
            break;
        }
    }
    for(double j = 0;j<size_y;j++){
        for(double i = 0;i<size_x;i++){
            cout << tempe[j][i] << " ";
        }
        cout << endl;
    }
    ofstream ofs("output.csv");
    for(double j = 0;j<size_y;j++){
        for(double i = 0;i<size_x;i++){
            ofs << tempe[j][i] << ", ";
        }
        ofs << endl;
    }*/
    
    
    //ここからヤコビ
    /*for(int count = 0;count < MAX;count++){
        for(double j = 1; j < size_y-1;j++){
            for(double i = 1; i < size_x-1;i++){
                copy_tempe[j][i] = (tempe[j][i-1] + tempe[j+1][i] + tempe[j-1][i] +tempe[j][i+1])/4.0;
                ave += tempe[j][i];
            }
        }
        tempe = copy_tempe;
        ave = ave / ((size_y-1) * (size_x-1));
        for(double j = 1; j < size_y-1;j++){
            for(double i = 1; i < size_x-1;i++){
                S += (tempe[j][i] - ave) * (tempe[j][i] - ave);
            }
        }
        S = S / ((size_y-1) * (size_x-1));
        S = pow(S, 1.0/2);
        sa= S - S_1;
        S_1 = S;
        if(sa < 10e-12){
            break;
        }
    }
     
     
    
    for(double j = 0;j<size_y;j++){
        cout << " " << tempe[j][1.0 / space] << endl;
    }
    cout << endl;
    for(double j = 0;j<size_y;j++){
        cout << " " << tempe[j][0.4 / space] << endl;;
    }
    cout << endl;
    for(double j = 0;j<size_y;j++){
        cout << " " << tempe[j][1.6 / space] << endl;;
    }
    cout << endl;
    for(double i = 0;i < max_y;i += space){
        cout << i << endl;
    }*/
    
    
    return 0;
}
