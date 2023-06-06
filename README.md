# PUSH_SWAP
### 42 NETWORK PROJECT - QUEBEC
### ppaquet

Here is my first algorithm program called "push_swap", which validates and sorts (if not already)
an unknown amount of random numbers. The sorting process is limited by specific operations
executed with two different stack (a & b). Here's a list of permitted moves;

	- push to stack b (pb)
	- push to stack a (pa)
	- rotate stack b (rb)
	- rotate stack a (ra)
	- rotate stacks a & b (rr)
	- reverse rotate stack b (rrb)
	- reverse rotate stack a (rra)
	- reverse rotate stacks a & b (rrr)
	- swap stack b (sb)
	- swap stack a (sa)
	- swap stacks a & b (ss)

You can find below the results I got from a tester runned over my program, that checks the amount
of operations applied to the stacks, if it is sorted at exit, and finally the detection
of any leak(s):

[STACK SIZE: 3__________100 LOOPS]
	TOTAL INSTRUCTIONS__121
	LEAKS_______________0
	MINIMUM_____________0 (test case 5)
	MAXIMUM_____________2 (test case 1)
	AVERAGE_____________1

[STACK SIZE: 10_________1,000 LOOPS]
	TOTAL INSTRUCTIONS__27703
	LEAKS_______________0
	MINIMUM_____________19 (test case 737)
	MAXIMUM_____________37 (test case 651)
	AVERAGE_____________27

[STACK SIZE: 100________10,000 LOOPS]
	TOTAL INSTRUCTIONS__6484936
	LEAKS_______________0
	MINIMUM_____________591 (test case 4014)
	MAXIMUM_____________704 (test case 2274)
	AVERAGE_____________648

[STACK SIZE: 500________10,000 LOOPS]
	TOTAL INSTRUCTIONS__51382722
	LEAKS_______________0
	MINIMUM_____________4923 (test case 1153)
	MAXIMUM_____________5401 (test case 4171)
	AVERAGE_____________5138
