- testing variables

Command | Description
-------- | ------------------
`test –f /dev/ttyS0` | `0` if the file exists
`test ! –f /dev/ttyS0` |`0` if the file doesn’t exist
`test –d /tmp` | `0` if the directory exists
`` test –x `which ls` `` | substitute the location of `ls` then `test` if the user can execute
`test 1 –eq 1` | `0` if numeric comparison succeeds
`test ! 1 –eq 1` | `NOT – 0` if the comparison fails
`test 1 –ne 1` | Easier, `test` for numeric inequality
`test “a” = “a”` | `0` if the string comparison succeeds
`test “a” != “a”` | `0` if the strings are different
`test 1 –eq 1 –o 2 –eq 2` | `-o` is OR: either can be the same
`test 1 –eq 1 –a 2 –eq 2` | `-a` is AND: both must be the same