- In this problem, we will develop classes to use for testing two sorting algorithms (Selection
and Quick sort). The class will have methods to support experimenting and analyzing sorting
algorithms performance.


- Here is our functions and its job:

(1) GenerateRandomList(min, max, size) Generate a given number of random integer
data from a certain range. For example, one can generate a vector/array of 10000
integer numbers that fall in the range from 1 to 100000, e.g., [5554, 32300, 98000,
342, …]

(2) GenerateReverseOrderedList(min, max, size) Generate a given number of reverse
ordered integer data from a certain range.

(3) RunOnce(sorter, data, size) Run a given sorting algorithm on a given set of data
and calculate the time taken to sort the data

(4) RunAndAverage(sorter, type, min, max, size, sets_num) Run a given sorting
algorithm on several sets of data of the same length and same attributes (from the
same range and equally sorted; e.g., random or reversed) and calculate the average
time

(5) RunExperient (sorter, type, min, max, min_val, max_val, sets_num, step) Develop
an experiment to run a given sorting algorithm and calculate its performance on sets
of different sizes (e.g., data of size 10000, 20000, etc.) as follows:
I. All sets are generated with values between min and max
II. First, generate sets_num sets with size min_val. Use RunAndAverage () and
record average time to process the sets
III. Next, repeat step ii but with sets whose size increases by step till reaching
max_val. Each time record average time to process the sets
IV. For example I should be able to design an experiment to run Quick sort
algorithm on randomly sorted integers data taken from the range (1 to
1,100,000) and with input value (data size) from 0 to 100000, with step 5000.
This means we will run the algorithms on data sets of 5000, 10000, 15000, …,
100000 randomly sorted integers. Note that with each step you will generate
sets_num different sets and take the average of their runs
V. The output of the experiment goes to screen as a table with two columns; first
column indicates set size, and second column indicates average time

- the main() is a demo to show that the function works correctly and to measure the
performance of Quick sort and Selection sort in cases of random data and reverse ordered data using
this  class. 

- NOTE: You will find images showing the performance and the final results of 2 test cases of the program.