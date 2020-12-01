#include "ToeflScore.hpp"

//constructor
ToeflScore::ToeflScore(int read, int listen, int speak, int write)
  : reading(read), listening(listen), speaking(speak), writing(write){
}

//default constructor
ToeflScore::ToeflScore() 
{}

//set Toefl Functions   
void ToeflScore::setReading(int read){
    reading = read;
}

void ToeflScore::setListening(int listen){
    listening = listen;
}

void ToeflScore::setSpeaking(int speak){
    speaking = speak;
}

void ToeflScore::setWriting(int write){
    writing = write;
}

//get Toefl Functions
int ToeflScore::getReading() const{
     return reading;
}

int ToeflScore::getListening() const{
    return listening;
}

int ToeflScore::getSpeaking() const{
    return speaking;
}

int ToeflScore::getWriting() const{
    return writing;
}

int ToeflScore::getTOEFL() const {
    return (reading + listening + speaking + writing);
}
