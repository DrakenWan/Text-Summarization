#include<iostream>
#include<utility>
#include<vector>
#include<map>
#include<stdio.h>
#include<string>
#include<fstream>

using namespace std;

struct student
 {
 	string name;
 	char sex;
 	int age;
 };
 
int main()
 {		  
 	pair<int, char> g1;
  	pair<string, int> g2("Kartikay", 1);
  	pair<int, string> g3(1, "jkrowl");
  	pair<int, string> g4(g3);
  	g3 = make_pair(10, "karr");
  	cout<<g3.first<<' '<<g3.second;
  	/////////////////
  	////////////////
  	
  	cout<<endl<<endl;
  	
  	////////////////
  	///////////////
  	vector<int>::iterator ptr;
  	
  	vector<int> choot;
  	for(int i=1; i<=6; i++)
  	 choot.push_back(i);
  	choot.pop_back();
  	
  	cout<<endl<<endl;
  	
  	for(int x : choot)
  	 cout << x <<" ";
  	 cout<<endl;
  	for(ptr = choot.begin(); ptr!= choot.end(); ++ptr)
  	  cout<<*ptr<<'\t';
  	//////////////
  	cout<<endl<<endl;
  	/////////////
  	
  	map<int, string> m;
  	map<int, string>::iterator itr;
  	
  	pair<int, string> dump;
  	
  	for(int i=0; i<5; i++)
  	  {
  	  	cout<<"\nINPUT #"<<i+1;
  	  	cout<<"\nEnter Key value: "; cin>>dump.first;
  	  	cout<<"Enter Value: "; 
		cin.ignore(1, '\n'); //removing \n from it all
		getline(cin, dump.second);
  	  	m.insert(dump);
	  }
	
	for(itr = m.begin(); itr != m.end(); ++itr)
	 cout<<'\t'<<itr->first<<'\t'<<itr->second<<endl;
  	////
  	
  	
  	//new map
  	pair<int, student> dump2;
  	map<int, student> m1;
  	map<int, student>::iterator p;
  	for(int i=0; i<5; i++)
  	 {
    	cout<<"\n\nInput #"<<i+1;
    	cout<<"\nEnter rollnumber: "; cin>>dump2.first;
    	cout<<"Enter Student Name: ";
    	cin.ignore(1, '\n');
    	getline(cin, dump2.second.name);
    	cout<<"Enter age: ";
    	cin>>dump2.second.age;
    	cout<<"Enter sex: ";
    	cin>>dump2.second.sex;
    	m1.insert(dump2);
     }
    
    for(p = m1.begin(); p != m1.end(); ++p)
     {
     	cout<<"\nStudent Roll Number: "<<p->first;
     	cout<<"\nStudent Name: "<<p->second.name;
     	cout<<"\nAge: "<<p->second.age;
     	cout<<"\nSex: "<<p->second.sex;
	 }
	 
	 map<string, int> words;
	 
	 pair<string, int> dump3;
	 string str;
	 ifstream file;
	 file.open("story.txt", ios::in);
	 while(!file.eof())
	  {
	  	file>>str;
	  	
	  }
	 file.close();
	return 0;
 }
