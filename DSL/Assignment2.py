# Write a Python program to compute following operations on String: 
# a) To display word with the longest length 
# b) To determines the frequency of occurrence of particular character in the string 
# c) To check whether given string is palindrome or not 
# d) To display index of first appearance of the substring 
# e) To count the occurrences of each word in a given string 
# (Do not use string built-in functions)


def funA(s):
    words = []
    w = ""
    for i in s:
        if i == " ":
            words.append(w)
            w = ""
        else:
            w += i
    words.append(w)

    maxlen = 0
    word = ""
    for w in words:
        lenght = 0
        for i in w:
            lenght += 1
        if lenght >= maxlen:
            maxlen = lenght
            word = w
    print(word)

def funB(s):
    ch = input("Enter character to find : ")

    count = 0
    for i in s:
        if i == ch:
            count += 1
    print(ch, count)

def funC(s):
    str_len = 0
    for i in s:
        str_len += 1
    
    rev = ""
    for i in range(str_len-1, -1, -1):
        rev += s[i]

    if s == rev:
        print("Palindrome")
    else:
        print("Not Palindrome")

def funD(s):
    sub = input("Enter a substring : ")

    str_len = 0
    for i in s:
        str_len += 1

    sub_len = 0
    for i in sub:
        sub_len += 1

    index = 0
    test = str()
    for i in range(0, str_len-sub_len+1):
        test = str()
        for j in range(i, i+sub_len):
            test = test + s[j]
        if test == sub:
            index += i

    if index == str_len-1:
        print("Not Found")
    else:
        print(sub, index)

def funE(s):
    str_len = 0
    for i in s:
        str_len += 1

    word = str()
    listOfWord = []
    for i in range(str_len):
        if s[i] != " ":
            word += s[i]
        else:
            listOfWord.append(word)
            word = str()
    
    listofDiffWords = []
    for word1 in listOfWord:
        if word1 not in listofDiffWords:
            listofDiffWords.append(word1)

    for word1 in listofDiffWords:
        count = 0
        for word2 in listOfWord:
            if word1 == word2:
                count +=1
        print(word1,count)

string = "Thisss is a test string"

while(True):
    ch = input("""
1) To display word with the longest length 
2) To determines the frequency of occurrence of particular character in the string 
3) To check whether given string is palindrome or not 
4) To display index of first appearance of the substring 
5) To count the occurrences of each word in a given string     
6) Exit

Enter A choice : """)

    if ch == '1':
        funA(string)
    elif ch == '2':
        funB(string)
    elif ch == '3':
        funC(string)
    elif ch == '4':
        funD(string)
    elif ch == '5':
        funE(string)
    elif ch == '6':
        break
    else:
        print("Please Enter valid choice")