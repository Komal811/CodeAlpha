#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string taskName;
    bool completed;

    Task(const string& name) : taskName(name), completed(false) {}
};

class ToDoListApp {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskName) {
        if (taskName.empty()) {
            cout << "Task cannot be empty." << endl;
            return;
        }
        tasks.emplace_back(taskName);
        cout << "Task '" << taskName << "' added successfully!" << endl;
    }

    void markCompleted(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        Task& task = tasks[taskNumber - 1];
        if (task.completed) {
            cout << "Task '" << task.taskName << "' is already marked as completed." << endl;
        } else {
            task.completed = true;
            cout << "Task '" << task.taskName << "' marked as completed!" << endl;
        }
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "\nCurrent Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            string status = task.completed ? "[Completed]" : "[Pending]";
            cout << i + 1 << ". " << task.taskName << " " << status << endl;
        }
    }

    void run() {
        while (true) {
            cout << "\n--- To-Do List Application ---" << endl;
            cout << "1. Add Task" << endl;
            cout << "2. Mark Task as Completed" << endl;
            cout << "3. View all Tasks" << endl;
            cout << "4. Exit" << endl;

            cout << endl;

            int choice;
            cout << "Select an option: ";
            cin >> choice;
            cin.ignore(); // Clear the input buffer

            switch (choice) {
                case 1: {
                    string taskName;
                    cout << "Enter the Task Name: ";
                    getline(cin, taskName);
                    addTask(taskName);
                    break;
                }
                case 2: {
                    int taskNumber;
                    cout << "Enter task number to mark as completed: ";
                    cin >> taskNumber;
                    markCompleted(taskNumber);
                    break;
                }
                case 3:
                    viewTasks();
                    break;
                case 4:
                    cout << "Exiting the application. Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
    }
};

int main() {
    ToDoListApp app;
    app.run();
    return 0;
}

