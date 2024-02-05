# C Plummet

More to come about this side project!

## LLDB Tips

- compile with -O0 -g for lldb to give debug info
- target create "a.out" will allow for breakpoints
- thread step-over use this if you are about to go into the cstdlib function to save time
- step (s) step into the next line
- p <var> look at the LLDB docs for this one, it prints a lot of things
- f (I think it stands for frame) print the current line of code and the surroundings lines of code

## Known Issues

read the LLDB Tips above if you want to tackle this problem

- b main.c:18 where the current error is for the list data structure
