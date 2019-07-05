#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    vector<long> X;
    vector<long> Y;
    int i = 0, rows = 0, n, dn, tn;
     __int64 sumx2, sumy2, sumxy = 0, sumx_2 = 0, sumy_2 = 0, temp = 0, sumx = 0, sumy = 0, sse = 0;
    char file_name[100], comp_name[100];
    string value1, value2;
    system("python updated_stock.py");
    cout<<"Enter file name: ";
    cin>>file_name;
    strcat(file_name, ".csv");
    cout<<"Enter the comparators name: ";
    cin>>comp_name;
    strcat(comp_name, ".csv");
    ifstream file1, file2;
    file1.open(file_name);
    file2.open(comp_name);
    while(file1.good())
    {
        getline(file1, value1, ',');
        if(rows%2 == 0)
        {
            temp = atol(value1.c_str());
            Y.push_back(temp);
        }
    }
    n = Y.size();
    dn = Y.size() * 0.75;
    tn = n - dn;
    while(file2.good())
    {
        getline(file2, value2, ',');
        if(rows%2 == 0)
        {
            temp = atol(value2.c_str());
            X.push_back(temp);
        }
    }
    double error, predict, a = 1, b = 1;
    n = X.size();
    float alpha = 0.0008;
    for(i=0; i<n; i++)
    {
        predict = a + b*X.at(i);
        error = Y.at(i) - predict;
        a = a+error * X.at(i) * alpha;
        b = b + error * alpha;
        cout<<"\na: "<<a<<"\tb: "<<b<<"\tpredit: "<<predict;
    }
    cout<<"A: "<<a<<" B:"<<b<<endl;
    cout<<endl<<a + b*(X.at(i-1));
  