//Библюотеките нужни за изпълнение на кода
#include <iostream>
#include <fstream>

//Използван namespace
using namespace std;

int main() {
    //Дължината на масива
    int arrayLength;
    //Тригер за while loop
    bool isReady = false;
    //Дефиниране на масива
    int arr[arrayLength];
    
    //Цикълът ще се извършва докато валидацията не премине успешно
    while (!isReady) {
        //Принтиране в конзолата
        cout<<"Въведи число от 5 - 50: ";
        //Взима се числото (дължината на масива) подадено от потребителя
        scanf ("%d",&arrayLength);
        
        //Проверка/Валидация на input-ите на потребителя
        if(arrayLength < 5){
            cout<<"Съжелявам, числото трябва да е повече от 5.\n";
            continue;
        } else if(arrayLength > 50){
            cout<<"Съжелявам, числото трябва да е по-малко от 50.\n";
            continue;
        }
        
    
        /*
            - АЛГОРИТЪМ - за умножение на индексите в масива
            Преминаване през масива като се умножи всеки един от индексите по 2
        */
        for (int i = 0; i < arrayLength; i++) {
            int number;
            cout<<"Въведете елемент #" << (i + 1) << ": ";
            scanf ("%d",&number);
            arr[i] = number * i; 
        }
        
        //Създаване на файла
        ofstream myfile ("arrayOfmultipliedNumbers.txt");
    
        /*
            - АЛГОРИТЪМ - за записване на масива във файл
            Проверка/Валидация ако файлът е създаден успешно
        */
        if (myfile.is_open()){
            //Записване на първия ред
            myfile << "Умножениете числа от масива са.\n";
            //Записване на втория ред и масива във формат
            myfile << "int arr[" << arrayLength << "] = {";
            for (int i = 0; i < arrayLength; i++) {
                int l = arr[arrayLength - 1]; 
                if(arr[i] != l){
                    myfile << arr[i] << ", ";
                } else {
                    myfile << arr[i];
                }
            }
            myfile << "}";
            //Затваряне на метода викнат от stream-a
            myfile.close();
        } else {
            cout << "Неуспешно записване на масива.";
        }
    
        //Излиза от цикъла като сменя тригера с true
        isReady = true;
    }
    return 0;
}
