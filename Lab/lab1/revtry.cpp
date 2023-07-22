#include <iostream>
#include <string.h>
#include <string>

using namespace std;

// int main(){
//     char a[] = "Muk";
//     int len = strlen(a);
//     char b[len];
//     int lens = len;
//     lens--;
//     for(int i=0;i<len;i++){
//         b[lens] = a[i];
//         lens--;
//     }
//     cout<<b;
// }

int main(){
    char a[] = "Muk";
    strrev(a);
    cout<<a;
}