 
#include <iostream>
#include <stdlib.h>
using namespace std;
 
int main(){
    const char *str1 = "42"; 
    const char *str2 = "3.14159"; 
    const char *str3 = "31337 nguyenvanhieu.vn"; 
    string s = "12345";
     
    int num1 = atoi(str1); 
    int num2 = atoi(str2); 
    int num3 = atoi(str3); 
    int num4 = atoi(s.c_str()); // N?u là string, convert v? char array s? d?ng .c_str()
    cout << "atoi(\"" << str1  
              << "\") is " << num1 << '\n'; 
    cout << "atoi(\"" << str2  
              << "\") is " << num2 << '\n'; 
    cout << "atoi(\"" << str3  
              << "\") is " << num3 << '\n'; 
    cout << "atoi(\"" << s
              << "\") is " << num4 << '\n'; 
}
