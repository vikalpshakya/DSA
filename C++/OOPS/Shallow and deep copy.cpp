#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Student{
    int age ;
    char *name ; 
    
    public :
    Student ( int age , char *name ){
        this -> age = age ;
        // shallow copy
        
        // this ->name = name ;
        
        // deep copy 
        this -> name = new char[strlen(name)+1];
        strcpy(this->name , name);
        
    }
    void display(){
        cout<< name << " " << age << endl ; 
    }
    } ;
 
int main() {
    char name[] = "abcd" ; 
    Student s1(20 , name ); 
    s1.display() ; 
    
    name[3] = 'e' ;
    Student s2(24,name);
    s2.display() ; 
    s1.display() ;
    
    
    
    
    
    
    
    
}
