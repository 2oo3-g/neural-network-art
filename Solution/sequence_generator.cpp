#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

class SequenceGenerator
{
private:
    vector<int> inputSequence;
    vector<int> outputSequences[5];

    vector<int> getInputSequenceCopy()
    {
        vector<int> temp = inputSequence;

        return temp;
    }

    vector<int> perturbateBySwap()
    {
        vector<int> outputSequence = getInputSequenceCopy();
    }

    vector<int> perturbateByShift()
    {
        vector<int> outputSequence = getInputSequenceCopy();
    }

    void loadInputSequence(char *fileName)
    {
        ifstream inFile;
        int jobId;

        inFile.open(fileName);
        if (!inFile)
        {
            printf("\nFile opening error: %s\n", fileName);
            exit(0);
        }

        while (inFile >> jobId)
        {
            inputSequence.push_back(jobId);
        }

        inFile.close();
    }

    void saveOutputSequences(){
        ofstream outFile("input/input.dat");

        for(auto i = 0; i < 5; i++){
            vector<int> currentSequence = outputSequences[i];

            for (auto j = currentSequence.begin(); j != currentSequence.end(); j++) {
                outFile << *j << " ";
            }

            outFile << endl;
        }

        outFile.close();
    }

public:
    SequenceGenerator();

    void runEngine(char *fileName)
    {
        loadInputSequence(fileName);

        for(auto i = 0; i < 5; i++){
            vector<int> temp = perturbateByShift();

            outputSequences[i] = temp;
        }

        saveOutputSequences();
    }
};

int main(int argc, char *argv[])
{
    SequenceGenerator sequenceGenerator = SequenceGenerator();

    if (argc > 1)
    {
        sequenceGenerator.runEngine(argv[1]);
    }
    else
    {
        printf("Enter job sequence file name\n");
        exit(0);
    }

    return 0;
}