# Code Analysis

## Members
- Divyateja Pasupuleti 2021A7PS0075H
- Kumarasamy Chelliah 2021A7PS0096H
- Harsh Rachalwar 2021A7PS0200H
- Manan Gupta 2021A7PS2091H
  
---

We chose to use C because of the fact that There is no proper implementation in C before this and we thought, it would be a good learning experience for us if we use our CP knowledge, and put it to use here instead of learning C++ again and shifting to another language

## Graphs
### Analysis 1
```
Function  = (a((b>c)>d)*e)>f
Inputs - a=0, b=1, c=0, d=0, e=1, f=1
Result= 1
```

<img src="https://user-images.githubusercontent.com/28446977/196999959-be4f98fa-de75-489d-a5dc-02f830be50f5.png" alt="drawing" width="600"/>

### Analysis 2
```
Function  = (a+b+c)*d
Inputs - a=1, b=0, c=0, d=1
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/196999995-fa88adc7-8d89-4398-bada-4f431b694220.png" alt="drawing" width="600"/>

### Analysis 3
```
Function  = ((a+b)>c)>d
Inputs - a=1, b=0, c=0, d=0
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/197000021-4065bb25-e4f0-4c04-8873-2bafc6676ae2.png" alt="drawing" width="600"/>

### Analysis 4
```
Function  = ((~a)\*b)>(c+(d\*e))
Inputs - a=1, b=0, c=0, d=1, e=0
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/196999655-8b4f6085-2bc9-457d-9814-95d018429d5c.png" alt="drawing" width="600"/>

### Analysis 5
```
Function  = (a+b+c)*d
Inputs - a=1, b=0, c=0, d=1
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/197000062-0cf40336-ceee-4f00-af94-b4facc069159.png" alt="drawing" width="600"/>


## Running the Code
- This was a project made for Logic in CS Course Assignment 1
- Compile by using `gcc -Wall -pg Task.c -o Task.exe`
- Then Run the exe
- You get the gmon file
- `gprof Task.exe gmon.out >> analysis.txt` Use this to get analysis
- To graph this in points use gprof2dot and graph

## Basic Git Commands you might want to know to push onto this repository
- `git pull`: to pull from remote
- `git add .`: to add your files
- `git commit -m "Message Goes here"`: Add Message for the commit
- `git push`: push files to remote

NOTE: Pushing Task.exe leads to merge conflicts :)
