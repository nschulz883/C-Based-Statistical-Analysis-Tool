# CSV Statistical Analyser

A command-line application written in C that reads numerical data from a CSV file and calculates basic statistical measurements.

The project demonstrates fundamental C programming concepts, including file handling, dynamic memory allocation, arrays, pointers, sorting algorithms and statistical calculations.

## Features

- Reads numerical data from a CSV file.
- Dynamically allocates memory to store input data.
- Extracts numerical values from file contents.
- Calculates the arithmetic mean.
- Calculates the median using a sorting algorithm.
- Determines the mode by identifying the most frequently occurring value.
- Releases dynamically allocated memory after execution.

## Technologies

- C
- Standard C libraries:
  - stdio.h
  - stdlib.h
  - string.h
  - ctype.h

## How It Works

1. The program requests a CSV filename from the user.
2. It opens the file and reads its contents line by line.
3. Input values are dynamically stored using allocated memory.
4. Numerical values are extracted using integer conversion.
5. The program calculates the mean, median and mode.
6. Results are displayed in the terminal.
7. Dynamically allocated memory is released.

## Compilation

Using GCC:

```bash
gcc main.c -o analyser
```

## Execution

```bash
./analyser
```

On Windows:

```bash
analyser.exe
```

The program will request the name of the CSV file.

## Example Input

`sample_data.csv`

```csv
10
20
30
20
40
```

## Example Output

```text
Mean: 24.00
Median: 20.00
Mode: 20
```

## Concepts Demonstrated

- File input and output using `FILE` and `fopen()`.
- Dynamic memory allocation using `malloc()` and `realloc()`.
- Pointer manipulation and dynamic arrays.
- String processing and input extraction.
- Bubble sort implementation.
- Statistical calculations.
- Memory management using `free()`.

## Future Improvements

- Support comma-separated values and multiple columns.
- Improve input validation and error handling.
- Implement more efficient sorting algorithms.
- Support floating-point numerical data.
- Add standard deviation and variance calculations.

## Author

Noah Schulz
