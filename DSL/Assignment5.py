# Write a python program to store second year percentage of students in array. 
# Write function for sorting array of floating point numbers in ascending order using 
# a) Insertion sort 
# b) Shell Sort and display top five scores

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print("Pass", i, " : ", arr)

def shellSort(arr, n):
    gap = n // 2
    c = 1
    while gap > 0:
        j = gap
        while j < n:
            i = j - gap
            while i >= 0:
                if arr[i + gap] > arr[i]:
                    break
                else:
                    arr[i + gap], arr[i] = arr[i], arr[i + gap]
                    print("Pass", c, " : ", arr)
                i = i - gap
                c += 1
            j += 1
        gap = gap // 2

subjects = int(input("Enter number of subjects : "))
print("Enter second year percentage : ")
per = []
for i in range(subjects):
    per.append(input())

print("List of percentage is : ", per)

while(True):
    print("""
    Enter You Choice :
    1. Insertion Sort
    2. Shell Sort
    0. To Exit
    """)
    ch = input("Choice : ")
    if ch == '1':
        insertionSort(per)
        print(per)
    elif ch == '2':
        shellSort(per, len(per))
        print(per)
    elif ch == '0':
        print("Thank You")
        break
    else:
        print("Entered Wrong choice, please enter correct choice")
        break