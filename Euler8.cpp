//
//  main.cpp
//  Euler#8.cpp
//
//  Created by Kirsteeng Ng on 21/8/2017.
//  Copyright © 2017 Kirsteeng Ng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

void print_vec(vector<int> &q)
{
    if (q.empty())
    {
        cout << "Vector is empty" << endl;
        return;
    }
    
    for(vector<int>::iterator it = q.begin(); it < q.end(); it++)
    {
        cout << *it ;
    }
    
    cout << endl;
}


int main(int argc, const char * argv[]) {
    
    
    ifstream myfile;
    myfile.open("/Users/Kirsteenng/Desktop/codes/Euler#8.cpp/input.txt");
    string num;
    vector <int> l;
    int temp;
    print_vec(l);
    
    myfile >> num;
    myfile.close();
    for (int i =0; i < num.length(); i++)
    {
        // incorrectly if convert directly from stoi
        temp = num[i] - '0';
        l.push_back(temp);
        
    }

    cout << l.size() << endl;
    int ind = 0;
    
    // To prevent overflow
    unsigned long int prod = 1;
    unsigned long int curr = 1;
    
    vector <int> q;
    vector <int> max;
    
    while (ind < l.size())
    {
        while (q.size() < 13)
        {
            q.push_back(l[ind]);
            curr = curr * l[ind];
            ind++;
        }
        
        if(curr ==0)
        {
            q.clear();
            curr =1;
            //ind ++;
            cout << "************ hitting 0, rebuilding ************* " << endl;
            continue;
        }
        
        if(curr > prod)
        {
            prod = curr;
            max.clear();
            max.assign(q.begin(),q.end());
            cout << "********* Max being updated. current max: " ;
            print_vec(max);
            cout << "current prod: " << prod << endl;
        }
        
        q.push_back(l[ind]);
        ind++;
        
        curr = curr/q.front() * q.back();
        q.erase(q.begin());
        
    }
    cout << "final max: ";
    print_vec(max);
    cout << prod << endl;
    return 0;
}
