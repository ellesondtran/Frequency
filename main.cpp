//Elleson Tran
//Roberts
//Frequency of Occurences 3.0
//Tests out random number generation and other cool features
//FINAL

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//function that asks the user how many trials and generates all of the data and returns a vector
void generateData(vector<int>  &freqs){
  int trials;
  cout<<endl<<"How many trials do you want?: ";
  cin>>trials;

  for(int x = 0; x < trials; x++){//generates a random number how ever many times
    int num = rand()%50 + 1;
    freqs[num] = freqs[num] + 1;//goes to random number and adds a "tally"
  }
}

//prints the menu in all
void showFullVector(vector<int>  &freqs){
  cout<<"Number            Occurrences"<<endl;
  for(int x = 1; x <= 50; x++){
    cout<<x<<"         	      "<<freqs[x]<<endl;
  }
}

//prints the menu but in summary
void summaryTable(vector<int>  &freqs){
  cout<<endl<<"SUMMARY:";
  cout<<endl<<"Range	Occurrences";
  int firstNum = 1;
  int secondNum = 5;

  //keeps going until it goes out of range
  do{
    int occurences = 0;//sets the occurences this round to zero
    cout<<endl<<firstNum<<"-"<<secondNum<<":";

    for(int x = firstNum; x <= secondNum; x++){//from the firstnum to the secondnum loop
      occurences = freqs[x] + occurences;//adds firstnum to second nums occurences to this variable
    }
    cout<<"   "<<occurences;//prints the occurences

    //increases the increment
    firstNum = firstNum + 5;
    secondNum = secondNum + 5;
  }while(secondNum != 55);
  cout<<endl;
}

//prints the menu but in summary and in stars
void histogram(vector<int>  &freqs){
  cout<<endl<<"HISTOGRAM:";
  cout<<endl<<"Range	Occurrences";
  int firstNum = 1;
  int secondNum = 5;

  //keeps going until it goes out of range
  do{
    int occurences = 0;//sets the occurences this round to zero
    cout<<endl<<firstNum<<"-"<<secondNum<<":";

    for(int x = firstNum; x <= secondNum; x++){//from the firstnum to the secondnum loop
      occurences = freqs[x] + occurences;//adds firstnum to second nums occurences to this variable
    }

    cout<<"   ";
    
    for(int x = 0; x < occurences; x++){//prints the stars
      cout<<"*";
    }

    //increases the increment
    firstNum = firstNum + 5;
    secondNum = secondNum + 5;
  }while(secondNum != 55);
  cout<<endl;
}

//returns the mean of the random numbers generated
double mean(vector<int> &freqs){

  double total = 0; //everything added up
  int allNums = 0; //all of the generated numbers that were generated

  for(int x = 1; x <= freqs.size(); x++){ //goes through the whole vector
    if(freqs[x] > 0){//if the number we're on was generated
      total = total + (freqs[x] * x ); //adds the value we are at to the total
      allNums = allNums + 1;
    }
  }

  double mean = total/allNums;//final calculation
  return mean;
}

//returns the max of the random numbers generated
int max(vector<int> &freqs){
  int max;

  for(int x = 1; x <= freqs.size(); x++){ //goes through the whole vector
    if(freqs[x] > 0){//if number we're on was generated
      max = x;//whatever is the last one we generate, its the max
    }
  }
  
  return max;
}

// //returns the min of the random numbers generated
int min(vector<int> &freqs){
  int min;

  for(int x = freqs.size(); x <= freqs.size(); x--){//goes through the whole vector backwards
    if(freqs[x] > 0){//if the number we're on was generated
      min = x;//the last one is minimum since we're going backwards in this for loop
      
    }
  }

  return min;
}

// //returns the median of the random numbers generated
double median(vector<int> &freqs){
  double median;
  vector<int> numsGen;

  for(int x = 1; x < freqs.size(); x++){
    if(freqs[x] > 0){
      for(int i = 1; i <= freqs[x]; i++){
        numsGen.push_back(x);
      }
    }
  }
  
  if((numsGen.size() % 2) == 0){//if the numsgen is even
    double spotOne = numsGen[numsGen.size() / 2]; //the right side of the middle
    double spotTwo = numsGen[(numsGen.size() / 2) - 1]; //the left side of the middle
    median = (spotOne + spotTwo) / 2; //average out between the two middle spots
    return median;
  }
  else{//if the numsgen is odd
    median = numsGen[numsGen.size() / 2];
  }
  return median;
}


// //returns a vector of the modes of the random numbers generated
vector<int> modes(vector<int> &freqs){
  vector<int> vecModes;
  int highest = freqs[1];
  //loop to find the highest number of occurences
  for(int x = 1; x < freqs.size(); x++){
    if(highest <= freqs[x]){//if the one we're on is higher than the current one
      highest = freqs[x];
    }
  }
  //loop to add all the highest num of occured numbers to a vector
  for(int x = 1; x < freqs.size(); x++){
    if(freqs[x] == highest){
      vecModes.push_back(x);
    }
  }
  
  return vecModes;
}

int main() {
  srand(time(0));
  vector<int> amountOfNums(51);
  
  
  generateData(amountOfNums);
  showFullVector(amountOfNums);
  summaryTable(amountOfNums);
  histogram(amountOfNums);
  
  cout<<endl<<"STATISTICS:";
  cout<<endl<<"Mean: "<<mean(amountOfNums);
  cout<<endl<<"Max: "<<max(amountOfNums);
  cout<<endl<<"Min: "<<min(amountOfNums);
  cout<<endl<<"Median: "<<median(amountOfNums);

  vector<int> vecModes = modes(amountOfNums);
  cout<<endl<<"Modes: ";
  for(int x = 0; x < vecModes.size(); x++){
    cout<<vecModes[x]<<", ";
  }
}