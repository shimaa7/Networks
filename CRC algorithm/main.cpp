#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string xorFn(string a,string b){
    string result="";
    for(int i = 1;i<a.length();i++){
        if(a[i] == b[i]){
            result+="0";
        }
        else{
            result+="1";
        }
    }
    return result;
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
    int keyLen = key.length();
    string appData = "";
    appData = data + string(keyLen-1,'0');
    string rem = mod2div(key,appData);
    string codeword = data+rem;
    return codeword;
}
bool verifier(string codeword,string key){

}
string alter(string data, int index){
    string dataModified = data;
    char str = data.at(index - 1); // input start from 1 but we start from 0
    str = (str == '0')?'1':'0';
    dataModified.replace(dataModified.begin()+index-1,dataModified.end()-dataModified.begin()+index-1,str);
    return dataModified;
}

int main()
{

    return 0;
}
