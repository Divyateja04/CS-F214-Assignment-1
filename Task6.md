## Task 6: Analysis and Graphs
References Used: (https://yuchen52.medium.com/profiling-with-gprof-64-bit-window-7-5e06ef614ba8)

We chose to use C because of the fact that we thought, it would be a good learning experience for us if we use our C knowledge, and put it to use here instead of learning C++ again and shifting to another language

## Graphs
### Analysis 1
```
Function = (a+((b>c)>d)*e)>f
Inputs - a=0, b=1, c=0, d=0, e=1, f=1
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197341945-73b54126-d68f-469d-a715-c22293455230.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/196999959-be4f98fa-de75-489d-a5dc-02f830be50f5.png" alt="drawing" width="600"/>

### Analysis 2
```
Function = (a+b+c)*d
Inputs - a=1, b=0, c=0, d=1
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197341963-d51e953d-e9dc-4fe6-b88e-3b11270e33be.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/196999995-fa88adc7-8d89-4398-bada-4f431b694220.png" alt="drawing" width="600"/>

### Analysis 3
```
Function = ((a+b)>c)>d
Inputs - a=1, b=0, c=0, d=0
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197341968-af0bc18d-4052-4df8-8960-7b2f069472fa.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/197000021-4065bb25-e4f0-4c04-8873-2bafc6676ae2.png" alt="drawing" width="600"/>

### Analysis 4
```
Function = ((~a)*b)>(c+(d*e))
Inputs - a=1, b=0, c=0, d=1, e=0
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197376153-71611387-ec27-468a-b3f4-f22b6817f9fc.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/196999655-8b4f6085-2bc9-457d-9814-95d018429d5c.png" alt="drawing" width="600"/>

### Analysis 5
```
Function  = (~a)+(b*c)
Inputs - a=0, b=0, c=0
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197342283-6ee9f2fb-912f-471a-9728-24721200593b.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/197000062-0cf40336-ceee-4f00-af94-b4facc069159.png" alt="drawing" width="600"/>

### Analysis 6
```
Function  = ((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)+((((a+b)*(~c))+d)>e)
Inputs - a=1, b=0, c=1, d=0, e=1
Result = 1
```
<img src="https://user-images.githubusercontent.com/28446977/197381048-2dc89453-5d34-44b6-848e-d50546c88560.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/197381059-cc52dc7a-aa54-4b7a-a59c-11fa231d4454.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/197381063-db1f7df6-6f78-4928-85b5-c326ebb8ebb0.png" alt="drawing" width="600"/>
<img src="https://user-images.githubusercontent.com/28446977/197381116-72c755be-6c84-4824-9b75-2927a2bb3f38.png" alt="drawing" width="600"/>


