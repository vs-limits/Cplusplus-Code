#include<iostream>
using namespace std;

class SeqList {
private:
    int* array; 
    int size; 
    int maxsize;
public:
    SeqList(int n) {
        size = 2 * n;
        maxsize = 1000;
        array = new int[maxsize];
        for (int i = 0; i < size; i++) {
            cin >> array[i];
        }
    }

    ~SeqList() {
        delete[] array;
    }

    SeqList add(SeqList& seq) {
        int* tempArray = new int[maxsize];
        int t_size = 0;

        int i = 0, j = 0;

        while (i < size && j < seq.size) {
            int coef1 = array[i];  
            int exp1 = array[i + 1];
            int coef2 = seq.array[j];  
            int exp2 = seq.array[j + 1]; 

            if (exp1 == exp2) {
                int sumCoef = coef1 + coef2;
                if (sumCoef != 0) {
                    tempArray[t_size++] = sumCoef;
                    tempArray[t_size++] = exp1;
                }
                i += 2;
                j += 2;
            }
            else if (exp1 < exp2) {
                tempArray[t_size++] = coef1;
                tempArray[t_size++] = exp1;
                i += 2;
            }
            else {
                tempArray[t_size++] = coef2;
                tempArray[t_size++] = exp2;
                j += 2;
            }
        }
        while (i < size) {
            tempArray[t_size++] = array[i++];
            tempArray[t_size++] = array[i++];
        }

        while (j < seq.size) {
            tempArray[t_size++] = seq.array[j++];
            tempArray[t_size++] = seq.array[j++];
        }

        SeqList result(0);
        delete[] result.array;
        result.array = tempArray;
        result.size = t_size;
        return result;
    }

    void print() {
        if (size == 0) {
            cout << "0" << endl;
            return;
        }

        for (int i = 0; i < size; i += 2) {
            int coef = array[i];
            int exp = array[i + 1];

            if (i != 0 && coef != 0) {
                cout << " + ";
            }
            /*else if (coef < 0) {
                cout << " ";
            }*/

            if (exp == 0) {
                if(coef < 0 && coef != 0) cout << "(" << coef << ")";
				else if(coef > 0 && coef != 0) cout << coef;
            }
            else if (exp < 0 && coef < 0) {
				cout << "(" << coef << ")x^(" << exp << ")";
			}
            else if (exp < 0 && coef > 0) {
				cout << coef << "x^(" << exp << ")";
            }
            else if (exp > 0 && coef < 0) {
				cout << "(" << coef << ")x^" << exp;
			}
            else if (exp > 0 && coef > 0) {
				cout << coef << "x^" << exp;
            }
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        SeqList seq1(n);
        seq1.print();

        cin >> n;
        SeqList seq2(n);
        seq2.print();

        SeqList sum = seq1.add(seq2);
        sum.print();
    }
    return 0;
}