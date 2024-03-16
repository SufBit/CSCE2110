/*
 Rules followed from https://web.ics.purdue.edu/~morelanj/RAO/prepare2.html
 
Most words in Pig Latin end in "ay." Use the rules below to translate normal English into Pig Latin.

1. If a word starts with a consonant and a vowel, put the first letter of the word at the end of the word and add "ay."

Example: Happy = appyh + ay = appyhay


2. If a word starts with two consonants move the two consonants to the end of the word and add "ay."

Example: Child = Ildch + ay = Ildchay


3. If a word starts with a vowel add the word "way" at the end of the word.

Example: Awesome = Awesome +way = Awesomeway

*/
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

//If characters are a vowel function will return true
bool isVowel(char ch) {
  switch(ch) {
  case 'A': case 'E': case 'I': case 'O': case 'U':
  case 'a': case 'e': case 'i': case 'o': case 'u':
    return true;
  default:
    return false;
  }
}

//This will check if first word is a vowel or not.
int firstVowel(string w) {
    int i = 0;
  while(i < w.length()) {
    if (isVowel(w[i])) {
        return i;
    }
    i++;
  }
  return -1;
}

//Each word converted individually 
string wordConvert(string w) {

  string start;
  string end;
    
  int fVowel = firstVowel(w);
  if (fVowel == -1) {
    return w;
  } 
  //if only first leter is a vowel
  else if (fVowel == 0) {
    return w + "way";
  } 
  else {
    start = w.substr(0, fVowel);
    end = w.substr(fVowel);
    return end + start + "ay";
  }
}

//Function to convert each word in th eline to pigLatin, starting the sentence from -1
string convertLine(string line) {
    
  string r;
  int i = 0;
  int start = -1;
  while(i < line.length()) {
    char ch = line[i];
    
    //Check if each character is a letter
    if (isalpha(ch)) {
      if (start == -1){
        start = i;
      }
    } 
    else {
      if (start >= 0) {
    	r += wordConvert(line.substr(start, i - start));
    	start = -1;
      }
      r += ch;
    }
    i++;
  }
  if (start >= 0) {
      //Word taken from the start and added into a string r
    r += wordConvert(line.substr(start));
  }
  return r;
}

bool checkForQuit(string sen){

    string word;
    stringstream ss(sen);

    while (ss)
    {
        ss >> word;
        if (word == "quit" || word == "Quit" ){
            return true;
        }
    }

    return false;
    

}

int main() {
  
  string sen;

  while(1){

    cout << "Enter sentence: ";
    getline(cin, sen);

    if (checkForQuit(sen)){
        cout << "Program ended" << endl;
        break;
    }

    else{
        string translateToPigLatin = convertLine(sen);
        cout << "Output in Pig Latin: " << translateToPigLatin << endl;
        }
  }
  return 0;
  
}
