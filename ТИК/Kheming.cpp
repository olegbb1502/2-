#include <iostream>
#include <cstring>
using namespace std;

char xxor(char a, char b)
{
    if(a==b)
        return '0';
    else
        return '1';
}

string insert_control_bits(string code)
{
    int i=0, number=1;
    while(code[i])
    {
        if(i==number-1)
        {
            code.insert(i, "0");
            number*=2;
        }
        i++;
    }
    return code;
}

string find_control_bits(string code)
{
    int i=0, number=1;
    char x;
    string ctr_bits, str_xor;

    while(number<code.length())
    {
        str_xor.erase();
        for(i=number-1; i<code.length(); i+=number*2)
        {
            for(int j=0; j<number && i+j<code.length(); j++)
            {
                x=code[i+j];
                str_xor.push_back(x);
            }
        }
        int q=1;
        x=str_xor[0];
        while(q<str_xor.length())
        {
          x=xxor(x,str_xor[q]);
          q++;
        }
        ctr_bits.push_back(x);
        number*=2;
    }
    return ctr_bits;
}

string set_control_bits(string code, string ctr_bits)
{
    int number=1, i=0;

    while(i<ctr_bits.length())
    {
        code[number-1]=ctr_bits[i];
        number=number*2;
        i++;
    }
    return code;
}

int main()
{
    string code, ctr_bits;

    code="1101011110010101";
    cout<<"Code: "<<code<<endl;
    code=insert_control_bits(code);
    ctr_bits=find_control_bits(code);
    code=set_control_bits(code, ctr_bits);
    cout<<"Code with control bits: "<<code<<endl;
    code[11]='0';
    cout<<"Code with mistake: "<<code<<endl;
    ctr_bits=find_control_bits(code);
    cout<<"Place of mistake: "<<ctr_bits<<endl;
    return 0;
}

