# In second year computer engineering class, group A student’s play cricket, group B students play badminton and group C students play football. 
# Write a Python program using functions to compute following: - 
# a) List of students who play both cricket and badminton 
# b) List of students who play either cricket or badminton but not both 
# c) Number of students who play neither cricket nor badminton 
# d) Number of students who play cricket and football but not badminton. 
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)

def funA(A, B):
    temp = []
    for i in A:
        if i in B:
            temp.append(i)
    print(temp)

def funB(A, B):
    temp = []
    for i in A:
        if i not in B:
            temp.append(i)
    for i in B:
        if i not in A:
            temp.append(i)
    print(temp)

def funC(A, B, C):
    temp = []
    for i in C:
        if i not in A and i not in B:
            temp.append(i)
    print(temp)

def funD(A, B, C):
    temp = []
    for i in A:
        if i in C and i not in B:
            temp.append(i)
    print(temp)

A = [1, 2, 5, 7, 8, 10]
B = [1, 3, 4, 6, 7 , 9]
C = [2, 3, 5, 8, 11]

while(True):
    ch = input("""
Menu
1) List of students who play both cricket and badminton 
2) List of students who play either cricket or badminton but not both 
3) Number of students who play neither cricket nor badminton 
4) Number of students who play cricket and football but not badminton. 
5) Exit

Enter a choice : """)

    if ch == '1':
        funA(A, B)
    elif ch == '2':
        funB(A, B)
    elif ch == '3':
        funC(A, B, C)
    elif ch == '4':
        funD(A, B, C)
    elif ch == '5':
        break
    else:
        print("Please Enter valid choice")