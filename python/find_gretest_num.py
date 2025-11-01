# write a program to find the greatest of 3 number entered by the user

num1 = int(input("Enter 1st num : "))
num2 = int(input("Enter 2nd num : "))
num3 = int(input("Enter 3rd num : "))

if(num1 >= num2 and num1 >= num3):
    print(num1)
elif(num2 >= num3 and num2 >= num1):
    print(num2)
else:
    print(num3)