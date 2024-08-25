#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cctype>
using namespace std;
int main()
{
    const int MAX_WRONG = 8;
    vector<string>words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    cout << "Welcome!\n";
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "You have " << (MAX_WRONG-wrong) << " incorrect answers\n";
        cout << used << endl;
        cout << soFar << endl;
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess);
        while (used.find(guess) != string::npos)
        {
            cout << "You already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used+=guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right " << guess << " in word";
            for (int i = 0; i < THE_WORD.size(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, but " << guess << " not in word\n";
            ++wrong;
        }
    }
    if (wrong == MAX_WRONG)
        {
            cout << "You lose!!" << endl;
        }
    else
    {
        cout << "You win!" << endl;
    }
    cout << THE_WORD << " is answer" << endl;
    return 0;
}