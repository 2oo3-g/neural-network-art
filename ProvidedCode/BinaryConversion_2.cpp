#include<bits/stdc++.h>
using namespace std;

#define NUMBER_OF_JOBS 20
#define ASH_COLOR 3

class BinaryConvertor {
    private:
        int binaryData[NUMBER_OF_JOBS][NUMBER_OF_JOBS];
        int decimalData[NUMBER_OF_JOBS];

    public:
        BinaryConvertor() {

            for (int i=0; i<NUMBER_OF_JOBS; i++) {
                for (int j=0; j<NUMBER_OF_JOBS; j++) {
                    binaryData[i][j]=0;
                }
                decimalData[i]=0;
            }
        };

        void printBinaryData() {
            cout<<endl<<"Binary Data Start"<<endl;
            for (int i=0; i<NUMBER_OF_JOBS; i++) {
                for (int j=0; j<NUMBER_OF_JOBS; j++) {
                    cout<<binaryData[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"Binary Data End"<<endl;
        }

        void printDecimalData() {
            cout<<endl<<"Decimal Data Start"<<endl;
            for (int i = 0; i < NUMBER_OF_JOBS; i++) {
                cout<<decimalData[i]<<" ";
            }
            cout<<endl<<"Decimal Data End"<<endl;
        }

        void loadDecimalData(int jobs[]) {
            for (int i = 0; i < NUMBER_OF_JOBS; i++) {
                decimalData[i] = jobs[i];
            }
        }

        void convertDecimalToBinaryData() {

            for(int i = 0; i < NUMBER_OF_JOBS; i++) {

                int rowIndex = decimalData[i] - 1;
                for (int j = -ASH_COLOR; j <= ASH_COLOR; j++) {

                    int colIndex = i+j;
                    if(colIndex >=0 && colIndex < NUMBER_OF_JOBS) {
                        binaryData[rowIndex][colIndex] = 1;
                    }
                }
            }
        }

};

int main() {
    BinaryConvertor bc;

    int inputData[] = {16,11,15,4,7,17,19,12,9,19,8,5,1,10,3,6,14,18,2,20};
    bc.loadDecimalData(inputData);;
    bc.convertDecimalToBinaryData();
    bc.printBinaryData();
    return 0;
}


