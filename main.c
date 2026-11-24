

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 256
#define INITIAL_CAPACITY 10

char **getfile(int *line_count){
char filename[50];    

printf("enter a filename .csv format: ");
scanf("%49s", filename);

FILE *fp = fopen(filename, "r");

int capacity = INITIAL_CAPACITY;  
char **str = malloc(capacity * sizeof(char*));

char buffer[LINE_SIZE];
while (fgets(buffer, sizeof(buffer), fp)) {
    buffer[strcspn(buffer, "\n")] = 0;

if (*line_count >= capacity) {
    capacity =capacity * 2;
     str = realloc(str, capacity * sizeof(char*));
    }

 str[*line_count] = malloc(strlen(buffer) + 1);
    if (!str[*line_count]) {
    printf("Memory allocation failed.\n");
    fclose(fp);

}
strcpy(str[*line_count], buffer);
(*line_count)++;
}
fclose(fp);
return str;
}


int *extract_numbers(char **str, int count) {
int *nums = malloc(count * sizeof(int));
 for (int i = 0; i < count; i++) {
    nums[i] = atoi(str[i]);
}
return nums;
}

float mean(int nums[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += nums[i];

    return (float)sum / n;
}


void sort(int nums[], int n) {
int temp;
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (nums[j] > nums[j + 1]) {
            temp = nums[j];
            nums[j] = nums[j + 1];
            nums[j + 1] = temp;
            }
        }
    }
}


float median(int nums[], int n) {
    sort(nums, n);

    if (n % 2 != 0)
    return nums[n / 2];
    else
    return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
}

int mode(int nums[], int n) {
    int mode = nums[0];
    int maxCount = 0;

for (int i = 0; i < n; i++) {
    int count = 0;

    for (int j = 0; j < n; j++) {
        if (nums[j] == nums[i])
        count++;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = nums[i];
        }
    }

    return mode;
}



int main() {
    int line_count;

    char **str = getfile(&line_count);

    int *nums = extract_numbers(str, line_count);

    printf("Mean: %.2f\n", mean(nums, line_count));
    printf("Median: %.2f\n", median(nums, line_count));
    printf("Mode: %d\n", mode(nums, line_count));
   
    for (int i = 0; i < line_count; i++)
        free(str[i]);
    free(str);
    free(nums);
    return 0;
}
