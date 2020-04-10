/*
    There are 52 cards in playing deck numbered from 1-52.
    The order of suits is Spades, Clubs, Hearts & Diamonds.
    Within a suit, cards are ordered in increasing order of their value, Ace being 1.
    You are given an input number from 1-52 and you have to give the card in the output.
    Example:
    1.
        input:
            1
        output:
            Ace of Spades
    2.
        input:
            26
        output:
            King of Clubs
    3.
        input:
            33
        output:
            7 of Hearts
    Question from IIT Bombay exam
*/
#include <iostream>

int main()
{
    int card;
    std::cout << "Enter Card: ";
    std::cin >> card;
    if (card >= 1 && card <= 52)
    {
        int number = card % 13;
        if (number == 1)
            std::cout << "Ace of ";
        else if (number == 0)
            std::cout << "King of ";
        else if (number == 12)
            std::cout << "Queen of ";
        else if (number == 11)
            std::cout << "Jack of ";
        else
            std::cout << number << " of ";
        if (card >= 1 && card <= 13)
            std::cout << "Spades" << std::endl;
        else if (card >= 14 && card <= 26)
            std::cout << "Clubs" << std::endl;
        else if (card >= 27 && card <= 39)
            std::cout << "Hearts" << std::endl;
        else
            std::cout << "Diamonds" << std::endl;
    }
    else
        std::cout << "Invlid card: " << card << std::endl;
    return 0;
}