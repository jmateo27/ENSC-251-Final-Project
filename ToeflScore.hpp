#ifndef TOEFLSCORE_H
#define TOEFLSCORE_H

class ToeflScore{ // Creating the TOEFL class
    public: // The following are the public members
        ToeflScore(int read, int listen, int speak, int write);
        //Precondition: Defining the constructor for ToeflScore with its 4 parameters
        // which will be used by used only by mututator and accessor functions for ADT
        ToeflScore();
        //Precondition: Initializes the constructors to its parameters

        //set
        void setReading(int read);
        // Precondition: the Mutator function for the read parameter, allows to change the 
        // Reading score and is used to insert data from text file to the arrays
        void setListening(int listen);
        // Precondition: the Mutator function for the listen parameter, allows to change the 
        // Listening score and is used to insert data from text file to the arrays
        void setSpeaking(int speak);
        // Precondition: the Mutator function for the speak parameter, allows to change the 
        // Speaking score and is used to insert data from text file to the arrays
        void setWriting(int write);
        // Precondition: the Mutator function for the write parameter, allows to change the 
        // Writing score and is used to insert data from text file to the arrays

        //get
        int getReading() const;
        // Precondition: the Accessor function for the reading variable, it returns the value 
        // of the reading variable once this is called and is of type static (const)
        int getListening() const;
        // Precondition: the Accessor function for the listening variable, it returns the value 
        // of the listeningn variable once this is called and is of type static (const)
        int getSpeaking() const;
        // Precondition: the Accessor function for the speaking variable, it returns the value 
        // of the speaking variable once this is called and is of type static (const)
        int getWriting() const;
        // Precondition: the Accessor function for the writing variable, it returns the value 
        // of the writing variable once this is called and is of type static (const)
        int getTOEFL() const;
        // Precondition: the Accessor function for the TOEFL variable, it returns the value 
        // of the TOEFL variable (the sum) once this is called and is of type static (const)

    private: // The following are the private members
        int reading, listening, speaking, writing, TOEFL;// defining the private members for ADT

};
#endif