#include <iostream>
#include "ToDoList.h"
#include "ToDo.h"

int main() {
    ToDoList newList;

    bool stop = false;
    int option;
    std::cout << "**************** Welcome To my Todo List! ******************" << std::endl;
    std::cout << "List of options: " << std::endl;
    std::cout << "1) Create your new TodoList " << std::endl;
    std::cout << "2) Add a new Todo " << std::endl;
    std::cout << "3) Remove a Todo " << std::endl;
    std::cout << "4) Modify a Todo " << std::endl;
    std::cout << "5) Set completed a Todo " << std::endl;
    std::cout << "6) Display your uncompleted todos in a ToDoList " << std::endl;
    std::cout << "7) Display all your todos in a ToDoList " << std::endl;
    std::cout << "************************************************************" << std::endl;

    do {
        std::cout << "Choose Your option(press 0 to exit): ";
        std::cin >> option;

        Date date;
        std::string title;
        std::string description;
        std::string newDescription;
        char choice;
        int day, month, year;


        switch (option) {
            case 0:
                stop = true;
                std::cout << "Goodbye!" << std::endl;
                break;
            case 1:
                std::cout << "Please enter the name of the todolist: ";
                std::cin >> title;
                newList = ToDoList(title);
                break;
            case 2:
                std::cout << "Please enter the description of the todo: ";
                std::cin >> description;
                std::cout << "Then enter the due date(in dd mm yy format): ";
                std::cin >> day >> month >> year;
                date = Date(day, month, year);
                newList.addToDo(ToDo(date, description));
                break;
            case 3:
                std::cout << "Please enter the description of the todo you want to remove: ";
                std::cin >> description;
                newList.removeTodo(description);
                break;
            case 4:
                std::cout << "Please enter the description of the todo you want to modify: ";
                std::cin >> description;
                std::cout << "What do you want to modify?(Enter d for description, g for date or c for completed): ";
                std::cin >> choice;
                if (choice == 'd') {
                    std::cout << "Then please enter your new description: ";
                    std::cin >> newDescription;
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
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                std::cout << "Please enter a option on the list of options!" << std::endl;

        }
    } while (!stop);

    return 0;
}
