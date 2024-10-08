# Resta 22

This program simulates a dice game called “Resta 22”, which is played between two people, but in this case, one is you and the other is the computer. The objective of the game is to accumulate the highest number of points as close as possible to 22 without exceeding that value.
 
 Each player is allowed to make three rolls if they choose. In each roll, the player throws two dice, identified as the first die and the second die, and sums the numbers that come up. Remember that each die is a cube with six faces numbered from 1 to 6. These rolls are cumulative.
 
 Game rules:
 
 If the accumulated value is:
    •	Greater than 22 points (the game ends and the player loses).
    •	More than 11 and less than or equal to 22 points (the player continues in the game).
    •	Less than 11 points, the game passes to the other player.
    
Going to the game:
    •	The player with the highest score wins.
    •	If the scores are tied, the player with the fewest rolls wins.
    •	If the number of rolls is the same, the player with the highest score on the first die wins.
    •	If the score on the first die is the same, the game is a draw.
    
The program starts by asking the player how much money they have. In each round, the program asks the player for the amount of the bet. This amount is accepted if it is less than 1000 kwanzas. The computer always has money and always bets the same amount as the player. For each round, the winning player receives the total amount bet, and the game continues if the player has money. In each round, if the game is a draw, both players receive back the amounts they bet. Note that the computer always has money to play. When a round is over, the player can choose to leave the game if they wish.

In each round, the program should show, for each player:
    •	The amount bet;
    •	The number of dice rolls;
    •	The accumulated value of the dice;
    •	The accumulated value of the first die;
    •	Who won the game and how much they won.

At the end of the game, the program should show:
    •	The number of games played;
    •	How much the player won;
    •	How much the computer won.
