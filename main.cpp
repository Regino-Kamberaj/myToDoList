#include <iostream>
#include "ToDoList.h"
#include "ToDo.h"

int main() {
    ToDoList newList;
    bool stop = false;
    int option;

    std::cout << std::endl;
    std::cout << "**************** Welcome To my Todo List! ******************" << std::endl;
    std::cout << "\nList of options: " << std::endl;
    std::cout << "1) Enter the title for your todolist " << std::endl;
    std::cout << "2) Add a new Todo " << std::endl;
    std::cout << "3) Remove a Todo " << std::endl;
    std::cout << "4) Modify a Todo " << std::endl;
    std::cout << "5) Set completed a Todo " << std::endl;
    std::cout << "6) Display your uncompleted todos" << std::endl;
    std::cout << "7) Display all your todos " << std::endl;
    std::cout << "8) Save your todos in a file" << std::endl;
    std::cout << "9) Upload your todos from a file" << std::endl;

    do {
        std::cout << "\n************************************************************" << std::endl;
        std::cout << "\nChoose Your option(press 0 to exit): ";
        std::cin >> option;

        Date date;
        std::string title;
        std::string description;
        std::string newDescription;
        std::string fileName;
        char choice;
        int day, month, year;


        switch (option) {
            case 0:
                stop = true;
                std::cout << "\n************************************************************" << std::endl;
                std::cout << "\nThank you for using my application...\nGoodbye!" << std::endl;
                std::cout << "\n************************************************************" << std::endl;

                break;
            case 1:
                std::cout << "Please enter the name of the todolist: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                newList.setTitle(title);
                break;
            case 2:
                std::cout << "Please enter the description of the todo: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Then enter the due date(in dd mm yy format): ";
                std::cin >> day >> month >> year;
                date = Date(day, month, year);
                newList.addToDo(ToDo(date, description));
                break;
            case 3:
                std::cout << "Please enter the description of the todo you want to remove: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                newList.removeTodo(description);
                break;
            case 4:
                std::cout << "Please enter the description of the todo you want to modify: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "What do you want to modify?(Enter d for description, g for date or c for completed): ";
                std::cin >> choice;
                if (choice == 'd') {
                    std::cout << "Then please enter your new description: ";
                    std::cin.ignore();
                    std::getline(std::cin, newDescription);
                    newList.modifyTodo(description, newDescription, date);
                } else if (choice == 'g') {
                    std::cout << "Then enter the new date(in dd mm yy format): ";
                    std::cin >> day >> month >> year;
                    date = Date(day, month, year);
                    newList.modifyTodo(description, newDescription, date);
                } else if (choice == 'c')
                    newList.modifyTodo(description, newDescription, date);
                else
                    std::cout << "Sorry you did not enter a right option..." << std::endl;
                break;
            case 5:
                std::cout << "Please enter the description of the todo you want to be completed: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                newList.setTodoCompleted(description);
                break;
            case 6:
                newList.displayUncompletedToDos();
                break;
            case 7:
                newList.displayAllToDos();
                break;
            case 8:
                newList.saveToFile(newList.getTitle() + ".txt");
                std::cout << "Your file has been successfully saved!" << std::endl;
                break;
            case 9:
                std::cout << "Please enter the name of the file:";
                std::cin.ignore();
                std::getline(std::cin, fileName);
                ToDoList::loadFromFile(fileName, newList);
                std::cout << "Your file has been successfully loaded!" << std::endl;
                break;
            default:
                std::cout << "Please enter a option on the list of options!" << std::endl;
        }
    } while (!stop);

    return 0;
}
