#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check_win(vector<char> tic, char Alpha)
{
    int win = 0;
    if (tic[0] == Alpha && tic[1] == Alpha && tic[2] == Alpha ||
        tic[0] == Alpha && tic[4] == Alpha && tic[8] == Alpha ||
        tic[0] == Alpha && tic[3] == Alpha && tic[6] == Alpha ||
        tic[1] == Alpha && tic[4] == Alpha && tic[7] == Alpha ||
        tic[2] == Alpha && tic[4] == Alpha && tic[6] == Alpha ||
        tic[2] == Alpha && tic[5] == Alpha && tic[8] == Alpha ||
        tic[3] == Alpha && tic[4] == Alpha && tic[5] == Alpha ||
        tic[6] == Alpha && tic[7] == Alpha && tic[8] == Alpha)
    {
        std::cout << "PLAYER WITH '" << Alpha << "' WON THE GAME \n";
        win = 1;
    }
    return win;
}

void end_of_game()
{
    std::cout << "\nTHANKS FOR WITH US , HOPE YOU ENJOYED COME BACK SOON";
}

int index_is_free(vector<char> &tic, int index, char Alpha)
{
    int count = 0;
    if (tic[index - 1] == '_')
    {
        tic[index - 1] = Alpha;
        count = 1;
    }
    else
        std::cout << "\nOOPS YOU MADE A MISTAKE THIS INDEX IS ALREADY OCCUPY PLEASE TRY AGAIN\t\n";
    return count;
}

void show(vector<char> tic)
{
    int count = 0;
    std::cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "_" << tic[count] << "_  ";
            count++;
        }
        std::cout << endl;
    }
    std::cout << endl;
}

int want_to_play_or_not()
{
    int want_to_play = 1;
    do
    {
        if (want_to_play == 1 || want_to_play == 0)
        {
            cout << "WANT TO PLAY AGAIN??\t";
            cout << "\nIF YES PRESS 1 ELSE 0:\t";
            cin >> want_to_play;
        }
        else
        {
            cout << "OOPS WRONG CHOICE PLZ SELECT \"1\" OR \"0\":  ";
            cin >> want_to_play;
        }

    } while (want_to_play != 0 && want_to_play != 1);
    return want_to_play;
}