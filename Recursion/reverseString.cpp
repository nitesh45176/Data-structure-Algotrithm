
#include<iostream>
using namespace std;

void reverse(string& str, int i, int j){

    //Base case
 
    if(i > j) return ;

    swap(str[i++], str[j--]);

  //Recursive call
    reverse(str, i , j);
    
}


int main(){
    string name = "nitesh";

    reverse(name, 0 , name.length()-1);

    cout<< name;
    

}
