# a) Write a Python program to store roll numbers of student in array who attended training program in random order. 
# Write function for searching whether particular student attended training program or not, using Linear search and Sentinel search.

# b) Write a Python program to store roll numbers of student array who attended training program in sorted order. 
# Write function for searching whether particular student attended training program or not, using Binary search and Fibonacci search.

def LinearSearch(arr, key, n):
    for i in range(n):
        if arr[i] == key:
            print(key, "Found at", i+1)
            return
    print("Not Found")

def sentinelSearch(arr, key, n):
    last = arr[n-1]
    arr[n-1] = key
    i = 0
    while arr[i] != key:
        i += 1

    arr[n-1] = last
    if i < n-1 or key == arr[n-1]:
        print(key, "Found at", i+1)
    else:
        print("Not Found")

def binarySearch(arr, x, low, high):
    if low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            print(x, "Found")
            return 1
        elif arr[mid] > x:
            binarySearch(arr, x, low, mid-1)
        elif arr[mid] < x:
            binarySearch(arr, x, mid+1, high)
    else:
        print("Not Found")
        return

def fibo(n):
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)

def fibonacciSearch(arr, x, n):
    m = 0
    while fibo(m) < n:
        m += 1
    offset = -1

    while fibo(m) > 1:
        mid = min(offset + fibo(m-2), n-1)
        if x > arr[mid]:
            m -= 1
            offset = mid
        elif x < arr[mid]:
            m -= 2
        else:
            print(x, 'Found')
            return

    if fibo(m-1) == False and arr[offset + 1] == x:
        print(x, "Found")

    print("Not Found")

count = int(input("Enter number of students : "))
i = 0
array = []
while i < count:
    st = int(input("Enter roll number of "+str(i+1)+" student : "))
    if st not in array:
        array.append(st)
        i += 1
    else:
        print("Student", st, "aleardy present please reenter")

key = int(input("Enter a roll no  to find : "))

print("Linear Search : ", end = "")
LinearSearch(array, key, count)

print("Sentinel Search : ", end = "")
sentinelSearch(array, key, count)

array.sort()

print("Binary Search : ", end = "")
binarySearch(array, key, 0, count)

print("Fibonacci Search : ", end = "")
fibonacciSearch(array, key, count)