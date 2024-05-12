## rocket-league

The aim of this project is to take in a csv file of data from Rocket League:
Player as a string
Score as an integer
Goals as an integer
Assists as an integer
Saves as an integer
Shots as an integer

These datums will be collected on a per person basis, stored as a Menu object.

Thank you to https://www.fluentcpp.com/2018/01/30/most-vexing-parse/
for helping me understand how clang and gcc parse parentheses and 
the disambiguation of the parentheses by replacing an object declaration
with curly braces for initialization{}

To process the csv, I am using the [Boost library](https://www.boost.org/doc/libs/1_50_0/doc/html/string_algo/usage.html#id3207193), specifically the split function.

To reference point structure in Rocket League, I used the [official page](https://rocketleague.fandom.com/wiki/Points).

### To configure the build directory
```
cd build
cmake ../src
```

### To build the files
```
cd build
cmake --build .
```
