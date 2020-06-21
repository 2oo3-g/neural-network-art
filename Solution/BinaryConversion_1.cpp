#include<bits/stdc++.h>
using namespace std;

#define NUMBER_OF_JOBS 10

class BinaryConvertor {
    private:
        bool binaryData[NUMBER_OF_JOBS][NUMBER_OF_JOBS];
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
            cout<<endl<<"Binary Output"<<endl;
            for (int i=0; i<NUMBER_OF_JOBS; i++) {
                for (int j=0; j<NUMBER_OF_JOBS; j++) {
                    cout<<binaryData[i][j];
                }
            }
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
            int single_bit = 1;
            int decimal_to_be_converted = 0;
            for(int row = 0; row < NUMBER_OF_JOBS; row++) {
                single_bit = 1;
                decimal_to_be_converted = decimalData[row];
                for (int column = 0; column < NUMBER_OF_JOBS; column++)
                {
                    binaryData[column][row] = ((decimal_to_be_converted & single_bit)?1:0);
                    single_bit = single_bit<<1;
                }
            }
        }

};

int main() {
    BinaryConvertor bc;
    int inputData[] = {10,8,4,5,2,3,1,6,9,7};
    bc.loadDecimalData(inputData);
    // bc.printDecimalData();
    bc.convertDecimalToBinaryData();
    bc.printBinaryData();
    // Output 
    // 0001011011100011010100110001011100000010000000000000000000000000000000000000000000000000000000000000
    // Expected
    // 000101101110001101010011000101...............................0
    return 0;
}