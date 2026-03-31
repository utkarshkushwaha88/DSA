#include <bits/stdc++.h>
using namespace std;
int main() {

    //creation

    unordered_map<string,int>m;

    //insertion:
    
    //method:1

    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);

    //method:2
    pair<string,int>q("love",3);
    m.insert(q);
    //method:3
    m["mera"]=4;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    cout<<m["unknown"]<<endl;//it will declare varaible with 0 value
    cout<<m.at("unknown")<<endl;// it will give terminate called after throwing an instance of 'std::out_of_range'

    //for size
    cout<<"size "<<m.size()<<endl;

    //to check element present if present it give 1 and if not it give 0

    cout<<"present "<<m.count("shar")<<endl;

    //erase
    m.erase("love"); 

    //access all element :
        //by for loop

    for(auto i:m){
        cout<<i.first<<"  "<<i.second<<endl;
    }
    //by iterator

    unordered_map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++;
    }
return 0;
}