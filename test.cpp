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
    int y = 2, a, k, N;
    int numb = 0;                                               //счетчик переменных по индексу Y, необходим для исключения N-ых строк
    int countRows = 0;
    string line, pathToFile;
    
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
    
    ifstream inputFile;
    while(true){
        cout << "Enter path to input file" << endl;
        cin >> pathToFile;                                        //ручной ввод пути к файлу
        inputFile.open(pathToFile);
        if(inputFile.is_open()){
            while(!inputFile.eof()){
                getline(inputFile, line);
                countRows++;
            }
            inputFile.close();
            break;
        } else{
            cout<< "Error. File not found> try again" << endl;
        }
    }
    int arr[countRows][y];
    int newArr[countRows][y];
    inputFile.open(pathToFile);
    for(int i = 0; i < countRows; i++){
        for(int j = 0; j < y; j++){
            inputFile >> arr[i][j];
        }
    }
    
    for(int i = 0; i < countRows; i++){
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
        
    while(a < countRows){
        for(int j = 0; j < y; j++){
            newArr[a][j] = 00;
        }
        a++;
        k++;
    }
    
    ofstream resultFile;                                       //вывод в файле результирующего массива данных
    resultFile.open("result.txt", ios_base::out);
    if (resultFile.is_open()){

        for(int i = 0; i < (a - k); i++){
            for(int j = 0; j < y; j++){
                
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

int main(){
    int x;
    bool var = true;
    

    while(var != false){
        cout << "Enter 1 if you want to load data from a file" << endl;
        cout << "Enter 2 if you want to enter the data yourself" << endl;
        cout << "Enter 3 if you save result and close program" << endl;
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
