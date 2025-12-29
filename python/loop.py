a = int(input())
fst = [2,3,4,5]
scnd = [6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
if a % 2 == 0:
    if a in fst:
        print("Not Weird")
    elif a in scnd:
        print("Weird")
    elif a > 20:
        print("Not Weird")

else:
    print("Weird")