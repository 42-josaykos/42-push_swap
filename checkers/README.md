# Tests

For 3 values = between 2 / 3 operations
For 5 values = max 12
For 100 values = score from 1 to 5

- less than 700: 5
- less than 900: 4
- less than 1100: 3
- less than 1300: 2
- less than 1500: 1

  For 500 values = score from 1 to 5

- less than 5500: 5
- less than 7000: 4
- less than 8500: 3
- less than 10000: 2
- less than 11500: 1

> Note: min 4/5 for 100 numbers and 3/5 for 500 numbers to pass

```
ARG=`tests/genstack.pl 100 -1000 1000`; ./push_swap $ARG | ./checker $ARG
```
