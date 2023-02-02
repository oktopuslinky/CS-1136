#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
int readFile(char theArray[50], string fileName, bool& fileValid, int theItems=0);
void displayResults(const char keyArray[50], const char studentArray[50], const int numItems);


/*
PURPOSE: Reads the file given and puts it into a character array.
INPUTS:
    1) Character Array: Will store the file contents
    2) String: Name of the file
    3) Integer: Will store the number of items in the array
OUTPUTS: 
    - Returns the number of items in the array
    - If the file cannot be opened, it will say so.
*/
int readFile(char theArray[50], string fileName, bool& fileValid, int theItems){
    char tempAnswer;
    int i = 0;
    ifstream inputFile;

    inputFile.open(fileName);
    if (inputFile){
        fileValid = true;
        while (inputFile >> tempAnswer){
            if (i < 50){
                theArray[i] = tempAnswer;
                i++;
                theItems++;
            } else {
                break;
            }
        }
    } else {
        cout << "\"" << fileName << "\" could not be opened." << endl;;
        fileValid = false;
    }
    inputFile.close();

    return theItems;
}

/*
PURPOSE: Displays the results of the program
INPUTS:
    1) Constant Character Array: Contains the answers on the answer key
    2) Constant Character Array: Contains the answers on the student copy
    3) Integer: Contains the number of items in the arrays
OUTPUTS:
    - The questions msised
    - The number of questions missed
    - The student grade
    - Whether or not the student passed
*/
void displayResults(const char keyArray[50], const char studentArray[50], int numItems){
    int missedQuestions = 0;
    bool passed = false;

    for (unsigned int i = 0; i < numItems; i++){
        if (keyArray[i] != studentArray[i]){
            missedQuestions++;
            cout << "Question " << i + 1 << " has incorrect answer '" << studentArray[i] << "', the correct answer is '" << keyArray[i] << "'." << endl;;
        }
    }

    double finalGrade = 100.00 * (numItems - missedQuestions) / numItems;

    if (finalGrade >= 72.5){
        passed = true;
    }

    cout << missedQuestions << " questions were missed out of " << numItems << "." << endl;
    cout << "The student grade is " << fixed << setprecision(2) << finalGrade << "%" << endl;
    
    if (passed == true){
        cout << "The student has passed the quiz." << endl;
    } else {
        cout << "The student has failed the quiz." << endl;
    }
}

int main(){
    bool fileValid = false;
    string answerKey;
    string studentAnswers;
    char keyArray[50] = {};
    char studentArray[50] = {};

    cout << "Enter the name of the file containing the key." << endl;
    getline(cin, answerKey);

    int answerKeyItems = readFile(keyArray, answerKey, fileValid);
    if (fileValid == false){
        return 0;
    }
    if (answerKeyItems == 0){
        cout << "The file containing the key was empty." << endl;
        return 0;
    }

    cout << "Enter the name of the file containing the student's responses." << endl;
    getline(cin, studentAnswers);

    fileValid = false;
    int studentAnswersItems =  readFile(studentArray, studentAnswers, fileValid);
    if (fileValid == false){
        return 0;
    }
    if (studentAnswersItems < answerKeyItems){
        cout << "File error! There is a mismatch between the number of questions and answers." << endl;
        return 0;
    }

    if (studentAnswersItems == 0){
        cout << "The file containing the key was empty." << endl;
        return 0;
    }

    displayResults(keyArray, studentArray, answerKeyItems);
}