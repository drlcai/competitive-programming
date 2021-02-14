Difficulty: 900. Time: 20 min

Again I made a mistake on simple quesions...

This one is very simple. We just need to realize that we can simply first increase b. Then modify a.

Why is there no better solution after we increase b to a certain value:


After this proof, we can simply simulate how we decrease a. The mistake I made was: I thougt this
was equal to log_b(a), which is wrong in many cases. 

This is what I found: if I use double r = log a / log b. For 571787 and 83, this should be 3. 
However if we cast it to int, this gives us 2.

This is very related to the floating point number in C++ or any programming language. 

The trick to solve it is to add 1e-12 to the numbers so it doesn't cast it to a wrong way. 
