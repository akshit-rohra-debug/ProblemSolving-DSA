# Given two binary strings, return their sum (also a binary string).

def addBinary(A, B):
    i = len(A)-1
    j = len(B)-1
    result = ""
    tempA = 0
    tempB = 0
    carry = 0
    while i>-1 or j>-1:
        if i>-1:
            tempA = int(A[i])
        else:
            tempA = 0
        if j>-1:
            tempB = int(B[j])
        else:
            tempB = 0
        result = str(tempA^tempB^carry) + result
        carry = (tempA and tempB) or (tempA and carry) or (tempB and carry)
        i-=1
        j-=1
    if carry == 1:
        result = "1" + result
    return result

print(addBinary("100", "11"))