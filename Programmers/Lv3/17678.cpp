// 2018 KAKAO BLIND RECRUIT
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

string func(int x){
    if(x>= 10){
        return to_string(x);
    }else{
        return "0" + to_string(x);
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    deque<int> people;
    
    for(auto t : timetable){
        stringstream ss(t);
        string hh,mm;
        int time = 0;
        getline(ss, hh, ':');
        getline(ss, mm);
        int ht,mt;
        ht = stoi(hh);
        mt = stoi(mm);
        time = 60*ht + mt;
        people.push_back(time);
        
    }
    
    sort(people.begin(), people.end());
    
    int start = 60 * 9;
    int count = n;
    int interval = t;
    int idx = 0;
    
    int lastTime = 0;
    int lastBusPeople = 0;
    int lastBusTime = 0;
    
    while(n--){
        int now = start + (idx++)*interval;
        int busPeople = 0;
        if(people.empty())break;
        
        
        
        while(people.front() <= now && !people.empty()){
            int person = people.front();
            if(busPeople < m){
                busPeople++;
                people.pop_front();
                lastTime = person;
            }else{
                break;
            }
        }
        lastBusPeople = busPeople;
        lastBusTime = now;
    }
    if(lastBusPeople < m){
        answer = func(lastBusTime/60) + ":" + func(lastBusTime%60);
    }else{
        answer = func((lastTime-1)/60) + ":" + func((lastTime-1)%60);
    }
    
    
    return answer;
}