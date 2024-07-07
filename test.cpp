#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


void createArr(){
    int x, y, a, N;
    int numb = 0;                                               //счетчик переменных по индексу Y, необходим для исключения N-ых строк
    a = 0;

    cout << "Enter rows: ";
    while(true){
        cin >> x;
        if(cin.fail()) {                                        //проверка ввода числового значения
            cin.clear();
            cin.ignore();
            cout << "Not num" << std::endl;
        } else {
            std::cout << "done! num is: " << x << std::endl;
            break;
        }
    }
    cout << "Enter columns: ";
    while(true){
        cin >> y;
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Not num" << std::endl;
        } else {
            std::cout << "done! num is: " << y << std::endl;
            break;
        }
    }
    cout << "Enter N: ";
    while(true){
        cin >> N;                                               //параметр для исключения каждой N-ой строки
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Not num" << std::endl;
        } else {
            std::cout << "done! num is: " << N << std::endl;
            break;
        }
    }

    int arr[x][y];                                              //основной массив
    int newArr[x][y];                                           //отсортированный массив

    for(int i = 0; i < x; i++){
        for(int j = 0; j< y; j++){

            cout << "Enter element " << i << " " << j << ": ";
            while(true){
                cin >> arr[i][j];
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Not num" << std::endl;
                } else {
                    std::cout << "done! num is: " << arr[i][j] << std::endl;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < x; i++){
        if(arr[i][1] == arr[i+1][1]){
            if(numb == (N - 1)){
               cout << "Row " << i << " is deleted" << endl;
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

    cout << " \n";
    cout << "it's old array:\n";
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            
            if(j < 1){
                cout << arr[i][j] << " ";
            } else{
                cout << arr[i][j] << "\n";
            }
            
        }
    }

    cout << " \n";
    cout << "it's new array:\n";
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){

            if(j < 1){
                cout << newArr[i][j] << " ";
            } else{
                cout << newArr[i][j] << "\n";
            }
        }
    }
}
/*
void readArr(){
    string filename;
    // Имя файла
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream mFile (filename);

    int rows = 0, cols = 0;
    if (mFile.is_open()) {
        while (!mFile.eof()) {
            string line;
            getline(mFile, line);

            // Разбиваем строку на элементы массива
            vector<string> elements = split(line, ' ');

            rows += 1;
            cols = max(cols, elements.size());
        }
    }
    mFile.close();

    cout << "Количество строк: " << rows << endl;
    cout << "Количество столбцов: " << cols << endl;

    const int row = 5, column = 7;
    int array[row][column];
    ifstream f("input.txt");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
           f >> array[i][j];
           cout << array[i][j] << endl;
        }
    }
}*/

int main(){

    createArr();

    return 0;
}