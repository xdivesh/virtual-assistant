#include <iostream>
#include <windows.h>
#include <string.h>
#include <ctime> // Include time header to use time functions
#include <algorithm> // Include algorithm for string transformation

using namespace std;

// Function to convert string to lower case
string toLower(const string &s) {
    string lowerStr = s;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to wish the user according to the time 
void wishme() {
    // Get current date and time based on your system's time zone
    time_t now = time(0);
    tm *time = localtime(&now);

    if (time->tm_hour < 12) {
        cout << "GOOD MORNING SIR" << endl;
        string phrase = "GOOD MORNING sir";
        string command = "espeak \"" + phrase + "\"";
        const char *charcommand = command.c_str();
        system(charcommand);
    } 
    else if (time->tm_hour >= 12 && time->tm_hour < 16) {
        cout << "GOOD AFTERNOON SIR" << endl;
        string phrase = "GOOD AFTERNOON SIR ";
        string command = "espeak \"" + phrase + "\"";
        const char *charcommand = command.c_str();
        system(charcommand);
    } 
    else {
        cout << "GOOD EVENING SIR" << endl;
        string phrase = "GOOD EVENING SIR";
        string command = "espeak \"" + phrase + "\"";
        const char *charcommand = command.c_str();
        system(charcommand);
    }
}

// Function to display the current date and time
void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The date and time is: " << endl << dt << endl;
}

int main() {
    system("cls"); // Clear the console

    cout << "<---------------------WELCOME------------------------->" << endl;
    cout << "<---------------------I'M A VIRTUAL ASSISTANT------------------------->" << endl;
    cout << "<---------------------MY NAME IS NOBITA------------------------->" << endl;
    cout << "<---------------------I'M HERE TO HELP YOU SIR------------------------->" << endl << endl;

    char password[20]; // to take password 
    char ch[100]; // to take queries/input from user 

    // Declare startinfo and processinfo variables here
    STARTUPINFO startinfo = {0};
    PROCESS_INFORMATION processinfo = {0};
    startinfo.cb = sizeof(startinfo); // Initialize STARTUPINFO struct

    // Password authentication
    do {
        cout << "***********************************" << endl;
        cout << " ENTER YOUR PASSWORD " << endl;
        cout << "***********************************" << endl << endl;

        string phrase = "enter your password";
        string command = "espeak \"" + phrase + "\"";
        const char *charcommand = command.c_str();
        system(charcommand);

        cin.getline(password, 20); // Take password input safely

        if (strcmp(password, "devesh") == 0) {
            cout << "------------------------------------" << endl;
            wishme(); // Greet the user based on the time
            break; // Exit loop when correct password is entered
        } 
        else {
            cout << "Incorrect password. Please try again." << endl;
            string phrase = "Incorrect password";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
        }
    } while (1); // Infinite loop until correct password is entered

    // Handle user queries
    do {
        cout << "\n=================================";
        cout << endl << "How can I help you sir..." << endl;
        string phrase = "how can i help you sir..";
        string command = "espeak \"" + phrase + "\"";
        const char *charcommand = command.c_str();
        system(charcommand);

        cout << "Your query ===> ";
        cin.getline(ch, 100); // Get user input
        cout << endl;

        cout << "Here is the result of your query ===> ";

        // Convert input to lower case for easier comparison
        string input = toLower(ch);

        // Query handling logic
        if (input == "hi" || input == "hey" || input == "hello") {
            cout << "Hello sir, how can I assist you?" << endl;
            string phrase = "hello, sir how can I assist you.";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
        } 
        else if (input == "bye" || input == "stop" || input == "exit") {
            cout << "Thanks for choosing me, sir. I am glad to help you." << endl;
            string phrase = "Thanks for choosing me, sir I am glad to help you.";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
            break; // Exit loop when user says bye or stop
        } 
        else if (input == "who are you" || input == "your name" || input == "about yourself") {
            cout << "Thanks for asking sir, I am Nobita, a virtual assistant created by Devesh." << endl;
            string phrase = "Thanks for asking sir, I am Nobita, a virtual assistant created by Devesh.";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
        } 
        else if (input == "how are you" || input == "whatsupp" || input == "hows your day") {
            cout << "Thanks for asking sir, I am good. Please tell me how can I help you?" << endl;
            string phrase = "Thanks for asking sir, I am good. Please tell me how can I help you?";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
        } 
        else if (input == "date" || input == "time") {
            // Calling function to show time and date
            datetime();
        } 
        else if (input == "open notepad") {
            cout << "opening notepad....." << endl;
            string phrase = "opening notepad..... ";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);

            // Correcting CreateProcess syntax
            if (!CreateProcess(TEXT("C:\\windows\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startinfo, &processinfo)) {
                cout << "Failed to open Notepad." << endl;
                string phrase = "Failed to open Notepad.";
                string command = "espeak \"" + phrase + "\"";
                const char *charcommand = command.c_str();
                system(charcommand);
            }
        } 
        else if (input == "open youtube") {
            cout << "opening YouTube sir," << endl;
            string phrase = "opening YouTube sir, ";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
            system("start https://www.youtube.com");
        } 
        else if (input == "open instagram") {
            cout << "opening Instagram sir," << endl;
            string phrase = "opening Instagram sir, ";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
            system("start https://www.instagram.com");
        } 
        else if (input == "open facebook") {
            cout << "opening Facebook sir," << endl;
            string phrase = "opening Facebook sir, ";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
            system("start https://www.facebook.com");
        } 
        else if (input == "open whatsapp") {
            cout << "opening WhatsApp sir," << endl;
            string phrase = "opening WhatsApp sir, ";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
            system("start https://www.whatsapp.com");
        } 
        else {
            cout << "Sorry sir, I am unable to understand your query. I will try to find more information for you." << endl;
            string phrase = "Sorry sir, I am unable to understand your query. I will try to find more information for you.";
            string command = "espeak \"" + phrase + "\"";
            const char *charcommand = command.c_str();
            system(charcommand);
        }
    } while (1); // Keep looping until user exits

    return 0;
}
