# sieve-of-eritosthenes
Find every prime number between a given low and high boundary

This was a project I had to do in C++, it's main function is to find every prime number up to a given height using the algorithm called "the sieve of eritosthenes." Then when displaying the results it cuts off the lower boundary to fit between the high and low. The algorithm works like so:

Given a height n:
1). List all integers from 0 to n and cross out 0 and 1.
2). Circle the first integer not crossed out or circled.
3). If it is greater than sqrt(n), go to step 6.
4). Cross out all multiples of the number greater than itself.
5). Repeat from step 2.
6). Circle all remaining integers not crossed out or circled.

From here all circled numbers are prime.

I tried recreating the methods to fit these steps, so I could follow the algorithm and just call methods as they were needed. It runs through the console.
