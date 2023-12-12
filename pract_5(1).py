def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    print(arr)

# Function to display the sorted array
"""def display_sorted_array(arr):
    print("Sorted array of percentages:")
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()
"""
# Example array of second-year percentages
percentages = [75.6, 89.2, 67.8, 93.5, 82.1, 71.4]

# Sorting the array using insertion sort
insertion_sort(percentages)

# Displaying the sorted array
#display_sorted_array(percentages)
