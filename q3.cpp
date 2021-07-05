#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <algorithm>
using namespace std;

pthread_t tid1, tid2, tid3, tid4;
string s;

void* inputThread(void* arg) 
{   
    cout << "Enter the string you want to modify = ";
    getline (cin, s);

    while (s.empty()) {
        cout << "Empty string. Enter again: ";
        getline(cin, s);
    }

    cout << "Entered string = " << s << endl;
    return NULL;
}

void* reverseThread(void* arg) 
{
    for (int i = 0; i < s.length() / 2; i++) 
        swap(s[i], s[s.length() - i - 1]); 

    cout << "Reversed string = " << s << endl;
    return NULL;
}

void* capitalThread(void* arg) 
{
    for (int i = 0; i <s.length(); i++)
         s[i] =  toupper(s[i]);

    cout<<"The capitalized string is = "<< s << endl;
    return NULL;
}

void* shiftThread(void* arg) 
{

     for (int i = 0; i <s.length(); i++){
         if (s[i] == ' ')
         {
             continue;
         }
         s[i] =  s[i]+2;
}
    cout<<"The shifted string is = "<< s << endl;
    return NULL;
}

int main() {

    pthread_create(&tid1, NULL, inputThread, NULL);
    pthread_join(tid1, NULL);
    pthread_create(&tid2, NULL, reverseThread, NULL);
    pthread_create(&tid3, NULL, capitalThread, NULL);
    pthread_create(&tid4, NULL, shiftThread, NULL);

	pthread_exit(NULL);
}

