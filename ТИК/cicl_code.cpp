//ѕри несистематическом кодировании кодовое слово получаетс€ в виде произведени€ информационного полинома на порождающий
#include <iostream>
#include <vector>
#include <conio.h>
 
using namespace std;
 
vector <bool> Resault;
vector <bool> Polynom;
vector <bool> Rest;
 
vector <bool> BoolTransform   (string str){ //запись строки полинома
    vector <bool> v;
    for(int i=0; i< str.size(); i++)
        if(str[i]=='1')
            v.push_back(1);
        else
            v.push_back(0);
    return v;
}
 
vector <bool> multiple(vector <bool> v)
{
    vector <bool> s;
    for(int i=0; i<v.size(); i++)
        s.push_back(v[i]);
    for(int i=0; i<Polynom.size()-1; i++)
        s.push_back(0);
    return s;
}
 
void divide(vector <bool> str, vector <bool> bgn=Polynom,  int tmp=0)//деление на производный многочлен
{
    if(!str[tmp])
    {
        Resault.push_back(0);
        if(tmp+bgn.size()<str.size())
            divide(str, bgn, tmp+1);
        else
            Rest=str;
    }
    else
    {
        Resault.push_back(1);
        for(int i=0; i<bgn.size(); i++)
        {
            str[tmp+i]=str[tmp+i] ^ bgn[i];
        }
        if(tmp+bgn.size()<str.size())
            divide(str, bgn, tmp+1);
        else
            Rest=str;
    }
}
 
void repair(vector <bool> str){ //нахождение ошибки кода
            int count=0;
            for(int i=0; i<Rest.size(); i++)
                if(Rest[i])
                count++;
            if(!count){
                for(int i=0; i<str.size(); i++){
                cout<<str[i];}
            cout<<endl;
            }
            else{
                count=0;
                vector <bool> b;
                b.push_back(1);
                for(int i=0; i<str.size()-1; i++)
                    b.push_back(0);
                divide(b);
                
                vector <bool> Ro=Rest;
                while(1){
                    divide(str);
                   	
                    Rest.erase(Rest.begin(), Rest.begin()+count);
                    if(Rest==Ro){
                        str[count]=str[count]^1;
                        break;
                }
                count++;
                str.push_back(0);
                cout<<"/"<<str[count]<<"/";
                }
            }
            str.erase(str.end()-count, str.end());
            for(int i=0; i<str.size(); i++)
 	cout<<str[i];
//            	repair(str);}
            cout<<endl;
}
vector <bool> go_left(vector <bool> vector){//перемещение по вектору 
    bool b=vector[0];
    for(int i=0; i<vector.size()-1; i++)
        vector[i]=vector[i+1];
    vector[vector.size()-1]=b;
    return vector;
}
 
vector <bool> go_right(vector <bool> vector){ //перемещение по вектору 
    bool b=vector[vector.size()-1];
    for(int i=vector.size()-1; i>0; i--)
        vector[i]=vector[i-1];
    vector[0]=b;
    return vector;
}
 
int main(){
    Polynom=BoolTransform("110111");//ѕорождающий полином
 
    string cmd;
    cin>>cmd;
    vector <bool> Comm=BoolTransform(cmd);
     
    int n;
    cout<<endl<<"1 Form the Code;"<<endl<<"2 Repair broken Code;"
        <<endl<<"3 Form the matrix; "<<endl;
    cin>>n;
     
    switch(n)
    {   case 1:
            Comm=multiple(Comm);
            divide(Comm);
            for(int i=0; i<Comm.size(); i++)
            {   Comm[i]=Comm[i] || Rest[i];
                cout<<Comm[i];
            }
            cout<<endl;
        break;
         
        case 2://јлгоритм вы€влени€ ошибки
            divide(Comm);
            repair(Comm);
        break;
         
        case 3:
            Comm.clear();
            Comm.push_back(1);
            for(int i=0; i<11; i++)
                Comm.push_back(0);
            divide(Comm);
             
            cout<<"Forming"<<endl;//ѕорождающа€ матрица
            for(int i=0;i<Polynom.size();i++)
            {
                cout<<"   "<<i+1<<"\t";
                for(int j=0;j<Resault.size();j++)
                    cout<<Resault[j];
                Resault=go_right(Resault);
                cout<<endl;
            }
            cout<<endl;
            Resault=go_left(Resault);
            cout<<"Verify"<<endl;//ѕроверочна€ матрица
            for(int i=0;i<Polynom.size();i++)
            {
                cout<<"   "<<i+1<<"\t";
                for(int j=0;j<Resault.size();j++)
                    cout<<Resault[j];
                Resault=go_left(Resault);
                cout<<endl;
            }
             
        break;  
    }
    _getch();
}
