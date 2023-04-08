#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include "methods/METHODS.cpp"
// #include "methods/ONLY_ONE_PLAYER.cpp"
using namespace std;

int main()
{
    int index, want_to_play = 1, check = 0, win_status = 0, count = 0, player_count;
    vector<int> free_index = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number_of_filled_boxes = 0;
    vector<char> game(9, '_');
    cout << "\t\t\tTHIS IS OUR GAME LAYOUT \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "_" << count + 1 << "_  ";
            count++;
        }
        cout << "\n";
    }
    cout << "\t\t\tWELCOME TO TIC-TAC-TOE GAME\n";
    // ask here if you are 1 player or 2 player
    cout << "HOW MANY PLAYER(S) ARE YOU \"1\" OR \"2\"??  ";
    cin >> player_count;
    if (player_count == 2)
    {
        cout << "PLAYER 1ST TELL WHICH SYMBOL YOU WANT TO PLAY WITH 'x' OR 'o':  ";
        char symbol;
        cin >> symbol;
        if (symbol == 'o')
        {
            do
            {
                if (win_status == 0 && number_of_filled_boxes != 9)
                {
                    do
                    {
                        number_of_filled_boxes++;
                        cout << "PLAYER 1ST PLZ TELL THE INDEX WHERE YOU WANT TO ADD 'o'\t";
                        cin >> index;
                        check = index_is_free(game, index, 'o');
                        show(game);
                        win_status = check_win(game, 'o');
                    } while (check == 0);
                }
                if (win_status == 0 && number_of_filled_boxes != 9)
                {
                    do
                    {
                        number_of_filled_boxes++;
                        cout << "PLAYER 2nd PLZ TELL THE INDEX WHERE YOU WANT TO ADD 'x'\t";
                        cin >> index;
                        check = index_is_free(game, index, 'x');
                        show(game);
                        win_status = check_win(game, 'x');
                    } while (check == 0);
                }
                else
                {
                    if (number_of_filled_boxes == 9)
                    {
                        cout << "MATCHED DRAW BOTH ARE WINNER:";
                        want_to_play = want_to_play_or_not();
                        if (want_to_play == 1)
                        {
                            system("cls");
                            main();
                        }
                        else
                        {
                            end_of_game();
                            exit(0);
                        }
                    }
                    else
                    {
                        want_to_play = want_to_play_or_not();
                        if (want_to_play == 0)
                        {
                            end_of_game();
                            exit(0);
                        }
                        else
                        {
                            system("cls");
                            main();
                        }
                    }
                }
            } while (want_to_play == 1);
        }

        else if (symbol == 'x')
        {
            do
            {
                if (win_status == 0 && number_of_filled_boxes != 9)
                {
                    do
                    {
                        number_of_filled_boxes++;
                        cout << "PLAYER 1ST PLZ TELL THE INDEX WHERE YOU WANT TO ADD 'x'\t";
                        cin >> index;
                        check = index_is_free(game, index, 'x');
                        show(game);
                        win_status = check_win(game, 'x');
                    } while (check == 0);
                }
                if (win_status == 0 && number_of_filled_boxes != 9)
                {
                    do
                    {
                        number_of_filled_boxes++;
                        cout << "PLAYER 2nd PLZ TELL THE INDEX WHERE YOU WANT TO ADD 'o'\t";
                        cin >> index;
                        check = index_is_free(game, index, 'o');
                        show(game);
                        win_status = check_win(game, 'o');
                    } while (check == 0);
                }
                else
                {
                    if (number_of_filled_boxes == 9)
                    {
                        cout << "MATCHED DRAW BOTH ARE WINNER:";
                        want_to_play = want_to_play_or_not();
                        if (want_to_play == 1)
                        {
                            system("cls");
                            main();
                        }
                        else
                        {
                            end_of_game();
                            exit(0);
                        }
                    }
                    else
                    {
                        want_to_play = want_to_play_or_not();
                        if (want_to_play == 0)
                        {
                            end_of_game();
                            exit(0);
                        }
                        else
                        {
                            system("cls");
                            main();
                        }
                    }
                }
            } while (want_to_play == 1);
        }
        else
        {
            cout << "\nOOPS WRONG ALPHABET PLEASE CHOICE WISELY\n";
            main();
        }
    }

    // from here only one player program
    else
    {
        do
        {
            if (win_status == 0 && number_of_filled_boxes != 9)
            {
                do
                {
                    // cout << "\t\tim in human body\n";
                    number_of_filled_boxes++;
                    cout << "PLAYER 1ST PLZ TELL THE INDEX WHERE YOU WANT TO ADD 'o'\t";
                    cin >> index;
                    check = index_is_free(game, index, 'o');
                    show(game);
                    win_status = check_win(game, 'o');
                } while (check == 0);
            }
            if (win_status == 0 && number_of_filled_boxes != 9)
            {
                do
                {
                    srand(time(0));
                    random_shuffle(free_index.begin(), free_index.end());
                    index = free_index[0];
                    check = index_is_free(game, index, 'x');
                    if (check == 1)
                    {
                        cout << "2ND PLAYER IS COMPUTER\n";
                        show(game);
                        auto it = find(free_index.begin(), free_index.end(), index);
                        free_index.erase(it);
                    }
                    win_status = check_win(game, 'x');
                } while (check == 0);
            }
            else
            {
                if (number_of_filled_boxes == 9 || win_status == 1)
                {
                    if (number_of_filled_boxes == 9)
                    {
                        cout << "MATCHED DRAW BOTH ARE WINNER:";
                    }
                    want_to_play = want_to_play_or_not();
                    if (want_to_play == 1)
                    {
                        system("cls");
                        main();
                    }
                    else
                    {
                        end_of_game();
                        exit(0);
                    }
                }
            }

        } while (want_to_play == 1);
    }
    return 0;
}
