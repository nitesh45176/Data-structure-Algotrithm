

#include <iostream>
using namespace std;


bool palindrome(string str, int i, int j)
{
     //base case
     if(i > j) return true;
     
     if(str[i] != str[j]) {
        return false;
     }
     else{
       //recursive call
        return palindrome(str, i+1 ,j-1);
     }

}

int main()
{
    string name = "BookooB";

    int isPalindrome = palindrome(name, 0 , name.length()-1);

    if(isPalindrome){
        cout<< "It is palindrome";
    }
    else{
        cout<< "Not a palindrome";
    }
}
