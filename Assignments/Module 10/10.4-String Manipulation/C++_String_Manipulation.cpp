/**
 * Jay Gupta
 * 4/13/2020
 * C++_String_Manipulation.cpp (V1.0)
 * Professor: Dan McElory 
 * Class: CIS 054
 * Inputs: 
 * Outputs: 
*/

#include <iostream> // cout and cin
#include <time.h> // time
#include <string> // C++ strings 
using namespace std; 

// arrays for each part of speech 
const char * article[] = {"the", "a", "one", "some", "any", "an"}; 
const char * adjective[] = {"brave", "orange", "red", "fast", "slow", "smart", "painful", "tight", "dry", "dirty"}; 
const char * noun[] = {"desk", "person", "chair", "envelope", "car", "train", "bus", "boat",
  "elephant", "dog", "cat", "moose", "rabbit"}; 
const char * verb[] = {"drove", "jumped", "ran", "walked", "skipped", "wrote", "thought", "loved", "held", "felt", "sat"}; 
const char * preposition[] = {"to", "from", "over", "under", "on", "toward", "until"}; 

// find each array's size 
int articleCount = sizeof(article) / sizeof(char*);  
int adjectiveCount = sizeof(adjective) / sizeof(char*); 
int nounCount = sizeof(noun) / sizeof(char*); 
int verbCount = sizeof(verb) / sizeof(char*); 
int prepositionCount = sizeof(preposition) / sizeof(char*); 

int main() {
    // seed the random number generator
    srand((unsigned int) time(0)); // in order to have different random numbers each time 
    
    // Declare Variables
    string sentence; 

    // 20 sentences, 1 each iteration
    for (int i = 0; i < 20; i++) {
        // reset sentence each time 
        sentence = ""; 

        string firstArticle = article[rand() % articleCount];
        sentence += firstArticle + " ";   

        string firstAdjective = adjective[rand() % adjectiveCount]; 
        sentence += firstAdjective + " ";

        string firstNoun = noun[rand() % nounCount];
        sentence += firstNoun + " "; 

        string onlyVerb = verb[rand() % verbCount];
        sentence += onlyVerb + " "; 

        string onlyPreposition = preposition[rand() % prepositionCount];
        sentence += onlyPreposition + " "; 

        string secondArticle = article[rand() % articleCount]; 
        sentence += secondArticle + " ";

        string secondAdjective = adjective[rand() % adjectiveCount]; 
        sentence += secondAdjective + " ";

        string secondNoun = noun[rand() % nounCount]; 
        sentence += secondNoun + ".";

        // capitalize first letter of string
        sentence[0] = toupper(sentence[0]); 

        // display sentence
        cout << sentence << endl; 
    }



    return 0; 
}