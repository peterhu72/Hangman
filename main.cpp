#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

void display_word(vector<char> found_words, string curr_word, unsigned int& curr_length){
    // Displays _ if word not in found_words, displays letter otherwise
    for (unsigned int i = 0; i < curr_word.length(); i++){
        if (find(found_words.begin(), found_words.end(), curr_word[i]) != found_words.end()){
            cout << curr_word[i] << " ";
            curr_length--;
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

unsigned int get_rand(unsigned int num){
    // Get random num that isn't the current num
    unsigned int random_num = rand() % 10;
    if (random_num == num){
        return get_rand(num);
    }
    return random_num;
}

void gallows(unsigned int guesses){
    if (guesses == 1){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|      "<< endl;
        cout << "|      "<< endl;
        cout << "_________"<< endl;
    }
    if (guesses == 2){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|   |"<< endl;
        cout << "|      "<< endl;
        cout << "_________"<< endl;
    }
    if (guesses == 3){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|  \\|"<< endl;
        cout << "|     "<< endl;
        cout << "_________"<< endl;
    }
    if (guesses == 4){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|  \\|/"<< endl;
        cout << "|     "<< endl;
        cout << "_________"<< endl;
    }
    if (guesses == 5){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|  \\|/"<< endl;
        cout << "|  /"<< endl;
        cout << "_________"<< endl;
    }
    if (guesses == 6){
        cout << "-----"<< endl;
        cout << "|   |"<< endl;
        cout << "|   o"<< endl;
        cout << "|  \\|/"<< endl;
        cout << "|  / \\ "<< endl;
        cout << "_________"<< endl;
    }
}

int main() {
    bool gamestate = true;

    srand(time(0));
    unsigned int random_num = rand() % 10;

    vector<string> words{"tiger","april","interesting","tooth","ape","zygote","mine","guess","hangman","pencil"};
    vector<char> found_chars;
    string curr_word = words.at(random_num);

    unsigned int curr_length = curr_word.length();
    unsigned int temp_length = curr_length;
    unsigned int correct_guesses = 0;
    unsigned int incorrect_guesses = 0;

    char temp_word;
    string keep_playing;


    cout << "Welcome to Hangman!!!\n*********************" << endl;

    while (gamestate){
        if (temp_length == curr_length){
            cout << "There are " << curr_length << " letters in the word!" << endl;
        }
        cout << "Guess a letter: ";
        cin >> temp_word;
        if (curr_word.find(temp_word) != std::string::npos){
            correct_guesses++;
            found_chars.push_back(temp_word);
            curr_length = curr_word.length();
            display_word(found_chars, curr_word, curr_length);

            cout << "You have " << incorrect_guesses + correct_guesses << " guesse(s)." << endl;
            cout << incorrect_guesses << " are incorrect and " << correct_guesses << " are correct" << endl;
        }
        else {
            incorrect_guesses++;
            gallows(incorrect_guesses);
            curr_length = curr_word.length();
            display_word(found_chars, curr_word, curr_length);

            cout << "You have " << incorrect_guesses + correct_guesses << " guesse(s)." << endl;
            cout << incorrect_guesses << " are incorrect and " << correct_guesses << " are correct" << endl;
        }
        if (curr_length == 0) {
            cout << "Congratulations, you guessed the word correctly!" << endl;
            cout << "Do you want to keep playing? (Y/N)" << endl;
            cin >> keep_playing;
            if (keep_playing == "Y"){
                incorrect_guesses = 0;
                correct_guesses = 0;

                found_chars.clear();

                random_num = get_rand(random_num);
                curr_word = words.at(random_num);
                curr_length = curr_word.length();
            }
            else {
                cout << "Thank you for playing!" << endl;
                gamestate = false;
            }
        }
        if (incorrect_guesses == 6){
            cout << "Too bad, you lose." << endl;
            gamestate = false;
        }

    }




    return 0;
}
