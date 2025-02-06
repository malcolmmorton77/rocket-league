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
From here, I just inputted the raw data from each game I played with Bots as integers:
aBc12,Me,773,4,2,0,7

### Analysis
After looking at a lot of the data and replaying certain matches, I have developed a lot of insight on the mobility of the player.
If the miscellaneous score (the score from centering and clearing balls, possible epic saves and special goals) is under 50, the player wasn't much contribution to the game unless they were goalie for most of the game.
Now, I played with a bunch of bots to rack up the data so it would be interesting to see how actual players perform, but I don't want to commit real player names for privacy concerns. For a misc score of 50-100, the player had low mobility and made a few plays, but generally they weren't the driving force behind the team.
Anything from 101 to 200 for misc score was a very mobile player. This player would be setting up plays and centering or clearing balls.
From 201-300, this player is valuable to the team and creating soccer from zero. 
Bots have never received more than 250 points in the miscellaneous category, so a team member with above 250 points in the misc category is probably a real person.


| Score range | Mobility |
| ----------- | -------- |
|   0 - 50    |  imobile |
|  51 - 100   |   low    |
|  101 - 200  |  medium  |
|  201-300    |   high   |
|    301+     | valuable |

### Analysis 2.0
Sometimes, a player can "steal" a goal from their teammate, as happened to me twice in a championship game with bots. The bot finished my shot on goal by touching it before it went in, but I had already been credited the shot on goal, so I was credited in the scoreboard with a shot on goal, but the bot had the goal. Since the computer always attributes a shot on goal with a goal, no player should have more goals than shots on goal.
This can be seen in the data when the goals for a player are larger than their shots. From there, we can see that I would have those shots on goal. In this particular example, it's clear whose goals were stolen from who:

|   Player  |   Goals   |   Shots   |
| --------- | --------- | --------- |
|   Me      |   4       |   8       |
|   Chipper |   4       |   2       |
|   Tex     |   2       |   2       |

A simple check that this occurred is that a player has more goals than shots on goal. We can safely eliminate any players as being involved in this trade-off by comparing their
goals and shots. If they are equal, it's realistic to say that every shot on goal was their goal. If they have extra shots on goal, we will have to account for that and account for some ambiguity clause.
