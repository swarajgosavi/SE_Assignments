# Write a python program to store first year percentage of students in array. 
# Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.

def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1

def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

subjects = int(input("Enter number of subjects : "))
print("Enter first year percentage : ")
per = []
for i in range(subjects):
    per.append(int(input()))

print("List of percentage is : ", per)
quick_sort(per, 0, len(per) - 1)

print(f"Sorted Percentage are : {per}")

print("\nTop 5 scores : ")
for i in range(1,6):
    print(per[subjects - i])