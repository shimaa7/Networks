#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string xorFn(string a,string b){

}
string mod2div(string key, string data)
{
    int nBits = key.length();
    string temp = data.substr(0,nBits);
    string zDiv ="";
    while(nBits<data.length()){
        if(temp[0] == '1'){
            temp = xorFn(temp,key)+data[nBits];
        }
        else{
            zDiv = string(nBits,'0');
            temp = xorFn(temp,zDiv)+data[nBits];
        }
        nBits++;
    }
    if(temp[0]=='1'){
        temp = xorFn(temp,key);

    }
    else{
        zDiv = string(nBits,'0');
        temp = xorFn(temp,zDiv);
    }

    return temp;
}
string encodeData(string data,string key)
{

}
bool verifier(string codeword,string key){

}
string alter(string data, int index){

}

int main()
{

    return 0;
}
