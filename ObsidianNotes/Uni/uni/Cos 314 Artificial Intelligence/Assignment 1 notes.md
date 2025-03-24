
Simulated Annealing:
Getting temp:
- At 20 iterations
	- Temp
		- Calculate average of abs(newDistance - currentDistance) over 20 iterations
		- repeated with different seed values the average loss fell in the range of:
		  28 - 47
		- Taken the inital temp to be 55
- Cooling rate
	- tried values between 0.90 - 0.99
	- 346, 346, 327, 303, 303 303, 394, 394. 394
	- Optimal values:
		- 0.93 0.94 0.95
		- 0.95 chosen arbitrarily 

Brute force:
================
Dimension: 8
Distance: 286.50165144471555
Tour:
1 -> 3 -> 7 -> 5 -> 2 -> 6 -> 8 -> 4 -> 1
================
Dimension: 12
Distance: 402.1760580365969
Tour:
11 -> 8 -> 2 -> 9 -> 7 -> 4 -> 10 -> 6 -> 12 -> 1 -> 5 -> 3 -> 11
================
Dimension: 15
Distance: 479.1933743677713
Tour:
7 -> 1 -> 14 -> 13 -> 9 -> 10 -> 12 -> 5 -> 8 -> 4 -> 11 -> 15 -> 6 -> 2 -> 3 -> 7
================
Dimension: 20
Distance: 452.50001258809266
Tour:
4 -> 15 -> 10 -> 12 -> 19 -> 6 -> 9 -> 1 -> 11 -> 13 -> 20 -> 5 -> 2 -> 17 -> 7 -> 8 -> 14 -> 3 -> 16 -> 18 -> 4
================
Dimension: 25
Distance: 610.5021014984347
Tour:
23 -> 20 -> 13 -> 17 -> 22 -> 25 -> 10 -> 6 -> 18 -> 15 -> 2 -> 19 -> 21 -> 1 -> 24 -> 12 -> 7 -> 9 -> 5 -> 3 -> 14 -> 16 -> 11 -> 4 -> 8 -> 23

Iteration 15:
================
Dimension: 8
Distance: 377.707057479161
Tour:
5 -> 7 -> 3 -> 1 -> 8 -> 2 -> 6 -> 4 -> 5
================
Dimension: 12
Distance: 518.1974641159014
Tour:
8 -> 2 -> 12 -> 4 -> 9 -> 7 -> 10 -> 6 -> 11 -> 1 -> 5 -> 3 -> 8
================
Dimension: 15
Distance: 692.8670848985964
Tour:
11 -> 9 -> 13 -> 6 -> 8 -> 3 -> 12 -> 7 -> 10 -> 5 -> 14 -> 1 -> 4 -> 2 -> 15 -> 11
================
Dimension: 20
Distance: 934.4385124706077
Tour:
4 -> 9 -> 17 -> 11 -> 19 -> 8 -> 2 -> 14 -> 3 -> 6 -> 18 -> 5 -> 20 -> 1 -> 7 -> 12 -> 16 -> 10 -> 13 -> 15 -> 4
================
Dimension: 25
Distance: 1002.9725677568499
Tour:
18 -> 13 -> 6 -> 4 -> 19 -> 15 -> 10 -> 2 -> 8 -> 23 -> 3 -> 24 -> 21 -> 1 -> 11 -> 12 -> 7 -> 9 -> 17 -> 22 -> 16 -> 5 -> 14 -> 20 -> 25 -> 18