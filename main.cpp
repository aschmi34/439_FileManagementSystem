#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "Welcome to File Management System Simulation. "
            "Enter a command or enter 'help' to see a list of commands." << std::endl;

    string command, name, oldName, newName;
    //cout << "Type your command: ";
    cout << ">> ";
    getline (cin, command); // get user input from the keyboard
    //cout << "Your command is: " << command;

    while (command != "exit"/* && command != "change to from"*/){
        if (command == "help"){
            cout << "\nhelp: display a list of possible commands\n"
                    "currentdir: display name of the current directory\n"
                    "moveup: move up one directory\n"
                    "changedir DIRNAME: move into another directory if it is inside current directory\n"
                    "newfile FILENAME / newdir DIRNAME: creates a new file or directory\n"
                    "delfile FILENAME / deldir DIRNAME: deletes the specified name or directory\n"
                    "renamefile FILENAME NEWNAME / renamedir DIRNAME NEWNAME: renames spedified file or directory to NEWNAME\n"
                    "list: lists all files and directories in current directory\n"
                    "exit: ends program\n\n";
        }
        else if (command == "currentdir"){
            cout << "currentdir method\n";
        }
        else if (command == "moveup"){
            cout << "moveup method\n";
        }
        else if (command == "list"){
            cout << "list method\n";
        }
        else {
            string space_delimiter = " ";
            vector<string> words{};

            size_t pos = 0;
            while ((pos = command.find(space_delimiter)) != string::npos) {
                words.push_back(command.substr(0, pos));
                command.erase(0, pos + space_delimiter.length());
            }
            words.push_back(command.substr(0, pos));

//            for (const auto &str : words) {
//                cout << str << endl;
//            }

            if (words[0] == "changedir"){
                cout << "changedir method\n";
//                cout << words[1];
            }
            else if (words[0] == "newfile"){
                cout << "newfile method\n";
            }
            else if (words[0] == "newdir"){
                cout << "newdir method\n";
            }
            else if (words[0] == "delfile"){
                cout << "delfile method\n";
            }
            else if (words[0] == "deldir"){
                cout << "deldir method\n";
            }
            else if (words[0] == "renamefile"){
                cout << "renamefile method\n";
            }
            else if (words[0] == "renamedir"){
                cout << "renamedir method\n";
            }
            else {
                cout << "Invalid command. Type 'help' for list of commands.\n";
            }//Invalid input
        }
        //cout << "Type your command: ";
        cout << ">> " ;
        getline (cin, command); // get user input from the keyboard
        //cout << "Your command is: " << command;
    }
//
//    string space_delimiter = " ";
//    vector<string> words{};
//
//    size_t pos = 0;
//    while ((pos = command.find(space_delimiter)) != string::npos) {
//        words.push_back(command.substr(0, pos));
//        command.erase(0, pos + space_delimiter.length());
//    }
//    words.push_back(command.substr(0, pos));
//
//    for (const auto &str : words) {
//        cout << str << endl;
//    }


    cout << "\nGoodbye:)";
    return 0;

}


