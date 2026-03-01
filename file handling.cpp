#include<iostream>
#include<fstream>
using namespace std;
void task1(){
fstream writefile("notes.txt", ios::out);

cout <<writefile.tellp() << endl;
writefile << "Hello welcome ";
writefile << "How are you ";
writefile << "Fuck you ";
writefile.seekp(-8, ios::end);
writefile << "dont Fuck you";
writefile.close();
fstream readfile("notes.txt", ios::in);
string line;
fstream appendfile("notes.txt", ios::app);
appendfile << "name" << endl ;
appendfile.close();
readfile.seekg(14);
while(getline(readfile, line)){	
cout << line << endl;
}
readfile.close();

}

int main (){
task1();
return 0;
}