#include<bits/stdc++.h>
#include<algorithm>
#define lex_punct_condn i == '-' || i == '{' || i == '}' || i == ':' || i == ';' || i == '<' || i == '>' || i == '\"' || i == '.' || i == '/' || i == ',' || i == '\'' || i == '?' || i == '!' || i == '(' || i == ')'

// Assuming we are working on richly formatted text documents instead of
// programming source code files

using namespace std;

string string_to_lower(string s)
 {
 	string ns = "";
 	for (char c : s)
 		  ns.push_back(tolower(c));
    return ns;
 }
 
 
//stopwords vector
int main()
 {
 	    //vector of stop words
 	    vector<string> stop_words{"html", "script", "style", "h1", "h2", "h3", "h4",
		 "h6", "h5", "pre", "b", "a","able","about","after","all","also","am",
        "an","and","any","are","as","at","be","because","been","but","by","can",
        "do","does","either","else","ever","every","for","from","get","got","had",
        "cannot","could","did","has","have","he","her","hers","him","his","how","I",
        "if","in","into","is","it","its","just","let","like","likely","may","me",
        "might","most","must","my","neither","no","nor","not","of","off",
        "often","on","only","or","other","our","own","said","say","says","she",
        "should","so","some","than","that","the","their","them","then","there",
        "these","they","this","they're","to","too","that's","us","was","we","were",
        "what","when","where","which","while","who","whom","why","will","with",
        "would","yet","you","your", "you're", "myself", "ours", "ourselves", 
		"you've", "you'll", "you'd", "yours", "yourself", "yourselves", "him",
		"himself", "she's", "herself", "it's", "itself", "theirs", "themselves", 
	    "that'll", "those", "being", "having", "doing", "until", "with", "against",
	    "s", "t", "don", "don't", "should've", "now", "d", "ll", "m", "0", "re", "ve",
		 "y", "ain", "aren", "aren't", "couldn", "couldn't", "didn", "didn't", "doesn", 
		 "doesn't", "hadn", "hadn't", "hasn", "hasn't", "haven't", "isn", "isn't", "ma",
		  "mightn", "mightn't", "mustn", "mustn't", "needn", "needn't", "shan", 
		  "shan't", "shouldn", "shouldn't", "wasn", "wasn't", "weren", "weren't", 
		  "won", "won't", "wouldn", "wouldn't" };
		  
/*	for(string i : stop_words)
	  if(i.size() == 6)
	    cout<<i<<endl;
*/ 
    string story, new_story;
    
    //retrieving from the file
    fstream file;
    file.open("C:\\Users\\Draken Wan\\Desktop\\story.txt", ios::in);
    getline(file, story,'~'); //ADDED tilde as my delimiter
    file.close();
	
	ofstream up_file;
    up_file.open("C:\\Users\\Draken Wan\\Desktop\\updated_story.txt", ios::out); //updated story file
    //displaying # of chars in story and the story itself
    cout << "\nsize of raw story: "<<story.size() << endl
    	;// << story <<endl << endl;
    
    //removal of punctuations from the story
    for(char i : story)
     {
	  if(lex_punct_condn) 
       continue;
      new_story.push_back(i);
     }
     
//	cout<<endl<<new_story; //for programmer's purposes
    story = new_story;
//  cout<<endl<<endl<<story;  //for programmer's purposes
    new_story.clear();
    cout<<"\n\nsize of lexed story: "<<story.size();
    file.open("C:\\Users\\Draken Wan\\Desktop\\lexed_story.txt", ios::out);
    file<<story;  //successfully put in entire string in lexed_file
	file.close();
	
	file.open("C:\\Users\\Draken Wan\\Desktop\\lexed_story.txt", ios::in);
	
	string w1; //temporal string //
	while(!file.eof())
	 {
	   file>>w1;
	   w1 = string_to_lower(w1);
	   int counter = stop_words.size();
	   //cout<<w1;
	   for(string i : stop_words)
	    	if( i != w1)
	    	 	counter--;
	   if(counter==0)
	            up_file<<w1<<' ';
	 }//while
	up_file.close();
	
	w1.clear(); //clear the temporal string
	
	file.open("C:\\Users\\Draken Wan\\Desktop\\updated_story.txt", ios::in);
	getline(file, w1);
	file.close();

	cout<<endl<<w1; //for programmer's use
	
	cout<<endl<<endl<<"size of updated story: "<<w1.length();
	////Code above is logically correct////
 	return 0;
 }

/*
  if(i == w1)
	         break;
	        else if( i!= w1)
	         {
	         	
			 }
*/
