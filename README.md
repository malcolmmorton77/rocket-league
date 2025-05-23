## rocket-league

The aim of this project is to take in a csv file of data from Rocket League:
- Team_Id as a string
- Player as a string
- Score as an integer
- Goals as an integer
- Assists as an integer
- Saves as an integer
- Shots as an integer

These datums will be collected on a per person basis, stored as a `Menu` object.

Team_Id is a unique, 5 character string used to identify members of the team.
Then, these datums will be used to calculate as much of the accounted for points as possible.
By subtracting these accounted for points from the total score, we can get the points earned
from ball touches (2 pts per touch, unless from a first touch), epic saves, special goals, demolishing,
centering and clearing balls.

### Special Goals:
- Aerial Goals: 20 pts
- Backwards Goals: 20 pts
- Bicycle Goals: 20 pts
- Long Goal: 20 pts
- Turtle Goals: 20 pts
- Pool Shot: 20 pts
- Overtime Goal: 25 pts

### Special Saves:
- Epic Save: 75 pts

### Miscellaneous Field Points:
- Centering Balls: 10 pts
- Clearing Balls: 20 pts
- Ball touches: 2 pts
- Extermination (demolish players 7 times): 20 pts

To process the csv, I am using the [Boost library](https://www.boost.org/doc/libs/1_50_0/doc/html/string_algo/usage.html#id3207193), specifically the split function.

To reference point structure in Rocket League, I used the [official page](https://rocketleague.fandom.com/wiki/Points).

### To configure the build directory
```shell
cmake --preset default
```

### To build the files
```shell
cmake --build --preset rocket-league
```

### To run the program
```shell
./build/rocket-league /path/to/filename.csv
```

### Format of the csv
The header of the csv should be comprised of "Team_Id,Player,Score,Goals,Assists,Saves,Shots"  
From here, input the raw data from each game as integers:
aBc12,Me,773,4,2,0,7

### Mobility Analysis
Looking at a lot of the data and replaying certain matches provides lots of insight on the mobility of the player based on the miscellaneous points.

- If the score is under 50, the player wasn't much contribution to the game.
- For a score of 50-100, the player had low mobility and made a few plays, but generally they weren't the driving force behind the team.
- Anything from 101 to 200 was a very mobile player. This player would be setting up plays and centering or clearing balls.
- From 201-300, this player is valuable to the team and creating soccer from zero. 

> [!NOTE]
> Bots have never received more than 250 points in the miscellaneous category, so a team member with above 250 points in the misc category is probably a real person.


| Score range |       Mobility      |
| ----------- | ------------------- |
|   0 - 50    |       imobile*      |
|  51 - 100   |         low         |
|  101 - 200  |        medium       |
|  201-300    |         high        |
|    301+     |       valuable      |

> [!NOTE]
> Imobile players were possibly goalies with really good teammates, although this is unlikely given the number of ball touches, clears, and centers that would accumulate from being goalie.

### Stolen Goals Analysis
Sometimes, a player can "steal" a goal from their teammate, as happened to me twice in a championship game with bots. The bot finished my shot on goal by touching it before it went in, but I had already been credited the shot on goal, so I was credited in the scoreboard with a shot on goal, but the bot had the goal. 

Since the game is built to handle the possibility of players having more shots on goal, there had to be a limit where the player was awarded the shot on goal. A goalie can save the goal, miss the goal, or the shot on goal can hit the post. However, in all of these cases, no player should have more goals than shots on goal, unless a teammate touches the ball after the shot on goal has already been awarded.

I catalogued data in my csv and ran it through the first draft of the calculateStolenGoals function. It correctly caught that there was a discrepancy with the below data:

|   Player  |   Goals   |   Shots   |
| --------- | --------- | --------- |
|   Me      |   4       |   7       |
|   Stinger |   3       |   2       |
|   Rex     |   4       |   6       |

> [!WARNING]
> The current solution only checks one teammate with the next rather than comparing all members of the team to each other.
> So, with this real data, we are comparing Me to Stinger, and Stinger to Rex, but never Me to Rex.

#### Here's the core logic of the function:
1. Check that one of the provided players has more goals than shots
2. Check that the difference in shots and goals of the other player is positive and greater than the original player's goal difference
3. Return the difference of the original player's goal difference

#### Limitations:
- No hashmap of teammates which makes comparisons difficult to analyze further
- Does not account for the possibility that one teammate stole goals from the other two
- Does not account for the possibility that 2 teammates each stole a goal from the third teammate.
- Does not analyze the assists to see if the shot on goal ended up being a pass to the teammate, which then results in a goal.