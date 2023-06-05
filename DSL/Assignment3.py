# Write a python program to compute following computation on matrix: 
#  a) Addition of two matrices 
#  b) Subtraction of two matrices 
#  c) Multiplication of two matrices 
#  d) Transpose of a matrix

class Matrix:

    def __init__(self):
        self.ls = []

    def input(self):
        self.row = int(input("Enter no of rows : "))
        self.col = int(input("Enter no of columns : "))
        print("Enter values in matrix")

        for i in range(self.row):
            temp = []
            for j in range(self.col):
                temp.append(int(input("Enter value at " + str(i) + " " + str(j) + " : ")))
            self.ls.append(temp)

    def display(self):
        print(self.ls)

    def __add__(self, b):
        if self.row != b.row or self.col != b.col:
            print("Matrix are not equal : ")
            print("You Entered", self.row, "x", self.col,"Not Equal to", b.row, "x", b.col)
        else:
            d = Matrix()
            for i in range(self.row):
                temp = []
                for j in range(self.col):
                    temp.append(self.ls[i][j] + b.ls[i][j])
                d.ls.append(temp)
            return d

    def __sub__(self, b):
        if self.row != b.row or self.col != b.col:
            print("Matrix are not equal : ")
            print("You Entered", self.row, "x", self.col,"Not Equal to", b.row, "x", b.col)
        else:
            d = Matrix()
            for i in range(self.row):
                temp = []
                for j in range(self.col):
                    temp.append(self.ls[i][j] - b.ls[i][j])
                d.ls.append(temp)
            return d

    def __mul__(self, b):
        d = Matrix()
        temp = [[0 for i in range(b.col)] for j in range(self.row)]
        for i in range(self.row):
            for j in range(b.col):
                for k in range(b.row):
                    temp[i][j] += self.ls[i][k] * b.ls[k][j]
        d.ls = temp
        return d

    def transpose(self):
        d = Matrix()
        for i in range(self.row):
            temp = []
            for j in range(self.col):
                temp.append(self.ls[j][i])
            d.ls.append(temp)
        d.display()


a = Matrix()
b = Matrix()
c = Matrix()

a.input()
a.display()
b.input()
b.display()

while(True):
    ch = input("""
    Menu
 1) Addition of two matrices 
 2) Subtraction of two matrices 
 3) Multiplication of two matrices 
 4) Transpose of a matrix
 5) Exit

Choose an option : """)

    if ch == '1':
        c = a + b
        c.display()
    elif ch == '2':
        c = a - b
        c.display()
    elif ch == '3':
        c = a * b
        c.display()
    elif ch == '4':
        a.transpose()
        b.transpose()
    elif ch == '5':
        break
    else:
        print("Please Enter Valid choice")