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
    string reminder = mod2div(key,codeword);
    bool correct = false;
    string::size_type sz;
    int rem = stoi (reminder,&sz);
    if(rem == 0){
        return true;
    }
    return false;
}
string alter(string data, int index){
    string dataModified = data;
    char str = data.at(index - 1); // input start from 1 but we start from 0
        cout<<str<<  endl; 
    str = (str == '0')?'1':'0';
    for(int i = 0;i<dataModified.length();i++){
        if (i == index - 1){
            dataModified[i] = str;
        }
    }
    return dataModified;
}

int main()
{
    cout<<"Enter File name and Location (e.g. D:\\message_generator.txt):\n(if in same file as this exe enter file name without location)\n";
    string inpfile = "msg.txt";
    cin>>inpfile;
     string key = "";
    string data = "";
    string codeword ="";
    ifstream inp(inpfile.c_str());
    if(inp.is_open()){
        
    }else {cout<<"File in not open"<<endl;}

    
    // verifier and alter
    cout<<"Do you want to Alter sent message or verify it?\nenter 0 to alter message or 1 to verify it\n";
    string op ="";
    cin>>op;
    while(op!="0"&&op!="1"){
        cout<<"enter 0 to alter message or 1 to verify it\n";
        cin>>op;
    }
    if(op=="0"){
        cout<<"enter number of bit to be modified:\n";
        int n =0;
        cin>>n;
        codeword = alter(codeword,n);
        op="1";
        cout<<"altered message: "<<codeword<<endl;
    }
    if(op=="1"){
        if(verifier(codeword,key)){
            cout<<"Message is correct\n";
        }
        else{
            cout<<"Message is not correct\n";
        }
    }
    return 0;
}
