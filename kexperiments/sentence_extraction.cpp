#include<iostream>
#include<vector>
#include<string.h>
#define condition 
//#include<fstream>
//Program to split a string paragraph into sentences vector

using namespace std;

vector<string> extract_sentence(string text)
 {
 	string temp="";
 	vector<string> sentence;
 	
 	int quote_flag = 0;
 	for(char letter : text)
 	 {
 	  if(letter == '"')
 	   quote_flag++;
 	  if( (letter != '!' && letter != '.' && letter != '?' ) && (quote_flag%2 == 0))
 	  {
 	   temp.push_back(letter);
 	   //cout<<temp;
 	   //cout<<"\nRand the first condition: quote_flag = 0";
 	  }
 	  else 
	   {
		  if(quote_flag%2 == 1)
	 	  {
	 	  	temp.push_back(letter);
	 	  	//cout<<temp;
	 	  	//cout<<"\nRand the second condition: quote_flag = 1";
		  }
	 	  else
	 	  {
	 	  	//cout<<endl<<"third condition\n temp = "<<temp<<endl;
	 	  	if(temp[0] == ' ')
	 	  	 temp.erase(temp.begin()); //remove the spaces reserved in the temp[0]
	 	  	sentence.push_back(temp);
	 	  	temp=""; //re-initialise the temp variable with empty string
		  }
	   }
	 }
	 
	return sentence;
 }


int main()
 {
 	string text = "There was once a woman who was very, very cheerful, though she had little to make her so; for she was old, and poor, and lonely. She lived in a little bit of a cottage and earned a scant living by running errands for her neighbours, getting a bite here, a sup there, as reward for her services. So she made shift to get on, and always looked as spry and cheery as if she had not a want in the world. Now one summer evening, as she was trotting, full of smiles as ever, along the high road to her hovel, what should she see but a big black pot lying in the ditch! \"Goodness me!\" she cried, \"that would be just the very thing for me if I only had something to put in it! But I haven't! Now who could have left it in the ditch?\". And she looked about her expecting the owner would not be far off; but she could see nobody. \"Maybe there is a hole in it,\" she went on, \"and that's why it has been cast away. But it would do fine to put a flower in for my window; so I'll just take it home with me.\". And with that she lifted the lid and looked inside. \"Mercy me!\" she cried, fair amazed. \"If it isn't full of gold pieces. Here's luck!\". And so it was, brimful of great gold coins. Well, at first she simply stood stock-still, wondering if she was standing on her head or her heels. Then she began saying: \"Lawks! But I do feel rich. I feel awful rich!\".";
	vector<string> sentence = extract_sentence(text);
	vector<string>::iterator itr;
	
	cout<<int(sentence.size())<<endl;
	
	for(itr=sentence.begin(); itr != sentence.end(); ++itr)
	 {
	 	cout<<';'<<*itr<<endl;
	 }
 	return 0;
 }
