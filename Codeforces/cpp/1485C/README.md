Difficulty: 1700. Time: 30 min

This is a number theory problem. 

The experience is that we cannot enumerate all pairs. 1e18 iterations must be so wrong.

Such problems must have other ways to get around the iterations. We notice that `a = b * r + r`.
So given an upper bound for `a`, we know that `b <= (a - r) / r`. Then we also know that `b > r`.
Hence for one specific `r`, we know how many `b`s we can get. Once `b` is set, we can easily find
`a`. 
