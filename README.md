# CareMatrix
A C program that simulates and analyzes the occupancy of patients across different care levels (I–III) and by gender (male/female) throughout the year. The system randomly generates monthly patient data and provides tools to query specific time ranges and filter results by care level and gender.



## 🩺 Features
* Randomized monthly occupancy data

* 3 care levels: I, II, III

* Gender split: Male (M) and Female (W)

* User can:

  * View total occupancy per year

  * Select a specific range of months to analyze

  * Filter by care level(s)

  * Filter by gender



## 📊 Output Example
```
Month  1 | Care Level   1   M: 12     W: 9 |
Month  2 | Care Level   1   M: 14     W: 11 |
...
M Total in period: 160  
W Total in period: 142  
M in Care Level II: 50  
W in Care Level III: 40
```


## 🧠 How It Works
Data is generated using rand() based on system time.

The 2D array mwmo[6][12] holds values for 6 care groups (M/W × 3 levels) over 12 months.

User interacts via CLI to select filters and period of interest.

Final output shows detailed statistics based on selected filters.



## 🛠️ Requirements
C compiler (e.g., gcc)

Terminal or console environment



## 🚀 How to Run

Compile:
```bash
gcc -o carematrix carematrix.c
```
Run:
```bash
./carematrix
```


## 🧾 File Structure
carematrix.c – Main source code for the simulation and analysis.
