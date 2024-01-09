#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;
#include "linkedlist.h"
#include "ArgumentManager.h"

int main(int argc, char* argv[]){

    ArgumentManager am(argc, argv);

    string input = am.get("input");
    string command = am.get("command");
    string output = am.get("output");

    ofstream fout(output);
    ifstream fin(input);
    ifstream com(command);


    if(!fin.is_open()){
        cout << "File Not Found!" << endl;
        return -1;
    }

    string attributes;
    string name;
    int age;
    int deposit;
    int drinks;

    list link;

    while(getline(fin, attributes)){

        attributes.erase(remove(attributes.begin(), attributes.end(), '\n'), attributes.end());
        attributes.erase(remove(attributes.begin(), attributes.end(), '\r'), attributes.end());

        if(attributes.empty()){
            continue;
        }
        
        istringstream ins(attributes);
        ins >> name >> age >> deposit >> drinks;

        name = attributes.substr(7, attributes.find(';') - 7);

        attributes = attributes.substr(attributes.find(';') + 2);

        age = stoi(attributes.substr(5, attributes.find(';') - 5));
        attributes = attributes.substr(attributes.find(';') + 2);

        deposit = stoi(attributes.substr(9, attributes.find(';') - 9));
        attributes = attributes.substr(attributes.find(';') + 2);

        drinks = stoi(attributes.substr(18, attributes.find(']') - 18));

        link.insertAtEnd(name, age, deposit, drinks);
    }

    //link.print2();
    //part 2 command files

    com.open("command3.txt");

    if(!com.is_open()){
        cout << "File Not Found!" << endl;
        return -1;
    }

    string data;
    string function;
    

    while(getline(com, data)){

        data.erase(remove(data.begin(), data.end(), '\n'), data.end());
        data.erase(remove(data.begin(), data.end(), '\r'), data.end());

        if(data.empty()){
            continue;
        }
        
        istringstream comins(data);
        comins >> function;

        if(function == "Add"){
            string tempIndex;
            comins >> tempIndex;
            tempIndex.erase(remove(tempIndex.begin(), tempIndex.end(), '('), tempIndex.end());
            tempIndex.erase(remove(tempIndex.begin(), tempIndex.end(), ')'), tempIndex.end());
            string comAttributes;
            string comName;
            int comAge;
            int comDeposit;
            int comDrinks;

            getline(comins, comAttributes);
            comAttributes.erase(0, 1);
            
            comName = comAttributes.substr(7, comAttributes.find(';') - 7);

            comAttributes = comAttributes.substr(comAttributes.find(';') + 2);
            
            comAge = stoi(comAttributes.substr(5, comAttributes.find(';') - 5));
            comAttributes = comAttributes.substr(comAttributes.find(';') + 2);

            comDeposit = stoi(comAttributes.substr(9, comAttributes.find(';') - 9));
            comAttributes = comAttributes.substr(comAttributes.find(';') + 2);

            comDrinks = stoi(comAttributes.substr(18, comAttributes.find(']') - 18));

            int index = stoi(tempIndex);
            link.insertAtPosition(comName, comAge, comDeposit, comDrinks, index);

            
        }
        else if(function == "Remove"){

            string line;
            string attribute;
            string attributeVal;

            getline(comins,line);
            
            line.erase(0, 1);
            line.erase(remove(line.begin(), line.end(), '('), line.end());
            line.erase(remove(line.begin(), line.end(), ')'), line.end());

            attribute = line.substr(0, line.find(':'));

            if(attribute == "number of drinks"){
                attributeVal = line.substr(line.find(':') + 2);
                attribute = "drinks";
                
                link.remove(attribute, attributeVal);
                //link.print2();
            }
            else if(attribute == "age"){

                attributeVal = line.substr(line.find(':') + 2);
                link.remove(attribute, attributeVal);


            }
            else if(attribute == "deposit"){

                attributeVal = line.substr(line.find(':') + 2);
                link.remove(attribute, attributeVal);
                

            }
            else if(attribute == "name"){
                attributeVal = line.substr(line.find(':') + 2);
                link.remove(attribute, attributeVal);
            }

        }
        else if(function == "Sort"){
            string sortCommand;
            comins >> sortCommand;

            sortCommand.erase(remove(sortCommand.begin(), sortCommand.end(), '\n'), sortCommand.end());
            sortCommand.erase(remove(sortCommand.begin(), sortCommand.end(), '\r'), sortCommand.end());

            sortCommand.erase(0, 1);
            sortCommand.erase(remove(sortCommand.begin(), sortCommand.end(), '('), sortCommand.end());
            sortCommand.erase(remove(sortCommand.begin(), sortCommand.end(), ')'), sortCommand.end());
            
            if(sortCommand == "name"){
                link.sortName();
            }
            else if(sortCommand == "age"){
                link.sortAge();
            }
            else if(sortCommand == "deposit"){
                link.sortDeposit();
            }
            else if(sortCommand == "number of drinks"){
                link.sortDrinks();
            }


        }
        
    }
   
    link.print(fout);
    //link.print2();


    return 0;

}