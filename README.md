## rocket-league

The aim of this project is to take in a csv file of data from Rocket League:
- Player as a string
- Score as an integer
- Goals as an integer
- Assists as an integer
- Saves as an integer
- Shots as an integer

These datums will be collected on a per person basis, stored as a `Menu` object.

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
The header of the csv should be comprised of "Player,Score,Goals,Assists,Saves,Shots"
From here, I just inputted the raw data from each game I played with Bots as integers:
Me,773,4,2,0,7