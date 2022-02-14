#include <iostream>
#include <string>
#include "Ndimension.h"
using namespace std;
int main() {
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int size = 10;
//    NDimension<int> p1(size, arr);
//    for(int i = 0; i<p1.getSize(); i++) {
//        cout << "This is p1 at the index "<<i<<": "<< p1.getValByInd(i) << endl;
//    }
//    string strArray[4] = {"Matthew", "Li", "Is", "Here"};
//    int strSize = 4;
//    NDimension<string> s1(strSize, strArray);
//    cout<<s1.getSize()<<endl;
//    for(int i = 0; i<s1.getSize(); i++) {
//        cout << "This is s1 at the index "<<i<<": "<< s1.getValByInd(i) << endl;
//    }
//    int arr2[5] = {11, 12, 13, 5, 6};
//    int size2 = 5;
//    NDimension<int> p2(size2, arr2);
//    cout<<p2[2]<<endl;
//    p1=p2;
//    for(int i = 0; i<p1.getSize(); i++) {
//        cout << "This is p1 at the index "<<i<<": "<< p1.getValByInd(i) << endl;
//    }
//    string strArray2[6] = {"My", "Name", "Is", "Matt", "Lee", "Hello"};
//    int strSize2 = 6;
//    NDimension<string> s2(strSize2, strArray2);
//    s1 = s2;
//    for(int i = 0; i<s1.getSize(); i++) {
//        cout << "This is s1 at the index "<<i<<": "<< s1.getValByInd(i) << endl;
//    }
//    int arr3[3] = {1, 2, 3};
//    int size3 = 3;
//    NDimension<int> p3(size3, arr3);
//    p2+=p3;
//    for(int i = 0; i<p2.getSize(); i++) {
//        cout<<"p2's value at the index "<<i<<": "<<p2[i]<<endl;
//    }
//    string strArray3[2] = {"General", "Kenobi"};
//    int strSize3 = 2;
//    NDimension<string> s3(strSize3, strArray3);
//    string strArray4[3] = {"A", "Bold", "One"};
//    int strSize4 = 3;
//    NDimension<string> s4(strSize4, strArray4);
//    s3+=s4;
//    for(int i = 0; i<s3.getSize(); i++) {
//        cout << "s3's value at the index " << i << ": " << s3[i] << endl;
//    }
//    int arr4[4] = {1, 2, 3, 4};
//    int size4 = 4;
//    NDimension<int> p4(size4, arr4);
//    int arr5[5] = {1, 2, 6, 4, 10};
//    int size5 = 5;
//    NDimension<int> p5(size5, arr5);
//    NDimension<int> pSum45 = p4+p5;
//    for(int i = 0; i<pSum45.getSize(); i++) {
//        cout<<"pSum45's value at the index: "<<pSum45[i]<<endl;
//    }
//    string strArray5[3] = {"Computer", "Social", "Math"};
//    int strSize5 = 3;
//    NDimension<string> s5(strSize5, strArray5);
//    string strArray6[2] = {"Science", "Studies"};
//    int strSize6 = 2;
//    NDimension<string> s6(strSize6, strArray6);
//    NDimension<string> s5Sums6 = s5+s6;
//    for(int i = 0; i<s5Sums6.getSize(); i++) {
//        cout<<"s5Sum6 value at the index: "<<s5Sums6[i]<<endl;
//    }
//    int arr6[4] = {1, 2, 3, 4};
//    int size6 = 4;
//    NDimension<int> p6(size6, arr6);
//    int arr7[4] = {1, 2, 3, 4};
//    int size7 = 4;
//    NDimension<int> p7(size7, arr7);
//    bool isMatch = p6==p7;
//    cout<<isMatch<<endl;
//    string strArray7[3] = {"Chemistry", "Biology", "Physics"};
//    int strSize7 = 3;
//    NDimension<string> s7(strSize7, strArray7);
//    string strArray8[3] = {"Chemistry", "Biology", "Physics"};
//    int strSize8 = 3;
//    NDimension<string> s8(strSize8, strArray8);
//    bool sMatch = s7==s8;
//    cout<<sMatch<<endl;
    string arr8[2] = {"Hi", "Hello"};
    int size8 = 2;
    NDimension<string> p8(size8, arr8);
    string arr9[2] = {"Ii", "Jello"};
    int size9 = 2;
    NDimension<string> p9(size9, arr9);
    NDimension<int> diff = p9-p8;
    for(int i = 0; i<diff.getSize(); i++) {
        cout<<diff[i]<<endl;
    }
    int arr10[2] = {2, 6};
    int size10 = 2;
    NDimension<int> p10(size10, arr10);
    int arr11[2] = {3, 5};
    int size11 = 2;
    NDimension<int> p11(size11, arr11);
    NDimension<int> d = p11-p10;
    for(int i = 0; i<d.getSize(); i++) {
        cout<<"d["<<i<<"]: "<<d[i]<<endl;
    }

}
