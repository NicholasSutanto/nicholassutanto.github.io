/*Nicholas Sutanto
* HW9
* 6/1/2019
* Create an email account
*/


#include<bits/stdc++.h>
#include<string>
using namespace std;

void CreateAccount(string *name,string *loginname);
    string CreatePassword();

void OutputAccount(string name,string loginname,string password);

int main() {
    string name,loginname,password;
    CreateAccount(&name,&loginname);
    password=CreatePassword();
    OutputAccount(name,loginname,password);
    return 0;
}

void CreateAccount(string *name,string *loginname) {
    string firstname,lastname,domain,extension;
    cout<<"Enter your name with space separating first and last name:";
    cin>>firstname>>lastname;
    *name=firstname+" "+lastname;
    cout<<"Enter domain name:";
    cin>>domain;
        while(1) {
            char *ch;
            cout<<"Enter extension:";
            cin>>extension;
        if((extension.compare(".com")!=0)&&(extension.compare(".net")!=0)&&(extension.compare(".edu")!=0)){
            cout<<"Invalid extension\n";
        continue;
        }
        else
        break;
        }
        transform(firstname.begin(), firstname.end(), firstname.begin(), ::tolower);
        transform(lastname.begin(), lastname.end(), lastname.begin(), ::tolower);
        transform(domain.begin(), domain.end(), domain.begin(), ::tolower);
        *loginname=lastname+"."+firstname.at(0)+"@"+domain+extension;
}

string CreatePassword() {
    string password;
    bool error;
    cout<<"Rules for password\n";
    cout<<"\t1.)Minimum 12 characters long\n";
    cout<<"\t2.)At least one uppercase letter and one lowercase letter\n";
    cout<<"\t3.)At least one number\n";
    cout<<"\t4.)At least one character that is not a digit or letter\n";
    cout<<"\t5.)No whitespace\n";
        while(1) {
            error=false;
            cout<<"Enter password:";
            cin>>password;
        if(password.size()<12) {
            error=true;
            cout<<"-> Password must be at least 12 characters long\n";
}
        int i;
            for(i=0;i<password.size();i++) {
            if(islower(password[i]))
        break;
}
        if(i==password.size()) {
            error=true;
            cout<<"-> At least one lowercase letter must be there\n";
}
        for(i=0;i<password.size();i++) {
            if(isupper(password[i]))
            break;
}
        if(i==password.size()) {
            error=true;
            cout<<"-> At least one uppercase letter must be there\n";
}
        for(i=0;i<password.size();i++) {
            if(isdigit(password[i]))
            break;
}
        if(i==password.size()) {
            error=true;
            cout<<"-> At least one number must be there\n";
}
        for(i=0;i<password.size();i++) {
            if((!isalpha(password[i]))&&(!isdigit(password[i])))
            break;
}
        if(i==password.size()) {
            error=true;
            cout<<"-> At least one character that is not a digit or letter must be there\n";
}
        for(i=0;i<password.size();i++) {
            if(password[i]==' ')
            break;
}
        if(i!=password.size()) {
            error=true;
            cout<<"-> No whitespaces must be there\n";
}
        if(error==false)
            break;
}
    return password;
}

void OutputAccount(string name,string loginname,string password) {
    cout<<"\nName : "<<name<<"\n";
    cout<<"Login-name : "<<loginname<<"\n";
    cout<<"Password : "<<password<<"\n";
}
