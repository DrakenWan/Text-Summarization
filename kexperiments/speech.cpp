#include<fstream>
#include<iostream>
#include<string>

using namespace std;

struct word
 {
 	int id;
 	string val;
	string type;
	/* 
	 noun = NN  0
	 adverb = ADV 1
	 adjective = ADJ 2
	 verb = VB 3
	*/
 };
 
int main()
 {
 	word w[9000];
 	string temp;
 	ifstream file;
 	file.open("\speech\\adjectives\\1syllableadjectives.txt", ios::in);
 	long int i=0;
 	while(!file.eof())
 	 {
 	 	w[i].id = i+1;
 	 	file>>temp;
 	 	w[i].val = temp;
 	 	w[i].type = "ADJ";
 	 	i++;
	 }
 	file.close();
 	
 	ofstream newfile("\speech\\adjectives\\1syllableadjectives2.dat", ios::out|ios::app);
 	
 	i=0;
	 while(!newfile.eof())
 	 {
 	 	newfile.write( (char *)&w[i], sizeof(word) );
 	 	i++;
	  }
	newfile.close();
	
 	file.open("\speech\\adjectives\\1syllableadjectives2.dat", ios::in);
 	file.read( (char *)&w[0], sizeof(word));
 	file.seekg(0, ios::beg);
 	cout<<w[0].id<<endl;
 	cout<<w[0].val<<endl;
 	cout<<w[0].type<<endl;
 	file.close();
 	return 0;
 }
