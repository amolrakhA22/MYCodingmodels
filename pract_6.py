def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less_than_pivot = [x for x in arr[1:] if x <= pivot]
        greater_than_pivot = [x for x in arr[1:] if x > pivot]
        return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)

# Function to display top five scores
def display_top_scores(arr):
    sorted_arr = quick_sort(arr)
    top_scores = sorted_arr[-5:]
    print("Top five scores are:")
    for score in top_scores[::-1]:
        print(score)

# Example array of first year percentages
percentages = [78.5, 85.2, 91.7, 76.9, 88.3, 94.1, 82.6, 79.8]

# Sorting the percentages using quicksort and displaying top five scores
display_top_scores(percentages)
