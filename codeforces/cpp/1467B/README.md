Difficulty: 1700. Time: 30min.

It took me around 30min to code the entire stuff. Then realize that there are edge cases for YYN and NYY. This problem is not hard once the idea is clear.

For YYN or NYY, we need to compare the ending points for the side N and Y. It is not so hard to realize how to solve the problem once we notice that,
in this case it could be -1 or -2.

In YYY or NYN, it is quite simple. -3 and -1 respectively. 

I made a serious stupid mistake, which causes the wrong answer result: for cases like n = 1, n = 2, I forgot to read in the numbers.
So the program did not process the input from the previous test case and then go next, the program got wrong whenever there exist
an n = 1, or n = 2.

**I SHOULD NOT MAKE THE SAME MISTAKE IN A CONTEST AGAIN.**

If I do not make such stupid mistake, this round I should be able to get 1600+. 




