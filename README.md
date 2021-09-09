A simple example that uses two threads to show that Intel x86 does not implement
sequential consistency. The example is similar to the one used by Lamport in
his classic paper *How to Make a Multiprocessor Computer That Correctly Executes 
Multiprocess Programs*.

Compile with: `g++ -otest.x test.cc -std=c++11 -pthread`

You should never see as output both `1` and `2` printed. It is very rare, but
it happens! I suggest you keep the code running for awhile, such as:

`while true; do ./test.x >> log; done`

then check the file for both 1 and 2 (e.g., `cat log | awk 'NF {if (++n >= 2) print NR; next}; {n=0}'`).

This will return the line numbers where both numbers were printed in the log.
