#include <iostream>
 
using namespace std;

 
int main(){
    int test, student;
    int total, count;
    double result;
    cin >> test;
 
 
    for(int i = 0; i < test; i++){
        cin >> student;
        int *score;
        total = 0;
        count = 0;
        score = new int[student];
        
        for(int j = 0; j < student; j++){
            cin >> score[j];
            total += score[j];
        }
        
        for(int k = 0; k < student; k++){
            if(score[k] > (total/student)) count++;
        }
        result = (double)count/student;
        cout << fixed;
        cout.precision(3);
        cout << result*100 << "%" << endl;
        delete []score;
    }
}
