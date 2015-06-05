# Artisanship - By Harrison Shoebridge
One of my biggest strengths in programming is that of reflection, I am always looking for ways to make my existing code better (in all sense of the word: neater, faster, more documentation). Examples of this include `danish.c` where I spent originally was using two for loops to complete a job that could be accomplished by one!

Original: https://github.com/paked/1917/blob/1789847d2cb0cd5623b6564772a5cc7d178abe25/danish.c

Polished: https://github.com/paked/1917/blob/7a0564687e00df5da8a607e5e1d5f3e8df797ec3/danish.c

Another example of this is an extra piece of work I did as practice for the exam. Oliver gave us a task where we had to print a triangle of stars, I completed this task using the implied method... but felt something was missing. After some quick thinking after dinner that night I realised that I could use recursion to solve the problem, in a much more elegant way.

Original: https://gist.github.com/paked/56b8ae2b0d5a6bd6b02c

Updated: https://github.com/paked/1917/blob/master/recursive_stars.c

While writing code for 1917 I was interested in writing tests for my code, in the projects I did extensive testing of how things worked. In doomsday I even tested the tests for my project!

Rot13 testing: https://github.com/paked/1917/blob/master/rot13.c

Doomsday testing: https://github.com/paked/1917/blob/master/assignments/doomsday/main.c

Complex/ADT testing: https://github.com/paked/1917/blob/master/testComplex.c

During the course my craftsmanship skills improved exponentially, this was due to my configuration and personal pedant-ness. When I first started off 1917 I was using an incredibly poorely configured Vim, tabs and bad syntax coloring all over the place! Im honestly amazed I got anything written at all. I also was used to a few patterns from my other programming languages, I spent a lot of time naming "public variables" in characters in structs with capitol letters and not properly indentating a my code (in Go, we have a tool called gofmt... it auto formats your code, needless to say I miss it!). Overtime this got better during the projects I made myself use proper indentation and it led to some nice looking code. Another issue for me was my constant use of magic numbers. This was fixed quickly too.

Bad indentation: https://github.com/paked/1917/blob/master/assignments/doomsday/main.c#L105-L143

Magic numbers: https://github.com/paked/1917/blob/master/leap_year.c

Better code: https://github.com/paked/1917/blob/master/tictactoe.c

Craftsmanship to me is about building things that other people are able to quickly understand and contribute too. Symptoms of this are modularity and abstraction, both of which I am now trying very hard to achieve.

As a programmer I came across a few bugs while writing my something awesome project to do with angular (a library I am relatively new to), the most notorious one to me was a bug that was due to the angular scoping system. I was sending a scope variable to another controller and sometimes it would receive and others not... Turns out I was not allowing my scope to update before sending (way too many hours wasted on that). A bug we came across during the major project was the "inconsistent environemnt bug"... occasionally the tests would fail and occasionally they wouldnt. Turns out we had exposed our self to a memory leak, it wasnt fun to track down!

Now that the course is over I have greatly improved the quality of my testing and overall care of my programs. I am now writing much more documentation for my code, and writing better commit messages within my projects. My testing skills have also improved and I am able to write proper integration and unit tests.

Tictactoe documentation: https://github.com/paked/1917/blob/master/tictactoe.h

Golang documentation: http://godoc.org/github.com/paked/models

Doomsday documetation: https://github.com/paked/1917/blob/master/assignments/doomsday/main.c

Commit messages: https://github.com/paked/NUMBERSFORPICTURES/commits/master
