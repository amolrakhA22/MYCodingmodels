def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Function to display the top five scores
def display_top_scores(arr):
    print("Top five scores:")
    for i in range(-1, -6, -1):
        if -i <= len(arr):
            print(arr[i])

# Example array of second-year percentages
percentages = [75.6, 89.2, 67.8, 93.5, 82.1, 71.4, 98.7, 85.3, 79.0]

# Sorting the array using Shell Sort
shell_sort(percentages)
print(percentages)

# Displaying the top five scores
#display_top_scores(percentages)
