#include <iostream>
#include <fstream>

using namespace std;


void createArr(){
    int x, y = 2, a, k = 0, N;
    int numb = 0;                                               //счетчик переменных по индексу Y, необходим для исключения N-ых строк
    a = 0;

    cout << "Enter rows: ";
    while(true){
        cin >> x;
        if(cin.fail()) {                                        //проверка ввода числового значения
            cin.clear();
            cin.ignore();
            cout << "Not num" << endl;
            cout << "Enter rows: ";
        } else {
            break;
        }
    }

    cout << "Enter N: ";
    while(true){
        cin >> N;
        if(N >= 2){//параметр для исключения каждой N-ой строки
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Not num" << endl;
                cout << "Enter N: ";
            } else {
                break;
            }
        } else{
            cin.clear();
            cin.ignore();
            cout << "N must be > 2" << endl;
            cout << "Enter N: ";
        }
    }

    int arr[x][y];                                              //основной массив
    int newArr[x][y];                                           //результирующий массив

    for(int i = 0; i < x; i++){
        for(int j = 0; j< y; j++){

            cout << "Enter element with index " << i << " " << j << ": ";
            while(true){
                cin >> arr[i][j];
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Not num" << endl;
                    cout << "Enter element with index " << i << " " << j << ": ";
                } else {
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < x; i++){
        if(arr[i][1] == arr[i+1][1]){
            if(numb == (N - 1)){
               cout << "Row " << i+1 << " is deleted" << endl;
            } else{
                newArr[a][0] = arr[i][0];
                newArr[a][1] = arr[i][1];
                a++;
            }
            numb++;
            } else{
                numb = 0;
                newArr[a][0] = arr[i][0];
                newArr[a][1] = arr[i][1];
                a++;
            }
        }
    
    while(a < x){
        for(int j = 0; j < y; j++){
            newArr[a][j] = 00;
        }
        a++;
        k++;
    }

    ofstream inputFile;                                       //вывод в файле входного массива данных
    inputFile.open("input.txt", ios_base::out);
    if (inputFile.is_open()){

        for(int i = 0; i < x; i++){
            for(int j = 0; j< y; j++){
                
                if(j == 1){
                    inputFile << arr[i][j] << endl;
                } else {
                    inputFile << arr[i][j] << " ";
                }
            }
        }
    }
    inputFile.close();

    ofstream resultFile;                                       //вывод в файле результирующего массива данных
    resultFile.open("result.txt", ios_base::out);
    if (resultFile.is_open()){

        for(int i = 0; i < (a - k); i++){
            for(int j = 0; j< y; j++){
                
                if(j == 1){
                    resultFile << newArr[i][j] << endl;
                } else {
                    resultFile << newArr[i][j] << " ";
                }
            }
        }
    }
    resultFile.close();
}

void readArr(){
    bool var = true;
    int coutRows = 0;
    string line, pathToFile;
    
    ifstream inputFile;
    while(true){
        cout << "Enter path to input file" << endl;
        cin >> pathToFile;                                        //ручной ввод пути к файлу
        inputFile.open(pathToFile);
        if(inputFile.is_open()){
            while(!inputFile.eof()){
                getline(inputFile, line);
                cout<< line << endl;
                coutRows++;
            }
            inputFile.close();
            int arr[coutRows][2];
            break;
        } else{
            cout<< "Error. File not found> try again" << endl;
        }
    }
    
}

int main(){
    int x;
    bool var = true;
    

    while(var != false){
        cout << "Enter 1 if you want to load data from a file" << endl;
        cout << "Enter 2 if you want to enter the data yourself" << endl;
        cout << "Enter 3 if you want close this program" << endl;
        cin >> x;
        switch(x){
            case 1:{
                readArr();
                break;
            }
            case 2:{
                createArr();
                break;
            }
            case 3:{
                var = false;
                break;
            }
            break;
        }
    }
    return 0;
}
